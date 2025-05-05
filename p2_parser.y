%{
#include "sd_common.hpp"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string> 

extern int  yylex();
extern int  yylineno;
extern FILE* yyin;

SymbolTable symTab;
TypeArena typePool;
Type* currentDeclType = nullptr;  // 用來暫存 type_spec 傳回的型別

/* 之後若要在 semantic action 使用，可用 $$ = new ExprNode 之類 */

void yyerror(const char* s)
{
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}
%}

/* ---------- token 型別 ---------- */
%union{
    int ival;
    float fval;
    bool bval;
    std::string* sval;
    Type* type;
    Symbol* symbol;
    std::vector<Symbol *>* vardecl_list;
    std::vector<int>* int_list;
    varInit* var_init;
    std::vector<varInit*>* var_init_list;
}

/* ---------- 關鍵字 / 常數 / 識別元 ---------- */
%token                BOOL FLOAT DOUBLE INT_TOK CHAR STRING_TOK VOID
%token                IF ELSE WHILE FOR FOREACH RETURN
%token                CONST PRINT PRINTLN READ TRUE FALSE
%token <sval>         ID
%token <ival>         INT_LIT
%token <fval>         REAL_LIT
%token <sval>         STRING_LIT
%token <bval>         BOOL_LIT         

%type <type> type_spec
%type <type> const_expr
%type <type> expression
%type <symbol> const_decl
%type <int_list> array_dims
%type <ival> array_ref
%type <var_init> var_init
%type <var_init_list> var_init_list
%type <type> lvalue

/* ---------- 運算子 / 分隔符 ---------- */
%token                LE GE EQ NEQ LT GT
%token                PLUS MINUS MUL DIV MOD ASSIGN NOT
%token                AND OR INC DEC
%token                DOT COMMA COLON SEMICOLON
%token                LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE

%token BREAK CONTINUE SWITCH CASE DEFAULT DO EXTERN

// DOUBLE CHAR

/* ---------- 運算子優先序 ---------- */
/* 由低到高（最下面優先序最高） */
%left   OR              /* || ── 最低 */
%left   AND             /* && */
%nonassoc EQ NEQ        /* == !=  (比 && 高) */
%nonassoc LT LE GT GE   /* < <= > >= */
%left   PLUS MINUS      /* + - */
%left   MUL DIV MOD     /* * / % */
%right  NOT             /* !x */
%right  UPLUS UMINUS    /* +x -x */
%right  INC DEC         /* ++ -- */
%right  ASSIGN          /* =  */



/* ---------- 起點 ---------- */
%start program

%% /* ---------- grammar ---------- */

/* 2. Program  ----------------------------------------------------------------*/
program:
     decl_list                              /* 空白程式亦合法 */
    ;

/* 3. 可能為空的宣告序列 ------------------------------------------------------*/
decl_list:
    /* empty */
  | decl_list declaration
    ;

/* 4. Declaration -------------------------------------------------------------*/
declaration:
     const_decl
  |  var_decl
  |  func_decl
    ;

/* 4-a. 常數宣告 --------------------------------------------------------------*/
const_decl:
    CONST type_spec ID ASSIGN const_expr SEMICOLON
    {
        if (*$2 != *$5) {
            throw SemanticError("const type mismatch", yylineno);
        }

        Symbol s(*$3, $2, true);
        if (!symTab.insert(s)) {
            throw SemanticError("redeclared const: " + *$3, yylineno);
        }

        delete $3; 
    }
    ;

/* 4-b. 變數 / 陣列宣告 --------------------------------------------------------*/
var_decl:
     type_spec var_init_list SEMICOLON
    {
        for (auto& var : *$2) {
           if (var->constType != nullptr) {
                if (*$1 != *var->constType) {
                    throw SemanticError("var type mismatch", yylineno);
                }
                Symbol s(*var->name, $1, false);
                if (!symTab.insert(s)) {
                    throw SemanticError("redeclared const: " + *var->name, yylineno);
                }
            }
            else if (var->arrayDims != nullptr) {
                Type* arrType = typePool.makeArray($1, *var->arrayDims);
                Symbol s(*var->name, arrType, false);
                if (!symTab.insert(s)) {
                    throw SemanticError("redeclared var: " + *var->name, yylineno);
                }
            }else{
                Symbol s(*var->name, $1, false);
                if (!symTab.insert(s)) {
                    throw SemanticError("redeclared var: " + *var->name, yylineno);
                }
            }

            if (var->name != nullptr) {
                delete var->name;
            }
            if (var->arrayDims != nullptr) {
                delete var->arrayDims;
            }
            delete var;
        }
    }
    ;

var_init_list:
     var_init{
        $$ = new std::vector<varInit*>;
        $$->push_back($1);}
  |  var_init_list COMMA var_init {
        $$ = $1;
        $$->push_back($3);
    }
    ;

var_init:
     ID                     { $$ = new varInit($1); }  
  |  ID ASSIGN const_expr   { $$ = new varInit($1, $3); }
  |  ID array_dims          { $$ = new varInit($1, $2); }
    ;

/* 4-c. 函式宣告 --------------------------------------------------------------*/
func_decl:
     type_spec ID LPAREN param_list_opt RPAREN block
        /* 動作：insertFunc(); */
  |  VOID      ID LPAREN param_list_opt RPAREN block
        /* 動作：insertProc(); */
    ;

param_list_opt:
    /* empty */
  | param_list
    ;

param_list:
     param
  |  param_list COMMA param
    ;

param:
     type_spec ID
  |  type_spec ID array_dims
    ;

/* 5. Block / Statement -------------------------------------------------------*/
block:
     LBRACE {
        symTab.enterScope();
     } block_items_opt RBRACE{
        symTab.leaveScope();
     }
    ;

block_items_opt:
    /* empty */
  | block_items
    ;

block_items:
     block_items block_item
  |  block_item
    ;

block_item:
     declaration
  |  statement
    ;

statement:
     simple_stmt
  |  if_stmt
  |  loop_stmt
  |  return_stmt
  |  proc_call SEMICOLON
  |  block
    ;

/* 5-a. Simple ---------------------------------------------------------------*/
simple_stmt:
     assign_stmt
  |  PRINT  expression SEMICOLON
  |  PRINTLN expression SEMICOLON
  |  READ   lvalue SEMICOLON
  |  lvalue INC SEMICOLON {
        if ($1->base != BK_Int && $1->base != BK_Float) {
            throw SemanticError("increment to non-integer type", yylineno);
        }
     }
  |  lvalue DEC SEMICOLON {
        if ($1->base != BK_Int && $1->base != BK_Float) {
            throw SemanticError("decrement to non-integer type", yylineno);
        }
  }
  |  SEMICOLON
    ;

assign_stmt:
     lvalue ASSIGN expression SEMICOLON
     {
        if ($1 != $3) {
            if (!(($1->base == BK_Int || $1->base == BK_Float) && ($3->base == BK_Int || $3->base == BK_Float))) {
                throw SemanticError("assignment type mismatch", yylineno);
            }
        }
     }
    ;

lvalue:
     ID
     {
        Symbol* symbol = symTab.lookup(*$1);
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *$1, yylineno);
        }

        if (symbol->isConst) {
            throw SemanticError("assignment to const: " + *$1, yylineno);
        }

        $$ = symbol->type;
     }
  |  ID array_ref
    {
        Symbol* symbol = symTab.lookup(*$1);
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *$1, yylineno);
        }

        if (symbol->isConst) {
            throw SemanticError("assignment to const: " + *$1, yylineno);
        }

        if (!symbol->type->isArray()) {
            throw SemanticError("array index to non-array type: " + *$1, yylineno);
        }

        if ($2 != symbol->type->dim) {
            printf("array index dimension: %d, %d\n", $2, symbol->type->dim);
            throw SemanticError("array index dimension mismatch: " + *$1, yylineno);
        }

        $$ = symbol->type;
    }
    ;

/* 5-b. If --------------------------------------------------------------------*/
if_stmt:
     IF LPAREN expression RPAREN statement 
     {
        if ($3->base != BK_Bool) {
            throw SemanticError("if condition must be bool", yylineno);
        }
     }
  |  IF LPAREN expression RPAREN statement ELSE statement
    {
        if ($3->base != BK_Bool) {
            throw SemanticError("if condition must be bool", yylineno);
        }
    }
    ;

/* 5-c. Loop ------------------------------------------------------------------*/
loop_stmt:
     WHILE LPAREN expression RPAREN statement{
        if ($3->base != BK_Bool) {
            throw SemanticError("while condition must be bool", yylineno);
        }
     }
  |  FOR LPAREN for_start_opt SEMICOLON expression SEMICOLON for_update_opt RPAREN statement{
        if ($5->base != BK_Bool) {
            throw SemanticError("for condition must be bool", yylineno);
        }
      }
  |  FOREACH LPAREN ID COLON INT_LIT DOT DOT INT_LIT RPAREN statement
    ;

for_start_opt:
    /* empty */
  | assign_no_semi
    ;

for_update_opt:
    /* empty */
  | assign_no_semi
  | lvalue INC {
            if ($1->base != BK_Int && $1->base != BK_Float) {
                throw SemanticError("increment to non-integer type", yylineno);
            }
    }
  | lvalue DEC{
            if ($1->base != BK_Int && $1->base != BK_Float) {
                throw SemanticError("decrement to non-integer type", yylineno);
            }
        }   
    ;

assign_no_semi:
     lvalue ASSIGN expression {
        if ($1 != $3) {
            if (!(($1->base == BK_Int || $1->base == BK_Float) && ($3->base == BK_Int || $3->base == BK_Float))) {
                throw SemanticError("assignment type mismatch", yylineno);
            }
        }
     }
    ;

/* 5-d. Return ----------------------------------------------------------------*/
return_stmt:
     RETURN expression SEMICOLON
    ;

/* 6. Expressions -------------------------------------------------------------*/
expression:
     expression PLUS  expression    { $$ = binaryNumericResult($1, $3, typePool, yylineno);}
  |  expression MINUS expression    { $$ = binaryNumericResult($1, $3, typePool, yylineno);}
  |  expression MUL   expression    { $$ = binaryNumericResult($1, $3, typePool, yylineno);}
  |  expression DIV   expression    { 
        if ($3->isZero) {
            throw SemanticError("division by zero", yylineno);
        }
        $$ = binaryNumericResult($1, $3, typePool, yylineno);
    }
  |  expression MOD   expression    { $$ = binaryModResult($1, $3, typePool, yylineno);}
  |  expression LT    expression    { $$ = binaryCompareResult($1, $3, typePool, yylineno);}
  |  expression LE    expression    { $$ = binaryCompareResult($1, $3, typePool, yylineno);}
  |  expression GT    expression    { $$ = binaryCompareResult($1, $3, typePool, yylineno);}
  |  expression GE    expression    { $$ = binaryCompareResult($1, $3, typePool, yylineno);}
  |  expression EQ    expression    { $$ = binaryEqualNotEqualResult($1, $3, typePool, yylineno);}
  |  expression NEQ   expression    { $$ = binaryEqualNotEqualResult($1, $3, typePool, yylineno);}
  |  expression AND   expression    { $$ = binaryBoolResult($1, $3, typePool, yylineno);}
  |  expression OR    expression    { $$ = binaryBoolResult($1, $3, typePool, yylineno);}
  |  NOT expression                 { $$ = unaryBoolResult($2, typePool, yylineno);}
  |  MINUS expression %prec UMINUS  { 
        if ($2->base == BK_Float) {
            $$ = typePool.make(BK_Float);
        } else if ($2->base == BK_Int) {
            $$ = typePool.make(BK_Int);
        } else {
            throw SemanticError("unary minus on non-numeric type", yylineno);
        }
    }
  |  PLUS expression %prec UPLUS    { 
        if ($2->base == BK_Float) {
            $$ = typePool.make(BK_Float);
        } else if ($2->base == BK_Int) {
            $$ = typePool.make(BK_Int);
        } else {
            throw SemanticError("unary plus on non-numeric type", yylineno);
        }
    }
  |  LPAREN expression RPAREN       { $$ = $2;}
  |  lvalue                         { $$ = $1;}
  |  const_expr                     { $$ = $1;}
  |  func_call                      { $$ = typePool.make(BK_Int);}
    ;



/* 7. 常數 / 呼叫 -------------------------------------------------------------*/
const_expr
    : INT_LIT     { $$ = typePool.make(BK_Int, $1 == 0);    }
    | REAL_LIT    { $$ = typePool.make(BK_Float, $1 == 0);  }
    | STRING_LIT  { $$ = typePool.make(BK_String); }
    | BOOL_LIT    { $$ = typePool.make(BK_Bool);   }
    ;

func_call:
     ID LPAREN arg_list_opt RPAREN
    ;

proc_call:
     ID LPAREN arg_list_opt RPAREN
    ;

arg_list_opt:
    /* empty */
  | arg_list
    ;

arg_list:
     expression
  |  arg_list COMMA expression
    ;

/* 8. 陣列次方括號 ------------------------------------------------------------*/
array_dims:
     LBRACK INT_LIT RBRACK{
        if ($2 <= 0) {
            throw SemanticError("array dimension must be positive", yylineno);
        }
        $$ = new std::vector<int>;
        $$->push_back($2);
     }
  |  array_dims LBRACK INT_LIT RBRACK{
        if ($3 <= 0) {
            throw SemanticError("array dimension must be positive", yylineno);
        }
        $$ = $1;
        $$->push_back($3);
     }
    ;

array_ref:
     LBRACK expression RBRACK{
        if ($2->base != BK_Int) {
            throw SemanticError("array index must be int", yylineno);
        }
        $$ = 0;
     }
  |  array_ref LBRACK expression RBRACK{
        if ($3->base != BK_Int) {
            throw SemanticError("array index must be int", yylineno);
        }
        $$ += 1;
  }
    ;

/* 9. 型別 --------------------------------------------------------------------*/
type_spec
    : INT_TOK    { $$ = typePool.make(BK_Int);   }
    | FLOAT      { $$ = typePool.make(BK_Float); }
    | BOOL       { $$ = typePool.make(BK_Bool);  }
    | STRING_TOK { $$ = typePool.make(BK_String);}
    ;

%% /* ---------- user C code ---------- */

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::puts("Usage: sd <source-file>");
        return 1;
    }
    if (!(yyin = std::fopen(argv[1], "r"))) { perror("open"); return 1; }

    try {
        return yyparse();
    } catch (SemanticError& e) {
        std::fprintf(stderr, "Semantic error @ line %d: %s\n",
                     e.line, e.what());
        return 1;
    }
}