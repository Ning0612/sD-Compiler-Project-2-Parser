/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_Y_TAB_HPP_INCLUDED
# define YY_YY_SRC_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BOOL_TOK = 258,                /* BOOL_TOK  */
    FLOAT_TOK = 259,               /* FLOAT_TOK  */
    DOUBLE_TOK = 260,              /* DOUBLE_TOK  */
    INT_TOK = 261,                 /* INT_TOK  */
    CHAR_TOK = 262,                /* CHAR_TOK  */
    STRING_TOK = 263,              /* STRING_TOK  */
    VOID_TOK = 264,                /* VOID_TOK  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    DO = 267,                      /* DO  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    FOREACH = 270,                 /* FOREACH  */
    RETURN = 271,                  /* RETURN  */
    CONST = 272,                   /* CONST  */
    PRINT = 273,                   /* PRINT  */
    PRINTLN = 274,                 /* PRINTLN  */
    READ = 275,                    /* READ  */
    TRUE = 276,                    /* TRUE  */
    FALSE = 277,                   /* FALSE  */
    ID = 278,                      /* ID  */
    INT_LIT = 279,                 /* INT_LIT  */
    REAL_LIT = 280,                /* REAL_LIT  */
    STRING_LIT = 281,              /* STRING_LIT  */
    BOOL_LIT = 282,                /* BOOL_LIT  */
    LE = 283,                      /* LE  */
    GE = 284,                      /* GE  */
    EQ = 285,                      /* EQ  */
    NEQ = 286,                     /* NEQ  */
    LT = 287,                      /* LT  */
    GT = 288,                      /* GT  */
    PLUS = 289,                    /* PLUS  */
    MINUS = 290,                   /* MINUS  */
    MUL = 291,                     /* MUL  */
    DIV = 292,                     /* DIV  */
    MOD = 293,                     /* MOD  */
    ASSIGN = 294,                  /* ASSIGN  */
    NOT = 295,                     /* NOT  */
    AND = 296,                     /* AND  */
    OR = 297,                      /* OR  */
    INC = 298,                     /* INC  */
    DEC = 299,                     /* DEC  */
    DOT = 300,                     /* DOT  */
    COMMA = 301,                   /* COMMA  */
    COLON = 302,                   /* COLON  */
    SEMICOLON = 303,               /* SEMICOLON  */
    LPAREN = 304,                  /* LPAREN  */
    RPAREN = 305,                  /* RPAREN  */
    LBRACK = 306,                  /* LBRACK  */
    RBRACK = 307,                  /* RBRACK  */
    LBRACE = 308,                  /* LBRACE  */
    RBRACE = 309,                  /* RBRACE  */
    BREAK = 310,                   /* BREAK  */
    CONTINUE = 311,                /* CONTINUE  */
    SWITCH = 312,                  /* SWITCH  */
    CASE = 313,                    /* CASE  */
    DEFAULT = 314,                 /* DEFAULT  */
    EXTERN = 315,                  /* EXTERN  */
    IFX = 316,                     /* IFX  */
    UPLUS = 317,                   /* UPLUS  */
    UMINUS = 318                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BOOL_TOK 258
#define FLOAT_TOK 259
#define DOUBLE_TOK 260
#define INT_TOK 261
#define CHAR_TOK 262
#define STRING_TOK 263
#define VOID_TOK 264
#define IF 265
#define ELSE 266
#define DO 267
#define WHILE 268
#define FOR 269
#define FOREACH 270
#define RETURN 271
#define CONST 272
#define PRINT 273
#define PRINTLN 274
#define READ 275
#define TRUE 276
#define FALSE 277
#define ID 278
#define INT_LIT 279
#define REAL_LIT 280
#define STRING_LIT 281
#define BOOL_LIT 282
#define LE 283
#define GE 284
#define EQ 285
#define NEQ 286
#define LT 287
#define GT 288
#define PLUS 289
#define MINUS 290
#define MUL 291
#define DIV 292
#define MOD 293
#define ASSIGN 294
#define NOT 295
#define AND 296
#define OR 297
#define INC 298
#define DEC 299
#define DOT 300
#define COMMA 301
#define COLON 302
#define SEMICOLON 303
#define LPAREN 304
#define RPAREN 305
#define LBRACK 306
#define RBRACK 307
#define LBRACE 308
#define RBRACE 309
#define BREAK 310
#define CONTINUE 311
#define SWITCH 312
#define CASE 313
#define DEFAULT 314
#define EXTERN 315
#define IFX 316
#define UPLUS 317
#define UMINUS 318

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "src/p2_parser.y"

    int ival;
    float fval;
    bool bval;
    std::string* sval;
    Type* type;
    Symbol* symbol;
    VarInit* var_init;
    ExprInfo* expr_info;

    std::vector<int>* int_list;
    std::vector<Symbol>* symbol_list;
    std::vector<VarInit>* var_init_list;
    std::vector<ExprInfo>* expr_info_list;

#line 209 "src/y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_Y_TAB_HPP_INCLUDED  */
