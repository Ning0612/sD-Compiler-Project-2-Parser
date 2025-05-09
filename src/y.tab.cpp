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
#line 1 "src/p2_parser.y"

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

#line 91 "src/y.tab.cpp"

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
  YYSYMBOL_BOOL_TOK = 3,                   /* BOOL_TOK  */
  YYSYMBOL_FLOAT_TOK = 4,                  /* FLOAT_TOK  */
  YYSYMBOL_DOUBLE_TOK = 5,                 /* DOUBLE_TOK  */
  YYSYMBOL_INT_TOK = 6,                    /* INT_TOK  */
  YYSYMBOL_CHAR_TOK = 7,                   /* CHAR_TOK  */
  YYSYMBOL_STRING_TOK = 8,                 /* STRING_TOK  */
  YYSYMBOL_VOID_TOK = 9,                   /* VOID_TOK  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_DO = 12,                        /* DO  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_FOREACH = 15,                   /* FOREACH  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_CONST = 17,                     /* CONST  */
  YYSYMBOL_PRINT = 18,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 19,                   /* PRINTLN  */
  YYSYMBOL_READ = 20,                      /* READ  */
  YYSYMBOL_TRUE = 21,                      /* TRUE  */
  YYSYMBOL_FALSE = 22,                     /* FALSE  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_INT_LIT = 24,                   /* INT_LIT  */
  YYSYMBOL_REAL_LIT = 25,                  /* REAL_LIT  */
  YYSYMBOL_STRING_LIT = 26,                /* STRING_LIT  */
  YYSYMBOL_BOOL_LIT = 27,                  /* BOOL_LIT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_PLUS = 34,                      /* PLUS  */
  YYSYMBOL_MINUS = 35,                     /* MINUS  */
  YYSYMBOL_MUL = 36,                       /* MUL  */
  YYSYMBOL_DIV = 37,                       /* DIV  */
  YYSYMBOL_MOD = 38,                       /* MOD  */
  YYSYMBOL_ASSIGN = 39,                    /* ASSIGN  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_INC = 43,                       /* INC  */
  YYSYMBOL_DEC = 44,                       /* DEC  */
  YYSYMBOL_DOT = 45,                       /* DOT  */
  YYSYMBOL_COMMA = 46,                     /* COMMA  */
  YYSYMBOL_COLON = 47,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 48,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 49,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 50,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 51,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 52,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 53,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 54,                    /* RBRACE  */
  YYSYMBOL_BREAK = 55,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 56,                  /* CONTINUE  */
  YYSYMBOL_SWITCH = 57,                    /* SWITCH  */
  YYSYMBOL_CASE = 58,                      /* CASE  */
  YYSYMBOL_DEFAULT = 59,                   /* DEFAULT  */
  YYSYMBOL_EXTERN = 60,                    /* EXTERN  */
  YYSYMBOL_IFX = 61,                       /* IFX  */
  YYSYMBOL_UPLUS = 62,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 63,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_program = 65,                   /* program  */
  YYSYMBOL_global_decl_list = 66,          /* global_decl_list  */
  YYSYMBOL_global_decl = 67,               /* global_decl  */
  YYSYMBOL_local_decl = 68,                /* local_decl  */
  YYSYMBOL_const_decl = 69,                /* const_decl  */
  YYSYMBOL_var_decl = 70,                  /* var_decl  */
  YYSYMBOL_71_1 = 71,                      /* $@1  */
  YYSYMBOL_var_init_list = 72,             /* var_init_list  */
  YYSYMBOL_var_init = 73,                  /* var_init  */
  YYSYMBOL_func_decl = 74,                 /* func_decl  */
  YYSYMBOL_75_2 = 75,                      /* $@2  */
  YYSYMBOL_76_3 = 76,                      /* $@3  */
  YYSYMBOL_param_list_opt = 77,            /* param_list_opt  */
  YYSYMBOL_param_list = 78,                /* param_list  */
  YYSYMBOL_param = 79,                     /* param  */
  YYSYMBOL_block = 80,                     /* block  */
  YYSYMBOL_81_4 = 81,                      /* $@4  */
  YYSYMBOL_block_items_opt = 82,           /* block_items_opt  */
  YYSYMBOL_block_items = 83,               /* block_items  */
  YYSYMBOL_block_item = 84,                /* block_item  */
  YYSYMBOL_statement = 85,                 /* statement  */
  YYSYMBOL_simple_stmt = 86,               /* simple_stmt  */
  YYSYMBOL_assign_stmt = 87,               /* assign_stmt  */
  YYSYMBOL_lvalue = 88,                    /* lvalue  */
  YYSYMBOL_if_stmt = 89,                   /* if_stmt  */
  YYSYMBOL_loop_stmt = 90,                 /* loop_stmt  */
  YYSYMBOL_for_simple_opt = 91,            /* for_simple_opt  */
  YYSYMBOL_for_simple_item = 92,           /* for_simple_item  */
  YYSYMBOL_assign_no_semi = 93,            /* assign_no_semi  */
  YYSYMBOL_return_stmt = 94,               /* return_stmt  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_const_lit = 96,                 /* const_lit  */
  YYSYMBOL_func_call = 97,                 /* func_call  */
  YYSYMBOL_proc_call = 98,                 /* proc_call  */
  YYSYMBOL_arg_list_opt = 99,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 100,                 /* arg_list  */
  YYSYMBOL_array_dims = 101,               /* array_dims  */
  YYSYMBOL_array_ref = 102,                /* array_ref  */
  YYSYMBOL_type_spec = 103                 /* type_spec  */
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
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,   112,   113,   118,   119,   120,   124,   125,
     131,   140,   140,   146,   150,   157,   158,   179,   201,   201,
     230,   230,   248,   251,   257,   262,   270,   274,   283,   283,
     291,   292,   296,   297,   301,   302,   306,   307,   308,   309,
     310,   311,   316,   317,   321,   325,   329,   333,   337,   341,
     350,   372,   381,   385,   393,   397,   401,   405,   415,   416,
     417,   421,   422,   426,   430,   434,   438,   445,   454,   462,
     476,   480,   484,   488,   493,   497,   501,   505,   510,   514,
     519,   523,   527,   532,   536,   541,   542,   543,   544,   549,
     553,   557,   561,   570,   581,   592,   593,   597,   602,   611,
     616,   625,   631,   641,   642,   643,   644,   645
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
  "\"end of file\"", "error", "\"invalid token\"", "BOOL_TOK",
  "FLOAT_TOK", "DOUBLE_TOK", "INT_TOK", "CHAR_TOK", "STRING_TOK",
  "VOID_TOK", "IF", "ELSE", "DO", "WHILE", "FOR", "FOREACH", "RETURN",
  "CONST", "PRINT", "PRINTLN", "READ", "TRUE", "FALSE", "ID", "INT_LIT",
  "REAL_LIT", "STRING_LIT", "BOOL_LIT", "LE", "GE", "EQ", "NEQ", "LT",
  "GT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ASSIGN", "NOT", "AND", "OR",
  "INC", "DEC", "DOT", "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "BREAK", "CONTINUE", "SWITCH",
  "CASE", "DEFAULT", "EXTERN", "IFX", "UPLUS", "UMINUS", "$accept",
  "program", "global_decl_list", "global_decl", "local_decl", "const_decl",
  "var_decl", "$@1", "var_init_list", "var_init", "func_decl", "$@2",
  "$@3", "param_list_opt", "param_list", "param", "block", "$@4",
  "block_items_opt", "block_items", "block_item", "statement",
  "simple_stmt", "assign_stmt", "lvalue", "if_stmt", "loop_stmt",
  "for_simple_opt", "for_simple_item", "assign_no_semi", "return_stmt",
  "expression", "const_lit", "func_call", "proc_call", "arg_list_opt",
  "arg_list", "array_dims", "array_ref", "type_spec", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -108,     6,   168,  -108,  -108,  -108,  -108,  -108,  -108,     0,
      25,  -108,  -108,  -108,  -108,    11,    22,    52,    32,    62,
      25,    50,    25,   -32,   -11,  -108,    48,    59,  -108,    85,
     -13,    61,   -13,   -13,    63,    62,  -108,    65,    25,    78,
       7,  -108,  -108,  -108,  -108,   -13,   -13,   -13,   -13,  -108,
     362,  -108,  -108,    79,   506,   112,   -13,  -108,  -108,  -108,
      63,   -13,   -13,    82,  -108,  -108,   535,   247,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,  -108,  -108,  -108,   172,    49,   506,    66,    91,   197,
     -13,  -108,   546,   546,   546,   546,   546,   546,    42,    42,
    -108,  -108,  -108,   535,   521,    49,  -108,    89,   107,    90,
     109,   110,   -13,   -13,   -13,   133,    43,  -108,  -108,  -108,
    -108,  -108,  -108,   111,    49,  -108,  -108,  -108,  -108,   -35,
    -108,  -108,  -108,   115,  -108,  -108,   -13,  -108,   222,   113,
     -13,   156,   -13,    68,   147,   383,   404,   425,   127,   131,
     -13,    49,  -108,  -108,   -13,   134,   135,  -108,   506,  -108,
    -108,   270,   132,   293,   -13,   -13,   133,   -19,    53,  -108,
    -108,   137,  -108,  -108,  -108,  -108,   136,   138,   446,  -108,
    -108,   107,   -13,   107,   506,   506,  -108,   -13,  -108,  -108,
      68,   -13,   -13,  -108,  -108,  -108,   176,   316,  -108,   506,
    -108,   467,   488,   107,   141,    68,   146,  -108,  -108,    27,
     -13,   107,   339,  -108,   107,  -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   106,   104,   105,   103,   107,     0,
       0,     4,     5,     6,     7,     0,     0,     0,     0,     0,
      22,     0,    22,    15,     0,    13,     0,    23,    24,     0,
       0,     0,     0,     0,    17,     0,    12,     0,     0,    26,
      50,    89,    90,    92,    91,     0,     0,     0,     0,    86,
       0,    87,    88,     0,    16,     0,     0,    14,    20,    25,
      27,    95,     0,    51,    84,    83,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    18,    99,     0,    30,    97,     0,    96,     0,
       0,    85,    75,    77,    78,    79,    74,    76,    69,    70,
      71,    72,    73,    80,    81,    30,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    48,    28,    34,
       8,     9,    41,     0,    31,    33,    35,    36,    42,     0,
      37,    38,    39,     0,    11,    93,     0,   101,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,    50,     0,
      95,    30,    21,    32,     0,     0,     0,    40,    98,   102,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      61,     0,    68,    43,    44,    45,     0,     0,     0,    46,
      47,     0,     0,     0,    62,    63,    64,     0,    65,    66,
       0,     0,     0,    94,    29,    49,    52,     0,    54,    67,
      60,     0,     0,     0,     0,    58,     0,    53,    55,     0,
       0,     0,     0,    56,     0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,  -108,   191,   192,  -108,  -108,   160,
    -108,  -108,  -108,   175,  -108,   173,  -108,  -108,  -100,  -108,
      74,  -107,  -108,  -108,   -15,  -108,  -108,    10,    26,  -108,
    -108,   -30,  -108,  -108,  -108,    67,  -108,   179,  -108,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    11,   119,   120,   121,    19,    24,    25,
      14,   105,    85,    26,    27,    28,   122,   151,   123,   124,
     125,   126,   127,   128,    49,   130,   131,   168,   169,   170,
     132,    86,    51,    52,   133,    87,    88,    34,    63,   134
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   141,    54,    55,   154,   139,     3,    32,   155,   156,
      40,    41,    42,    43,    44,    64,    65,    66,    67,    33,
     187,    45,    46,    16,   188,   189,    84,    47,     4,     5,
       6,     7,    89,     8,    18,    35,    48,    36,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   177,     4,     5,     6,     7,    61,     8,    62,   107,
     138,   108,   109,   110,   111,   112,    10,   113,   114,   115,
     129,    20,   116,   190,   196,    21,   198,   211,    76,    77,
      78,    22,   145,   146,   147,    23,   164,   165,   166,    30,
     129,   148,   150,   129,    62,    15,   207,   117,    37,   190,
     149,   191,   118,    17,   213,    38,   158,   215,    39,   129,
     161,    53,   163,    29,    56,    29,   135,   107,    58,   108,
     109,   110,   111,   112,   178,   113,   114,   115,   167,    33,
     116,    29,    82,    90,   184,   185,   129,   136,   140,   142,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   186,   197,    79,    80,   117,   148,   199,   143,   144,
     118,   201,   202,   157,    83,   152,   129,   160,   129,   162,
     171,     4,     5,     6,     7,   167,     8,     9,    62,   175,
     212,   182,   179,   180,   192,    10,   193,   203,   129,   208,
     167,   210,   194,    12,    13,    57,   129,    31,   153,   129,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    59,     0,    79,    80,   209,   200,   176,    60,     0,
       0,     0,     0,     0,   106,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,     0,     0,     0,     0,    91,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,     0,     0,     0,     0,
     181,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,   183,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,     0,     0,     0,     0,   204,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,   214,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,    79,    80,     0,     0,     0,     0,     0,
      81,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,     0,
       0,   172,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    80,     0,     0,     0,
       0,     0,   173,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,     0,     0,   174,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,     0,     0,   195,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,     0,     0,   205,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      80,     0,     0,   206,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,    79,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
      30,   108,    32,    33,    39,   105,     0,    39,    43,    44,
      23,    24,    25,    26,    27,    45,    46,    47,    48,    51,
      39,    34,    35,    23,    43,    44,    56,    40,     3,     4,
       5,     6,    62,     8,    23,    46,    49,    48,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   151,     3,     4,     5,     6,    49,     8,    51,    10,
      90,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      85,    49,    23,    46,   181,    23,   183,    50,    36,    37,
      38,    49,   112,   113,   114,    23,    18,    19,    20,    39,
     105,    23,    49,   108,    51,     2,   203,    48,    50,    46,
     115,    48,    53,    10,   211,    46,   136,   214,    23,   124,
     140,    50,   142,    20,    51,    22,    50,    10,    53,    12,
      13,    14,    15,    16,   154,    18,    19,    20,   143,    51,
      23,    38,    53,    51,   164,   165,   151,    46,    49,    49,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   166,   182,    41,    42,    48,    23,   187,    49,    49,
      53,   191,   192,    48,    52,    54,   181,    54,   183,    13,
      23,     3,     4,     5,     6,   190,     8,     9,    51,    48,
     210,    49,    48,    48,    47,    17,    50,    11,   203,    48,
     205,    45,    54,     2,     2,    35,   211,    22,   124,   214,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    38,    -1,    41,    42,   205,   190,   150,    39,    -1,
      -1,    -1,    -1,    -1,    52,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    45,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,     3,     4,     5,     6,     8,     9,
      17,    67,    69,    70,    74,   103,    23,   103,    23,    71,
      49,    23,    49,    23,    72,    73,    77,    78,    79,   103,
      39,    77,    39,    51,   101,    46,    48,    50,    46,    23,
      23,    24,    25,    26,    27,    34,    35,    40,    49,    88,
      95,    96,    97,    50,    95,    95,    51,    73,    53,    79,
     101,    49,    51,   102,    95,    95,    95,    95,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    41,
      42,    48,    53,    52,    95,    76,    95,    99,   100,    95,
      51,    50,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    75,    52,    10,    12,    13,
      14,    15,    16,    18,    19,    20,    23,    48,    53,    68,
      69,    70,    80,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    94,    98,   103,    50,    46,    52,    95,    82,
      49,    85,    49,    49,    49,    95,    95,    95,    23,    88,
      49,    81,    54,    84,    39,    43,    44,    48,    95,    52,
      54,    95,    13,    95,    18,    19,    20,    88,    91,    92,
      93,    23,    48,    48,    48,    48,    99,    82,    95,    48,
      48,    50,    49,    50,    95,    95,    88,    39,    43,    44,
      46,    48,    47,    50,    54,    48,    85,    95,    85,    95,
      92,    95,    95,    11,    50,    48,    45,    85,    48,    91,
      45,    50,    95,    85,    50,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    71,    70,    72,    72,    73,    73,    73,    75,    74,
      76,    74,    77,    77,    78,    78,    79,    79,    81,    80,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    87,
      88,    88,    89,    89,    90,    90,    90,    90,    91,    91,
      91,    92,    92,    92,    92,    92,    92,    93,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    97,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       6,     0,     4,     1,     3,     1,     3,     2,     0,     9,
       0,     9,     0,     1,     1,     3,     2,     3,     0,     4,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     3,     3,     3,     3,     1,     4,
       1,     2,     5,     7,     5,     7,     9,    10,     0,     1,
       3,     1,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     0,     1,     1,     3,     3,
       4,     3,     4,     1,     1,     1,     1,     1
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
  case 2: /* program: global_decl_list  */
#line 92 "src/p2_parser.y"
                       {
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
#line 1419 "src/y.tab.cpp"
    break;

  case 10: /* const_decl: CONST type_spec ID ASSIGN expression SEMICOLON  */
#line 131 "src/p2_parser.y"
                                                   {
        std::string id = *(yyvsp[-3].sval); delete (yyvsp[-3].sval);
        ExprInfo value = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        tryDeclareConstant(ctx->symTab, id, (yyvsp[-4].type), value, yylineno);
    }
#line 1429 "src/y.tab.cpp"
    break;

  case 11: /* $@1: %empty  */
#line 140 "src/p2_parser.y"
                {
        ctx->nowType = (yyvsp[0].type);
    }
#line 1437 "src/y.tab.cpp"
    break;

  case 13: /* var_init_list: var_init  */
#line 146 "src/p2_parser.y"
              {
        VarInit varInit = *(yyvsp[0].var_init); delete (yyvsp[0].var_init);
        tryDeclareVarable(ctx->symTab, ctx->typePool, varInit, ctx->nowType, yylineno);
    }
#line 1446 "src/y.tab.cpp"
    break;

  case 14: /* var_init_list: var_init_list COMMA var_init  */
#line 150 "src/p2_parser.y"
                                   {
        VarInit varInit = *(yyvsp[0].var_init); delete (yyvsp[0].var_init);
        tryDeclareVarable(ctx->symTab, ctx->typePool, varInit, ctx->nowType, yylineno);
    }
#line 1455 "src/y.tab.cpp"
    break;

  case 15: /* var_init: ID  */
#line 157 "src/p2_parser.y"
                             { (yyval.var_init) = new VarInit(*(yyvsp[0].sval)); delete (yyvsp[0].sval); }
#line 1461 "src/y.tab.cpp"
    break;

  case 16: /* var_init: ID ASSIGN expression  */
#line 158 "src/p2_parser.y"
                             {
        std::string id = *(yyvsp[-2].sval); delete (yyvsp[-2].sval);
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);

        if (!expr.isValid) {
            (yyval.var_init) = makeInvalidVar();
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
            (yyval.var_init) = new VarInit(id, expr.type);
        }
    }
#line 1487 "src/y.tab.cpp"
    break;

  case 17: /* var_init: ID array_dims  */
#line 179 "src/p2_parser.y"
                             { 
        std::string id = *(yyvsp[-1].sval); delete (yyvsp[-1].sval);
        std::vector<int> arrayIndex = *(yyvsp[0].int_list); delete (yyvsp[0].int_list);

        bool isValid = true;
        for (auto& index : arrayIndex) {
            if (index <= 0) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            (yyval.var_init) = makeInvalidVar();
        }else{
            (yyval.var_init) = new VarInit(id, arrayIndex);
        }
    }
#line 1510 "src/y.tab.cpp"
    break;

  case 18: /* $@2: %empty  */
#line 201 "src/p2_parser.y"
                                                       {
        ctx->returnsExpr.clear();

        std::string funcName = *(yyvsp[-4].sval); delete (yyvsp[-4].sval);
        std::vector<Symbol> paramList = *(yyvsp[-2].symbol_list); delete (yyvsp[-2].symbol_list);

        if (funcName == "main") {
            SemanticError("main function should be void", yylineno);
        }

        declareFunction(funcName, (yyvsp[-5].type), paramList, ctx->typePool, ctx->symTab, yylineno);
    }
#line 1527 "src/y.tab.cpp"
    break;

  case 19: /* func_decl: type_spec ID LPAREN param_list_opt RPAREN LBRACE $@2 block_items_opt RBRACE  */
#line 212 "src/p2_parser.y"
                             {
        if (ctx->returnsExpr.empty()) {
            SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : ctx->returnsExpr) {
            if (!(yyvsp[-8].type)->isCompatibleWith(*expr.first.type)) {
                SemanticError("return type mismatch !", expr.second);
            }

            if (isConvertible((yyvsp[-8].type)->base, expr.first.type->base)) {
                printf("Warning: implicit conversion from %s to %s @ line %d\n",
                    baseKindToStr((yyvsp[-8].type)->base).c_str(), baseKindToStr(expr.first.type->base).c_str(), expr.second);
            }
        }

        ctx->symTab.leaveScope();
    }
#line 1550 "src/y.tab.cpp"
    break;

  case 20: /* $@3: %empty  */
#line 230 "src/p2_parser.y"
                                                      {
        ctx->returnsExpr.clear();

        std::string funcName = *(yyvsp[-4].sval); delete (yyvsp[-4].sval);
        std::vector<Symbol> paramList = *(yyvsp[-2].symbol_list); delete (yyvsp[-2].symbol_list);

        declareFunction(funcName, ctx->typePool.make(BK_Void), paramList, ctx->typePool, ctx->symTab, yylineno);
    }
#line 1563 "src/y.tab.cpp"
    break;

  case 21: /* func_decl: VOID_TOK ID LPAREN param_list_opt RPAREN LBRACE $@3 block_items_opt RBRACE  */
#line 237 "src/p2_parser.y"
                             {
        if (!ctx->returnsExpr.empty()) {
            SemanticError("void function should not return value", yylineno);
        }

        ctx->symTab.leaveScope();
    }
#line 1575 "src/y.tab.cpp"
    break;

  case 22: /* param_list_opt: %empty  */
#line 248 "src/p2_parser.y"
                {
        (yyval.symbol_list) = new std::vector<Symbol>();
    }
#line 1583 "src/y.tab.cpp"
    break;

  case 23: /* param_list_opt: param_list  */
#line 251 "src/p2_parser.y"
                 {
        (yyval.symbol_list) = (yyvsp[0].symbol_list);
    }
#line 1591 "src/y.tab.cpp"
    break;

  case 24: /* param_list: param  */
#line 257 "src/p2_parser.y"
            {
        (yyval.symbol_list) = new std::vector<Symbol>;
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1601 "src/y.tab.cpp"
    break;

  case 25: /* param_list: param_list COMMA param  */
#line 262 "src/p2_parser.y"
                             {
        (yyval.symbol_list) = (yyvsp[-2].symbol_list);
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1611 "src/y.tab.cpp"
    break;

  case 26: /* param: type_spec ID  */
#line 270 "src/p2_parser.y"
                   {
        std::string id = *(yyvsp[0].sval); delete (yyvsp[0].sval);
        (yyval.symbol) = new Symbol(id, (yyvsp[-1].type), false);
    }
#line 1620 "src/y.tab.cpp"
    break;

  case 27: /* param: type_spec ID array_dims  */
#line 274 "src/p2_parser.y"
                             {
        std::string id = *(yyvsp[-1].sval); delete (yyvsp[-1].sval);
        std::vector<int> arrayIndex = *(yyvsp[0].int_list); delete (yyvsp[0].int_list);
        (yyval.symbol) = new Symbol(id, ctx->typePool.makeArray((yyvsp[-2].type), arrayIndex), false);
    }
#line 1630 "src/y.tab.cpp"
    break;

  case 28: /* $@4: %empty  */
#line 283 "src/p2_parser.y"
             {
        ctx->symTab.enterScope();
    }
#line 1638 "src/y.tab.cpp"
    break;

  case 29: /* block: LBRACE $@4 block_items_opt RBRACE  */
#line 285 "src/p2_parser.y"
                             {
        ctx->symTab.leaveScope();
    }
#line 1646 "src/y.tab.cpp"
    break;

  case 43: /* simple_stmt: PRINT expression SEMICOLON  */
#line 317 "src/p2_parser.y"
                                 {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        checkPrint(expr, yylineno);
    }
#line 1655 "src/y.tab.cpp"
    break;

  case 44: /* simple_stmt: PRINTLN expression SEMICOLON  */
#line 321 "src/p2_parser.y"
                                   {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        checkPrint(expr, yylineno);
    }
#line 1664 "src/y.tab.cpp"
    break;

  case 45: /* simple_stmt: READ lvalue SEMICOLON  */
#line 325 "src/p2_parser.y"
                            {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        checkRead(expr, yylineno);
    }
#line 1673 "src/y.tab.cpp"
    break;

  case 46: /* simple_stmt: lvalue INC SEMICOLON  */
#line 329 "src/p2_parser.y"
                           {
        ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        checkIncDecValid("increment", expr, yylineno);
     }
#line 1682 "src/y.tab.cpp"
    break;

  case 47: /* simple_stmt: lvalue DEC SEMICOLON  */
#line 333 "src/p2_parser.y"
                           {
        ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        checkIncDecValid("decrement", expr, yylineno);
    }
#line 1691 "src/y.tab.cpp"
    break;

  case 49: /* assign_stmt: lvalue ASSIGN expression SEMICOLON  */
#line 341 "src/p2_parser.y"
                                         {
        ExprInfo target = *(yyvsp[-3].expr_info); delete (yyvsp[-3].expr_info);
        ExprInfo value = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        checkAssignment(target, value, yylineno);
    }
#line 1701 "src/y.tab.cpp"
    break;

  case 50: /* lvalue: ID  */
#line 350 "src/p2_parser.y"
         {
        std::string id = *(yyvsp[0].sval); delete (yyvsp[0].sval);
        Symbol* symbol = ctx->symTab.lookup(id);

        if (symbol == nullptr) {
            SemanticError("undeclared identifier: " + id, yylineno);
            (yyval.expr_info) = makeInvalidExpr();
        } else {
            (yyval.expr_info) = new ExprInfo(symbol->type, symbol->isConst);

            if (symbol->hasConstValue()) {
                switch (symbol->type->base) {
                    case BK_Int:   (yyval.expr_info)->setInt(symbol->iVal); break;
                    case BK_Float: (yyval.expr_info)->setFloat(symbol->fVal); break;
                    case BK_Double: (yyval.expr_info)->setFloat(symbol->dVal); break;
                    case BK_Bool:  (yyval.expr_info)->setBool(symbol->bVal); break;
                    case BK_String: (yyval.expr_info)->setString(symbol->sVal); break;
                    default: break;
                }
            }
        }
    }
#line 1728 "src/y.tab.cpp"
    break;

  case 51: /* lvalue: ID array_ref  */
#line 372 "src/p2_parser.y"
                   {
        std::string id = *(yyvsp[-1].sval); delete (yyvsp[-1].sval);
        std::vector<int> arrayIndex = *(yyvsp[0].int_list); delete (yyvsp[0].int_list);
        (yyval.expr_info) = resolveArrayAccess(id, ctx->typePool, ctx->symTab, arrayIndex, yylineno);
    }
#line 1738 "src/y.tab.cpp"
    break;

  case 52: /* if_stmt: IF LPAREN expression RPAREN statement  */
#line 381 "src/p2_parser.y"
                                                      {
        ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        checkBoolExpr("if", expr, yylineno);
    }
#line 1747 "src/y.tab.cpp"
    break;

  case 53: /* if_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 385 "src/p2_parser.y"
                                                           {
        ExprInfo expr = *(yyvsp[-4].expr_info); delete (yyvsp[-4].expr_info);
        checkBoolExpr("if", expr, yylineno);
    }
#line 1756 "src/y.tab.cpp"
    break;

  case 54: /* loop_stmt: WHILE LPAREN expression RPAREN statement  */
#line 393 "src/p2_parser.y"
                                              { 
        ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        checkBoolExpr("while", expr, yylineno); 
    }
#line 1765 "src/y.tab.cpp"
    break;

  case 55: /* loop_stmt: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 397 "src/p2_parser.y"
                                                            {
        ExprInfo expr = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        checkBoolExpr("do while", expr, yylineno);
    }
#line 1774 "src/y.tab.cpp"
    break;

  case 56: /* loop_stmt: FOR LPAREN for_simple_opt SEMICOLON expression SEMICOLON for_simple_opt RPAREN statement  */
#line 401 "src/p2_parser.y"
                                                                                              {
        ExprInfo expr = *(yyvsp[-4].expr_info); delete (yyvsp[-4].expr_info);
        checkBoolExpr("for", expr, yylineno);
    }
#line 1783 "src/y.tab.cpp"
    break;

  case 57: /* loop_stmt: FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement  */
#line 405 "src/p2_parser.y"
                                                                            {
        ExprInfo from = *(yyvsp[-5].expr_info); ExprInfo to = *(yyvsp[-2].expr_info); delete (yyvsp[-5].expr_info); delete (yyvsp[-2].expr_info);
        std::string id = *(yyvsp[-7].sval); delete (yyvsp[-7].sval);
        checkForeachRange(from, to, yylineno);
        checkForeachIndex(ctx->symTab.lookup(id), yylineno);
    }
#line 1794 "src/y.tab.cpp"
    break;

  case 62: /* for_simple_item: PRINT expression  */
#line 422 "src/p2_parser.y"
                         {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        checkPrint(expr, yylineno);
    }
#line 1803 "src/y.tab.cpp"
    break;

  case 63: /* for_simple_item: PRINTLN expression  */
#line 426 "src/p2_parser.y"
                          {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        checkPrint(expr, yylineno);
    }
#line 1812 "src/y.tab.cpp"
    break;

  case 64: /* for_simple_item: READ lvalue  */
#line 430 "src/p2_parser.y"
                   {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        checkRead(expr, yylineno);
    }
#line 1821 "src/y.tab.cpp"
    break;

  case 65: /* for_simple_item: lvalue INC  */
#line 434 "src/p2_parser.y"
                  {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        checkIncDecValid("increment", expr, yylineno);
     }
#line 1830 "src/y.tab.cpp"
    break;

  case 66: /* for_simple_item: lvalue DEC  */
#line 438 "src/p2_parser.y"
                  {
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        checkIncDecValid("decrement", expr, yylineno);
    }
#line 1839 "src/y.tab.cpp"
    break;

  case 67: /* assign_no_semi: lvalue ASSIGN expression  */
#line 445 "src/p2_parser.y"
                               {
        ExprInfo target = *(yyvsp[-2].expr_info); delete (yyvsp[-2].expr_info);
        ExprInfo value = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        checkAssignment(target, value, yylineno);
    }
#line 1849 "src/y.tab.cpp"
    break;

  case 68: /* return_stmt: RETURN expression SEMICOLON  */
#line 454 "src/p2_parser.y"
                                  {
        ctx->returnsExpr.push_back(std::make_pair(*(yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 1858 "src/y.tab.cpp"
    break;

  case 69: /* expression: expression PLUS expression  */
#line 462 "src/p2_parser.y"
                                 {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        if(!lhs.isValid || !rhs.isValid) {
            (yyval.expr_info) = makeInvalidExpr();
        }else {
            bool isStringConcat = (lhs.type->base == BK_String && rhs.type->base == BK_String);

            if (isStringConcat) {
                (yyval.expr_info) = concatStringResult(lhs, rhs, ctx->typePool, yylineno);
            } else {
                (yyval.expr_info) = numericOpResult(OPADD, lhs, rhs, ctx->typePool, yylineno);
            }
        }
    }
#line 1877 "src/y.tab.cpp"
    break;

  case 70: /* expression: expression MINUS expression  */
#line 476 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPSUB, lhs, rhs, ctx->typePool, yylineno);
    }
#line 1886 "src/y.tab.cpp"
    break;

  case 71: /* expression: expression MUL expression  */
#line 480 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPMUL, lhs, rhs, ctx->typePool, yylineno);
    }
#line 1895 "src/y.tab.cpp"
    break;

  case 72: /* expression: expression DIV expression  */
#line 484 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPDIV, lhs, rhs, ctx->typePool, yylineno);
    }
#line 1904 "src/y.tab.cpp"
    break;

  case 73: /* expression: expression MOD expression  */
#line 488 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPMOD, lhs, rhs, ctx->typePool, yylineno);
    }
#line 1913 "src/y.tab.cpp"
    break;

  case 74: /* expression: expression LT expression  */
#line 493 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPLT, lhs , rhs, ctx->typePool, yylineno);
    }
#line 1922 "src/y.tab.cpp"
    break;

  case 75: /* expression: expression LE expression  */
#line 497 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPLE, lhs , rhs, ctx->typePool, yylineno);
    }
#line 1931 "src/y.tab.cpp"
    break;

  case 76: /* expression: expression GT expression  */
#line 501 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPGT, lhs , rhs, ctx->typePool, yylineno);
    }
#line 1940 "src/y.tab.cpp"
    break;

  case 77: /* expression: expression GE expression  */
#line 505 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPGE, lhs , rhs, ctx->typePool, yylineno);
    }
#line 1949 "src/y.tab.cpp"
    break;

  case 78: /* expression: expression EQ expression  */
#line 510 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = eqOpResult(true, lhs, rhs, ctx->typePool, yylineno);
    }
#line 1958 "src/y.tab.cpp"
    break;

  case 79: /* expression: expression NEQ expression  */
#line 514 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = eqOpResult(false, lhs, rhs, ctx->typePool, yylineno);
    }
#line 1967 "src/y.tab.cpp"
    break;

  case 80: /* expression: expression AND expression  */
#line 519 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = boolOpResult(true, lhs , rhs, ctx->typePool, yylineno);
    }
#line 1976 "src/y.tab.cpp"
    break;

  case 81: /* expression: expression OR expression  */
#line 523 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = boolOpResult(false, lhs , rhs, ctx->typePool, yylineno);
    }
#line 1985 "src/y.tab.cpp"
    break;

  case 82: /* expression: NOT expression  */
#line 527 "src/p2_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = notOpResult(expr, ctx->typePool, yylineno);
    }
#line 1994 "src/y.tab.cpp"
    break;

  case 83: /* expression: MINUS expression  */
#line 532 "src/p2_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = unaryOpResult(true, expr, yylineno);
    }
#line 2003 "src/y.tab.cpp"
    break;

  case 84: /* expression: PLUS expression  */
#line 536 "src/p2_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = unaryOpResult(false, expr, yylineno);
    }
#line 2012 "src/y.tab.cpp"
    break;

  case 85: /* expression: LPAREN expression RPAREN  */
#line 541 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[-1].expr_info); }
#line 2018 "src/y.tab.cpp"
    break;

  case 86: /* expression: lvalue  */
#line 542 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2024 "src/y.tab.cpp"
    break;

  case 87: /* expression: const_lit  */
#line 543 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2030 "src/y.tab.cpp"
    break;

  case 88: /* expression: func_call  */
#line 544 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2036 "src/y.tab.cpp"
    break;

  case 89: /* const_lit: INT_LIT  */
#line 549 "src/p2_parser.y"
                  { 
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Int), true);
        (yyval.expr_info)->setInt((yyvsp[0].ival));
    }
#line 2045 "src/y.tab.cpp"
    break;

  case 90: /* const_lit: REAL_LIT  */
#line 553 "src/p2_parser.y"
                  {
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Double), true);
        (yyval.expr_info)->setFloat((yyvsp[0].fval));
    }
#line 2054 "src/y.tab.cpp"
    break;

  case 91: /* const_lit: BOOL_LIT  */
#line 557 "src/p2_parser.y"
                  {
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_Bool), true);
        (yyval.expr_info)->setBool((yyvsp[0].bval));
    }
#line 2063 "src/y.tab.cpp"
    break;

  case 92: /* const_lit: STRING_LIT  */
#line 561 "src/p2_parser.y"
                  { 
        (yyval.expr_info) = new ExprInfo(ctx->typePool.make(BK_String), true);
        (yyval.expr_info)->setString(*(yyvsp[0].sval));
        delete (yyvsp[0].sval);
    }
#line 2073 "src/y.tab.cpp"
    break;

  case 93: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 570 "src/p2_parser.y"
                                    {
        Symbol* symbol = ctx->symTab.lookup(*(yyvsp[-3].sval));
        std::string funcName = *(yyvsp[-3].sval);
        std::vector<ExprInfo> args = *(yyvsp[-1].expr_info_list);
        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].expr_info_list);
        checkFuncCall(symbol, funcName, args, yylineno);
        (yyval.expr_info) = new ExprInfo(symbol->type->ret);
    }
#line 2087 "src/y.tab.cpp"
    break;

  case 94: /* proc_call: ID LPAREN arg_list_opt RPAREN  */
#line 581 "src/p2_parser.y"
                                    {
        Symbol* symbol = ctx->symTab.lookup(*(yyvsp[-3].sval));
        std::string funcName = *(yyvsp[-3].sval);
        std::vector<ExprInfo> args = *(yyvsp[-1].expr_info_list);
        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].expr_info_list);
        checkFuncCall(symbol, funcName, args, yylineno);
    }
#line 2100 "src/y.tab.cpp"
    break;

  case 95: /* arg_list_opt: %empty  */
#line 592 "src/p2_parser.y"
                 { (yyval.expr_info_list) = new std::vector<ExprInfo>();}
#line 2106 "src/y.tab.cpp"
    break;

  case 96: /* arg_list_opt: arg_list  */
#line 593 "src/p2_parser.y"
               { (yyval.expr_info_list) = (yyvsp[0].expr_info_list); }
#line 2112 "src/y.tab.cpp"
    break;

  case 97: /* arg_list: expression  */
#line 597 "src/p2_parser.y"
                 {
        (yyval.expr_info_list) = new std::vector<ExprInfo>();
        (yyval.expr_info_list)->push_back(*(yyvsp[0].expr_info));
        delete (yyvsp[0].expr_info);
    }
#line 2122 "src/y.tab.cpp"
    break;

  case 98: /* arg_list: arg_list COMMA expression  */
#line 602 "src/p2_parser.y"
                               {
        (yyval.expr_info_list) = (yyvsp[-2].expr_info_list);
        (yyval.expr_info_list)->push_back(*(yyvsp[0].expr_info));
        delete (yyvsp[0].expr_info);
    }
#line 2132 "src/y.tab.cpp"
    break;

  case 99: /* array_dims: LBRACK expression RBRACK  */
#line 611 "src/p2_parser.y"
                               {
        (yyval.int_list) = new std::vector<int>;
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        (yyval.int_list)->push_back(checkArrayDimExpr(expr, yylineno));
    }
#line 2142 "src/y.tab.cpp"
    break;

  case 100: /* array_dims: array_dims LBRACK expression RBRACK  */
#line 616 "src/p2_parser.y"
                                          {
        (yyval.int_list) = (yyvsp[-3].int_list);
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        (yyval.int_list)->push_back(checkArrayDimExpr(expr, yylineno));
    }
#line 2152 "src/y.tab.cpp"
    break;

  case 101: /* array_ref: LBRACK expression RBRACK  */
#line 625 "src/p2_parser.y"
                               {
        (yyval.int_list) = new std::vector<int>;
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        (yyval.int_list)->push_back(extractArrayIndexOrZero(expr, yylineno));
        delete (yyvsp[-1].expr_info);
    }
#line 2163 "src/y.tab.cpp"
    break;

  case 102: /* array_ref: array_ref LBRACK expression RBRACK  */
#line 631 "src/p2_parser.y"
                                         {
        (yyval.int_list) = (yyvsp[-3].int_list);
        ExprInfo expr = *(yyvsp[-1].expr_info); delete (yyvsp[-1].expr_info);
        (yyval.int_list)->push_back(extractArrayIndexOrZero(expr, yylineno));
        delete (yyvsp[-1].expr_info);
    }
#line 2174 "src/y.tab.cpp"
    break;

  case 103: /* type_spec: INT_TOK  */
#line 641 "src/p2_parser.y"
                 { (yyval.type) = ctx->typePool.make(BK_Int);   }
#line 2180 "src/y.tab.cpp"
    break;

  case 104: /* type_spec: FLOAT_TOK  */
#line 642 "src/p2_parser.y"
                     { (yyval.type) = ctx->typePool.make(BK_Float); }
#line 2186 "src/y.tab.cpp"
    break;

  case 105: /* type_spec: DOUBLE_TOK  */
#line 643 "src/p2_parser.y"
                     { (yyval.type) = ctx->typePool.make(BK_Double); }
#line 2192 "src/y.tab.cpp"
    break;

  case 106: /* type_spec: BOOL_TOK  */
#line 644 "src/p2_parser.y"
                     { (yyval.type) = ctx->typePool.make(BK_Bool);  }
#line 2198 "src/y.tab.cpp"
    break;

  case 107: /* type_spec: STRING_TOK  */
#line 645 "src/p2_parser.y"
                 { (yyval.type) = ctx->typePool.make(BK_String);}
#line 2204 "src/y.tab.cpp"
    break;


#line 2208 "src/y.tab.cpp"

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

#line 648 "src/p2_parser.y"
 

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
        return 1;
    }

    return result;
}
