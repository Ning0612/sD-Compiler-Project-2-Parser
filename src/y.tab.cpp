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

void yyerror(const char* s)
{
    std::fprintf(stderr, "Syntax error @ line %d: %s\n", yylineno, s);
    std::exit(1);
}

#line 93 "src/y.tab.cpp"

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
  YYSYMBOL_UPLUS = 61,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 62,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program = 64,                   /* program  */
  YYSYMBOL_global_decl_list = 65,          /* global_decl_list  */
  YYSYMBOL_global_decl = 66,               /* global_decl  */
  YYSYMBOL_local_decl = 67,                /* local_decl  */
  YYSYMBOL_const_decl = 68,                /* const_decl  */
  YYSYMBOL_var_decl = 69,                  /* var_decl  */
  YYSYMBOL_var_init_list = 70,             /* var_init_list  */
  YYSYMBOL_var_init = 71,                  /* var_init  */
  YYSYMBOL_func_decl = 72,                 /* func_decl  */
  YYSYMBOL_73_1 = 73,                      /* $@1  */
  YYSYMBOL_74_2 = 74,                      /* $@2  */
  YYSYMBOL_param_list_opt = 75,            /* param_list_opt  */
  YYSYMBOL_param_list = 76,                /* param_list  */
  YYSYMBOL_param = 77,                     /* param  */
  YYSYMBOL_block = 78,                     /* block  */
  YYSYMBOL_79_3 = 79,                      /* $@3  */
  YYSYMBOL_block_items_opt = 80,           /* block_items_opt  */
  YYSYMBOL_block_items = 81,               /* block_items  */
  YYSYMBOL_block_item = 82,                /* block_item  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_simple_stmt = 84,               /* simple_stmt  */
  YYSYMBOL_assign_stmt = 85,               /* assign_stmt  */
  YYSYMBOL_lvalue = 86,                    /* lvalue  */
  YYSYMBOL_if_stmt = 87,                   /* if_stmt  */
  YYSYMBOL_loop_stmt = 88,                 /* loop_stmt  */
  YYSYMBOL_for_start_opt = 89,             /* for_start_opt  */
  YYSYMBOL_for_update_opt = 90,            /* for_update_opt  */
  YYSYMBOL_assign_no_semi = 91,            /* assign_no_semi  */
  YYSYMBOL_return_stmt = 92,               /* return_stmt  */
  YYSYMBOL_expression = 93,                /* expression  */
  YYSYMBOL_const_lit = 94,                 /* const_lit  */
  YYSYMBOL_func_call = 95,                 /* func_call  */
  YYSYMBOL_proc_call = 96,                 /* proc_call  */
  YYSYMBOL_arg_list_opt = 97,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 98,                  /* arg_list  */
  YYSYMBOL_array_dims = 99,                /* array_dims  */
  YYSYMBOL_array_ref = 100,                /* array_ref  */
  YYSYMBOL_type_spec = 101                 /* type_spec  */
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
#define YYLAST   583

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

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
       0,    99,    99,   119,   120,   127,   128,   129,   134,   135,
     141,   175,   209,   212,   219,   220,   230,   235,   235,   261,
     261,   276,   279,   285,   289,   296,   300,   309,   309,   316,
     318,   322,   323,   327,   328,   332,   333,   334,   335,   336,
     337,   342,   343,   353,   363,   375,   378,   381,   385,   418,
     438,   478,   481,   488,   491,   494,   497,   503,   505,   508,
     510,   511,   514,   520,   552,   560,   578,   579,   580,   581,
     583,   584,   585,   586,   588,   589,   590,   611,   632,   648,
     670,   693,   694,   695,   696,   701,   706,   711,   717,   725,
     733,   740,   743,   747,   751,   759,   763,   770,   775,   784,
     785,   786,   787,   788
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
  "CASE", "DEFAULT", "EXTERN", "UPLUS", "UMINUS", "$accept", "program",
  "global_decl_list", "global_decl", "local_decl", "const_decl",
  "var_decl", "var_init_list", "var_init", "func_decl", "$@1", "$@2",
  "param_list_opt", "param_list", "param", "block", "$@3",
  "block_items_opt", "block_items", "block_item", "statement",
  "simple_stmt", "assign_stmt", "lvalue", "if_stmt", "loop_stmt",
  "for_start_opt", "for_update_opt", "assign_no_semi", "return_stmt",
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
    -108,     1,   530,  -108,  -108,  -108,  -108,  -108,  -108,   -17,
      54,  -108,  -108,  -108,  -108,   -14,   -24,    16,   -18,   -34,
    -108,    54,    14,    99,    54,    99,    10,    50,  -108,    40,
      45,  -108,    72,    99,   -21,  -108,  -108,  -108,  -108,    99,
      99,    99,    99,  -108,   490,  -108,  -108,    47,   131,    99,
     -16,  -108,    48,    54,    49,   346,    99,    99,    68,  -108,
    -108,  -108,   231,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    77,  -108,   156,  -108,
    -108,    10,  -108,   490,    71,    52,   181,    99,  -108,   167,
     167,   534,   534,   167,   167,    91,    91,  -108,  -108,  -108,
     545,   520,  -108,  -108,    62,  -108,    99,  -108,   206,    62,
      82,    93,    86,    87,    88,    99,    99,    99,   115,    37,
    -108,  -108,  -108,  -108,  -108,  -108,    89,    62,  -108,  -108,
    -108,  -108,   -36,  -108,  -108,  -108,    92,    50,   490,  -108,
      90,    99,   129,    99,   115,   122,   367,   388,   409,    96,
     101,    99,    62,  -108,  -108,    99,   102,   103,  -108,  -108,
     254,   104,   277,   113,   107,  -108,   123,  -108,  -108,  -108,
    -108,   121,   120,   430,  -108,  -108,    93,    99,    93,    99,
      99,    99,  -108,  -108,  -108,   164,   300,  -108,   490,   451,
     472,    93,   128,   115,   133,  -108,  -108,    -7,   130,  -108,
      99,  -108,  -108,    93,   323,  -108,    93,  -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   102,   100,   101,    99,   103,     0,
       0,     4,     5,     6,     7,     0,     0,     0,    14,     0,
      12,    21,     0,     0,    21,     0,    16,     0,    11,     0,
      22,    23,     0,     0,    49,    85,    86,    87,    88,     0,
       0,     0,     0,    82,    15,    83,    84,     0,     0,     0,
      14,    13,     0,     0,    25,     0,    91,     0,    50,    80,
      79,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,    19,
      24,    26,    10,    93,     0,    92,     0,     0,    81,    71,
      73,    74,    75,    70,    72,    65,    66,    67,    68,    69,
      76,    77,    17,    96,    29,    89,     0,    97,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      47,    27,    33,     8,     9,    40,     0,    30,    32,    34,
      35,    41,     0,    36,    37,    38,     0,     0,    94,    98,
       0,     0,     0,     0,    57,     0,     0,     0,     0,    49,
       0,    91,    29,    20,    31,     0,     0,     0,    39,    18,
       0,     0,     0,     0,     0,    58,     0,    64,    42,    43,
      44,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    90,    28,    48,    51,     0,    53,    63,     0,
       0,     0,     0,    59,     0,    52,    54,     0,     0,    60,
       0,    61,    62,     0,     0,    55,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,  -108,   177,   179,  -108,   155,  -108,
    -108,  -108,   182,  -108,   154,  -108,  -108,   -98,  -108,    94,
    -107,  -108,  -108,   -89,  -108,  -108,  -108,  -108,    27,  -108,
     -23,  -108,  -108,  -108,    73,  -108,   171,  -108,     3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    11,   122,   123,   124,    19,    20,    14,
     109,   104,    29,    30,    31,   125,   152,   126,   127,   128,
     129,   130,   131,    43,   133,   134,   164,   198,   165,   135,
      83,    45,    46,   136,    84,    85,    26,    58,   137
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,     3,    48,   155,   142,    15,    16,   156,   157,    18,
      55,   140,    27,    17,    28,   132,    59,    60,    61,    62,
     132,    23,   132,    23,    32,    21,    78,    32,    56,   150,
      57,    24,   179,    25,    86,    25,   201,   202,   132,    22,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    33,   172,   163,    32,     4,     5,     6,
       7,    49,     8,   132,   108,     4,     5,     6,     7,   185,
       8,   187,   110,    50,   111,   112,   113,   114,   115,    10,
     116,   117,   118,   138,   195,   119,   151,   132,    57,   132,
      52,    53,   146,   147,   148,    54,   205,    76,   106,   207,
      25,    79,   132,   110,   197,   111,   112,   113,   114,   115,
     120,   116,   117,   118,   132,   121,   119,   132,   160,    87,
     162,   105,    34,    35,    36,    37,    38,    71,    72,    73,
     102,   141,   173,    39,    40,   143,   144,   145,   149,    41,
     158,   120,   161,   153,   159,   166,   121,    57,    42,   170,
     174,   175,   179,   177,   186,   180,   188,   189,   190,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
     181,   182,    74,    75,   183,   191,   196,   204,   200,    12,
     203,    13,    51,    77,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    74,    75,    -1,
      -1,    69,    70,    71,    72,    73,    47,    80,   103,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
     199,   154,    74,    75,   171,    81,     0,     0,     0,     0,
       0,     0,     0,   107,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
       0,    88,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,   176,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,     0,     0,     0,     0,   178,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,     0,     0,
     192,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,   206,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,     0,     0,    82,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,     0,     0,   167,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,   168,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,   169,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,   184,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,     0,   193,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,   194,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    10,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    63,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      23,     0,    25,    39,   111,     2,    23,    43,    44,    23,
      33,   109,    46,    10,    48,   104,    39,    40,    41,    42,
     109,    39,   111,    39,    21,    49,    49,    24,    49,   118,
      51,    49,    39,    51,    57,    51,    43,    44,   127,    23,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    39,   152,   144,    53,     3,     4,     5,
       6,    51,     8,   152,    87,     3,     4,     5,     6,   176,
       8,   178,    10,    23,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   106,   191,    23,    49,   176,    51,   178,
      50,    46,   115,   116,   117,    23,   203,    50,    46,   206,
      51,    53,   191,    10,   193,    12,    13,    14,    15,    16,
      48,    18,    19,    20,   203,    53,    23,   206,   141,    51,
     143,    50,    23,    24,    25,    26,    27,    36,    37,    38,
      53,    49,   155,    34,    35,    49,    49,    49,    23,    40,
      48,    48,    13,    54,    54,    23,    53,    51,    49,    48,
      48,    48,    39,    49,   177,    48,   179,   180,   181,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      47,    50,    41,    42,    54,    11,    48,   200,    45,     2,
      50,     2,    27,    52,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    28,    29,    41,    42,    32,
      33,    34,    35,    36,    37,    38,    24,    53,    52,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     193,   127,    41,    42,   151,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    28,
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
      -1,    -1,    -1,    50,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    -1,    45,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,     3,     4,     5,     6,     8,     9,
      17,    66,    68,    69,    72,   101,    23,   101,    23,    70,
      71,    49,    23,    39,    49,    51,    99,    46,    48,    75,
      76,    77,   101,    39,    23,    24,    25,    26,    27,    34,
      35,    40,    49,    86,    93,    94,    95,    75,    93,    51,
      23,    71,    50,    46,    23,    93,    49,    51,   100,    93,
      93,    93,    93,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    41,    42,    50,    52,    93,    53,
      77,    99,    48,    93,    97,    98,    93,    51,    50,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    53,    52,    74,    50,    46,    52,    93,    73,
      10,    12,    13,    14,    15,    16,    18,    19,    20,    23,
      48,    53,    67,    68,    69,    78,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    92,    96,   101,    93,    52,
      80,    49,    83,    49,    49,    49,    93,    93,    93,    23,
      86,    49,    79,    54,    82,    39,    43,    44,    48,    54,
      93,    13,    93,    86,    89,    91,    23,    48,    48,    48,
      48,    97,    80,    93,    48,    48,    50,    49,    50,    39,
      48,    47,    50,    54,    48,    83,    93,    83,    93,    93,
      93,    11,    50,    48,    45,    83,    48,    86,    90,    91,
      45,    43,    44,    50,    93,    83,    50,    83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    67,    67,
      68,    69,    70,    70,    71,    71,    71,    73,    72,    74,
      72,    75,    75,    76,    76,    77,    77,    79,    78,    80,
      80,    81,    81,    82,    82,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    89,    89,    90,
      90,    90,    90,    91,    92,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    94,    95,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   101,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       6,     3,     1,     3,     1,     3,     2,     0,     9,     0,
       9,     0,     1,     1,     3,     2,     3,     0,     4,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     3,     3,     3,     3,     1,     4,     1,
       2,     5,     7,     5,     7,     9,    10,     0,     1,     0,
       1,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     0,     1,     1,     3,     3,     4,     3,     4,     1,
       1,     1,     1,     1
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
#line 99 "src/p2_parser.y"
                      {
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
#line 1416 "src/y.tab.cpp"
    break;

  case 10: /* const_decl: CONST type_spec ID ASSIGN expression SEMICOLON  */
#line 142 "src/p2_parser.y"
    {
        if (!(yyvsp[-4].type)->isCompatibleWith(*(yyvsp[-1].expr_info)->type)) {
            throw SemanticError("const type mismatch", yylineno);
        }

        if (!(yyvsp[-1].expr_info)->isConst) {
            throw SemanticError("const expression must be const", yylineno);
        }

        Symbol s(*(yyvsp[-3].sval), (yyvsp[-4].type), true);
        s.setConstValueFromExpr((yyvsp[-1].expr_info));

        Symbol* exist = symTab.lookupGlobal(s.name);
        if (exist && exist->type->isFunc()) {
            throw SemanticError("const '" + s.name + "' conflicts with function", yylineno);
        }

        if (!symTab.insert(s)) {
            throw SemanticError("redeclared const: " + *(yyvsp[-3].sval), yylineno);
        }

        if (isConvertible((yyvsp[-4].type)->base, (yyvsp[-1].expr_info)->type->base)) {
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
                baseKindToStr((yyvsp[-4].type)->base).c_str(), baseKindToStr((yyvsp[-1].expr_info)->type->base).c_str(), yylineno);
        }

        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].expr_info);
    }
#line 1450 "src/y.tab.cpp"
    break;

  case 11: /* var_decl: type_spec var_init_list SEMICOLON  */
#line 175 "src/p2_parser.y"
                                       {
        for (auto& var : *(yyvsp[-1].var_init_list)) {
            Symbol s("", nullptr, false);

            if (var->constType != nullptr) {
                if (!(yyvsp[-2].type)->isCompatibleWith(*var->constType)) {
                    throw SemanticError("var type mismatch", yylineno);
                }

                if(isConvertible((yyvsp[-2].type)->base, var->constType->base)) {
                    printf("Warning: implicit conversion from %s to %s @ line %d\n",
                        baseKindToStr((yyvsp[-2].type)->base).c_str(), baseKindToStr(var->constType->base).c_str(), yylineno);
                }
                s = Symbol(*var->name, (yyvsp[-2].type), false);
            } 
            else if (var->arrayDims != nullptr) {
                Type* arrType = typePool.makeArray((yyvsp[-2].type), *var->arrayDims);
                s = Symbol(*var->name, arrType, false);
            } 
            else {
                s = Symbol(*var->name, (yyvsp[-2].type), false);
            }

            tryInsertVar(symTab, s, yylineno);

            delete var->name;
            if (var->arrayDims) delete var->arrayDims;
            delete var;
        }
        delete (yyvsp[-1].var_init_list);
    }
#line 1486 "src/y.tab.cpp"
    break;

  case 12: /* var_init_list: var_init  */
#line 209 "src/p2_parser.y"
             {
        (yyval.var_init_list) = new std::vector<varInit*>;
        (yyval.var_init_list)->push_back((yyvsp[0].var_init));}
#line 1494 "src/y.tab.cpp"
    break;

  case 13: /* var_init_list: var_init_list COMMA var_init  */
#line 212 "src/p2_parser.y"
                                  {
        (yyval.var_init_list) = (yyvsp[-2].var_init_list);
        (yyval.var_init_list)->push_back((yyvsp[0].var_init));
    }
#line 1503 "src/y.tab.cpp"
    break;

  case 14: /* var_init: ID  */
#line 219 "src/p2_parser.y"
                            { (yyval.var_init) = new varInit((yyvsp[0].sval)); }
#line 1509 "src/y.tab.cpp"
    break;

  case 15: /* var_init: ID ASSIGN expression  */
#line 220 "src/p2_parser.y"
                            {
        if ((yyvsp[0].expr_info)->type->isFunc()) {
            throw SemanticError("assignment from function", yylineno);
        }
        if ((yyvsp[0].expr_info)->type->isArray()) {
            throw SemanticError("assignment from array", yylineno);
        }

        (yyval.var_init) = new varInit((yyvsp[-2].sval), (yyvsp[0].expr_info)->type);
   }
#line 1524 "src/y.tab.cpp"
    break;

  case 16: /* var_init: ID array_dims  */
#line 230 "src/p2_parser.y"
                            { (yyval.var_init) = new varInit((yyvsp[-1].sval), (yyvsp[0].int_list)); }
#line 1530 "src/y.tab.cpp"
    break;

  case 17: /* $@1: %empty  */
#line 235 "src/p2_parser.y"
                                                     {
        returnsExpr.clear();

        if (*(yyvsp[-4].sval) == "main") {
            throw SemanticError("main function should be void", yylineno);
        }

        declareFunction(*(yyvsp[-4].sval), (yyvsp[-5].type), (yyvsp[-2].symbol_list), typePool, symTab, yylineno);
        delete (yyvsp[-4].sval);
    }
#line 1545 "src/y.tab.cpp"
    break;

  case 18: /* func_decl: type_spec ID LPAREN param_list_opt RPAREN LBRACE $@1 block_items_opt RBRACE  */
#line 244 "src/p2_parser.y"
                             {
        if (returnsExpr.empty()) {
            throw SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : returnsExpr) {
            if (!(yyvsp[-8].type)->isCompatibleWith(*expr.first.type)) {
                throw SemanticError("return type mismatch !", expr.second);
            }

            if (isConvertible((yyvsp[-8].type)->base, expr.first.type->base)) {
                printf("Warning: implicit conversion from %s to %s @ line %d\n",
                    baseKindToStr((yyvsp[-8].type)->base).c_str(), baseKindToStr(expr.first.type->base).c_str(), expr.second);
            }
        }
        symTab.leaveScope();
    }
#line 1567 "src/y.tab.cpp"
    break;

  case 19: /* $@2: %empty  */
#line 261 "src/p2_parser.y"
                                                    {
        Type* voidType = typePool.make(BK_Void);
        returnsExpr.clear();
        declareFunction(*(yyvsp[-4].sval), voidType, (yyvsp[-2].symbol_list), typePool, symTab, yylineno);
        delete (yyvsp[-4].sval);
    }
#line 1578 "src/y.tab.cpp"
    break;

  case 20: /* func_decl: VOID_TOK ID LPAREN param_list_opt RPAREN LBRACE $@2 block_items_opt RBRACE  */
#line 266 "src/p2_parser.y"
                             {
        if (!returnsExpr.empty()) {
            throw SemanticError("void function should not return value", yylineno);
        }

        symTab.leaveScope();
    }
#line 1590 "src/y.tab.cpp"
    break;

  case 21: /* param_list_opt: %empty  */
#line 276 "src/p2_parser.y"
                {
        (yyval.symbol_list) = new std::vector<Symbol*>();
    }
#line 1598 "src/y.tab.cpp"
    break;

  case 22: /* param_list_opt: param_list  */
#line 279 "src/p2_parser.y"
               {
        (yyval.symbol_list) = (yyvsp[0].symbol_list);
     }
#line 1606 "src/y.tab.cpp"
    break;

  case 23: /* param_list: param  */
#line 285 "src/p2_parser.y"
           {
        (yyval.symbol_list) = new std::vector<Symbol*>;
        (yyval.symbol_list)->push_back((yyvsp[0].symbol));
     }
#line 1615 "src/y.tab.cpp"
    break;

  case 24: /* param_list: param_list COMMA param  */
#line 289 "src/p2_parser.y"
                            {
        (yyval.symbol_list) = (yyvsp[-2].symbol_list);
        (yyval.symbol_list)->push_back((yyvsp[0].symbol));
     }
#line 1624 "src/y.tab.cpp"
    break;

  case 25: /* param: type_spec ID  */
#line 296 "src/p2_parser.y"
                  {
        (yyval.symbol) = new Symbol(*(yyvsp[0].sval), (yyvsp[-1].type), false);
        delete (yyvsp[0].sval);
     }
#line 1633 "src/y.tab.cpp"
    break;

  case 26: /* param: type_spec ID array_dims  */
#line 300 "src/p2_parser.y"
                            {
        (yyval.symbol) = new Symbol(*(yyvsp[-1].sval), typePool.makeArray((yyvsp[-2].type), *(yyvsp[0].int_list)), false);
        delete (yyvsp[-1].sval);
        delete (yyvsp[0].int_list);
     }
#line 1643 "src/y.tab.cpp"
    break;

  case 27: /* $@3: %empty  */
#line 309 "src/p2_parser.y"
            {
        symTab.enterScope();
     }
#line 1651 "src/y.tab.cpp"
    break;

  case 28: /* block: LBRACE $@3 block_items_opt RBRACE  */
#line 311 "src/p2_parser.y"
                             {
        symTab.leaveScope();
     }
#line 1659 "src/y.tab.cpp"
    break;

  case 42: /* simple_stmt: PRINT expression SEMICOLON  */
#line 343 "src/p2_parser.y"
                                 {
        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            throw SemanticError("print from function", yylineno);
        }
        if ((yyvsp[-1].expr_info)->type->isArray()) {
            throw SemanticError("print from array", yylineno);
        }

        delete (yyvsp[-1].expr_info);
  }
#line 1674 "src/y.tab.cpp"
    break;

  case 43: /* simple_stmt: PRINTLN expression SEMICOLON  */
#line 353 "src/p2_parser.y"
                                  {
        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            throw SemanticError("print from function", yylineno);
        }
        if ((yyvsp[-1].expr_info)->type->isArray()) {
            throw SemanticError("print from array", yylineno);
        }

        delete (yyvsp[-1].expr_info);
  }
#line 1689 "src/y.tab.cpp"
    break;

  case 44: /* simple_stmt: READ lvalue SEMICOLON  */
#line 363 "src/p2_parser.y"
                           {
        if ((yyvsp[-1].expr_info)->isConst) {
            throw SemanticError("read to const", yylineno);
        }

        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            throw SemanticError("read to function", yylineno);
        }
        if ((yyvsp[-1].expr_info)->type->isArray()) {
            throw SemanticError("read to array", yylineno);
        }
    }
#line 1706 "src/y.tab.cpp"
    break;

  case 45: /* simple_stmt: lvalue INC SEMICOLON  */
#line 375 "src/p2_parser.y"
                          {
        checkIncDecValid((yyvsp[-2].expr_info), "increment", yylineno);
     }
#line 1714 "src/y.tab.cpp"
    break;

  case 46: /* simple_stmt: lvalue DEC SEMICOLON  */
#line 378 "src/p2_parser.y"
                          {
        checkIncDecValid((yyvsp[-2].expr_info), "decrement", yylineno);
    }
#line 1722 "src/y.tab.cpp"
    break;

  case 48: /* assign_stmt: lvalue ASSIGN expression SEMICOLON  */
#line 385 "src/p2_parser.y"
                                        {
        if ((yyvsp[-3].expr_info)->isConst) {
            throw SemanticError("assignment to const", yylineno);
        }

        if ((yyvsp[-3].expr_info)->type->isFunc()) {
            throw SemanticError("assignment to function", yylineno);
        }
        if ((yyvsp[-3].expr_info)->type->isArray()) {
            throw SemanticError("assignment to array", yylineno);
        }

        if ((yyvsp[-1].expr_info)->type->isFunc()) {
            throw SemanticError("assignment from function", yylineno);
        }
        if ((yyvsp[-1].expr_info)->type->isArray()) {
            throw SemanticError("assignment from array", yylineno);
        }

        if (!isBaseCompatible((yyvsp[-3].expr_info)->type->base, (yyvsp[-1].expr_info)->type->base) ) {
                throw SemanticError("assignment type mismatch", yylineno);
        }

        if (isConvertible((yyvsp[-3].expr_info)->type->base, (yyvsp[-1].expr_info)->type->base)){
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr((yyvsp[-1].expr_info)->type->base).c_str(), baseKindToStr((yyvsp[-3].expr_info)->type->base).c_str(), yylineno);
        }

        delete (yyvsp[-1].expr_info);
     }
#line 1757 "src/y.tab.cpp"
    break;

  case 49: /* lvalue: ID  */
#line 418 "src/p2_parser.y"
        {
        Symbol* symbol = symTab.lookup(*(yyvsp[0].sval));
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *(yyvsp[0].sval), yylineno);
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
#line 1782 "src/y.tab.cpp"
    break;

  case 50: /* lvalue: ID array_ref  */
#line 438 "src/p2_parser.y"
                 {
        Symbol* symbol = symTab.lookup(*(yyvsp[-1].sval));
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *(yyvsp[-1].sval), yylineno);
        }

        if (!symbol->type->isArray()) {
            throw SemanticError("array index to non-array type: " + *(yyvsp[-1].sval), yylineno);
        }

        size_t given = (yyvsp[0].int_list)->size();
        std::vector<int> dims = symbol->type->sizes;

        for (size_t i = 0; i < given; ++i) {
            int index = (*(yyvsp[0].int_list))[i];
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

        (yyval.expr_info) = new ExprInfo(typePool.makeArray(typePool.make(symbol->type->base), dims), symbol->isConst);
        delete (yyvsp[0].int_list);
        delete (yyvsp[-1].sval);
    }
#line 1823 "src/y.tab.cpp"
    break;

  case 51: /* if_stmt: IF LPAREN expression RPAREN statement  */
#line 478 "src/p2_parser.y"
                                           {
        checkBoolExpr((yyvsp[-2].expr_info), "if", yylineno);
     }
#line 1831 "src/y.tab.cpp"
    break;

  case 52: /* if_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 481 "src/p2_parser.y"
                                                          {
        checkBoolExpr((yyvsp[-4].expr_info), "if", yylineno);
    }
#line 1839 "src/y.tab.cpp"
    break;

  case 53: /* loop_stmt: WHILE LPAREN expression RPAREN statement  */
#line 488 "src/p2_parser.y"
                                             { 
        checkBoolExpr((yyvsp[-2].expr_info), "while", yylineno); 
    }
#line 1847 "src/y.tab.cpp"
    break;

  case 54: /* loop_stmt: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 491 "src/p2_parser.y"
                                                           {
        checkBoolExpr((yyvsp[-2].expr_info), "do while", yylineno);
    }
#line 1855 "src/y.tab.cpp"
    break;

  case 55: /* loop_stmt: FOR LPAREN for_start_opt SEMICOLON expression SEMICOLON for_update_opt RPAREN statement  */
#line 494 "src/p2_parser.y"
                                                                                            {
        checkBoolExpr((yyvsp[-4].expr_info), "for", yylineno);
    }
#line 1863 "src/y.tab.cpp"
    break;

  case 56: /* loop_stmt: FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement  */
#line 497 "src/p2_parser.y"
                                                                           {
        checkForeachRange((yyvsp[-5].expr_info), (yyvsp[-2].expr_info), yylineno);
        checkForeachIndex(symTab.lookup(*(yyvsp[-7].sval)), yylineno);
    }
#line 1872 "src/y.tab.cpp"
    break;

  case 61: /* for_update_opt: lvalue INC  */
#line 511 "src/p2_parser.y"
               {
        checkIncDecValid((yyvsp[-1].expr_info), "increment", yylineno);
    }
#line 1880 "src/y.tab.cpp"
    break;

  case 62: /* for_update_opt: lvalue DEC  */
#line 514 "src/p2_parser.y"
              {
        checkIncDecValid((yyvsp[-1].expr_info), "decrement", yylineno);
    }
#line 1888 "src/y.tab.cpp"
    break;

  case 63: /* assign_no_semi: lvalue ASSIGN expression  */
#line 520 "src/p2_parser.y"
                             {
        if ((yyvsp[-2].expr_info)->isConst) {
            throw SemanticError("assignment to const", yylineno);
        }

        if ((yyvsp[-2].expr_info)->type->isFunc()) {
            throw SemanticError("assignment to function", yylineno);
        }
        if ((yyvsp[-2].expr_info)->type->isArray()) {
            throw SemanticError("assignment to array", yylineno);
        }

        if ((yyvsp[0].expr_info)->type->isFunc()) {
            throw SemanticError("assignment from function", yylineno);
        }
        if ((yyvsp[0].expr_info)->type->isArray()) {
            throw SemanticError("assignment from array", yylineno);
        }

        if (!isBaseCompatible((yyvsp[-2].expr_info)->type->base, (yyvsp[0].expr_info)->type->base) ) {
                throw SemanticError("assignment type mismatch", yylineno);
        }

        if (isConvertible((yyvsp[-2].expr_info)->type->base, (yyvsp[0].expr_info)->type->base)){
            printf("Warning: implicit conversion from %s to %s @ line %d\n",
               baseKindToStr((yyvsp[-2].expr_info)->type->base).c_str(), baseKindToStr((yyvsp[0].expr_info)->type->base).c_str(), yylineno);
        }
    }
#line 1921 "src/y.tab.cpp"
    break;

  case 64: /* return_stmt: RETURN expression SEMICOLON  */
#line 552 "src/p2_parser.y"
                                 {
        returnsExpr.push_back(std::make_pair(*(yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 1930 "src/y.tab.cpp"
    break;

  case 65: /* expression: expression PLUS expression  */
#line 560 "src/p2_parser.y"
                               {
        bool isStringConcat = ((yyvsp[-2].expr_info)->type->base == BK_String && (yyvsp[0].expr_info)->type->base == BK_String);

        if (isStringConcat) {
            ExprInfo* expr = new ExprInfo(typePool.make(BK_String), (yyvsp[-2].expr_info)->isConst && (yyvsp[0].expr_info)->isConst);
            if (expr->isConst) {
                expr->setString((yyvsp[-2].expr_info)->getString() + (yyvsp[0].expr_info)->getString());
            }
            (yyval.expr_info) = expr;
        } else if (isBaseCompatible((yyvsp[-2].expr_info)->type->base, (yyvsp[0].expr_info)->type->base)) {
            (yyval.expr_info) = numericResult(OPADD, (yyvsp[-2].expr_info), (yyvsp[0].expr_info), typePool, yylineno);
        } else {
            throw SemanticError("invalid types for '+' operator", yylineno);
        }

        delete (yyvsp[-2].expr_info);
        delete (yyvsp[0].expr_info);
    }
#line 1953 "src/y.tab.cpp"
    break;

  case 66: /* expression: expression MINUS expression  */
#line 578 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPSUB,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 1959 "src/y.tab.cpp"
    break;

  case 67: /* expression: expression MUL expression  */
#line 579 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPMUL,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 1965 "src/y.tab.cpp"
    break;

  case 68: /* expression: expression DIV expression  */
#line 580 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPDIV,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 1971 "src/y.tab.cpp"
    break;

  case 69: /* expression: expression MOD expression  */
#line 581 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPMOD,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 1977 "src/y.tab.cpp"
    break;

  case 70: /* expression: expression LT expression  */
#line 583 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPLT, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 1983 "src/y.tab.cpp"
    break;

  case 71: /* expression: expression LE expression  */
#line 584 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPLE, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 1989 "src/y.tab.cpp"
    break;

  case 72: /* expression: expression GT expression  */
#line 585 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPGT, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 1995 "src/y.tab.cpp"
    break;

  case 73: /* expression: expression GE expression  */
#line 586 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPGE, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 2001 "src/y.tab.cpp"
    break;

  case 74: /* expression: expression EQ expression  */
#line 588 "src/p2_parser.y"
                                  { (yyval.expr_info) = eqResult(true,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 2007 "src/y.tab.cpp"
    break;

  case 75: /* expression: expression NEQ expression  */
#line 589 "src/p2_parser.y"
                                  { (yyval.expr_info) = eqResult(false, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); delete (yyvsp[-2].expr_info); delete (yyvsp[0].expr_info); }
#line 2013 "src/y.tab.cpp"
    break;

  case 76: /* expression: expression AND expression  */
#line 590 "src/p2_parser.y"
                                   {
        if (!(yyvsp[-2].expr_info)->type->isScalar()){
            throw SemanticError("and on non-scalar type", yylineno);
        }

        if (!(yyvsp[0].expr_info)->type->isScalar()){
            throw SemanticError("and on non-scalar type", yylineno);
        }

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
#line 2039 "src/y.tab.cpp"
    break;

  case 77: /* expression: expression OR expression  */
#line 611 "src/p2_parser.y"
                                   { 
        if (!(yyvsp[-2].expr_info)->type->isScalar()){
            throw SemanticError("or on non-scalar type", yylineno);
        }

        if (!(yyvsp[0].expr_info)->type->isScalar()){
            throw SemanticError("or on non-scalar type", yylineno);
        }

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
#line 2065 "src/y.tab.cpp"
    break;

  case 78: /* expression: NOT expression  */
#line 632 "src/p2_parser.y"
                                   { 
        if (!(yyvsp[0].expr_info)->type->isScalar()){
            throw SemanticError("not on non-scalar type", yylineno);
        }

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
#line 2086 "src/y.tab.cpp"
    break;

  case 79: /* expression: MINUS expression  */
#line 648 "src/p2_parser.y"
                                   { 
        if (!(yyvsp[0].expr_info)->type->isScalar()){
            throw SemanticError("unary minus on non-scalar type", yylineno);
        }

        if ((yyvsp[0].expr_info)->type->base != BK_Float && (yyvsp[0].expr_info)->type->base != BK_Int && (yyvsp[0].expr_info)->type->base != BK_Double) {
            throw SemanticError("unary minus on non-numeric type", yylineno);
        }

        ExprInfo* expr = new ExprInfo((yyvsp[0].expr_info)->type, (yyvsp[0].expr_info)->isConst);
        if ((yyvsp[0].expr_info)->isConst){
            if ((yyvsp[0].expr_info)->valueKind == VK_Float) {
                expr->setFloat(-(yyvsp[0].expr_info)->getFloat());
            } else if ((yyvsp[0].expr_info)->valueKind == VK_Int) {
                expr->setInt(-(yyvsp[0].expr_info)->getInt());
            } else if ((yyvsp[0].expr_info)->valueKind == VK_Double) {
                expr->setFloat(-(yyvsp[0].expr_info)->getDouble());
            }
        }
        (yyval.expr_info) = expr;
        delete (yyvsp[0].expr_info);
    }
#line 2113 "src/y.tab.cpp"
    break;

  case 80: /* expression: PLUS expression  */
#line 670 "src/p2_parser.y"
                                   { 
        if (!(yyvsp[0].expr_info)->type->isScalar()){
            throw SemanticError("unary plus on non-scalar type", yylineno);
        }

        if ((yyvsp[0].expr_info)->type->base != BK_Float && (yyvsp[0].expr_info)->type->base != BK_Int && (yyvsp[0].expr_info)->type->base != BK_Double) {
            throw SemanticError("unary plus on non-numeric type", yylineno);
        }

        ExprInfo* expr = new ExprInfo((yyvsp[0].expr_info)->type, (yyvsp[0].expr_info)->isConst);
        if ((yyvsp[0].expr_info)->isConst){
            if ((yyvsp[0].expr_info)->valueKind == VK_Float) {
                expr->setFloat((yyvsp[0].expr_info)->getFloat());
            } else if ((yyvsp[0].expr_info)->valueKind == VK_Int) {
                expr->setInt((yyvsp[0].expr_info)->getInt());
            } else if ((yyvsp[0].expr_info)->valueKind == VK_Double) {
                expr->setFloat((yyvsp[0].expr_info)->getDouble());
            }
        }

        (yyval.expr_info) = expr;
        delete (yyvsp[0].expr_info);
    }
#line 2141 "src/y.tab.cpp"
    break;

  case 81: /* expression: LPAREN expression RPAREN  */
#line 693 "src/p2_parser.y"
                                   { (yyval.expr_info) = (yyvsp[-1].expr_info); }
#line 2147 "src/y.tab.cpp"
    break;

  case 82: /* expression: lvalue  */
#line 694 "src/p2_parser.y"
                                   { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2153 "src/y.tab.cpp"
    break;

  case 83: /* expression: const_lit  */
#line 695 "src/p2_parser.y"
                                  { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2159 "src/y.tab.cpp"
    break;

  case 84: /* expression: func_call  */
#line 696 "src/p2_parser.y"
                                   { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2165 "src/y.tab.cpp"
    break;

  case 85: /* const_lit: INT_LIT  */
#line 701 "src/p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Int), true);
        expr->setInt((yyvsp[0].ival));
        (yyval.expr_info) = expr;
    }
#line 2175 "src/y.tab.cpp"
    break;

  case 86: /* const_lit: REAL_LIT  */
#line 706 "src/p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Double), true);
        expr->setFloat((yyvsp[0].fval));
        (yyval.expr_info) = expr;
    }
#line 2185 "src/y.tab.cpp"
    break;

  case 87: /* const_lit: STRING_LIT  */
#line 711 "src/p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_String), true);
        expr->setString(*(yyvsp[0].sval));
        (yyval.expr_info) = expr;
        delete (yyvsp[0].sval);
    }
#line 2196 "src/y.tab.cpp"
    break;

  case 88: /* const_lit: BOOL_LIT  */
#line 717 "src/p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), true);
        expr->setBool((yyvsp[0].bval));
        (yyval.expr_info) = expr;
    }
#line 2206 "src/y.tab.cpp"
    break;

  case 89: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 725 "src/p2_parser.y"
                                  {
        Symbol* symbol = symTab.lookup(*(yyvsp[-3].sval));
        checkFuncCall(symbol, *(yyvsp[-3].sval), (yyvsp[-1].expr_info_list), yylineno);
        (yyval.expr_info) = new ExprInfo(symbol->type->ret);
        delete (yyvsp[-3].sval);
    }
#line 2217 "src/y.tab.cpp"
    break;

  case 90: /* proc_call: ID LPAREN arg_list_opt RPAREN  */
#line 733 "src/p2_parser.y"
                                  {
        Symbol* symbol = symTab.lookup(*(yyvsp[-3].sval));
        checkFuncCall(symbol, *(yyvsp[-3].sval), (yyvsp[-1].expr_info_list), yylineno);
        delete (yyvsp[-3].sval);
    }
#line 2227 "src/y.tab.cpp"
    break;

  case 91: /* arg_list_opt: %empty  */
#line 740 "src/p2_parser.y"
               { 
        (yyval.expr_info_list) = new std::vector<ExprInfo*>();
    }
#line 2235 "src/y.tab.cpp"
    break;

  case 92: /* arg_list_opt: arg_list  */
#line 743 "src/p2_parser.y"
             { (yyval.expr_info_list) = (yyvsp[0].expr_info_list); }
#line 2241 "src/y.tab.cpp"
    break;

  case 93: /* arg_list: expression  */
#line 747 "src/p2_parser.y"
                {
        (yyval.expr_info_list) = new std::vector<ExprInfo*>;
        (yyval.expr_info_list)->push_back((yyvsp[0].expr_info));
     }
#line 2250 "src/y.tab.cpp"
    break;

  case 94: /* arg_list: arg_list COMMA expression  */
#line 751 "src/p2_parser.y"
                              {
        (yyval.expr_info_list) = (yyvsp[-2].expr_info_list);
        (yyval.expr_info_list)->push_back((yyvsp[0].expr_info));
  }
#line 2259 "src/y.tab.cpp"
    break;

  case 95: /* array_dims: LBRACK expression RBRACK  */
#line 759 "src/p2_parser.y"
                              {
        (yyval.int_list) = new std::vector<int>;
        (yyval.int_list)->push_back(checkArrayDimExpr((yyvsp[-1].expr_info), yylineno));
     }
#line 2268 "src/y.tab.cpp"
    break;

  case 96: /* array_dims: array_dims LBRACK expression RBRACK  */
#line 763 "src/p2_parser.y"
                                         {
        (yyval.int_list) = (yyvsp[-3].int_list);
        (yyval.int_list)->push_back(checkArrayDimExpr((yyvsp[-1].expr_info), yylineno));
     }
#line 2277 "src/y.tab.cpp"
    break;

  case 97: /* array_ref: LBRACK expression RBRACK  */
#line 770 "src/p2_parser.y"
                              {
        (yyval.int_list) = new std::vector<int>;
        (yyval.int_list)->push_back(extractArrayIndexOrZero((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 2287 "src/y.tab.cpp"
    break;

  case 98: /* array_ref: array_ref LBRACK expression RBRACK  */
#line 775 "src/p2_parser.y"
                                        {
        (yyval.int_list) = (yyvsp[-3].int_list);
        (yyval.int_list)->push_back(extractArrayIndexOrZero((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 2297 "src/y.tab.cpp"
    break;

  case 99: /* type_spec: INT_TOK  */
#line 784 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Int);   }
#line 2303 "src/y.tab.cpp"
    break;

  case 100: /* type_spec: FLOAT_TOK  */
#line 785 "src/p2_parser.y"
                     { (yyval.type) = typePool.make(BK_Float); }
#line 2309 "src/y.tab.cpp"
    break;

  case 101: /* type_spec: DOUBLE_TOK  */
#line 786 "src/p2_parser.y"
                     { (yyval.type) = typePool.make(BK_Double); }
#line 2315 "src/y.tab.cpp"
    break;

  case 102: /* type_spec: BOOL_TOK  */
#line 787 "src/p2_parser.y"
                     { (yyval.type) = typePool.make(BK_Bool);  }
#line 2321 "src/y.tab.cpp"
    break;

  case 103: /* type_spec: STRING_TOK  */
#line 788 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_String);}
#line 2327 "src/y.tab.cpp"
    break;


#line 2331 "src/y.tab.cpp"

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

#line 791 "src/p2_parser.y"
 

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
