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

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    BOOL = 258,                    /* BOOL  */
    FLOAT = 259,                   /* FLOAT  */
    DOUBLE = 260,                  /* DOUBLE  */
    INT_TOK = 261,                 /* INT_TOK  */
    CHAR = 262,                    /* CHAR  */
    STRING_TOK = 263,              /* STRING_TOK  */
    VOID = 264,                    /* VOID  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    FOR = 268,                     /* FOR  */
    FOREACH = 269,                 /* FOREACH  */
    RETURN = 270,                  /* RETURN  */
    CONST = 271,                   /* CONST  */
    PRINT = 272,                   /* PRINT  */
    PRINTLN = 273,                 /* PRINTLN  */
    READ = 274,                    /* READ  */
    TRUE = 275,                    /* TRUE  */
    FALSE = 276,                   /* FALSE  */
    ID = 277,                      /* ID  */
    INT_LIT = 278,                 /* INT_LIT  */
    REAL_LIT = 279,                /* REAL_LIT  */
    STRING_LIT = 280,              /* STRING_LIT  */
    BOOL_LIT = 281,                /* BOOL_LIT  */
    LE = 282,                      /* LE  */
    GE = 283,                      /* GE  */
    EQ = 284,                      /* EQ  */
    NEQ = 285,                     /* NEQ  */
    LT = 286,                      /* LT  */
    GT = 287,                      /* GT  */
    PLUS = 288,                    /* PLUS  */
    MINUS = 289,                   /* MINUS  */
    MUL = 290,                     /* MUL  */
    DIV = 291,                     /* DIV  */
    MOD = 292,                     /* MOD  */
    ASSIGN = 293,                  /* ASSIGN  */
    NOT = 294,                     /* NOT  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    INC = 297,                     /* INC  */
    DEC = 298,                     /* DEC  */
    DOT = 299,                     /* DOT  */
    COMMA = 300,                   /* COMMA  */
    COLON = 301,                   /* COLON  */
    SEMICOLON = 302,               /* SEMICOLON  */
    LPAREN = 303,                  /* LPAREN  */
    RPAREN = 304,                  /* RPAREN  */
    LBRACK = 305,                  /* LBRACK  */
    RBRACK = 306,                  /* RBRACK  */
    LBRACE = 307,                  /* LBRACE  */
    RBRACE = 308,                  /* RBRACE  */
    BREAK = 309,                   /* BREAK  */
    CONTINUE = 310,                /* CONTINUE  */
    SWITCH = 311,                  /* SWITCH  */
    CASE = 312,                    /* CASE  */
    DEFAULT = 313,                 /* DEFAULT  */
    DO = 314,                      /* DO  */
    EXTERN = 315,                  /* EXTERN  */
    UPLUS = 316,                   /* UPLUS  */
    UMINUS = 317                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BOOL 258
#define FLOAT 259
#define DOUBLE 260
#define INT_TOK 261
#define CHAR 262
#define STRING_TOK 263
#define VOID 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define FOREACH 269
#define RETURN 270
#define CONST 271
#define PRINT 272
#define PRINTLN 273
#define READ 274
#define TRUE 275
#define FALSE 276
#define ID 277
#define INT_LIT 278
#define REAL_LIT 279
#define STRING_LIT 280
#define BOOL_LIT 281
#define LE 282
#define GE 283
#define EQ 284
#define NEQ 285
#define LT 286
#define GT 287
#define PLUS 288
#define MINUS 289
#define MUL 290
#define DIV 291
#define MOD 292
#define ASSIGN 293
#define NOT 294
#define AND 295
#define OR 296
#define INC 297
#define DEC 298
#define DOT 299
#define COMMA 300
#define COLON 301
#define SEMICOLON 302
#define LPAREN 303
#define RPAREN 304
#define LBRACK 305
#define RBRACK 306
#define LBRACE 307
#define RBRACE 308
#define BREAK 309
#define CONTINUE 310
#define SWITCH 311
#define CASE 312
#define DEFAULT 313
#define DO 314
#define EXTERN 315
#define UPLUS 316
#define UMINUS 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "p2_parser.y"

    int ival;
    float fval;
    bool bval;
    std::string* sval;
    Type* type;
    Symbol* symbol;
    std::vector<Symbol *>*
    
     vardecl_list;
    std::vector<int>* int_list;
    varInit* var_init;
    std::vector<varInit*>* var_init_list;

#line 206 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
