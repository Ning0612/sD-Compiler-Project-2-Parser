%{
#include "sem_utils.hpp"
#include "context.hpp"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string> 

extern int  yylex();
extern int  yylineno;
extern FILE* yyin;

Context* ctx = nullptr;

void yyerror(const char* s){
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}
%}
/* ---------- token type ---------- */
%union{
    int ival;
    float fval;
    bool bval;
    std::string* sval;
    Type* type;
    Symbol* symbol;
    VarInit* var_init_;
    ExprInfo* expr_info;

    std::vector<int>* int_list;
    std::vector<Symbol>* symbol_list;
    std::vector<ExprInfo>* expr_info_list;
}

/* ---------- Keywords / Constants / Identifiers ---------- */
%token                BOOL_TOK FLOAT_TOK DOUBLE_TOK INT_TOK CHAR_TOK STRING_TOK VOID_TOK
%token                IF ELSE DO WHILE FOR FOREACH RETURN
%token                CONST PRINT PRINTLN READ TRUE FALSE
%token <sval>         ID
%token <ival>         INT_LIT
%token <fval>         REAL_LIT
%token <sval>         STRING_LIT
%token <bval>         BOOL_LIT         

%type <type> type_spec
%type <symbol> param
%type <symbol> const_decl
%type <symbol_list> param_list
%type <symbol_list> param_list_opt
%type <expr_info> func_call
%type <expr_info> const_lit
%type <expr_info> expression
%type <expr_info> lvalue
%type <expr_info_list> arg_list
%type <expr_info_list> arg_list_opt
%type <int_list> array_dims
%type <int_list> array_ref
%type <var_init_> var_init

/* ---------- Operators / Delimiters ---------- */
%token                LE GE EQ NEQ LT GT
%token                PLUS MINUS MUL DIV MOD ASSIGN NOT
%token                AND OR INC DEC
%token                DOT COMMA COLON SEMICOLON
%token                LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE

%token BREAK CONTINUE SWITCH CASE DEFAULT EXTERN

// CHAR

/* ---------- Operator Precedence (Lowest to Highest) ---------- */
%left   OR                      /* || */
%left   AND                     /* && */
%nonassoc IFX                   /* if */
%nonassoc ELSE                  /* else */
%right  NOT                     /* !x */
%nonassoc LT LE GT GE EQ NEQ    /* < <= > >= == != */
%left   PLUS MINUS              /* + - */
%left   MUL DIV MOD             /* * / % */
%right  INC DEC UPLUS UMINUS    /* ++ -- */
%right  ASSIGN                  /* =  */

%start program // start symbol

%% 
/* ---------- Grammar Rules ---------- */

/* Program Rule */
program
    : global_decl_list {
        Symbol* mainFunc = ctx->symTab.lookup("main");
        if (mainFunc == nullptr) {
            SemanticError("missing main function", yylineno);
        }

        if (!mainFunc->type->isFunc()) {
            SemanticError("main function must be function", yylineno);
        }

        if (mainFunc->type->ret->base != BK_Void) {
            SemanticError("main function must be void", yylineno);
        }

        ctx->symTab.leaveScope();
        printf("\n");
    }
    ;

global_decl_list
    : /* empty */
    | global_decl_list global_decl
    ;

/* Declarations */
global_decl
    : const_decl
    | var_decl
    | func_decl     
    ;

local_decl
    : const_decl
    | var_decl       
    ;

/* Constant Declaration */
const_decl
    :
    CONST type_spec ID ASSIGN expression SEMICOLON {
        std::string id = *$3; delete $3;
        ExprInfo value = *$5; delete $5;
        tryDeclareConstant(ctx->symTab, id, $2, value, yylineno);
    }
    ;

/* Variable / Array Declaration */
var_decl
    : type_spec var_init_list SEMICOLON 
    ;

var_init_list
    : var_init{
        VarInit varInit = *$1; delete $1;
        tryDeclareVarable(ctx->symTab, ctx->typePool, varInit, ctx->nowType, yylineno);
    }
    | var_init_list COMMA var_init {
        VarInit varInit = *$3; delete $3;
        tryDeclareVarable(ctx->symTab, ctx->typePool, varInit, ctx->nowType, yylineno);
    }
    ;

var_init
    : ID                     { $$ = new VarInit(*$1); delete $1; }  
    | ID ASSIGN expression   {
        std::string id = *$1; delete $1;
        ExprInfo expr = *$3; delete $3;

        if (!expr.isValid) {
            $$ = makeInvalidVar();
        }else{
            if (expr.type->isFunc()) {
                SemanticError("assignment from function", yylineno);
            }

            if (expr.type->isArray()) {
                SemanticError("assignment from array", yylineno);
            }

            if (!expr.isConst) {
                SemanticError("assignment from non-constant", yylineno);
            }
            $$ = new VarInit(id, expr.type);
        }
    }
    | ID array_dims          { 
        std::string id = *$1; delete $1;
        std::vector<int> arrayIndex = *$2; delete $2;

        bool isValid = true;
        for (auto& index : arrayIndex) {
            if (index <= 0) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            $$ = makeInvalidVar();
        }else{
            $$ = new VarInit(id, arrayIndex);
        }
    }
    ;

/* Function Declaration */
func_decl
    : type_spec ID LPAREN param_list_opt RPAREN LBRACE {
        ctx->returnsExpr.clear();

        std::string funcName = *$2; delete $2;
        std::vector<Symbol> paramList = *$4; delete $4;

        if (funcName == "main") {
            SemanticError("main function should be void", yylineno);
        }

        declareFunction(funcName, $1, paramList, ctx->typePool, ctx->symTab, yylineno);
    } block_items_opt RBRACE {
        if (ctx->returnsExpr.empty()) {
            SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : ctx->returnsExpr) {
            if (!$1->isCompatibleWith(*expr.first.type)) {
                SemanticError("return type mismatch !", expr.second);
            }

            if (isConvertible($1->base, expr.first.type->base)) {
                printf("[Warning] Line %d:  implicit conversion from %s to %s\n", expr.second,
                    baseKindToStr($1->base).c_str(), baseKindToStr(expr.first.type->base).c_str());
            }
        }

        ctx->symTab.leaveScope();
    }
    | VOID_TOK ID LPAREN param_list_opt RPAREN LBRACE {
        ctx->returnsExpr.clear();

        std::string funcName = *$2; delete $2;
        std::vector<Symbol> paramList = *$4; delete $4;

        declareFunction(funcName, ctx->typePool.make(BK_Void), paramList, ctx->typePool, ctx->symTab, yylineno);
    } block_items_opt RBRACE {
        if (!ctx->returnsExpr.empty()) {
            SemanticError("void function should not return value", yylineno);
        }

        ctx->symTab.leaveScope();
    }
    ;

/* Function Parameters */
param_list_opt:
    /* empty */ {
        $$ = new std::vector<Symbol>();
    }
    | param_list {
        $$ = $1;
    }
    ;

param_list
    : param {
        $$ = new std::vector<Symbol>;
        $$->push_back(*$1);
        delete $1;
    }
    | param_list COMMA param {
        $$ = $1;
        $$->push_back(*$3);
        delete $3;
    }
    ;

param
    : type_spec ID {
        std::string id = *$2; delete $2;
        $$ = new Symbol(id, $1, false);
    }
    | type_spec ID array_dims{
        std::string id = *$2; delete $2;
        std::vector<int> arrayIndex = *$3; delete $3;
        $$ = new Symbol(id, ctx->typePool.makeArray($1, arrayIndex), false);
    }
    ;

/* Block and Statements */
block
    : LBRACE {
        ctx->symTab.enterScope();
    } block_items_opt RBRACE {
        ctx->symTab.leaveScope();
    }
    ;

block_items_opt
    :/* empty */
    | block_items
    ;

block_items
    : block_items block_item
    | block_item
    ;

block_item
    : local_decl        
    | statement
    ;

statement
    : simple_stmt
    | if_stmt
    | loop_stmt
    | return_stmt
    | proc_call SEMICOLON
    | block
    ;

/* Simple Statements */
simple_stmt
    : assign_stmt
    | PRINT expression SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        checkPrint(expr, yylineno);
    }
    | PRINTLN expression SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        checkPrint(expr, yylineno);
    }
    | READ lvalue SEMICOLON {
        ExprInfo expr = *$2; delete $2;
        checkRead(expr, yylineno);
    }
    | lvalue INC SEMICOLON {
        ExprInfo expr = *$1; delete $1;
        checkIncDecValid("increment", expr, yylineno);
     }
    | lvalue DEC SEMICOLON {
        ExprInfo expr = *$1; delete $1;
        checkIncDecValid("decrement", expr, yylineno);
    }
    | SEMICOLON
    ;

assign_stmt
    : lvalue ASSIGN expression SEMICOLON {
        ExprInfo target = *$1; delete $1;
        ExprInfo value = *$3; delete $3;
        checkAssignment(target, value, yylineno);
    }
    ;

/* Lvalue Access */
lvalue
    : ID {
        std::string id = *$1; delete $1;
        Symbol* symbol = ctx->symTab.lookup(id);

        if (symbol == nullptr) {
            SemanticError("undeclared identifier: " + id, yylineno);
            $$ = makeInvalidExpr();
        } else {
            $$ = new ExprInfo(symbol->type, symbol->isConst);

            if (symbol->hasConstValue()) {
                switch (symbol->type->base) {
                    case BK_Int:   $$->setInt(symbol->iVal); break;
                    case BK_Float: $$->setFloat(symbol->fVal); break;
                    case BK_Double: $$->setFloat(symbol->dVal); break;
                    case BK_Bool:  $$->setBool(symbol->bVal); break;
                    case BK_String: $$->setString(symbol->sVal); break;
                    default: break;
                }
            }
        }
    }
    | ID array_ref {
        std::string id = *$1; delete $1;
        std::vector<int> arrayIndex = *$2; delete $2;
        $$ = resolveArrayAccess(id, ctx->typePool, ctx->symTab, arrayIndex, yylineno);
    }
    ;

/* If Statement */
if_stmt
    : IF LPAREN expression RPAREN statement %prec IFX {
        ExprInfo expr = *$3; delete $3;
        checkBoolExpr("if", expr, yylineno);
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        ExprInfo expr = *$3; delete $3;
        checkBoolExpr("if", expr, yylineno);
    }
    ;

/* Loop Statements */
loop_stmt
    : WHILE LPAREN expression RPAREN statement{ 
        ExprInfo expr = *$3; delete $3;
        checkBoolExpr("while", expr, yylineno); 
    }
    | DO statement WHILE LPAREN expression RPAREN SEMICOLON {
        ExprInfo expr = *$5; delete $5;
        checkBoolExpr("do while", expr, yylineno);
    }
    | FOR LPAREN for_simple_opt SEMICOLON expression SEMICOLON for_simple_opt RPAREN statement{
        ExprInfo expr = *$5; delete $5;
        checkBoolExpr("for", expr, yylineno);
    }
    | FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement{
        ExprInfo from = *$5; ExprInfo to = *$8; delete $5; delete $8;
        std::string id = *$3; delete $3;
        checkForeachRange(from, to, yylineno);
        checkForeachIndex(ctx->symTab.lookup(id), yylineno);
    }
    ;

/* For Loop Optional Statements */
for_simple_opt
    : /* empty */
    | for_simple_item
    | for_simple_opt COMMA for_simple_item
    ;

for_simple_item
    : assign_no_semi
    | PRINT  expression  {
        ExprInfo expr = *$2; delete $2;
        checkPrint(expr, yylineno);
    }
    | PRINTLN expression  {
        ExprInfo expr = *$2; delete $2;
        checkPrint(expr, yylineno);
    }
    | READ lvalue  {
        ExprInfo expr = *$2; delete $2;
        checkRead(expr, yylineno);
    }
    | lvalue INC  {
        ExprInfo expr = *$1; delete $1;
        checkIncDecValid("increment", expr, yylineno);
     }
    | lvalue DEC  {
        ExprInfo expr = *$1; delete $1;
        checkIncDecValid("decrement", expr, yylineno);
    }
    ;

assign_no_semi
    : lvalue ASSIGN expression {
        ExprInfo target = *$1; delete $1;
        ExprInfo value = *$3; delete $3;
        checkAssignment(target, value, yylineno);
    }
    ;

/* Return Statement */
return_stmt
    : RETURN expression SEMICOLON {
        ctx->returnsExpr.push_back(std::make_pair(*$2, yylineno));
        delete $2;
     }
    ;

/* Expressions */
expression
    : expression PLUS expression {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        if(!lhs.isValid || !rhs.isValid) {
            $$ = makeInvalidExpr();
        }else {
            bool isStringConcat = (lhs.type->base == BK_String && rhs.type->base == BK_String);

            if (isStringConcat) {
                $$ = concatStringResult(lhs, rhs, ctx->typePool, yylineno);
            } else {
                $$ = numericOpResult(OPADD, lhs, rhs, ctx->typePool, yylineno);
            }
        }
    }
    | expression MINUS expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = numericOpResult(OPSUB, lhs, rhs, ctx->typePool, yylineno);
    }
    | expression MUL   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = numericOpResult(OPMUL, lhs, rhs, ctx->typePool, yylineno);
    }
    | expression DIV   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = numericOpResult(OPDIV, lhs, rhs, ctx->typePool, yylineno);
    }
    | expression MOD   expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = numericOpResult(OPMOD, lhs, rhs, ctx->typePool, yylineno);
    }

    | expression LT    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = relOpResult(OPLT, lhs , rhs, ctx->typePool, yylineno);
    }
    | expression LE    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = relOpResult(OPLE, lhs , rhs, ctx->typePool, yylineno);
    }
    | expression GT    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = relOpResult(OPGT, lhs , rhs, ctx->typePool, yylineno);
    }
    | expression GE    expression   { 
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = relOpResult(OPGE, lhs , rhs, ctx->typePool, yylineno);
    }

    | expression EQ    expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = eqOpResult(true, lhs, rhs, ctx->typePool, yylineno);
    }
    | expression NEQ   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = eqOpResult(false, lhs, rhs, ctx->typePool, yylineno);
    }

    | expression AND   expression   {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = boolOpResult(true, lhs , rhs, ctx->typePool, yylineno);
    }
    | expression OR expression      {
        ExprInfo lhs = *$1; ExprInfo rhs = *$3; delete $1; delete $3;
        $$ = boolOpResult(false, lhs , rhs, ctx->typePool, yylineno);
    }
    | NOT expression                {
        ExprInfo expr = *$2; delete $2;
        $$ = notOpResult(expr, ctx->typePool, yylineno);
    }

    | MINUS expression %prec UMINUS {
        ExprInfo expr = *$2; delete $2;
        $$ = unaryOpResult(true, expr, yylineno);
    }
    | PLUS expression %prec UPLUS   {
        ExprInfo expr = *$2; delete $2;
        $$ = unaryOpResult(false, expr, yylineno);
    }

    | LPAREN expression RPAREN       { $$ = $2; }
    | lvalue                         { $$ = $1; }
    | const_lit                      { $$ = $1; }
    | func_call                      { $$ = $1; }
    ;

/* Constants */
const_lit
    : INT_LIT     { 
        $$ = new ExprInfo(ctx->typePool.make(BK_Int), true);
        $$->setInt($1);
    }
    | REAL_LIT    {
        $$ = new ExprInfo(ctx->typePool.make(BK_Double), true);
        $$->setFloat($1);
    }
    | BOOL_LIT    {
        $$ = new ExprInfo(ctx->typePool.make(BK_Bool), true);
        $$->setBool($1);
    }    
    | STRING_LIT  { 
        $$ = new ExprInfo(ctx->typePool.make(BK_String), true);
        $$->setString(*$1);
        delete $1;
    }
    ;

/* Function Calls */
func_call
    : ID LPAREN arg_list_opt RPAREN {
        Symbol* symbol = ctx->symTab.lookup(*$1);
        std::string funcName = *$1; delete $1;
        std::vector<ExprInfo> args = *$3; delete $3;
        checkFuncCall(symbol, funcName, args, yylineno);
        $$ = new ExprInfo(symbol->type->ret);
    }

proc_call
    : ID LPAREN arg_list_opt RPAREN {
        Symbol* symbol = ctx->symTab.lookup(*$1);
        std::string funcName = *$1; delete $1;
        std::vector<ExprInfo> args = *$3; delete $3;
        checkFuncCall(symbol, funcName, args, yylineno);
    }

/* Function Arguments */
arg_list_opt
    : /* empty */{ $$ = new std::vector<ExprInfo>();}
    | arg_list { $$ = $1; }
    ;

arg_list
    : expression {
        $$ = new std::vector<ExprInfo>();
        $$->push_back(*$1);
        delete $1;
    }
    | arg_list COMMA expression{
        $$ = $1;
        $$->push_back(*$3);
        delete $3;
    }
    ;

/* Array Dimensions */
array_dims
    : LBRACK expression RBRACK {
        $$ = new std::vector<int>;
        ExprInfo expr = *$2; delete $2;
        $$->push_back(checkArrayDimExpr(expr, yylineno));
    }
    | array_dims LBRACK expression RBRACK {
        $$ = $1;
        ExprInfo expr = *$3; delete $3;
        $$->push_back(checkArrayDimExpr(expr, yylineno));
    }
    ;

/* Array Reference */
array_ref
    : LBRACK expression RBRACK {
        $$ = new std::vector<int>;
        ExprInfo expr = *$2; delete $2;
        $$->push_back(extractArrayIndexOrZero(expr, yylineno));
    }
    | array_ref LBRACK expression RBRACK {
        $$ = $1;
        ExprInfo expr = *$3; delete $3;
        $$->push_back(extractArrayIndexOrZero(expr, yylineno));
    }
    ;

/* Type Specification */
type_spec
    : INT_TOK    { $$ = ctx->typePool.make(BK_Int); ctx->nowType = $$; }
    | FLOAT_TOK      { $$ = ctx->typePool.make(BK_Float); ctx->nowType = $$; }
    | DOUBLE_TOK     { $$ = ctx->typePool.make(BK_Double); ctx->nowType = $$; }
    | BOOL_TOK       { $$ = ctx->typePool.make(BK_Bool);  ctx->nowType = $$; }
    | STRING_TOK { $$ = ctx->typePool.make(BK_String); ctx->nowType = $$;}
    ;

%% 

int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        std::puts("Usage: sd <source-file>");
        return 1;
    }

    // Try to open the input file
    if (!(yyin = std::fopen(argv[1], "r"))) {
        perror("open"); // Print system error message
        return 1;
    }

    // Initialize semantic analysis context
    Context context;
    ctx = &context;

    // Start parsing with error handling for semantic errors
    int result = yyparse();
    
    if (SemanticError::hasError()) {
        SemanticError::printAll();
        return 2;
    }

    return result;
}