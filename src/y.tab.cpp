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

void yyerror(const char* s){
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}

#line 92 "src/y.tab.cpp"

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
  YYSYMBOL_var_init_list = 71,             /* var_init_list  */
  YYSYMBOL_var_init = 72,                  /* var_init  */
  YYSYMBOL_func_decl = 73,                 /* func_decl  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_75_2 = 75,                      /* $@2  */
  YYSYMBOL_param_list_opt = 76,            /* param_list_opt  */
  YYSYMBOL_param_list = 77,                /* param_list  */
  YYSYMBOL_param = 78,                     /* param  */
  YYSYMBOL_block = 79,                     /* block  */
  YYSYMBOL_80_3 = 80,                      /* $@3  */
  YYSYMBOL_block_items_opt = 81,           /* block_items_opt  */
  YYSYMBOL_block_items = 82,               /* block_items  */
  YYSYMBOL_block_item = 83,                /* block_item  */
  YYSYMBOL_statement = 84,                 /* statement  */
  YYSYMBOL_simple_stmt = 85,               /* simple_stmt  */
  YYSYMBOL_assign_stmt = 86,               /* assign_stmt  */
  YYSYMBOL_lvalue = 87,                    /* lvalue  */
  YYSYMBOL_if_stmt = 88,                   /* if_stmt  */
  YYSYMBOL_loop_stmt = 89,                 /* loop_stmt  */
  YYSYMBOL_for_simple_opt = 90,            /* for_simple_opt  */
  YYSYMBOL_for_simple_item = 91,           /* for_simple_item  */
  YYSYMBOL_assign_no_semi = 92,            /* assign_no_semi  */
  YYSYMBOL_return_stmt = 93,               /* return_stmt  */
  YYSYMBOL_expression = 94,                /* expression  */
  YYSYMBOL_const_lit = 95,                 /* const_lit  */
  YYSYMBOL_func_call = 96,                 /* func_call  */
  YYSYMBOL_proc_call = 97,                 /* proc_call  */
  YYSYMBOL_arg_list_opt = 98,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 99,                  /* arg_list  */
  YYSYMBOL_array_dims = 100,               /* array_dims  */
  YYSYMBOL_array_ref = 101,                /* array_ref  */
  YYSYMBOL_type_spec = 102                 /* type_spec  */
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
#define YYLAST   625

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
       0,    95,    95,   115,   116,   123,   124,   125,   130,   131,
     137,   170,   201,   206,   214,   215,   230,   235,   235,   265,
     265,   286,   289,   295,   300,   308,   312,   321,   321,   329,
     330,   334,   335,   339,   340,   344,   345,   346,   347,   348,
     349,   354,   355,   366,   376,   388,   391,   394,   398,   431,
     451,   491,   494,   502,   505,   508,   511,   518,   519,   520,
     525,   526,   536,   546,   558,   561,   567,   600,   608,   619,
     623,   627,   631,   636,   640,   644,   648,   653,   657,   662,
     666,   670,   675,   679,   684,   685,   686,   687,   692,   697,
     702,   708,   716,   727,   737,   738,   742,   747,   756,   761,
     769,   774,   783,   784,   785,   786,   787
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
  "var_decl", "var_init_list", "var_init", "func_decl", "$@1", "$@2",
  "param_list_opt", "param_list", "param", "block", "$@3",
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

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -107,     6,    82,  -107,  -107,  -107,  -107,  -107,  -107,   -22,
      97,  -107,  -107,  -107,  -107,    -9,   -25,    10,   -19,   -33,
    -107,    97,   -32,    35,    97,    35,   -13,    30,  -107,   -21,
      11,  -107,    33,    35,   -12,  -107,  -107,  -107,  -107,    35,
      35,    35,    35,  -107,   547,  -107,  -107,    17,   184,    35,
     -30,  -107,    15,    97,    21,   403,    35,    35,    47,  -107,
    -107,   576,   288,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    28,  -107,   213,  -107,
    -107,   -13,  -107,   547,    61,    66,   238,    35,  -107,   587,
     587,   587,   587,   587,   587,    72,    72,  -107,  -107,  -107,
     576,   562,  -107,  -107,   175,  -107,    35,  -107,   263,   175,
      64,   187,    67,    68,    70,    35,    35,    35,    92,    14,
    -107,  -107,  -107,  -107,  -107,  -107,    69,   175,  -107,  -107,
    -107,  -107,   -16,  -107,  -107,  -107,    73,    30,   547,  -107,
      71,    35,   109,    35,    59,   101,   424,   445,   466,    75,
      80,    35,   175,  -107,  -107,    35,    81,    83,  -107,  -107,
     311,    84,   334,    35,    35,    92,    -8,    49,  -107,  -107,
      87,  -107,  -107,  -107,  -107,    85,    76,   487,  -107,  -107,
     187,    35,   187,   547,   547,  -107,    35,  -107,  -107,    59,
      35,    35,  -107,  -107,  -107,   125,   357,  -107,   547,  -107,
     508,   529,   187,    89,    59,    93,  -107,  -107,   -42,    35,
     187,   380,  -107,   187,  -107
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   105,   103,   104,   102,   106,     0,
       0,     4,     5,     6,     7,     0,     0,     0,    14,     0,
      12,    21,     0,     0,    21,     0,    16,     0,    11,     0,
      22,    23,     0,     0,    49,    88,    89,    90,    91,     0,
       0,     0,     0,    85,    15,    86,    87,     0,     0,     0,
      14,    13,     0,     0,    25,     0,    94,     0,    50,    83,
      82,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,    19,
      24,    26,    10,    96,     0,    95,     0,     0,    84,    74,
      76,    77,    78,    73,    75,    68,    69,    70,    71,    72,
      79,    80,    17,    99,    29,    92,     0,   100,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      47,    27,    33,     8,     9,    40,     0,    30,    32,    34,
      35,    41,     0,    36,    37,    38,     0,     0,    97,   101,
       0,     0,     0,     0,    57,     0,     0,     0,     0,    49,
       0,    94,    29,    20,    31,     0,     0,     0,    39,    18,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    60,
       0,    67,    42,    43,    44,     0,     0,     0,    45,    46,
       0,     0,     0,    61,    62,    63,     0,    64,    65,     0,
       0,     0,    93,    28,    48,    51,     0,    53,    66,    59,
       0,     0,     0,     0,    57,     0,    52,    54,     0,     0,
       0,     0,    55,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,  -107,  -107,   137,   141,  -107,   118,  -107,
    -107,  -107,   122,  -107,    94,  -107,  -107,   -97,  -107,    22,
    -106,  -107,  -107,   -38,  -107,  -107,   -56,   -39,  -107,  -107,
     -23,  -107,  -107,  -107,     2,  -107,    98,  -107,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    11,   122,   123,   124,    19,    20,    14,
     109,   104,    29,    30,    31,   125,   152,   126,   127,   128,
     129,   130,   131,    43,   133,   134,   167,   168,   169,   135,
      83,    45,    46,   136,    84,    85,    26,    58,   137
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    16,    48,    15,   189,   142,     3,    33,   210,    23,
      55,    17,   140,    27,    18,    28,    59,    60,    61,    62,
      23,    25,    32,   155,    21,    32,    78,   156,   157,    52,
      24,   186,    25,    22,    86,   187,   188,    56,    49,    57,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    50,    32,   176,    54,    53,    34,    35,
      36,    37,    38,   151,   108,    57,   132,    76,    79,    39,
      40,   132,    25,   132,   195,    41,   197,   163,   164,   165,
     150,   102,   149,   138,    42,     4,     5,     6,     7,   132,
       8,     9,   146,   147,   148,   189,   206,   190,    87,    10,
       4,     5,     6,     7,   212,     8,   166,   214,    71,    72,
      73,   105,   106,   141,   132,   149,   143,   144,   160,   145,
     162,   158,   161,   153,   170,   159,    57,   185,   174,   178,
     193,   179,   177,   181,   191,   192,   202,   207,   209,    12,
     183,   184,   132,    13,   132,    51,    47,    80,   208,   154,
     199,   166,    81,   175,     0,     0,     0,     0,   196,     0,
       0,     0,     0,   198,   132,     0,   166,   200,   201,     0,
       0,     0,   132,     0,     0,   132,     0,     0,     4,     5,
       6,     7,     0,     8,     0,   110,   211,   111,   112,   113,
     114,   115,    10,   116,   117,   118,     0,   110,   119,   111,
     112,   113,   114,   115,     0,   116,   117,   118,     0,     0,
     119,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,   120,     0,    74,    75,     0,   121,     0,
       0,     0,     0,     0,     0,   120,    77,     0,     0,     0,
     121,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,    88,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
       0,   180,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,   182,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,     0,     0,     0,     0,   203,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,     0,     0,
     213,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,     0,
       0,    82,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,   171,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,     0,     0,   172,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,     0,     0,   173,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,     0,     0,   194,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,   204,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,   205,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      23,    23,    25,     2,    46,   111,     0,    39,    50,    39,
      33,    10,   109,    46,    23,    48,    39,    40,    41,    42,
      39,    51,    21,    39,    49,    24,    49,    43,    44,    50,
      49,    39,    51,    23,    57,    43,    44,    49,    51,    51,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    23,    53,   152,    23,    46,    23,    24,
      25,    26,    27,    49,    87,    51,   104,    50,    53,    34,
      35,   109,    51,   111,   180,    40,   182,    18,    19,    20,
     118,    53,    23,   106,    49,     3,     4,     5,     6,   127,
       8,     9,   115,   116,   117,    46,   202,    48,    51,    17,
       3,     4,     5,     6,   210,     8,   144,   213,    36,    37,
      38,    50,    46,    49,   152,    23,    49,    49,   141,    49,
     143,    48,    13,    54,    23,    54,    51,   165,    48,    48,
      54,    48,   155,    49,    47,    50,    11,    48,    45,     2,
     163,   164,   180,     2,   182,    27,    24,    53,   204,   127,
     189,   189,    54,   151,    -1,    -1,    -1,    -1,   181,    -1,
      -1,    -1,    -1,   186,   202,    -1,   204,   190,   191,    -1,
      -1,    -1,   210,    -1,    -1,   213,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    10,   209,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    10,    23,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    -1,    -1,
      23,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    48,    -1,    41,    42,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    52,    -1,    -1,    -1,
      53,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    28,    29,    30,    31,    32,    33,    34,    35,    36,
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
      42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    45,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,     3,     4,     5,     6,     8,     9,
      17,    67,    69,    70,    73,   102,    23,   102,    23,    71,
      72,    49,    23,    39,    49,    51,   100,    46,    48,    76,
      77,    78,   102,    39,    23,    24,    25,    26,    27,    34,
      35,    40,    49,    87,    94,    95,    96,    76,    94,    51,
      23,    72,    50,    46,    23,    94,    49,    51,   101,    94,
      94,    94,    94,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    41,    42,    50,    52,    94,    53,
      78,   100,    48,    94,    98,    99,    94,    51,    50,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    53,    52,    75,    50,    46,    52,    94,    74,
      10,    12,    13,    14,    15,    16,    18,    19,    20,    23,
      48,    53,    68,    69,    70,    79,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    93,    97,   102,    94,    52,
      81,    49,    84,    49,    49,    49,    94,    94,    94,    23,
      87,    49,    80,    54,    83,    39,    43,    44,    48,    54,
      94,    13,    94,    18,    19,    20,    87,    90,    91,    92,
      23,    48,    48,    48,    48,    98,    81,    94,    48,    48,
      50,    49,    50,    94,    94,    87,    39,    43,    44,    46,
      48,    47,    50,    54,    48,    84,    94,    84,    94,    91,
      94,    94,    11,    50,    48,    45,    84,    48,    90,    45,
      50,    94,    84,    50,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    70,    71,    71,    72,    72,    72,    74,    73,    75,
      73,    76,    76,    77,    77,    78,    78,    80,    79,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    90,    90,    90,
      91,    91,    91,    91,    91,    91,    92,    93,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       6,     3,     1,     3,     1,     3,     2,     0,     9,     0,
       9,     0,     1,     1,     3,     2,     3,     0,     4,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     3,     3,     3,     3,     1,     4,     1,
       2,     5,     7,     5,     7,     9,    10,     0,     1,     3,
       1,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     0,     1,     1,     3,     3,     4,
       3,     4,     1,     1,     1,     1,     1
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
#line 95 "src/p2_parser.y"
                       {
        Symbol* mainFunc = symTab.lookup("main");
        if (mainFunc == nullptr) {
            SemanticError("missing main function", yylineno);
        }

        if (!mainFunc->type->isFunc()) {
            SemanticError("main function must be function", yylineno);
        }

        if (mainFunc->type->ret->base != BK_Void) {
            SemanticError("main function must return void", yylineno);
        }

        symTab.leaveScope();
        printf("\n");
    }
#line 1427 "src/y.tab.cpp"
    break;

  case 10: /* const_decl: CONST type_spec ID ASSIGN expression SEMICOLON  */
#line 137 "src/p2_parser.y"
                                                   {
        if (!(yyvsp[-4].type)->isCompatibleWith(*(yyvsp[-1].expr_info)->type)) {
            SemanticError("const type mismatch", yylineno);
        }

        if (!(yyvsp[-1].expr_info)->isConst) {
            SemanticError("const expression must be const", yylineno);
        }

        Symbol s(*(yyvsp[-3].sval), (yyvsp[-4].type), true);
        s.setConstValueFromExpr((yyvsp[-1].expr_info));

        Symbol* exist = symTab.lookupGlobal(s.name);
        if (exist && exist->type->isFunc()) {
            SemanticError("const '" + s.name + "' conflicts with function", yylineno);
        }

        if (!symTab.insert(s)) {
            SemanticError("redeclared const: " + *(yyvsp[-3].sval), yylineno);
        }

        if (isConvertible((yyvsp[-4].type)->base, (yyvsp[-1].expr_info)->type->base)) {
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
                baseKindToStr((yyvsp[-4].type)->base).c_str(), baseKindToStr((yyvsp[-1].expr_info)->type->base).c_str(), yylineno);
        }

        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].expr_info);
    }
#line 1461 "src/y.tab.cpp"
    break;

  case 11: /* var_decl: type_spec var_init_list SEMICOLON  */
#line 170 "src/p2_parser.y"
                                        {
        for (auto& var : *(yyvsp[-1].var_init_list)) {
            Symbol s("", nullptr, false);

            if (var.constType != nullptr) {
                if (!(yyvsp[-2].type)->isCompatibleWith(*var.constType)) {
                    SemanticError("var type mismatch", yylineno);
                }

                if(isConvertible((yyvsp[-2].type)->base, var.constType->base)) {
                    printf("Warning: implicit conversion from %s to %s @ line %d\n",
                        baseKindToStr((yyvsp[-2].type)->base).c_str(), baseKindToStr(var.constType->base).c_str(), yylineno);
                }
                s = Symbol(var.name, (yyvsp[-2].type), false);
            } 
            else if (!var.arrayDims.empty()) {
                Type* arrType = typePool.makeArray((yyvsp[-2].type), var.arrayDims);
                s = Symbol(var.name, arrType, false);
            } 
            else {
                s = Symbol(var.name, (yyvsp[-2].type), false);
            }


            tryInsertVar(symTab, s, yylineno);
        }
        delete (yyvsp[-1].var_init_list);
    }
#line 1494 "src/y.tab.cpp"
    break;

  case 12: /* var_init_list: var_init  */
#line 201 "src/p2_parser.y"
              {
        (yyval.var_init_list) = new std::vector<VarInit>;
        (yyval.var_init_list)->push_back(*(yyvsp[0].var_init));
        delete (yyvsp[0].var_init);
    }
#line 1504 "src/y.tab.cpp"
    break;

  case 13: /* var_init_list: var_init_list COMMA var_init  */
#line 206 "src/p2_parser.y"
                                   {
        (yyval.var_init_list) = (yyvsp[-2].var_init_list);
        (yyval.var_init_list)->push_back(*(yyvsp[0].var_init));
        delete (yyvsp[0].var_init);
    }
#line 1514 "src/y.tab.cpp"
    break;

  case 14: /* var_init: ID  */
#line 214 "src/p2_parser.y"
                             { (yyval.var_init) = new VarInit(*(yyvsp[0].sval)); delete (yyvsp[0].sval); }
#line 1520 "src/y.tab.cpp"
    break;

  case 15: /* var_init: ID ASSIGN expression  */
#line 215 "src/p2_parser.y"
                             {
        if ((yyvsp[0].expr_info)->type->isFunc()) {
            delete (yyvsp[0].expr_info);
            delete (yyvsp[-2].sval);
            SemanticError("assignment from function", yylineno);
        }

        if ((yyvsp[0].expr_info)->type->isArray()) {
            delete (yyvsp[0].expr_info);
            delete (yyvsp[-2].sval);
            SemanticError("assignment from array", yylineno);
        }

        (yyval.var_init) = new VarInit(*(yyvsp[-2].sval), (yyvsp[0].expr_info)->type);
    }
#line 1540 "src/y.tab.cpp"
    break;

  case 16: /* var_init: ID array_dims  */
#line 230 "src/p2_parser.y"
                             { (yyval.var_init) = new VarInit(*(yyvsp[-1].sval), *(yyvsp[0].int_list)); delete (yyvsp[-1].sval); delete (yyvsp[0].int_list); }
#line 1546 "src/y.tab.cpp"
    break;

  case 17: /* $@1: %empty  */
#line 235 "src/p2_parser.y"
                                                       {
        returnsExpr.clear();

        std::string funcName = *(yyvsp[-4].sval);
        std::vector<Symbol> paramList = *(yyvsp[-2].symbol_list);
        delete (yyvsp[-4].sval);
        delete (yyvsp[-2].symbol_list);
        
        if (funcName == "main") {
            SemanticError("main function should be void", yylineno);
        }

        declareFunction(funcName, (yyvsp[-5].type), paramList, typePool, symTab, yylineno);
    }
#line 1565 "src/y.tab.cpp"
    break;

  case 18: /* func_decl: type_spec ID LPAREN param_list_opt RPAREN LBRACE $@1 block_items_opt RBRACE  */
#line 248 "src/p2_parser.y"
                             {
        if (returnsExpr.empty()) {
            SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : returnsExpr) {
            if (!(yyvsp[-8].type)->isCompatibleWith(*expr.first.type)) {
                SemanticError("return type mismatch !", expr.second);
            }

            if (isConvertible((yyvsp[-8].type)->base, expr.first.type->base)) {
                printf("Warning: implicit conversion from %s to %s @ line %d\n",
                    baseKindToStr((yyvsp[-8].type)->base).c_str(), baseKindToStr(expr.first.type->base).c_str(), expr.second);
            }
        }
        symTab.leaveScope();
    }
#line 1587 "src/y.tab.cpp"
    break;

  case 19: /* $@2: %empty  */
#line 265 "src/p2_parser.y"
                                                      {
        Type* voidType = typePool.make(BK_Void);
        returnsExpr.clear();

        std::string funcName = *(yyvsp[-4].sval);
        std::vector<Symbol> paramList = *(yyvsp[-2].symbol_list);
        delete (yyvsp[-4].sval);
        delete (yyvsp[-2].symbol_list);

        declareFunction(funcName, voidType, paramList, typePool, symTab, yylineno);
    }
#line 1603 "src/y.tab.cpp"
    break;

  case 20: /* func_decl: VOID_TOK ID LPAREN param_list_opt RPAREN LBRACE $@2 block_items_opt RBRACE  */
#line 275 "src/p2_parser.y"
                             {
        if (!returnsExpr.empty()) {
            SemanticError("void function should not return value", yylineno);
        }

        symTab.leaveScope();
    }
#line 1615 "src/y.tab.cpp"
    break;

  case 21: /* param_list_opt: %empty  */
#line 286 "src/p2_parser.y"
                {
        (yyval.symbol_list) = new std::vector<Symbol>();
    }
#line 1623 "src/y.tab.cpp"
    break;

  case 22: /* param_list_opt: param_list  */
#line 289 "src/p2_parser.y"
                 {
        (yyval.symbol_list) = (yyvsp[0].symbol_list);
    }
#line 1631 "src/y.tab.cpp"
    break;

  case 23: /* param_list: param  */
#line 295 "src/p2_parser.y"
            {
        (yyval.symbol_list) = new std::vector<Symbol>;
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1641 "src/y.tab.cpp"
    break;

  case 24: /* param_list: param_list COMMA param  */
#line 300 "src/p2_parser.y"
                             {
        (yyval.symbol_list) = (yyvsp[-2].symbol_list);
        (yyval.symbol_list)->push_back(*(yyvsp[0].symbol));
        delete (yyvsp[0].symbol);
    }
#line 1651 "src/y.tab.cpp"
    break;

  case 25: /* param: type_spec ID  */
#line 308 "src/p2_parser.y"
                   {
        (yyval.symbol) = new Symbol(*(yyvsp[0].sval), (yyvsp[-1].type), false);
        delete (yyvsp[0].sval);
    }
#line 1660 "src/y.tab.cpp"
    break;

  case 26: /* param: type_spec ID array_dims  */
#line 312 "src/p2_parser.y"
                             {
        (yyval.symbol) = new Symbol(*(yyvsp[-1].sval), typePool.makeArray((yyvsp[-2].type), *(yyvsp[0].int_list)), false);
        delete (yyvsp[-1].sval);
        delete (yyvsp[0].int_list);
    }
#line 1670 "src/y.tab.cpp"
    break;

  case 27: /* $@3: %empty  */
#line 321 "src/p2_parser.y"
             {
        symTab.enterScope();
    }
#line 1678 "src/y.tab.cpp"
    break;

  case 28: /* block: LBRACE $@3 block_items_opt RBRACE  */
#line 323 "src/p2_parser.y"
                            {
        symTab.leaveScope();
    }
#line 1686 "src/y.tab.cpp"
    break;

  case 42: /* simple_stmt: PRINT expression SEMICOLON  */
#line 355 "src/p2_parser.y"
                                  {
        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            SemanticError("print from function", yylineno);
        }

        if ((yyvsp[-1].expr_info)->type->isArray()) {
            SemanticError("print from array", yylineno);
        }

        delete (yyvsp[-1].expr_info);
    }
#line 1702 "src/y.tab.cpp"
    break;

  case 43: /* simple_stmt: PRINTLN expression SEMICOLON  */
#line 366 "src/p2_parser.y"
                                   {
        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            SemanticError("print from function", yylineno);
        }
        if ((yyvsp[-1].expr_info)->type->isArray()) {
            SemanticError("print from array", yylineno);
        }

        delete (yyvsp[-1].expr_info);
    }
#line 1717 "src/y.tab.cpp"
    break;

  case 44: /* simple_stmt: READ lvalue SEMICOLON  */
#line 376 "src/p2_parser.y"
                            {
        if ((yyvsp[-1].expr_info)->isConst) {
            SemanticError("read to const", yylineno);
        }

        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            SemanticError("read to function", yylineno);
        }
        if ((yyvsp[-1].expr_info)->type->isArray()) {
            SemanticError("read to array", yylineno);
        }
    }
#line 1734 "src/y.tab.cpp"
    break;

  case 45: /* simple_stmt: lvalue INC SEMICOLON  */
#line 388 "src/p2_parser.y"
                           {
        checkIncDecValid((yyvsp[-2].expr_info), "increment", yylineno);
    }
#line 1742 "src/y.tab.cpp"
    break;

  case 46: /* simple_stmt: lvalue DEC SEMICOLON  */
#line 391 "src/p2_parser.y"
                           {
        checkIncDecValid((yyvsp[-2].expr_info), "decrement", yylineno);
    }
#line 1750 "src/y.tab.cpp"
    break;

  case 48: /* assign_stmt: lvalue ASSIGN expression SEMICOLON  */
#line 398 "src/p2_parser.y"
                                         {
        if ((yyvsp[-3].expr_info)->isConst) {
            SemanticError("assignment to const", yylineno);
        }

        if ((yyvsp[-3].expr_info)->type->isFunc()) {
            SemanticError("assignment to function", yylineno);
        }
        if ((yyvsp[-3].expr_info)->type->isArray()) {
            SemanticError("assignment to array", yylineno);
        }

        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            SemanticError("assignment from function", yylineno);
        }
        if ((yyvsp[-1].expr_info)->type->isArray()) {
            SemanticError("assignment from array", yylineno);
        }

        if (!isBaseCompatible((yyvsp[-3].expr_info)->type->base, (yyvsp[-1].expr_info)->type->base) ) {
                SemanticError("assignment type mismatch", yylineno);
        }

        if (isConvertible((yyvsp[-3].expr_info)->type->base, (yyvsp[-1].expr_info)->type->base)){
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr((yyvsp[-1].expr_info)->type->base).c_str(), baseKindToStr((yyvsp[-3].expr_info)->type->base).c_str(), yylineno);
        }

        delete (yyvsp[-1].expr_info);
    }
#line 1785 "src/y.tab.cpp"
    break;

  case 49: /* lvalue: ID  */
#line 431 "src/p2_parser.y"
         {
        Symbol* symbol = symTab.lookup(*(yyvsp[0].sval));
        if (symbol == nullptr) {
            SemanticError("undeclared identifier: " + *(yyvsp[0].sval), yylineno);
        }

        (yyval.expr_info) = new ExprInfo(symbol->type, symbol->isConst);

        if (symbol->hasConstValue()) {
            switch (symbol->type->base) {
                case BK_Int:   (yyval.expr_info)->setInt(symbol->iVal); break;
                case BK_Float: (yyval.expr_info)->setFloat(symbol->fVal); break;
                case BK_Bool:  (yyval.expr_info)->setBool(symbol->bVal); break;
                case BK_String: (yyval.expr_info)->setString(symbol->sVal); break;
                default: break;
            }
        }

        delete (yyvsp[0].sval);
    }
#line 1810 "src/y.tab.cpp"
    break;

  case 50: /* lvalue: ID array_ref  */
#line 451 "src/p2_parser.y"
                   {
        Symbol* symbol = symTab.lookup(*(yyvsp[-1].sval));
        if (symbol == nullptr) {
            SemanticError("undeclared identifier: " + *(yyvsp[-1].sval), yylineno);
        }

        if (!symbol->type->isArray()) {
            SemanticError("array index to non-array type: " + *(yyvsp[-1].sval), yylineno);
        }

        size_t given = (yyvsp[0].int_list)->size();
        std::vector<int> dims = symbol->type->sizes;

        for (size_t i = 0; i < given; ++i) {
            int index = (*(yyvsp[0].int_list))[i];
            int defined = symbol->type->sizes[i];

            if (index != 0) { 
                if (index < 0 || index >= defined) {
                    SemanticError(
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

        (yyval.expr_info) = new ExprInfo(typePool.makeArray(typePool.make(symbol->type->base), dims), symbol->isConst);
        delete (yyvsp[0].int_list);
        delete (yyvsp[-1].sval);
    }
#line 1851 "src/y.tab.cpp"
    break;

  case 51: /* if_stmt: IF LPAREN expression RPAREN statement  */
#line 491 "src/p2_parser.y"
                                                      {
        checkBoolExpr((yyvsp[-2].expr_info), "if", yylineno);
    }
#line 1859 "src/y.tab.cpp"
    break;

  case 52: /* if_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 494 "src/p2_parser.y"
                                                           {
        checkBoolExpr((yyvsp[-4].expr_info), "if", yylineno);
    }
#line 1867 "src/y.tab.cpp"
    break;

  case 53: /* loop_stmt: WHILE LPAREN expression RPAREN statement  */
#line 502 "src/p2_parser.y"
                                              { 
        checkBoolExpr((yyvsp[-2].expr_info), "while", yylineno); 
    }
#line 1875 "src/y.tab.cpp"
    break;

  case 54: /* loop_stmt: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 505 "src/p2_parser.y"
                                                            {
        checkBoolExpr((yyvsp[-2].expr_info), "do while", yylineno);
    }
#line 1883 "src/y.tab.cpp"
    break;

  case 55: /* loop_stmt: FOR LPAREN for_simple_opt SEMICOLON expression SEMICOLON for_simple_opt RPAREN statement  */
#line 508 "src/p2_parser.y"
                                                                                              {
        checkBoolExpr((yyvsp[-4].expr_info), "for", yylineno);
    }
#line 1891 "src/y.tab.cpp"
    break;

  case 56: /* loop_stmt: FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement  */
#line 511 "src/p2_parser.y"
                                                                            {
        checkForeachRange((yyvsp[-5].expr_info), (yyvsp[-2].expr_info), yylineno);
        checkForeachIndex(symTab.lookup(*(yyvsp[-7].sval)), yylineno);
    }
#line 1900 "src/y.tab.cpp"
    break;

  case 61: /* for_simple_item: PRINT expression  */
#line 526 "src/p2_parser.y"
                         {
        if ((yyvsp[0].expr_info)->type->isFunc()) {
            SemanticError("print from function", yylineno);
        }
        if ((yyvsp[0].expr_info)->type->isArray()) {
            SemanticError("print from array", yylineno);
        }

        delete (yyvsp[0].expr_info);
    }
#line 1915 "src/y.tab.cpp"
    break;

  case 62: /* for_simple_item: PRINTLN expression  */
#line 536 "src/p2_parser.y"
                          {
        if ((yyvsp[0].expr_info)->type->isFunc()) {
            SemanticError("print from function", yylineno);
        }
        if ((yyvsp[0].expr_info)->type->isArray()) {
            SemanticError("print from array", yylineno);
        }

        delete (yyvsp[0].expr_info);
    }
#line 1930 "src/y.tab.cpp"
    break;

  case 63: /* for_simple_item: READ lvalue  */
#line 546 "src/p2_parser.y"
                   {
        if ((yyvsp[0].expr_info)->isConst) {
            SemanticError("read to const", yylineno);
        }

        if ((yyvsp[0].expr_info)->type->isFunc()) {
            SemanticError("read to function", yylineno);
        }
        if ((yyvsp[0].expr_info)->type->isArray()) {
            SemanticError("read to array", yylineno);
        }
    }
#line 1947 "src/y.tab.cpp"
    break;

  case 64: /* for_simple_item: lvalue INC  */
#line 558 "src/p2_parser.y"
                   {
        checkIncDecValid((yyvsp[-1].expr_info), "increment", yylineno);
     }
#line 1955 "src/y.tab.cpp"
    break;

  case 65: /* for_simple_item: lvalue DEC  */
#line 561 "src/p2_parser.y"
                   {
        checkIncDecValid((yyvsp[-1].expr_info), "decrement", yylineno);
    }
#line 1963 "src/y.tab.cpp"
    break;

  case 66: /* assign_no_semi: lvalue ASSIGN expression  */
#line 567 "src/p2_parser.y"
                               {
        if ((yyvsp[-2].expr_info)->isConst) {
            SemanticError("assignment to const", yylineno);
        }

        if ((yyvsp[-2].expr_info)->type->isFunc()) {
            SemanticError("assignment to function", yylineno);
        }
        if ((yyvsp[-2].expr_info)->type->isArray()) {
            SemanticError("assignment to array", yylineno);
        }

        if ((yyvsp[0].expr_info)->type->isFunc()) {
            SemanticError("assignment from function", yylineno);
        }
        if ((yyvsp[0].expr_info)->type->isArray()) {
            SemanticError("assignment from array", yylineno);
        }

        if (!isBaseCompatible((yyvsp[-2].expr_info)->type->base, (yyvsp[0].expr_info)->type->base) ) {
                SemanticError("assignment type mismatch", yylineno);
        }

        if (isConvertible((yyvsp[-2].expr_info)->type->base, (yyvsp[0].expr_info)->type->base)){
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr((yyvsp[-2].expr_info)->type->base).c_str(), baseKindToStr((yyvsp[0].expr_info)->type->base).c_str(), yylineno);
        }
    }
#line 1996 "src/y.tab.cpp"
    break;

  case 67: /* return_stmt: RETURN expression SEMICOLON  */
#line 600 "src/p2_parser.y"
                                  {
        returnsExpr.push_back(std::make_pair(*(yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 2005 "src/y.tab.cpp"
    break;

  case 68: /* expression: expression PLUS expression  */
#line 608 "src/p2_parser.y"
                                 {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);

        bool isStringConcat = (lhs.type->base == BK_String && rhs.type->base == BK_String);

        if (isStringConcat) {
            (yyval.expr_info) = concatStringResult(lhs, rhs, typePool, yylineno);
        } else {
            (yyval.expr_info) = numericOpResult(OPADD, lhs, rhs, typePool, yylineno);
        }
    }
#line 2021 "src/y.tab.cpp"
    break;

  case 69: /* expression: expression MINUS expression  */
#line 619 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPSUB, lhs, rhs, typePool, yylineno);
    }
#line 2030 "src/y.tab.cpp"
    break;

  case 70: /* expression: expression MUL expression  */
#line 623 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPMUL, lhs, rhs, typePool, yylineno);
    }
#line 2039 "src/y.tab.cpp"
    break;

  case 71: /* expression: expression DIV expression  */
#line 627 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPDIV, lhs, rhs, typePool, yylineno);
    }
#line 2048 "src/y.tab.cpp"
    break;

  case 72: /* expression: expression MOD expression  */
#line 631 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = numericOpResult(OPMOD, lhs, rhs, typePool, yylineno);
    }
#line 2057 "src/y.tab.cpp"
    break;

  case 73: /* expression: expression LT expression  */
#line 636 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPLT, lhs , rhs, typePool, yylineno);
    }
#line 2066 "src/y.tab.cpp"
    break;

  case 74: /* expression: expression LE expression  */
#line 640 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPLE, lhs , rhs, typePool, yylineno);
    }
#line 2075 "src/y.tab.cpp"
    break;

  case 75: /* expression: expression GT expression  */
#line 644 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPGT, lhs , rhs, typePool, yylineno);
    }
#line 2084 "src/y.tab.cpp"
    break;

  case 76: /* expression: expression GE expression  */
#line 648 "src/p2_parser.y"
                                    { 
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = relOpResult(OPGE, lhs , rhs, typePool, yylineno);
    }
#line 2093 "src/y.tab.cpp"
    break;

  case 77: /* expression: expression EQ expression  */
#line 653 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = eqOpResult(true, lhs, rhs, typePool, yylineno);
    }
#line 2102 "src/y.tab.cpp"
    break;

  case 78: /* expression: expression NEQ expression  */
#line 657 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = eqOpResult(false, lhs, rhs, typePool, yylineno);
    }
#line 2111 "src/y.tab.cpp"
    break;

  case 79: /* expression: expression AND expression  */
#line 662 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = boolOpResult(true, lhs , rhs, typePool, yylineno);
    }
#line 2120 "src/y.tab.cpp"
    break;

  case 80: /* expression: expression OR expression  */
#line 666 "src/p2_parser.y"
                                    {
        ExprInfo lhs = *(yyvsp[-2].expr_info); ExprInfo rhs = *(yyvsp[0].expr_info); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = boolOpResult(false, lhs , rhs, typePool, yylineno);
    }
#line 2129 "src/y.tab.cpp"
    break;

  case 81: /* expression: NOT expression  */
#line 670 "src/p2_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = notOpResult(expr, typePool, yylineno);
    }
#line 2138 "src/y.tab.cpp"
    break;

  case 82: /* expression: MINUS expression  */
#line 675 "src/p2_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = unaryOpResult(true, expr, yylineno);
    }
#line 2147 "src/y.tab.cpp"
    break;

  case 83: /* expression: PLUS expression  */
#line 679 "src/p2_parser.y"
                                    {
        ExprInfo expr = *(yyvsp[0].expr_info); delete (yyvsp[0].expr_info);
        (yyval.expr_info) = unaryOpResult(false, expr, yylineno);
    }
#line 2156 "src/y.tab.cpp"
    break;

  case 84: /* expression: LPAREN expression RPAREN  */
#line 684 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[-1].expr_info); }
#line 2162 "src/y.tab.cpp"
    break;

  case 85: /* expression: lvalue  */
#line 685 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2168 "src/y.tab.cpp"
    break;

  case 86: /* expression: const_lit  */
#line 686 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2174 "src/y.tab.cpp"
    break;

  case 87: /* expression: func_call  */
#line 687 "src/p2_parser.y"
                                     { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2180 "src/y.tab.cpp"
    break;

  case 88: /* const_lit: INT_LIT  */
#line 692 "src/p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Int), true);
        expr->setInt((yyvsp[0].ival));
        (yyval.expr_info) = expr;
    }
#line 2190 "src/y.tab.cpp"
    break;

  case 89: /* const_lit: REAL_LIT  */
#line 697 "src/p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Double), true);
        expr->setFloat((yyvsp[0].fval));
        (yyval.expr_info) = expr;
    }
#line 2200 "src/y.tab.cpp"
    break;

  case 90: /* const_lit: STRING_LIT  */
#line 702 "src/p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_String), true);
        expr->setString(*(yyvsp[0].sval));
        (yyval.expr_info) = expr;
        delete (yyvsp[0].sval);
    }
#line 2211 "src/y.tab.cpp"
    break;

  case 91: /* const_lit: BOOL_LIT  */
#line 708 "src/p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), true);
        expr->setBool((yyvsp[0].bval));
        (yyval.expr_info) = expr;
    }
#line 2221 "src/y.tab.cpp"
    break;

  case 92: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 716 "src/p2_parser.y"
                                    {
        Symbol* symbol = symTab.lookup(*(yyvsp[-3].sval));
        std::string funcName = *(yyvsp[-3].sval);
        std::vector<ExprInfo> args = *(yyvsp[-1].expr_info_list);
        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].expr_info_list);
        checkFuncCall(symbol, funcName, args, yylineno);
        (yyval.expr_info) = new ExprInfo(symbol->type->ret);
    }
#line 2235 "src/y.tab.cpp"
    break;

  case 93: /* proc_call: ID LPAREN arg_list_opt RPAREN  */
#line 727 "src/p2_parser.y"
                                    {
        Symbol* symbol = symTab.lookup(*(yyvsp[-3].sval));
        std::string funcName = *(yyvsp[-3].sval);
        std::vector<ExprInfo> args = *(yyvsp[-1].expr_info_list);
        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].expr_info_list);
        checkFuncCall(symbol, funcName, args, yylineno);
    }
#line 2248 "src/y.tab.cpp"
    break;

  case 94: /* arg_list_opt: %empty  */
#line 737 "src/p2_parser.y"
                 { (yyval.expr_info_list) = new std::vector<ExprInfo>();}
#line 2254 "src/y.tab.cpp"
    break;

  case 95: /* arg_list_opt: arg_list  */
#line 738 "src/p2_parser.y"
               { (yyval.expr_info_list) = (yyvsp[0].expr_info_list); }
#line 2260 "src/y.tab.cpp"
    break;

  case 96: /* arg_list: expression  */
#line 742 "src/p2_parser.y"
                 {
        (yyval.expr_info_list) = new std::vector<ExprInfo>();
        (yyval.expr_info_list)->push_back(*(yyvsp[0].expr_info));
        delete (yyvsp[0].expr_info);
    }
#line 2270 "src/y.tab.cpp"
    break;

  case 97: /* arg_list: arg_list COMMA expression  */
#line 747 "src/p2_parser.y"
                               {
        (yyval.expr_info_list) = (yyvsp[-2].expr_info_list);
        (yyval.expr_info_list)->push_back(*(yyvsp[0].expr_info));
        delete (yyvsp[0].expr_info);
    }
#line 2280 "src/y.tab.cpp"
    break;

  case 98: /* array_dims: LBRACK expression RBRACK  */
#line 756 "src/p2_parser.y"
                               {
        (yyval.int_list) = new std::vector<int>;
        (yyval.int_list)->push_back(checkArrayDimExpr((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
    }
#line 2290 "src/y.tab.cpp"
    break;

  case 99: /* array_dims: array_dims LBRACK expression RBRACK  */
#line 761 "src/p2_parser.y"
                                          {
        (yyval.int_list) = (yyvsp[-3].int_list);
        (yyval.int_list)->push_back(checkArrayDimExpr((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
    }
#line 2300 "src/y.tab.cpp"
    break;

  case 100: /* array_ref: LBRACK expression RBRACK  */
#line 769 "src/p2_parser.y"
                               {
        (yyval.int_list) = new std::vector<int>;
        (yyval.int_list)->push_back(extractArrayIndexOrZero((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
    }
#line 2310 "src/y.tab.cpp"
    break;

  case 101: /* array_ref: array_ref LBRACK expression RBRACK  */
#line 774 "src/p2_parser.y"
                                         {
        (yyval.int_list) = (yyvsp[-3].int_list);
        (yyval.int_list)->push_back(extractArrayIndexOrZero((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
    }
#line 2320 "src/y.tab.cpp"
    break;

  case 102: /* type_spec: INT_TOK  */
#line 783 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Int);   }
#line 2326 "src/y.tab.cpp"
    break;

  case 103: /* type_spec: FLOAT_TOK  */
#line 784 "src/p2_parser.y"
                     { (yyval.type) = typePool.make(BK_Float); }
#line 2332 "src/y.tab.cpp"
    break;

  case 104: /* type_spec: DOUBLE_TOK  */
#line 785 "src/p2_parser.y"
                     { (yyval.type) = typePool.make(BK_Double); }
#line 2338 "src/y.tab.cpp"
    break;

  case 105: /* type_spec: BOOL_TOK  */
#line 786 "src/p2_parser.y"
                     { (yyval.type) = typePool.make(BK_Bool);  }
#line 2344 "src/y.tab.cpp"
    break;

  case 106: /* type_spec: STRING_TOK  */
#line 787 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_String);}
#line 2350 "src/y.tab.cpp"
    break;


#line 2354 "src/y.tab.cpp"

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

#line 790 "src/p2_parser.y"
 

int main(int argc, char* argv[])
{   
    if (argc != 2) {
        std::puts("Usage: sd <source-file>");
        return 1;
    }
    if (!(yyin = std::fopen(argv[1], "r"))) { perror("open"); return 1; }

    int result = yyparse();

    if (SemanticError::hasError()) {
        SemanticError::printAll();
    }

    return result;
}
