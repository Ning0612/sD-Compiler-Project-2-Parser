%{
#include "sem_utils.hpp"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string> 

extern int  yylex();
extern int  yylineno;
extern FILE* yyin;

SymbolTable symTab;
TypeArena typePool;
std::vector<std::pair<ExprInfo, int>> returnsExpr;

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
    std::vector<Type*>* type_list;
    std::vector<Symbol *>* symbol_list;
    std::vector<int>* int_list;
    varInit* var_init;
    std::vector<varInit*>* var_init_list;
    ExprInfo* expr_info;
    std::vector<ExprInfo*>* expr_info_list;
}

/* ---------- 關鍵字 / 常數 / 識別元 ---------- */
%token                BOOL_TOK FLOAT_TOK DOUBLE_TOK INT_TOK CHAR_TOK STRING_TOK VOID_TOK
%token                IF ELSE DO WHILE FOR FOREACH RETURN
%token                CONST PRINT PRINTLN READ TRUE FALSE
%token <sval>         ID
%token <ival>         INT_LIT
%token <fval>         REAL_LIT
%token <sval>         STRING_LIT
%token <bval>         BOOL_LIT         

%type <type> type_spec
%type <expr_info_list> arg_list
%type <expr_info_list> arg_list_opt
%type <expr_info> func_call
%type <expr_info> const_lit
%type <expr_info> expression
%type <expr_info> lvalue
%type <symbol> const_decl
%type <int_list> array_dims
%type <int_list> array_ref
%type <var_init> var_init
%type <var_init_list> var_init_list
%type <symbol_list> param_list
%type <symbol_list> param_list_opt
%type <symbol> param

/* ---------- 運算子 / 分隔符 ---------- */
%token                LE GE EQ NEQ LT GT
%token                PLUS MINUS MUL DIV MOD ASSIGN NOT
%token                AND OR INC DEC
%token                DOT COMMA COLON SEMICOLON
%token                LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE

%token BREAK CONTINUE SWITCH CASE DEFAULT EXTERN

// CHAR

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
     decl_list{
        Symbol* mainFunc = symTab.lookup("main");
        if (mainFunc == nullptr) {
            throw SemanticError("missing main function", yylineno);
        }

        if (!mainFunc->type->isFunc()) {
            throw SemanticError("main function must be function", yylineno);
        }

        if (mainFunc->type->ret->base != BK_Void) {
            throw SemanticError("main function must return void", yylineno);
        }

        symTab.dbgPrintCurrentScope();
        printf("\nProgram end\n");
     }
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
    CONST type_spec ID ASSIGN expression SEMICOLON
    {
        if (!$2->isCompatibleWith(*$5->type)) {
            throw SemanticError("const type mismatch", yylineno);
        }

        if (!$5->isConst) {
            throw SemanticError("const expression must be const", yylineno);
        }

        Symbol s(*$3, $2, true);
        s.setConstValueFromExpr($5);

        Symbol* exist = symTab.lookupGlobal(s.name);
        if (exist && exist->type->isFunc()) {
            throw SemanticError("const '" + s.name + "' conflicts with function", yylineno);
        }

        if (!symTab.insert(s)) {
            throw SemanticError("redeclared const: " + *$3, yylineno);
        }

        if (isConvertible($2->base, $5->type->base)) {
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
                baseKindToStr($2->base).c_str(), baseKindToStr($5->type->base).c_str(), yylineno);
        }

        delete $3;
        delete $5;
    }
    ;

/* 4-b. 變數 / 陣列宣告 --------------------------------------------------------*/
var_decl:
     type_spec var_init_list SEMICOLON {
        for (auto& var : *$2) {
            Symbol s("", nullptr, false);

            if (var->constType != nullptr) {
                if (!$1->isCompatibleWith(*var->constType)) {
                    throw SemanticError("var type mismatch", yylineno);
                }

                if(isConvertible($1->base, var->constType->base)) {
                    printf("Warning: implicit conversion from %s to %s @ line %d\n",
                        baseKindToStr($1->base).c_str(), baseKindToStr(var->constType->base).c_str(), yylineno);
                }
                s = Symbol(*var->name, $1, false);
            } 
            else if (var->arrayDims != nullptr) {
                Type* arrType = typePool.makeArray($1, *var->arrayDims);
                s = Symbol(*var->name, arrType, false);
            } 
            else {
                s = Symbol(*var->name, $1, false);
            }

            tryInsertVar(symTab, s, yylineno);

            delete var->name;
            if (var->arrayDims) delete var->arrayDims;
            delete var;
        }
        delete $2;
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
  |  ID ASSIGN expression   {
        if ($3->type->isFunc()) {
            throw SemanticError("assignment from function", yylineno);
        }
        if ($3->type->isArray()) {
            throw SemanticError("assignment from array", yylineno);
        }

        $$ = new varInit($1, $3->type);
   }
  |  ID array_dims          { $$ = new varInit($1, $2); }
    ;

/* 4-c. 函式宣告 --------------------------------------------------------------*/
func_decl:
    type_spec ID LPAREN param_list_opt RPAREN LBRACE {
        returnsExpr.clear();

        if (*$2 == "main") {
            throw SemanticError("main function should be void", yylineno);
        }

        declareFunction(*$2, $1, $4, typePool, symTab, yylineno);
        delete $2;
    } block_items_opt RBRACE {
        if (returnsExpr.empty()) {
            throw SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : returnsExpr) {
            if (!$1->isCompatibleWith(*expr.first.type)) {
                throw SemanticError("return type mismatch !", expr.second);
            }

            if (isConvertible($1->base, expr.first.type->base)) {
                printf("Warning: implicit conversion from %s to %s @ line %d\n",
                    baseKindToStr($1->base).c_str(), baseKindToStr(expr.first.type->base).c_str(), expr.second);
            }
        }
        symTab.leaveScope();
    }
  | VOID_TOK ID LPAREN param_list_opt RPAREN LBRACE {
        Type* voidType = typePool.make(BK_Void);
        returnsExpr.clear();
        declareFunction(*$2, voidType, $4, typePool, symTab, yylineno);
        delete $2;
    } block_items_opt RBRACE {
        if (!returnsExpr.empty()) {
            throw SemanticError("void function should not return value", yylineno);
        }

        symTab.leaveScope();
    };


param_list_opt:
    /* empty */ {
        $$ = new std::vector<Symbol*>();
    }
  | param_list {
        $$ = $1;
     }
    ;

param_list:
     param {
        $$ = new std::vector<Symbol*>;
        $$->push_back($1);
     }
  |  param_list COMMA param {
        $$ = $1;
        $$->push_back($3);
     }
    ;

param:
     type_spec ID {
        $$ = new Symbol(*$2, $1, false);
        delete $2;
     }
  |  type_spec ID array_dims{
        $$ = new Symbol(*$2, typePool.makeArray($1, *$3), false);
        delete $2;
        delete $3;
     }
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
  |  PRINT  expression SEMICOLON {
        if ($2->type->isFunc()) {
            throw SemanticError("print from function", yylineno);
        }
        if ($2->type->isArray()) {
            throw SemanticError("print from array", yylineno);
        }

        delete $2;
  }
  |  PRINTLN expression SEMICOLON {
        if ($2->type->isFunc()) {
            throw SemanticError("print from function", yylineno);
        }
        if ($2->type->isArray()) {
            throw SemanticError("print from array", yylineno);
        }

        delete $2;
  }
  |  READ lvalue SEMICOLON {
        if ($2->isConst) {
            throw SemanticError("read to const", yylineno);
        }

        if ($2->type->isFunc()) {
            throw SemanticError("read to function", yylineno);
        }
        if ($2->type->isArray()) {
            throw SemanticError("read to array", yylineno);
        }
    }
  |  lvalue INC SEMICOLON {
        checkIncDecValid($1, "increment", yylineno);
     }
  |  lvalue DEC SEMICOLON {
        checkIncDecValid($1, "decrement", yylineno);
    }
  |  SEMICOLON
    ;

assign_stmt:
     lvalue ASSIGN expression SEMICOLON {
        if ($1->isConst) {
            throw SemanticError("assignment to const", yylineno);
        }

        if ($1->type->isFunc()) {
            throw SemanticError("assignment to function", yylineno);
        }
        if ($1->type->isArray()) {
            throw SemanticError("assignment to array", yylineno);
        }

        if ($3->type->isFunc()) {
            throw SemanticError("assignment from function", yylineno);
        }
        if ($3->type->isArray()) {
            throw SemanticError("assignment from array", yylineno);
        }

        if (!isBaseCompatible($1->type->base, $3->type->base) ) {
                throw SemanticError("assignment type mismatch", yylineno);
        }

        if (isConvertible($1->type->base, $3->type->base)){
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr($3->type->base).c_str(), baseKindToStr($1->type->base).c_str(), yylineno);
        }

        delete $3;
     }
;

lvalue:
     ID {
        Symbol* symbol = symTab.lookup(*$1);
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *$1, yylineno);
        }

        $$ = new ExprInfo(symbol->type, symbol->isConst);

        if (symbol->hasConstValue()) {
            switch (symbol->type->base) {
                case BK_Int:   $$->setInt(symbol->iVal); break;
                case BK_Float: $$->setFloat(symbol->fVal); break;
                case BK_Bool:  $$->setBool(symbol->bVal); break;
                case BK_String: $$->setString(symbol->sVal); break;
                default: break;
            }
        }

        delete $1;
     }
  | ID array_ref {
        Symbol* symbol = symTab.lookup(*$1);
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *$1, yylineno);
        }

        if (!symbol->type->isArray()) {
            throw SemanticError("array index to non-array type: " + *$1, yylineno);
        }

        size_t given = $2->size();
        std::vector<int> dims = symbol->type->sizes;

        for (size_t i = 0; i < given; ++i) {
            int index = (*$2)[i];
            int defined = symbol->type->sizes[i];

            if (index != 0) { 
                if (index < 0 || index >= defined) {
                    throw SemanticError(
                        "array index out of bounds: " + std::to_string(index) +
                        " not in [0.." + std::to_string(symbol->type->sizes[i] - 1) + "]",
                        yylineno
                    );
                }
            }

            if (!dims.empty()){
                dims.erase(dims.begin());
            }
        }

        $$ = new ExprInfo(typePool.makeArray(typePool.make(symbol->type->base), dims), symbol->isConst);
        delete $2;
        delete $1;
    }
    ;

/* 5-b. If --------------------------------------------------------------------*/
if_stmt:
     IF LPAREN expression RPAREN statement {
        checkBoolExpr($3, "if", yylineno);
     }
  |  IF LPAREN expression RPAREN statement ELSE statement {
        checkBoolExpr($3, "if", yylineno);
    }
    ;

/* 5-c. Loop ------------------------------------------------------------------*/
loop_stmt:
     WHILE LPAREN expression RPAREN statement{ 
        checkBoolExpr($3, "while", yylineno); 
    }
  |  DO statement WHILE LPAREN expression RPAREN SEMICOLON {
        checkBoolExpr($5, "do while", yylineno);
    }
  |  FOR LPAREN for_start_opt SEMICOLON expression SEMICOLON for_update_opt RPAREN statement{
        checkBoolExpr($5, "for", yylineno);
    }
  |  FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement{
        checkForeachRange($5, $8, yylineno);
        checkForeachIndex(symTab.lookup(*$3), yylineno);
    }
    ;

for_start_opt:
    /* empty */
  | assign_no_semi
    ;

for_update_opt:
    /* empty */
  | assign_no_semi
  | lvalue INC {
        checkIncDecValid($1, "increment", yylineno);
    }
  | lvalue DEC{
        checkIncDecValid($1, "decrement", yylineno);
    }   
    ;

assign_no_semi:
    lvalue ASSIGN expression {
        if ($1->isConst) {
            throw SemanticError("assignment to const", yylineno);
        }

        if ($1->type->isFunc()) {
            throw SemanticError("assignment to function", yylineno);
        }
        if ($1->type->isArray()) {
            throw SemanticError("assignment to array", yylineno);
        }

        if ($3->type->isFunc()) {
            throw SemanticError("assignment from function", yylineno);
        }
        if ($3->type->isArray()) {
            throw SemanticError("assignment from array", yylineno);
        }

        if (!isBaseCompatible($1->type->base, $3->type->base) ) {
                throw SemanticError("assignment type mismatch", yylineno);
        }

        if (isConvertible($1->type->base, $3->type->base)){
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr($1->type->base).c_str(), baseKindToStr($3->type->base).c_str(), yylineno);
        }
    };


/* 5-d. Return ----------------------------------------------------------------*/
return_stmt:
     RETURN expression SEMICOLON {
        returnsExpr.push_back(std::make_pair(*$2, yylineno));
        delete $2;
     }
    ;

/* 6. Expressions -------------------------------------------------------------*/
expression:
    expression PLUS expression {
        bool isStringConcat = ($1->type->base == BK_String && $3->type->base == BK_String);

        if (isStringConcat) {
            ExprInfo* expr = new ExprInfo(typePool.make(BK_String), $1->isConst && $3->isConst);
            if (expr->isConst) {
                expr->setString($1->getString() + $3->getString());
            }
            $$ = expr;
        } else if (isBaseCompatible($1->type->base, $3->type->base)) {
            $$ = numericResult(OPADD, $1, $3, typePool, yylineno);
        } else {
            throw SemanticError("invalid types for '+' operator", yylineno);
        }

        delete $1;
        delete $3;
    }
  | expression MINUS expression   { $$ = numericResult(OPSUB,  $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression MUL   expression   { $$ = numericResult(OPMUL,  $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression DIV   expression   { $$ = numericResult(OPDIV,  $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression MOD   expression   { $$ = numericResult(OPMOD,  $1,$3,typePool,yylineno); delete $1; delete $3; }

  | expression LT    expression   { $$ = relResult(OPLT, $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression LE    expression   { $$ = relResult(OPLE, $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression GT    expression   { $$ = relResult(OPGT, $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression GE    expression   { $$ = relResult(OPGE, $1,$3,typePool,yylineno); delete $1; delete $3; }

  | expression EQ    expression   { $$ = eqResult(true,  $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression NEQ   expression   { $$ = eqResult(false, $1,$3,typePool,yylineno); delete $1; delete $3; }
  | expression AND   expression    {
        if (!$1->type->isScalar()){
            throw SemanticError("and on non-scalar type", yylineno);
        }

        if (!$3->type->isScalar()){
            throw SemanticError("and on non-scalar type", yylineno);
        }

        if ($1->type->base != BK_Bool || $3->type->base != BK_Bool) {
            throw SemanticError("and on non-bool type", yylineno);
        }

        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), $1->isConst && $3->isConst);
        if (expr->isConst){
            expr->setBool($1->getBool() && $3->getBool());
        }
        $$ = expr;
        delete $1;
        delete $3;
    }
  | expression OR    expression    { 
        if (!$1->type->isScalar()){
            throw SemanticError("or on non-scalar type", yylineno);
        }

        if (!$3->type->isScalar()){
            throw SemanticError("or on non-scalar type", yylineno);
        }

        if ($1->type->base != BK_Bool || $3->type->base != BK_Bool) {
            throw SemanticError("or on non-bool type", yylineno);
        }

        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), $1->isConst && $3->isConst);
        if (expr->isConst){
            expr->setBool($1->getBool() || $3->getBool());
        }
        $$ = expr;
        delete $1;
        delete $3;
    }
  | NOT expression                 { 
        if (!$2->type->isScalar()){
            throw SemanticError("not on non-scalar type", yylineno);
        }

        if ($2->type->base != BK_Bool) {
            throw SemanticError("not on non-bool type", yylineno);
        }

        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), $2->isConst);
        if ($2->isConst){
            expr->setBool(!$2->getBool());
        }
        $$ = expr;
        delete $2;
    }
  | MINUS expression %prec UMINUS  { 
        if (!$2->type->isScalar()){
            throw SemanticError("unary minus on non-scalar type", yylineno);
        }

        if ($2->type->base != BK_Float && $2->type->base != BK_Int && $2->type->base != BK_Double) {
            throw SemanticError("unary minus on non-numeric type", yylineno);
        }

        ExprInfo* expr = new ExprInfo($2->type, $2->isConst);
        if ($2->isConst){
            if ($2->valueKind == VK_Float) {
                expr->setFloat(-$2->getFloat());
            } else if ($2->valueKind == VK_Int) {
                expr->setInt(-$2->getInt());
            } else if ($2->valueKind == VK_Double) {
                expr->setFloat(-$2->getDouble());
            }
        }
        $$ = expr;
        delete $2;
    }
  | PLUS expression %prec UPLUS    { 
        if (!$2->type->isScalar()){
            throw SemanticError("unary plus on non-scalar type", yylineno);
        }

        if ($2->type->base != BK_Float && $2->type->base != BK_Int && $2->type->base != BK_Double) {
            throw SemanticError("unary plus on non-numeric type", yylineno);
        }

        ExprInfo* expr = new ExprInfo($2->type, $2->isConst);
        if ($2->isConst){
            if ($2->valueKind == VK_Float) {
                expr->setFloat($2->getFloat());
            } else if ($2->valueKind == VK_Int) {
                expr->setInt($2->getInt());
            } else if ($2->valueKind == VK_Double) {
                expr->setFloat($2->getDouble());
            }
        }

        $$ = expr;
        delete $2;
    }
  | LPAREN expression RPAREN       { $$ = $2; }
  | lvalue                         { $$ = $1; }
  | const_lit                     { $$ = $1; }
  | func_call                      { $$ = $1; }
    ;

/* 7. 常數 / 呼叫 -------------------------------------------------------------*/
const_lit
    : INT_LIT     { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Int), true);
        expr->setInt($1);
        $$ = expr;
    }
    | REAL_LIT    {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Double), true);
        expr->setFloat($1);
        $$ = expr;
    }
    | STRING_LIT  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_String), true);
        expr->setString(*$1);
        $$ = expr;
        delete $1;
    }
    | BOOL_LIT    {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), true);
        expr->setBool($1);
        $$ = expr;
    }
    ;

func_call:
    ID LPAREN arg_list_opt RPAREN {
        Symbol* symbol = symTab.lookup(*$1);
        checkFuncCall(symbol, *$1, $3, yylineno);
        $$ = new ExprInfo(symbol->type->ret);
        delete $1;
    }

proc_call:
    ID LPAREN arg_list_opt RPAREN {
        Symbol* symbol = symTab.lookup(*$1);
        checkFuncCall(symbol, *$1, $3, yylineno);
        delete $1;
    }

arg_list_opt:
    /* empty */{ 
        $$ = new std::vector<ExprInfo*>();
    }
  | arg_list { $$ = $1; }
    ;

arg_list:
     expression {
        $$ = new std::vector<ExprInfo*>;
        $$->push_back($1);
     }
  |  arg_list COMMA expression{
        $$ = $1;
        $$->push_back($3);
  }
    ;

/* 8. 陣列次方括號 ------------------------------------------------------------*/
array_dims:
     LBRACK expression RBRACK {
        $$ = new std::vector<int>;
        $$->push_back(checkArrayDimExpr($2, yylineno));
     }
  |  array_dims LBRACK expression RBRACK {
        $$ = $1;
        $$->push_back(checkArrayDimExpr($3, yylineno));
     }
    ;

array_ref:
     LBRACK expression RBRACK {
        $$ = new std::vector<int>;
        $$->push_back(extractArrayIndexOrZero($2, yylineno));
        delete $2;
     }
  |  array_ref LBRACK expression RBRACK {
        $$ = $1;
        $$->push_back(extractArrayIndexOrZero($3, yylineno));
        delete $3;
     }
    ;

/* 9. 型別 --------------------------------------------------------------------*/
type_spec
    : INT_TOK    { $$ = typePool.make(BK_Int);   }
    | FLOAT_TOK      { $$ = typePool.make(BK_Float); }
    | DOUBLE_TOK     { $$ = typePool.make(BK_Double); }
    | BOOL_TOK       { $$ = typePool.make(BK_Bool);  }
    | STRING_TOK { $$ = typePool.make(BK_String);}
    ;

%% 

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
        std::fprintf(stderr, "Semantic error @ line %d: %s\n", e.line, e.what());
        return 1;
    }
}