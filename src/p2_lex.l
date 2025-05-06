%option noyywrap nodefault         
%option yylineno                   

%{
/* ---------- C 區段：宣告巨集、標頭、全域 ---------- */
#include "sem_utils.hpp"
#include "y.tab.hpp"          /* Bison 產生；副檔名 hpp */
#include <cstdio>
#include <cstdlib>

#define MAX_LINE_LENGTH 1024

// #define DEBUG_LEX


#ifdef DEBUG_LEX
#define tokenNewline() printf("\n")
#define token(t)          { LIST; printf("<%s> ", #t); return t; }
#define tokenInteger(i)   { LIST; printf("<INT_LIT> "); yylval.ival = (i); return INT_LIT; }
#define tokenReal(r)      { LIST; printf("<REAL_LIT> "); yylval.fval = (r); return REAL_LIT; }
#define tokenBool(b)      { LIST; printf("<BOOL_LIT> "); yylval.bval = (b); return BOOL_LIT; }
#define tokenString(str)  { LIST; printf("<STRING_LIT> "); yylval.sval = new std::string(str); return STRING_LIT; }
#else
#define LIST /* nothing */
#define tokenNewline() /* nothing */
#define token(t)          { return t; }
#define tokenInteger(i)   { yylval.ival = (i); return INT_LIT; }
#define tokenReal(r)      { yylval.fval = (r); return REAL_LIT; }
#define tokenBool(b)      { yylval.bval = (b); return BOOL_LIT; }
#define tokenString(str)  { yylval.sval = new std::string(str); return STRING_LIT; }
#endif



%}

%x C_COMMENT CPP_COMMENT       

%%

"//"             { BEGIN(CPP_COMMENT); }
"/*"             { BEGIN(C_COMMENT);   }

<CPP_COMMENT>{
    "\n"         { BEGIN(INITIAL); /* 自動累計行號 */ }
    .            ;
}

<C_COMMENT>{
    "*/"         { BEGIN(INITIAL); }
    "\n"         ;                 /* 仍要累計行號 */
    .            ;
}

[ \t\r]+        ;                  /* 捨棄空白 */
\n { tokenNewline(); }

"++"            token(INC);
"--"            token(DEC);
"<="            token(LE);
">="            token(GE);
"=="            token(EQ);
"!="            token(NEQ);
"&&"            token(AND);
"||"            token(OR);

"+"             token(PLUS);
"-"             token(MINUS);
"*"             token(MUL);
"/"             token(DIV);
"%"             token(MOD);
"<"             token(LT);
">"             token(GT);
"="             token(ASSIGN);
"!"             token(NOT);

"."             token(DOT);
","             token(COMMA);
":"             token(COLON);
";"             token(SEMICOLON);

"("             token(LPAREN);
")"             token(RPAREN);
"["             token(LBRACK);
"]"             token(RBRACK);
"{"             token(LBRACE);
"}"             token(RBRACE);

"bool"          token(BOOL);
"break"         token(BREAK);
"case"          token(CASE);
"char"          token(CHAR);
"const"         token(CONST);
"continue"      token(CONTINUE);
"default"       token(DEFAULT);
"do"            token(DO);
"double"        token(DOUBLE);
"else"          token(ELSE);
"extern"        token(EXTERN);
"false"         tokenBool(false);
"float"         token(FLOAT);
"for"           token(FOR);
"foreach"       token(FOREACH);
"if"            token(IF);
"int"           token(INT_TOK);
"print"         token(PRINT);
"println"       token(PRINTLN);
"read"          token(READ);
"return"        token(RETURN);
"string"        token(STRING_TOK);
"switch"        token(SWITCH);
"true"          tokenBool(true);
"void"          token(VOID);
"while"         token(WHILE);

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = new std::string(yytext);
    token(ID);
}

([0-9]+)?\.[0-9]+([eE][+-]?[0-9]+)? |
[0-9]+\.[0-9]*([eE][+-]?[0-9]+)? {
    tokenReal(atof(yytext));
}

[0-9]+ {
    tokenInteger(atoi(yytext));
}

\"([^\"\\]|\\.)*\" {
    size_t len = yyleng - 2;                /* 去掉兩邊引號 */
    char *s = (char*)malloc(len + 1);
    strncpy(s, yytext + 1, len);
    s[len] = '\0';
    tokenString(s);
}

. {
    fprintf(stderr, "line %d: illegal character '%s'\n", yylineno, yytext);
    exit(1);
}

%%

