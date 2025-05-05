/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "p2_parser.y"

#include "var.hpp" 
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
Type* currentDeclType = nullptr;  // 用來暫存 type_spec 傳回的型別

/* 之後若要在 semantic action 使用，可用 $$ = new ExprNode 之類 */

void yyerror(const char* s)
{
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}

#line 96 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BOOL = 3,                       /* BOOL  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 5,                     /* DOUBLE  */
  YYSYMBOL_INT_TOK = 6,                    /* INT_TOK  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_STRING_TOK = 8,                 /* STRING_TOK  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_FOREACH = 14,                   /* FOREACH  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_CONST = 16,                     /* CONST  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 18,                   /* PRINTLN  */
  YYSYMBOL_READ = 19,                      /* READ  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_INT_LIT = 23,                   /* INT_LIT  */
  YYSYMBOL_REAL_LIT = 24,                  /* REAL_LIT  */
  YYSYMBOL_STRING_LIT = 25,                /* STRING_LIT  */
  YYSYMBOL_BOOL_LIT = 26,                  /* BOOL_LIT  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GE = 28,                        /* GE  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NEQ = 30,                       /* NEQ  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_MUL = 35,                       /* MUL  */
  YYSYMBOL_DIV = 36,                       /* DIV  */
  YYSYMBOL_MOD = 37,                       /* MOD  */
  YYSYMBOL_ASSIGN = 38,                    /* ASSIGN  */
  YYSYMBOL_NOT = 39,                       /* NOT  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_INC = 42,                       /* INC  */
  YYSYMBOL_DEC = 43,                       /* DEC  */
  YYSYMBOL_DOT = 44,                       /* DOT  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_COLON = 46,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 48,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 49,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 50,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 51,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 52,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 53,                    /* RBRACE  */
  YYSYMBOL_BREAK = 54,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 55,                  /* CONTINUE  */
  YYSYMBOL_SWITCH = 56,                    /* SWITCH  */
  YYSYMBOL_CASE = 57,                      /* CASE  */
  YYSYMBOL_DEFAULT = 58,                   /* DEFAULT  */
  YYSYMBOL_DO = 59,                        /* DO  */
  YYSYMBOL_EXTERN = 60,                    /* EXTERN  */
  YYSYMBOL_UPLUS = 61,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 62,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program = 64,                   /* program  */
  YYSYMBOL_decl_list = 65,                 /* decl_list  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_const_decl = 67,                /* const_decl  */
  YYSYMBOL_var_decl = 68,                  /* var_decl  */
  YYSYMBOL_var_init_list = 69,             /* var_init_list  */
  YYSYMBOL_var_init = 70,                  /* var_init  */
  YYSYMBOL_func_decl = 71,                 /* func_decl  */
  YYSYMBOL_param_list_opt = 72,            /* param_list_opt  */
  YYSYMBOL_param_list = 73,                /* param_list  */
  YYSYMBOL_param = 74,                     /* param  */
  YYSYMBOL_block = 75,                     /* block  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_block_items_opt = 77,           /* block_items_opt  */
  YYSYMBOL_block_items = 78,               /* block_items  */
  YYSYMBOL_block_item = 79,                /* block_item  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_simple_stmt = 81,               /* simple_stmt  */
  YYSYMBOL_assign_stmt = 82,               /* assign_stmt  */
  YYSYMBOL_lvalue = 83,                    /* lvalue  */
  YYSYMBOL_if_stmt = 84,                   /* if_stmt  */
  YYSYMBOL_loop_stmt = 85,                 /* loop_stmt  */
  YYSYMBOL_for_start_opt = 86,             /* for_start_opt  */
  YYSYMBOL_for_update_opt = 87,            /* for_update_opt  */
  YYSYMBOL_assign_no_semi = 88,            /* assign_no_semi  */
  YYSYMBOL_return_stmt = 89,               /* return_stmt  */
  YYSYMBOL_expression = 90,                /* expression  */
  YYSYMBOL_const_expr = 91,                /* const_expr  */
  YYSYMBOL_func_call = 92,                 /* func_call  */
  YYSYMBOL_proc_call = 93,                 /* proc_call  */
  YYSYMBOL_arg_list_opt = 94,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 95,                  /* arg_list  */
  YYSYMBOL_array_dims = 96,                /* array_dims  */
  YYSYMBOL_array_ref = 97,                 /* array_ref  */
  YYSYMBOL_type_spec = 98                  /* type_spec  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   443

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    98,   100,   105,   106,   107,   112,   146,
     183,   186,   193,   194,   201,   206,   208,   212,   214,   218,
     219,   223,   224,   229,   229,   236,   238,   242,   243,   247,
     248,   252,   253,   254,   255,   256,   257,   262,   263,   264,
     265,   270,   279,   288,   292,   306,   315,   337,   343,   353,
     358,   363,   366,   368,   371,   373,   374,   383,   395,   410,
     415,   416,   417,   418,   419,   421,   422,   423,   424,   426,
     427,   428,   441,   454,   466,   482,   499,   502,   505,   508,
     515,   520,   525,   531,   539,   543,   546,   548,   552,   553,
     558,   565,   575,   581,   591,   592,   593,   594
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BOOL", "FLOAT",
  "DOUBLE", "INT_TOK", "CHAR", "STRING_TOK", "VOID", "IF", "ELSE", "WHILE",
  "FOR", "FOREACH", "RETURN", "CONST", "PRINT", "PRINTLN", "READ", "TRUE",
  "FALSE", "ID", "INT_LIT", "REAL_LIT", "STRING_LIT", "BOOL_LIT", "LE",
  "GE", "EQ", "NEQ", "LT", "GT", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "ASSIGN", "NOT", "AND", "OR", "INC", "DEC", "DOT", "COMMA", "COLON",
  "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "BREAK", "CONTINUE", "SWITCH", "CASE", "DEFAULT", "DO", "EXTERN",
  "UPLUS", "UMINUS", "$accept", "program", "decl_list", "declaration",
  "const_decl", "var_decl", "var_init_list", "var_init", "func_decl",
  "param_list_opt", "param_list", "param", "block", "$@1",
  "block_items_opt", "block_items", "block_item", "statement",
  "simple_stmt", "assign_stmt", "lvalue", "if_stmt", "loop_stmt",
  "for_start_opt", "for_update_opt", "assign_no_semi", "return_stmt",
  "expression", "const_expr", "func_call", "proc_call", "arg_list_opt",
  "arg_list", "array_dims", "array_ref", "type_spec", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -102,     8,    92,  -102,  -102,  -102,  -102,  -102,    -2,     1,
    -102,  -102,  -102,  -102,    16,   -25,    40,   -36,    -8,  -102,
       1,    36,    34,     1,    46,    30,    61,  -102,    37,    42,
    -102,    68,    34,     5,  -102,  -102,  -102,  -102,    34,    34,
      34,    34,  -102,   366,  -102,  -102,    45,    52,    74,   -37,
    -102,    54,     1,    57,   240,    34,    34,    64,  -102,  -102,
    -102,   171,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    54,  -102,    53,  -102,  -102,
    -102,    30,  -102,   366,    62,    70,   121,    34,  -102,   106,
     106,   395,   395,   106,   106,    35,    35,  -102,  -102,  -102,
     406,   381,  -102,  -102,   113,  -102,    34,  -102,   146,    72,
      88,    98,    99,    34,    34,    34,    96,    31,  -102,  -102,
    -102,   111,   113,  -102,  -102,  -102,  -102,    67,  -102,  -102,
    -102,   112,   366,  -102,    34,    34,    96,   144,   261,   282,
     303,   119,   123,    34,  -102,  -102,    34,   124,   137,  -102,
     194,   217,   147,   141,  -102,   143,  -102,  -102,  -102,  -102,
     142,   324,  -102,  -102,    14,    14,    34,    34,   167,  -102,
    -102,   181,  -102,   366,   345,   149,    14,    96,   150,  -102,
     125,   160,  -102,   172,  -102,  -102,    14,   161,  -102,    14,
    -102
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    96,    95,    94,    97,     0,     0,
       4,     5,     6,     7,     0,     0,     0,    12,     0,    10,
      17,     0,     0,    17,     0,    14,     0,     9,     0,    18,
      19,     0,     0,    45,    80,    81,    82,    83,     0,     0,
       0,     0,    77,    13,    78,    79,     0,     0,     0,    12,
      11,     0,     0,    21,     0,    86,     0,    46,    75,    74,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,    23,    16,
      20,    22,     8,    88,     0,    87,     0,     0,    76,    66,
      68,    69,    70,    65,    67,    60,    61,    62,    63,    64,
      71,    72,    15,    91,    25,    84,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    43,    29,
      36,     0,    26,    28,    30,    31,    37,     0,    32,    33,
      34,     0,    89,    93,     0,     0,    52,     0,     0,     0,
       0,    45,     0,    86,    24,    27,     0,     0,     0,    35,
       0,     0,     0,     0,    53,     0,    59,    38,    39,    40,
       0,     0,    41,    42,     0,     0,     0,     0,     0,    85,
      44,    47,    49,    58,     0,     0,     0,    54,     0,    48,
       0,     0,    55,     0,    56,    57,     0,     0,    50,     0,
      51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,   211,  -102,  -102,  -102,   170,  -102,   191,
    -102,   163,   -45,  -102,  -102,  -102,    94,   -87,  -102,  -102,
    -101,  -102,  -102,  -102,  -102,    41,  -102,   -22,  -102,  -102,
    -102,    76,  -102,   164,  -102,     2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   119,    11,    12,    18,    19,    13,    28,
      29,    30,   120,   104,   121,   122,   123,   124,   125,   126,
      42,   128,   129,   153,   181,   154,   130,    83,    44,    45,
     131,    84,    85,    25,    57,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    22,    22,   127,     4,     5,    79,     6,     3,     7,
      54,    16,    23,    24,    24,   142,    58,    59,    60,    61,
      15,   127,    31,    20,   109,    31,   110,   111,   112,   113,
     102,   114,   115,   116,    86,   152,   117,    26,    17,    27,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    55,    31,    56,    33,    34,    35,    36,
      37,   118,    21,   127,   127,   108,    78,    38,    39,    47,
      70,    71,    72,    40,    32,   127,   180,   171,   172,   143,
      48,    56,    41,    49,   132,   127,    51,    52,   127,   179,
      53,   138,   139,   140,    75,     4,     5,    77,     6,   188,
       7,     8,   190,    76,   103,   146,    78,    24,     9,   147,
     148,   105,   150,   151,    87,   106,     4,     5,   141,     6,
     134,     7,     8,   109,   161,   110,   111,   112,   113,     9,
     114,   115,   116,    -1,    -1,   117,   135,    -1,    -1,    68,
      69,    70,    71,    72,   173,   174,   136,   137,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   149,
     118,    73,    74,   166,   144,    78,   155,   184,   185,    56,
     159,   162,   107,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   163,   166,    73,    74,   167,   168,
     175,   169,   176,   178,   183,   187,    50,   133,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   186,
     189,    73,    74,    10,    46,    80,   145,    81,   182,   160,
      88,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,     0,     0,     0,
       0,     0,     0,   164,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,     0,     0,     0,     0,   165,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,     0,     0,    82,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,     0,     0,   156,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,     0,     0,   157,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,     0,     0,
     158,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,     0,     0,     0,
       0,   170,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
       0,     0,   177,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72
};

static const yytype_int16 yycheck[] =
{
      22,    38,    38,   104,     3,     4,    51,     6,     0,     8,
      32,     9,    48,    50,    50,   116,    38,    39,    40,    41,
      22,   122,    20,    48,    10,    23,    12,    13,    14,    15,
      75,    17,    18,    19,    56,   136,    22,    45,    22,    47,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    48,    52,    50,    22,    23,    24,    25,
      26,    47,    22,   164,   165,    87,    52,    33,    34,    23,
      35,    36,    37,    39,    38,   176,   177,   164,   165,    48,
      50,    50,    48,    22,   106,   186,    49,    45,   189,   176,
      22,   113,   114,   115,    49,     3,     4,    23,     6,   186,
       8,     9,   189,    51,    51,    38,    52,    50,    16,    42,
      43,    49,   134,   135,    50,    45,     3,     4,    22,     6,
      48,     8,     9,    10,   146,    12,    13,    14,    15,    16,
      17,    18,    19,    27,    28,    22,    48,    31,    32,    33,
      34,    35,    36,    37,   166,   167,    48,    48,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    47,
      47,    40,    41,    38,    53,    52,    22,    42,    43,    50,
      47,    47,    51,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    47,    38,    40,    41,    47,    46,
      23,    49,    11,    44,    44,    23,    26,    51,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    49,
      49,    40,    41,     2,    23,    52,   122,    53,   177,   143,
      49,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,     3,     4,     6,     8,     9,    16,
      66,    67,    68,    71,    98,    22,    98,    22,    69,    70,
      48,    22,    38,    48,    50,    96,    45,    47,    72,    73,
      74,    98,    38,    22,    23,    24,    25,    26,    33,    34,
      39,    48,    83,    90,    91,    92,    72,    23,    50,    22,
      70,    49,    45,    22,    90,    48,    50,    97,    90,    90,
      90,    90,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    40,    41,    49,    51,    23,    52,    75,
      74,    96,    47,    90,    94,    95,    90,    50,    49,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    75,    51,    76,    49,    45,    51,    90,    10,
      12,    13,    14,    15,    17,    18,    19,    22,    47,    66,
      75,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      89,    93,    90,    51,    48,    48,    48,    48,    90,    90,
      90,    22,    83,    48,    53,    79,    38,    42,    43,    47,
      90,    90,    83,    86,    88,    22,    47,    47,    47,    47,
      94,    90,    47,    47,    49,    49,    38,    47,    46,    49,
      47,    80,    80,    90,    90,    23,    11,    47,    44,    80,
      83,    87,    88,    44,    42,    43,    49,    23,    80,    49,
      80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    67,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    76,    75,    77,    77,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    86,    87,    87,    87,    87,    88,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    92,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     6,     3,
       1,     3,     1,     3,     2,     6,     6,     0,     1,     1,
       3,     2,     3,     0,     4,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     3,     3,
       3,     3,     3,     1,     4,     1,     2,     5,     7,     5,
       9,    10,     0,     1,     0,     1,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     0,     1,     1,     3,
       3,     4,     3,     4,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* const_decl: CONST type_spec ID ASSIGN expression SEMICOLON  */
#line 113 "p2_parser.y"
    {
        if (*(yyvsp[-4].type) != *(yyvsp[-1].expr_info)->type) {
            throw SemanticError("const type mismatch", yylineno);
        }

        if (!(yyvsp[-1].expr_info)->isConst) {
            throw SemanticError("const expression must be const", yylineno);
        }

        Symbol s(*(yyvsp[-3].sval), (yyvsp[-4].type), true);

        if ((yyvsp[-1].expr_info)->valueKind == VK_Float) {
            s.setFloat((yyvsp[-1].expr_info)->getFloat());
        } else if ((yyvsp[-1].expr_info)->valueKind == VK_Int) {
            s.setInt((yyvsp[-1].expr_info)->getInt());
        } else if ((yyvsp[-1].expr_info)->valueKind == VK_String) {
            s.setString((yyvsp[-1].expr_info)->getString());
        } else if ((yyvsp[-1].expr_info)->valueKind == VK_Bool) {
            s.setBool((yyvsp[-1].expr_info)->getBool());
        }
        
        if (!symTab.insert(s)) {
            throw SemanticError("redeclared const: " + *(yyvsp[-3].sval), yylineno);
        }

        

        delete (yyvsp[-3].sval); 
    }
#line 1393 "y.tab.cpp"
    break;

  case 9: /* var_decl: type_spec var_init_list SEMICOLON  */
#line 147 "p2_parser.y"
    {
        for (auto& var : *(yyvsp[-1].var_init_list)) {
           if (var->constType != nullptr) {
                if (*(yyvsp[-2].type) != *var->constType) {
                    throw SemanticError("var type mismatch", yylineno);
                }
                Symbol s(*var->name, (yyvsp[-2].type), false);
                if (!symTab.insert(s)) {
                    throw SemanticError("redeclared const: " + *var->name, yylineno);
                }
            }
            else if (var->arrayDims != nullptr) {
                Type* arrType = typePool.makeArray((yyvsp[-2].type), *var->arrayDims);
                Symbol s(*var->name, arrType, false);
                if (!symTab.insert(s)) {
                    throw SemanticError("redeclared var: " + *var->name, yylineno);
                }
            }else{
                Symbol s(*var->name, (yyvsp[-2].type), false);
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
#line 1431 "y.tab.cpp"
    break;

  case 10: /* var_init_list: var_init  */
#line 183 "p2_parser.y"
             {
        (yyval.var_init_list) = new std::vector<varInit*>;
        (yyval.var_init_list)->push_back((yyvsp[0].var_init));}
#line 1439 "y.tab.cpp"
    break;

  case 11: /* var_init_list: var_init_list COMMA var_init  */
#line 186 "p2_parser.y"
                                  {
        (yyval.var_init_list) = (yyvsp[-2].var_init_list);
        (yyval.var_init_list)->push_back((yyvsp[0].var_init));
    }
#line 1448 "y.tab.cpp"
    break;

  case 12: /* var_init: ID  */
#line 193 "p2_parser.y"
                            { (yyval.var_init) = new varInit((yyvsp[0].sval)); }
#line 1454 "y.tab.cpp"
    break;

  case 13: /* var_init: ID ASSIGN expression  */
#line 194 "p2_parser.y"
                            {
        if (!(yyvsp[0].expr_info)->isConst) {
            throw SemanticError("assignment to non-const", yylineno);
        }

        (yyval.var_init) = new varInit((yyvsp[-2].sval), (yyvsp[0].expr_info)->type);
   }
#line 1466 "y.tab.cpp"
    break;

  case 14: /* var_init: ID array_dims  */
#line 201 "p2_parser.y"
                            { (yyval.var_init) = new varInit((yyvsp[-1].sval), (yyvsp[0].int_list)); }
#line 1472 "y.tab.cpp"
    break;

  case 23: /* $@1: %empty  */
#line 229 "p2_parser.y"
            {
        symTab.enterScope();
     }
#line 1480 "y.tab.cpp"
    break;

  case 24: /* block: LBRACE $@1 block_items_opt RBRACE  */
#line 231 "p2_parser.y"
                             {
        symTab.leaveScope();
     }
#line 1488 "y.tab.cpp"
    break;

  case 40: /* simple_stmt: READ lvalue SEMICOLON  */
#line 265 "p2_parser.y"
                           {
        if ((yyvsp[-1].symbol)->isConst) {
            throw SemanticError("read to const", yylineno);
        }
    }
#line 1498 "y.tab.cpp"
    break;

  case 41: /* simple_stmt: lvalue INC SEMICOLON  */
#line 270 "p2_parser.y"
                          {
        if ((yyvsp[-2].symbol)->isConst) {
            throw SemanticError("increment to const", yylineno);
        }

        if ((yyvsp[-2].symbol)->type->base != BK_Int && (yyvsp[-2].symbol)->type->base != BK_Float) {
            throw SemanticError("increment to non-integer type", yylineno);
        }
     }
#line 1512 "y.tab.cpp"
    break;

  case 42: /* simple_stmt: lvalue DEC SEMICOLON  */
#line 279 "p2_parser.y"
                          {
        if ((yyvsp[-2].symbol)->isConst) {
            throw SemanticError("decrement to const", yylineno);
        }

        if ((yyvsp[-2].symbol)->type->base != BK_Int && (yyvsp[-2].symbol)->type->base != BK_Float) {
            throw SemanticError("decrement to non-integer type", yylineno);
        }
    }
#line 1526 "y.tab.cpp"
    break;

  case 44: /* assign_stmt: lvalue ASSIGN expression SEMICOLON  */
#line 292 "p2_parser.y"
                                        {
        if ((yyvsp[-3].symbol)->isConst) {
            throw SemanticError("assignment to const", yylineno);
        }

        if ((yyvsp[-3].symbol)->type != (yyvsp[-1].expr_info)->type) {
            if (!(((yyvsp[-3].symbol)->type->base == BK_Int || (yyvsp[-3].symbol)->type->base == BK_Float) && ((yyvsp[-1].expr_info)->type->base == BK_Int || (yyvsp[-1].expr_info)->type->base == BK_Float))) {
                throw SemanticError("assignment type mismatch", yylineno);
            }
        }
     }
#line 1542 "y.tab.cpp"
    break;

  case 45: /* lvalue: ID  */
#line 307 "p2_parser.y"
     {
        Symbol* symbol = symTab.lookup(*(yyvsp[0].sval));
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *(yyvsp[0].sval), yylineno);
        }

        (yyval.symbol) = symbol;
     }
#line 1555 "y.tab.cpp"
    break;

  case 46: /* lvalue: ID array_ref  */
#line 316 "p2_parser.y"
    {
        Symbol* symbol = symTab.lookup(*(yyvsp[-1].sval));
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *(yyvsp[-1].sval), yylineno);
        }

        if (!symbol->type->isArray()) {
            throw SemanticError("array index to non-array type: " + *(yyvsp[-1].sval), yylineno);
        }

        if ((yyvsp[0].ival) != symbol->type->dim) {
            printf("array index dimension: %d, %d\n", (yyvsp[0].ival), symbol->type->dim);
            throw SemanticError("array index dimension mismatch: " + *(yyvsp[-1].sval), yylineno);
        }

        (yyval.symbol) = symbol;
    }
#line 1577 "y.tab.cpp"
    break;

  case 47: /* if_stmt: IF LPAREN expression RPAREN statement  */
#line 338 "p2_parser.y"
     {
        if ((yyvsp[-2].expr_info)->type->base != BK_Bool) {
            throw SemanticError("if condition must be bool", yylineno);
        }
     }
#line 1587 "y.tab.cpp"
    break;

  case 48: /* if_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 344 "p2_parser.y"
    {
        if ((yyvsp[-4].expr_info)->type->base != BK_Bool) {
            throw SemanticError("if condition must be bool", yylineno);
        }
    }
#line 1597 "y.tab.cpp"
    break;

  case 49: /* loop_stmt: WHILE LPAREN expression RPAREN statement  */
#line 353 "p2_parser.y"
                                             {
            if ((yyvsp[-2].expr_info)->type->base != BK_Bool) {
                throw SemanticError("while condition must be bool", yylineno);
            }
        }
#line 1607 "y.tab.cpp"
    break;

  case 50: /* loop_stmt: FOR LPAREN for_start_opt SEMICOLON expression SEMICOLON for_update_opt RPAREN statement  */
#line 358 "p2_parser.y"
                                                                                            {
        if ((yyvsp[-4].expr_info)->type->base != BK_Bool) {
            throw SemanticError("for condition must be bool", yylineno);
        }
      }
#line 1617 "y.tab.cpp"
    break;

  case 56: /* for_update_opt: lvalue INC  */
#line 374 "p2_parser.y"
               {
            if ((yyvsp[-1].symbol)->isConst) {
                throw SemanticError("increment to const", yylineno);
            }

            if ((yyvsp[-1].symbol)->type->base != BK_Int && (yyvsp[-1].symbol)->type->base != BK_Float) {
                throw SemanticError("increment to non-integer type", yylineno);
            }
    }
#line 1631 "y.tab.cpp"
    break;

  case 57: /* for_update_opt: lvalue DEC  */
#line 383 "p2_parser.y"
              {
            if ((yyvsp[-1].symbol)->isConst) {
                throw SemanticError("decrement to const", yylineno);
            }

            if ((yyvsp[-1].symbol)->type->base != BK_Int && (yyvsp[-1].symbol)->type->base != BK_Float) {
                throw SemanticError("decrement to non-integer type", yylineno);
            }
        }
#line 1645 "y.tab.cpp"
    break;

  case 58: /* assign_no_semi: lvalue ASSIGN expression  */
#line 395 "p2_parser.y"
                              {
        if ((yyvsp[-2].symbol)->isConst) {
            throw SemanticError("assignment to const", yylineno);
        }

        if ((yyvsp[-2].symbol)->type != (yyvsp[0].expr_info)->type) {
            if (!(((yyvsp[-2].symbol)->type->base == BK_Int || (yyvsp[-2].symbol)->type->base == BK_Float) && ((yyvsp[0].expr_info)->type->base == BK_Int || (yyvsp[0].expr_info)->type->base == BK_Float))) {
                throw SemanticError("assignment type mismatch", yylineno);
            }
        }
     }
#line 1661 "y.tab.cpp"
    break;

  case 60: /* expression: expression PLUS expression  */
#line 415 "p2_parser.y"
                                    { (yyval.expr_info) = numericResult(OPADD,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1667 "y.tab.cpp"
    break;

  case 61: /* expression: expression MINUS expression  */
#line 416 "p2_parser.y"
                                    { (yyval.expr_info) = numericResult(OPSUB,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1673 "y.tab.cpp"
    break;

  case 62: /* expression: expression MUL expression  */
#line 417 "p2_parser.y"
                                    { (yyval.expr_info) = numericResult(OPMUL,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1679 "y.tab.cpp"
    break;

  case 63: /* expression: expression DIV expression  */
#line 418 "p2_parser.y"
                                    { (yyval.expr_info) = numericResult(OPDIV,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1685 "y.tab.cpp"
    break;

  case 64: /* expression: expression MOD expression  */
#line 419 "p2_parser.y"
                                    { (yyval.expr_info) = numericResult(OPMOD,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1691 "y.tab.cpp"
    break;

  case 65: /* expression: expression LT expression  */
#line 421 "p2_parser.y"
                                    { (yyval.expr_info) = relResult(OPLT, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1697 "y.tab.cpp"
    break;

  case 66: /* expression: expression LE expression  */
#line 422 "p2_parser.y"
                                    { (yyval.expr_info) = relResult(OPLE, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1703 "y.tab.cpp"
    break;

  case 67: /* expression: expression GT expression  */
#line 423 "p2_parser.y"
                                    { (yyval.expr_info) = relResult(OPGT, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1709 "y.tab.cpp"
    break;

  case 68: /* expression: expression GE expression  */
#line 424 "p2_parser.y"
                                    { (yyval.expr_info) = relResult(OPGE, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1715 "y.tab.cpp"
    break;

  case 69: /* expression: expression EQ expression  */
#line 426 "p2_parser.y"
                                    { (yyval.expr_info) = eqResult(true,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1721 "y.tab.cpp"
    break;

  case 70: /* expression: expression NEQ expression  */
#line 427 "p2_parser.y"
                                    { (yyval.expr_info) = eqResult(false, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1727 "y.tab.cpp"
    break;

  case 71: /* expression: expression AND expression  */
#line 428 "p2_parser.y"
                                    {
        if ((yyvsp[-2].expr_info)->type->base != BK_Bool || (yyvsp[0].expr_info)->type->base != BK_Bool) {
            throw SemanticError("and on non-bool type", yylineno);
        }

        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), (yyvsp[-2].expr_info)->isConst && (yyvsp[0].expr_info)->isConst);
        if (expr->isConst){
            expr->setBool((yyvsp[-2].expr_info)->getBool() && (yyvsp[0].expr_info)->getBool());
        }
        (yyval.expr_info) = expr;
        delete (yyvsp[-2].expr_info);
        delete (yyvsp[0].expr_info);
    }
#line 1745 "y.tab.cpp"
    break;

  case 72: /* expression: expression OR expression  */
#line 441 "p2_parser.y"
                                    { 
        if ((yyvsp[-2].expr_info)->type->base != BK_Bool || (yyvsp[0].expr_info)->type->base != BK_Bool) {
            throw SemanticError("or on non-bool type", yylineno);
        }

        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), (yyvsp[-2].expr_info)->isConst && (yyvsp[0].expr_info)->isConst);
        if (expr->isConst){
            expr->setBool((yyvsp[-2].expr_info)->getBool() || (yyvsp[0].expr_info)->getBool());
        }
        (yyval.expr_info) = expr;
        delete (yyvsp[-2].expr_info);
        delete (yyvsp[0].expr_info);
    }
#line 1763 "y.tab.cpp"
    break;

  case 73: /* expression: NOT expression  */
#line 454 "p2_parser.y"
                                    { 
        if ((yyvsp[0].expr_info)->type->base != BK_Bool) {
            throw SemanticError("not on non-bool type", yylineno);
        }

        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), (yyvsp[0].expr_info)->isConst);
        if ((yyvsp[0].expr_info)->isConst){
            expr->setBool(!(yyvsp[0].expr_info)->getBool());
        }
        (yyval.expr_info) = expr;
        delete (yyvsp[0].expr_info);
    }
#line 1780 "y.tab.cpp"
    break;

  case 74: /* expression: MINUS expression  */
#line 466 "p2_parser.y"
                                    { 
        if ((yyvsp[0].expr_info)->type->base != BK_Float && (yyvsp[0].expr_info)->type->base != BK_Int) {
            throw SemanticError("unary minus on non-numeric type", yylineno);
        }

        ExprInfo* expr = new ExprInfo((yyvsp[0].expr_info)->type, (yyvsp[0].expr_info)->isConst);
        if ((yyvsp[0].expr_info)->isConst){
            if ((yyvsp[0].expr_info)->valueKind == VK_Float) {
                expr->setFloat(-(yyvsp[0].expr_info)->getFloat());
            } else if ((yyvsp[0].expr_info)->valueKind == VK_Int) {
                expr->setInt(-(yyvsp[0].expr_info)->getInt());
            }
        }
        (yyval.expr_info) = expr;
        delete (yyvsp[0].expr_info);
    }
#line 1801 "y.tab.cpp"
    break;

  case 75: /* expression: PLUS expression  */
#line 482 "p2_parser.y"
                                    { 
        if ((yyvsp[0].expr_info)->type->base != BK_Float && (yyvsp[0].expr_info)->type->base != BK_Int) {
            throw SemanticError("unary plus on non-numeric type", yylineno);
        }

        ExprInfo* expr = new ExprInfo((yyvsp[0].expr_info)->type, (yyvsp[0].expr_info)->isConst);
        if ((yyvsp[0].expr_info)->isConst){
            if ((yyvsp[0].expr_info)->valueKind == VK_Float) {
                expr->setFloat((yyvsp[0].expr_info)->getFloat());
            } else if ((yyvsp[0].expr_info)->valueKind == VK_Int) {
                expr->setInt((yyvsp[0].expr_info)->getInt());
            }
        }

        (yyval.expr_info) = expr;
        delete (yyvsp[0].expr_info);
    }
#line 1823 "y.tab.cpp"
    break;

  case 76: /* expression: LPAREN expression RPAREN  */
#line 499 "p2_parser.y"
                                    {
        (yyval.expr_info) = (yyvsp[-1].expr_info);
    }
#line 1831 "y.tab.cpp"
    break;

  case 77: /* expression: lvalue  */
#line 502 "p2_parser.y"
                                    {
        (yyval.expr_info) = (yyvsp[0].symbol)->getExpr();
    }
#line 1839 "y.tab.cpp"
    break;

  case 78: /* expression: const_expr  */
#line 505 "p2_parser.y"
                                     {
        (yyval.expr_info) = (yyvsp[0].expr_info);
    }
#line 1847 "y.tab.cpp"
    break;

  case 79: /* expression: func_call  */
#line 508 "p2_parser.y"
                                    {
    
  }
#line 1855 "y.tab.cpp"
    break;

  case 80: /* const_expr: INT_LIT  */
#line 515 "p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Int), true);
        expr->setInt((yyvsp[0].ival));
        (yyval.expr_info) = expr;
    }
#line 1865 "y.tab.cpp"
    break;

  case 81: /* const_expr: REAL_LIT  */
#line 520 "p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Float), true);
        expr->setFloat((yyvsp[0].fval));
        (yyval.expr_info) = expr;
    }
#line 1875 "y.tab.cpp"
    break;

  case 82: /* const_expr: STRING_LIT  */
#line 525 "p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_String), true);
        expr->setString(*(yyvsp[0].sval));
        (yyval.expr_info) = expr;
        delete (yyvsp[0].sval);
    }
#line 1886 "y.tab.cpp"
    break;

  case 83: /* const_expr: BOOL_LIT  */
#line 531 "p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), true);
        expr->setBool((yyvsp[0].bval));
        (yyval.expr_info) = expr;
    }
#line 1896 "y.tab.cpp"
    break;

  case 90: /* array_dims: LBRACK INT_LIT RBRACK  */
#line 558 "p2_parser.y"
                          {
        if ((yyvsp[-1].ival) <= 0) {
            throw SemanticError("array dimension must be positive", yylineno);
        }
        (yyval.int_list) = new std::vector<int>;
        (yyval.int_list)->push_back((yyvsp[-1].ival));
     }
#line 1908 "y.tab.cpp"
    break;

  case 91: /* array_dims: array_dims LBRACK INT_LIT RBRACK  */
#line 565 "p2_parser.y"
                                     {
        if ((yyvsp[-1].ival) <= 0) {
            throw SemanticError("array dimension must be positive", yylineno);
        }
        (yyval.int_list) = (yyvsp[-3].int_list);
        (yyval.int_list)->push_back((yyvsp[-1].ival));
     }
#line 1920 "y.tab.cpp"
    break;

  case 92: /* array_ref: LBRACK expression RBRACK  */
#line 575 "p2_parser.y"
                             {
        if ((yyvsp[-1].expr_info)->type->base != BK_Int) {
            throw SemanticError("array index must be int", yylineno);
        }
        (yyval.ival) = 0;
     }
#line 1931 "y.tab.cpp"
    break;

  case 93: /* array_ref: array_ref LBRACK expression RBRACK  */
#line 581 "p2_parser.y"
                                       {
        if ((yyvsp[-1].expr_info)->type->base != BK_Int) {
            throw SemanticError("array index must be int", yylineno);
        }
        (yyval.ival) += 1;
  }
#line 1942 "y.tab.cpp"
    break;

  case 94: /* type_spec: INT_TOK  */
#line 591 "p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Int);   }
#line 1948 "y.tab.cpp"
    break;

  case 95: /* type_spec: FLOAT  */
#line 592 "p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Float); }
#line 1954 "y.tab.cpp"
    break;

  case 96: /* type_spec: BOOL  */
#line 593 "p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Bool);  }
#line 1960 "y.tab.cpp"
    break;

  case 97: /* type_spec: STRING_TOK  */
#line 594 "p2_parser.y"
                 { (yyval.type) = typePool.make(BK_String);}
#line 1966 "y.tab.cpp"
    break;


#line 1970 "y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 597 "p2_parser.y"
 /* ---------- user C code ---------- */

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
