%{
#include "sd_common.hpp"
#include <cstdio>
#include <cstdlib>

extern int  yylex();
extern int  yylineno;
extern FILE* yyin;

static SymbolTable symTab;

/* 之後若要在 semantic action 使用，可用 $$ = new ExprNode 之類 */

void yyerror(const char* s)
{
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}
%}

/* ---------- token 型別 ---------- */
%union{
    int    ival;
    double fval;
    char  *sval;
}

/* ---------- 關鍵字 / 常數 / 識別元 ---------- */
%token                BOOL FLOAT DOUBLE INT_TOK CHAR STRING_TOK VOID
%token                IF ELSE WHILE FOR FOREACH RETURN
%token                CONST PRINT PRINTLN READ TRUE FALSE
%token <sval>         ID
%token <ival>         INT_LIT
%token <fval>         REAL_LIT
%token <sval>         STRING_LIT
%token                BOOL_LIT         /* 由 lexer 將 TRUE/FALSE 映射 */

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
        /* 動作：insertConst(); */
    ;

/* 4-b. 變數 / 陣列宣告 --------------------------------------------------------*/
var_decl:
     type_spec var_init_list SEMICOLON
        /* 動作：insertVarList(); */
    ;

var_init_list:
     var_init
  |  var_init_list COMMA var_init
    ;

var_init:
     ID
  |  ID ASSIGN const_expr
  |  ID array_dims
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
     LBRACE block_items_opt RBRACE
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
  |  error SEMICOLON          { yyerrok; /* 行級復原 */ }
    ;

/* 5-a. Simple ---------------------------------------------------------------*/
simple_stmt:
     assign_stmt
  |  PRINT  expression SEMICOLON
  |  PRINTLN expression SEMICOLON
  |  READ   lvalue SEMICOLON
  |  INC lvalue SEMICOLON
  |  DEC lvalue SEMICOLON
  |  SEMICOLON                               /* 空敘述 */
    ;

assign_stmt:
     lvalue ASSIGN expression SEMICOLON
    ;

lvalue:
     ID
  |  ID array_ref
    ;

/* 5-b. If --------------------------------------------------------------------*/
if_stmt:
     IF LPAREN expression RPAREN statement
  |  IF LPAREN expression RPAREN statement ELSE statement
    ;

/* 5-c. Loop ------------------------------------------------------------------*/
loop_stmt:
     WHILE LPAREN expression RPAREN statement
  |  FOR LPAREN for_start_opt SEMICOLON expression SEMICOLON for_update_opt RPAREN statement
  |  FOREACH LPAREN ID COLON INT_LIT DOT DOT INT_LIT RPAREN statement
    ;

for_start_opt:
    /* empty */
  | assign_no_semi
    ;

for_update_opt:
    /* empty */
  | assign_no_semi
  | lvalue INC
  | lvalue DEC
    ;

assign_no_semi:
     lvalue ASSIGN expression
    ;

/* 5-d. Return ----------------------------------------------------------------*/
return_stmt:
     RETURN expression SEMICOLON
    ;

/* 6. Expressions -------------------------------------------------------------*/
expression:
     expression PLUS  expression
  |  expression MINUS expression
  |  expression MUL   expression
  |  expression DIV   expression
  |  expression MOD   expression
  |  expression LT    expression
  |  expression LE    expression
  |  expression GT    expression
  |  expression GE    expression
  |  expression EQ    expression
  |  expression NEQ   expression
  |  expression AND   expression
  |  expression OR    expression
  |  NOT expression
  |  MINUS expression %prec UMINUS
  |  PLUS expression %prec UPLUS
  |  LPAREN expression RPAREN
  |  lvalue
  |  const_expr
  |  func_call
    ;

/* 7. 常數 / 呼叫 -------------------------------------------------------------*/
const_expr:
     INT_LIT
  |  REAL_LIT
  |  STRING_LIT
  |  BOOL_LIT
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
     LBRACK INT_LIT RBRACK
  |  array_dims LBRACK INT_LIT RBRACK
    ;

array_ref:
     LBRACK expression RBRACK
  |  array_ref LBRACK expression RBRACK
    ;

/* 9. 型別 --------------------------------------------------------------------*/
type_spec:
     BOOL
  |  FLOAT
  |  INT_TOK
  |  STRING_TOK
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
                     e.line(), e.what());
        return 1;
    }
}