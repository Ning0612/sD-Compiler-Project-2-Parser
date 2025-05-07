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
  YYSYMBOL_BOOL = 3,                       /* BOOL  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 5,                     /* DOUBLE  */
  YYSYMBOL_INT_TOK = 6,                    /* INT_TOK  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_STRING_TOK = 8,                 /* STRING_TOK  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
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
  YYSYMBOL_decl_list = 65,                 /* decl_list  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_const_decl = 67,                /* const_decl  */
  YYSYMBOL_var_decl = 68,                  /* var_decl  */
  YYSYMBOL_var_init_list = 69,             /* var_init_list  */
  YYSYMBOL_var_init = 70,                  /* var_init  */
  YYSYMBOL_func_decl = 71,                 /* func_decl  */
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_73_2 = 73,                      /* $@2  */
  YYSYMBOL_param_list_opt = 74,            /* param_list_opt  */
  YYSYMBOL_param_list = 75,                /* param_list  */
  YYSYMBOL_param = 76,                     /* param  */
  YYSYMBOL_block = 77,                     /* block  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_block_items_opt = 79,           /* block_items_opt  */
  YYSYMBOL_block_items = 80,               /* block_items  */
  YYSYMBOL_block_item = 81,                /* block_item  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_simple_stmt = 83,               /* simple_stmt  */
  YYSYMBOL_assign_stmt = 84,               /* assign_stmt  */
  YYSYMBOL_lvalue = 85,                    /* lvalue  */
  YYSYMBOL_if_stmt = 86,                   /* if_stmt  */
  YYSYMBOL_loop_stmt = 87,                 /* loop_stmt  */
  YYSYMBOL_for_start_opt = 88,             /* for_start_opt  */
  YYSYMBOL_for_update_opt = 89,            /* for_update_opt  */
  YYSYMBOL_assign_no_semi = 90,            /* assign_no_semi  */
  YYSYMBOL_return_stmt = 91,               /* return_stmt  */
  YYSYMBOL_expression = 92,                /* expression  */
  YYSYMBOL_const_expr = 93,                /* const_expr  */
  YYSYMBOL_func_call = 94,                 /* func_call  */
  YYSYMBOL_proc_call = 95,                 /* proc_call  */
  YYSYMBOL_arg_list_opt = 96,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 97,                  /* arg_list  */
  YYSYMBOL_array_dims = 98,                /* array_dims  */
  YYSYMBOL_array_ref = 99,                 /* array_ref  */
  YYSYMBOL_type_spec = 100                 /* type_spec  */
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
#define YYLAST   616

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

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
       0,    99,    99,   115,   117,   122,   123,   124,   129,   158,
     187,   190,   197,   198,   208,   214,   213,   232,   232,   246,
     249,   255,   259,   266,   270,   279,   279,   286,   288,   292,
     293,   297,   298,   302,   303,   304,   305,   306,   307,   312,
     313,   314,   315,   327,   330,   333,   337,   365,   385,   428,
     431,   438,   441,   444,   447,   453,   455,   458,   460,   461,
     464,   470,   497,   505,   523,   524,   525,   526,   528,   529,
     530,   531,   533,   534,   535,   548,   561,   573,   589,   606,
     607,   608,   609,   614,   619,   624,   630,   638,   646,   653,
     656,   660,   664,   672,   676,   683,   688,   697,   698,   699,
     700,   701
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
  "DOUBLE", "INT_TOK", "CHAR", "STRING_TOK", "VOID", "IF", "ELSE", "DO",
  "WHILE", "FOR", "FOREACH", "RETURN", "CONST", "PRINT", "PRINTLN", "READ",
  "TRUE", "FALSE", "ID", "INT_LIT", "REAL_LIT", "STRING_LIT", "BOOL_LIT",
  "LE", "GE", "EQ", "NEQ", "LT", "GT", "PLUS", "MINUS", "MUL", "DIV",
  "MOD", "ASSIGN", "NOT", "AND", "OR", "INC", "DEC", "DOT", "COMMA",
  "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE",
  "RBRACE", "BREAK", "CONTINUE", "SWITCH", "CASE", "DEFAULT", "EXTERN",
  "UPLUS", "UMINUS", "$accept", "program", "decl_list", "declaration",
  "const_decl", "var_decl", "var_init_list", "var_init", "func_decl",
  "$@1", "$@2", "param_list_opt", "param_list", "param", "block", "$@3",
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

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -105,     9,    72,  -105,  -105,  -105,  -105,  -105,  -105,    -2,
       0,  -105,  -105,  -105,  -105,     6,   -25,    10,   -19,   -34,
    -105,     0,    -1,   154,     0,   154,     5,    42,  -105,    16,
      22,  -105,    47,   154,   -12,  -105,  -105,  -105,  -105,   154,
     154,   154,   154,  -105,   538,  -105,  -105,    23,   179,   154,
     -38,  -105,    19,     0,    28,   394,   154,   154,    31,  -105,
    -105,  -105,   279,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,    32,  -105,   204,  -105,
    -105,     5,  -105,   538,    36,    41,   229,   154,  -105,    98,
      98,   567,   567,    98,    98,    25,    25,  -105,  -105,  -105,
     578,   553,  -105,  -105,   153,  -105,   154,  -105,   254,   153,
      39,    90,    46,    48,    52,   154,   154,   154,    68,     8,
    -105,  -105,  -105,  -105,    53,   153,  -105,  -105,  -105,  -105,
     -16,  -105,  -105,  -105,    63,   538,  -105,    58,   154,   101,
     154,    68,    93,   415,   436,   457,    67,    71,   154,   153,
    -105,  -105,   154,    73,    75,  -105,  -105,   302,    76,   325,
      81,    80,  -105,    94,  -105,  -105,  -105,  -105,    92,    86,
     478,  -105,  -105,    90,   154,    90,   154,   154,   154,  -105,
    -105,  -105,   133,   348,  -105,   538,   499,   520,    90,    97,
      68,   102,  -105,  -105,    -8,    96,  -105,   154,  -105,  -105,
      90,   371,  -105,    90,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   100,    98,    99,    97,   101,     0,
       0,     4,     5,     6,     7,     0,     0,     0,    12,     0,
      10,    19,     0,     0,    19,     0,    14,     0,     9,     0,
      20,    21,     0,     0,    47,    83,    84,    85,    86,     0,
       0,     0,     0,    80,    13,    81,    82,     0,     0,     0,
      12,    11,     0,     0,    23,     0,    89,     0,    48,    78,
      77,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,    17,
      22,    24,     8,    91,     0,    90,     0,     0,    79,    69,
      71,    72,    73,    68,    70,    63,    64,    65,    66,    67,
      74,    75,    15,    94,    27,    87,     0,    95,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      45,    25,    31,    38,     0,    28,    30,    32,    33,    39,
       0,    34,    35,    36,     0,    92,    96,     0,     0,     0,
       0,    55,     0,     0,     0,     0,    47,     0,    89,    27,
      18,    29,     0,     0,     0,    37,    16,     0,     0,     0,
       0,     0,    56,     0,    62,    40,    41,    42,     0,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,    88,
      26,    46,    49,     0,    51,    61,     0,     0,     0,     0,
      57,     0,    50,    52,     0,     0,    58,     0,    59,    60,
       0,     0,    53,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   146,  -105,  -105,  -105,   123,  -105,  -105,
    -105,   136,  -105,   111,  -105,  -105,   -94,  -105,    50,  -104,
    -105,  -105,   -51,  -105,  -105,  -105,  -105,    -7,  -105,   -23,
    -105,  -105,  -105,    34,  -105,   130,  -105,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   122,    12,    13,    19,    20,    14,   109,
     104,    29,    30,    31,   123,   149,   124,   125,   126,   127,
     128,   129,    43,   131,   132,   161,   195,   162,   133,    83,
      45,    46,   134,    84,    85,    26,    58,    15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    23,    48,     4,     5,     6,     7,   139,     8,     3,
      55,    17,    27,    25,    28,   137,    59,    60,    61,    62,
      23,    16,    32,   152,    21,    32,    78,   153,   154,    18,
      24,   176,    25,    22,    86,   198,   199,    56,    33,    57,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   130,    32,   169,    49,   148,   130,    57,
     130,    71,    72,    73,   108,    50,    52,   147,    53,   182,
      54,   184,    79,    76,   130,     4,     5,     6,     7,    25,
       8,     9,    87,   135,   192,   102,   105,   106,   138,    10,
     160,   146,   143,   144,   145,   140,   202,   141,   130,   204,
     110,   142,   111,   112,   113,   114,   115,   150,   116,   117,
     118,   155,   156,   119,   158,   157,   163,   159,    57,   167,
     176,   171,   130,   172,   130,   174,    -1,    -1,   177,   170,
      -1,    -1,    69,    70,    71,    72,    73,   130,   120,   194,
     180,   178,   179,   121,   188,   193,   200,   197,    11,   130,
      51,   183,   130,   185,   186,   187,     4,     5,     6,     7,
      47,     8,     9,   110,    80,   111,   112,   113,   114,   115,
      10,   116,   117,   118,   201,   151,   119,    34,    35,    36,
      37,    38,   168,   196,    81,     0,     0,     0,    39,    40,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,   120,     0,    42,     0,     0,   121,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,    88,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,     0,     0,
       0,     0,   173,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,     0,     0,     0,     0,   175,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,   189,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
       0,   203,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,    82,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,     0,     0,   164,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,     0,     0,   165,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,     0,     0,   166,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,     0,     0,   181,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,     0,     0,   190,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,   191,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    63,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      23,    39,    25,     3,     4,     5,     6,   111,     8,     0,
      33,    10,    46,    51,    48,   109,    39,    40,    41,    42,
      39,    23,    21,    39,    49,    24,    49,    43,    44,    23,
      49,    39,    51,    23,    57,    43,    44,    49,    39,    51,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   104,    53,   149,    51,    49,   109,    51,
     111,    36,    37,    38,    87,    23,    50,   118,    46,   173,
      23,   175,    53,    50,   125,     3,     4,     5,     6,    51,
       8,     9,    51,   106,   188,    53,    50,    46,    49,    17,
     141,    23,   115,   116,   117,    49,   200,    49,   149,   203,
      10,    49,    12,    13,    14,    15,    16,    54,    18,    19,
      20,    48,    54,    23,    13,   138,    23,   140,    51,    48,
      39,    48,   173,    48,   175,    49,    28,    29,    48,   152,
      32,    33,    34,    35,    36,    37,    38,   188,    48,   190,
      54,    47,    50,    53,    11,    48,    50,    45,     2,   200,
      27,   174,   203,   176,   177,   178,     3,     4,     5,     6,
      24,     8,     9,    10,    53,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   197,   125,    23,    23,    24,    25,
      26,    27,   148,   190,    54,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    49,    -1,    -1,    53,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    28,    29,    30,    31,    32,    33,    34,    35,
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
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    45,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    41,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,     3,     4,     5,     6,     8,     9,
      17,    66,    67,    68,    71,   100,    23,   100,    23,    69,
      70,    49,    23,    39,    49,    51,    98,    46,    48,    74,
      75,    76,   100,    39,    23,    24,    25,    26,    27,    34,
      35,    40,    49,    85,    92,    93,    94,    74,    92,    51,
      23,    70,    50,    46,    23,    92,    49,    51,    99,    92,
      92,    92,    92,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    41,    42,    50,    52,    92,    53,
      76,    98,    48,    92,    96,    97,    92,    51,    50,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    53,    52,    73,    50,    46,    52,    92,    72,
      10,    12,    13,    14,    15,    16,    18,    19,    20,    23,
      48,    53,    66,    77,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    91,    95,    92,    52,    79,    49,    82,
      49,    49,    49,    92,    92,    92,    23,    85,    49,    78,
      54,    81,    39,    43,    44,    48,    54,    92,    13,    92,
      85,    88,    90,    23,    48,    48,    48,    48,    96,    79,
      92,    48,    48,    50,    49,    50,    39,    48,    47,    50,
      54,    48,    82,    92,    82,    92,    92,    92,    11,    50,
      48,    45,    82,    48,    85,    89,    90,    45,    43,    44,
      50,    92,    82,    50,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    67,    68,
      69,    69,    70,    70,    70,    72,    71,    73,    71,    74,
      74,    75,    75,    76,    76,    78,    77,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    85,    86,
      86,    87,    87,    87,    87,    88,    88,    89,    89,    89,
      89,    90,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    93,    93,    93,    93,    94,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     6,     3,
       1,     3,     1,     3,     2,     0,     9,     0,     9,     0,
       1,     1,     3,     2,     3,     0,     4,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     3,     3,     3,     3,     1,     4,     1,     2,     5,
       7,     5,     7,     9,    10,     0,     1,     0,     1,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     0,
       1,     1,     3,     3,     4,     3,     4,     1,     1,     1,
       1,     1
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
  case 2: /* program: decl_list  */
#line 99 "src/p2_parser.y"
              {
        Symbol* mainFunc = symTab.lookup("main");
        if (mainFunc == nullptr) {
            throw SemanticError("missing main function", yylineno);
        }

        if (!mainFunc->type->isFunc()) {
            throw SemanticError("main function must be function", yylineno);
        }

        symTab.dbgPrintCurrentScope();
        printf("\nProgram end\n");
     }
#line 1416 "src/y.tab.cpp"
    break;

  case 8: /* const_decl: CONST type_spec ID ASSIGN expression SEMICOLON  */
#line 130 "src/p2_parser.y"
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

        delete (yyvsp[-3].sval);
        delete (yyvsp[-1].expr_info);
    }
#line 1445 "src/y.tab.cpp"
    break;

  case 9: /* var_decl: type_spec var_init_list SEMICOLON  */
#line 158 "src/p2_parser.y"
                                       {
        for (auto& var : *(yyvsp[-1].var_init_list)) {
            Symbol s("", nullptr, false);

            if (var->constType != nullptr) {
                if (*(yyvsp[-2].type) != *var->constType) {
                    throw SemanticError("var type mismatch", yylineno);
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
#line 1476 "src/y.tab.cpp"
    break;

  case 10: /* var_init_list: var_init  */
#line 187 "src/p2_parser.y"
             {
        (yyval.var_init_list) = new std::vector<varInit*>;
        (yyval.var_init_list)->push_back((yyvsp[0].var_init));}
#line 1484 "src/y.tab.cpp"
    break;

  case 11: /* var_init_list: var_init_list COMMA var_init  */
#line 190 "src/p2_parser.y"
                                  {
        (yyval.var_init_list) = (yyvsp[-2].var_init_list);
        (yyval.var_init_list)->push_back((yyvsp[0].var_init));
    }
#line 1493 "src/y.tab.cpp"
    break;

  case 12: /* var_init: ID  */
#line 197 "src/p2_parser.y"
                            { (yyval.var_init) = new varInit((yyvsp[0].sval)); }
#line 1499 "src/y.tab.cpp"
    break;

  case 13: /* var_init: ID ASSIGN expression  */
#line 198 "src/p2_parser.y"
                            {
        if ((yyvsp[0].expr_info)->type->isFunc()) {
            throw SemanticError("assignment from function", yylineno);
        }
        if ((yyvsp[0].expr_info)->type->isArray()) {
            throw SemanticError("assignment from array", yylineno);
        }

        (yyval.var_init) = new varInit((yyvsp[-2].sval), (yyvsp[0].expr_info)->type);
   }
#line 1514 "src/y.tab.cpp"
    break;

  case 14: /* var_init: ID array_dims  */
#line 208 "src/p2_parser.y"
                            { (yyval.var_init) = new varInit((yyvsp[-1].sval), (yyvsp[0].int_list)); }
#line 1520 "src/y.tab.cpp"
    break;

  case 15: /* $@1: %empty  */
#line 214 "src/p2_parser.y"
    {
        returnsExpr.clear();
        declareFunction(*(yyvsp[-4].sval), (yyvsp[-5].type), (yyvsp[-2].symbol_list), typePool, symTab, yylineno);
        delete (yyvsp[-4].sval);
    }
#line 1530 "src/y.tab.cpp"
    break;

  case 16: /* func_decl: type_spec ID LPAREN param_list_opt RPAREN LBRACE $@1 block_items_opt RBRACE  */
#line 220 "src/p2_parser.y"
    {
        if (returnsExpr.empty()) {
            throw SemanticError("missing return statement", yylineno);
        }

        for (auto& expr : returnsExpr) {
            if (expr.first.type != (yyvsp[-8].type)) {
                throw SemanticError("return type mismatch !", expr.second);
            }
        }
        symTab.leaveScope();
    }
#line 1547 "src/y.tab.cpp"
    break;

  case 17: /* $@2: %empty  */
#line 232 "src/p2_parser.y"
                                               {
        Type* voidType = typePool.make(BK_Void);
        returnsExpr.clear();
        declareFunction(*(yyvsp[-4].sval), voidType, (yyvsp[-2].symbol_list), typePool, symTab, yylineno);
        delete (yyvsp[-4].sval);
    }
#line 1558 "src/y.tab.cpp"
    break;

  case 18: /* func_decl: VOID ID LPAREN param_list_opt RPAREN LBRACE $@2 block_items_opt RBRACE  */
#line 239 "src/p2_parser.y"
    {

        symTab.leaveScope();
    }
#line 1567 "src/y.tab.cpp"
    break;

  case 19: /* param_list_opt: %empty  */
#line 246 "src/p2_parser.y"
                {
        (yyval.symbol_list) = new std::vector<Symbol*>();
    }
#line 1575 "src/y.tab.cpp"
    break;

  case 20: /* param_list_opt: param_list  */
#line 249 "src/p2_parser.y"
               {
        (yyval.symbol_list) = (yyvsp[0].symbol_list);
     }
#line 1583 "src/y.tab.cpp"
    break;

  case 21: /* param_list: param  */
#line 255 "src/p2_parser.y"
           {
        (yyval.symbol_list) = new std::vector<Symbol*>;
        (yyval.symbol_list)->push_back((yyvsp[0].symbol));
     }
#line 1592 "src/y.tab.cpp"
    break;

  case 22: /* param_list: param_list COMMA param  */
#line 259 "src/p2_parser.y"
                            {
        (yyval.symbol_list) = (yyvsp[-2].symbol_list);
        (yyval.symbol_list)->push_back((yyvsp[0].symbol));
     }
#line 1601 "src/y.tab.cpp"
    break;

  case 23: /* param: type_spec ID  */
#line 266 "src/p2_parser.y"
                  {
        (yyval.symbol) = new Symbol(*(yyvsp[0].sval), (yyvsp[-1].type), false);
        delete (yyvsp[0].sval);
     }
#line 1610 "src/y.tab.cpp"
    break;

  case 24: /* param: type_spec ID array_dims  */
#line 270 "src/p2_parser.y"
                            {
        (yyval.symbol) = new Symbol(*(yyvsp[-1].sval), typePool.makeArray((yyvsp[-2].type), *(yyvsp[0].int_list)), false);
        delete (yyvsp[-1].sval);
        delete (yyvsp[0].int_list);
     }
#line 1620 "src/y.tab.cpp"
    break;

  case 25: /* $@3: %empty  */
#line 279 "src/p2_parser.y"
            {
        symTab.enterScope();
     }
#line 1628 "src/y.tab.cpp"
    break;

  case 26: /* block: LBRACE $@3 block_items_opt RBRACE  */
#line 281 "src/p2_parser.y"
                             {
        symTab.leaveScope();
     }
#line 1636 "src/y.tab.cpp"
    break;

  case 42: /* simple_stmt: READ lvalue SEMICOLON  */
#line 315 "src/p2_parser.y"
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
#line 1653 "src/y.tab.cpp"
    break;

  case 43: /* simple_stmt: lvalue INC SEMICOLON  */
#line 327 "src/p2_parser.y"
                          {
        checkIncDecValid((yyvsp[-2].expr_info), "increment", yylineno);
     }
#line 1661 "src/y.tab.cpp"
    break;

  case 44: /* simple_stmt: lvalue DEC SEMICOLON  */
#line 330 "src/p2_parser.y"
                          {
        checkIncDecValid((yyvsp[-2].expr_info), "decrement", yylineno);
    }
#line 1669 "src/y.tab.cpp"
    break;

  case 46: /* assign_stmt: lvalue ASSIGN expression SEMICOLON  */
#line 337 "src/p2_parser.y"
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

        delete (yyvsp[-1].expr_info);
     }
#line 1699 "src/y.tab.cpp"
    break;

  case 47: /* lvalue: ID  */
#line 365 "src/p2_parser.y"
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
#line 1724 "src/y.tab.cpp"
    break;

  case 48: /* lvalue: ID array_ref  */
#line 385 "src/p2_parser.y"
                 {
        Symbol* symbol = symTab.lookup(*(yyvsp[-1].sval));
        if (symbol == nullptr) {
            throw SemanticError("undeclared identifier: " + *(yyvsp[-1].sval), yylineno);
        }

        if (!symbol->type->isArray()) {
            throw SemanticError("array index to non-array type: " + *(yyvsp[-1].sval), yylineno);
        }

        size_t given = (yyvsp[0].int_list)->size();
        size_t expected = static_cast<size_t>(symbol->type->dim);
        std::vector<int> dims = symbol->type->sizes;

        for (size_t i = 0; i < given; ++i) {
            int index = (*(yyvsp[0].int_list))[i];
            int defined = symbol->type->sizes[i];
            printf("array index: %d, defined: %d\n", index, defined);

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
        (yyval.expr_info)->type->dbgPrint();
        delete (yyvsp[0].int_list);
        delete (yyvsp[-1].sval);
    }
#line 1768 "src/y.tab.cpp"
    break;

  case 49: /* if_stmt: IF LPAREN expression RPAREN statement  */
#line 428 "src/p2_parser.y"
                                           {
        checkBoolExpr((yyvsp[-2].expr_info), "if", yylineno);
     }
#line 1776 "src/y.tab.cpp"
    break;

  case 50: /* if_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 431 "src/p2_parser.y"
                                                          {
        checkBoolExpr((yyvsp[-4].expr_info), "if", yylineno);
    }
#line 1784 "src/y.tab.cpp"
    break;

  case 51: /* loop_stmt: WHILE LPAREN expression RPAREN statement  */
#line 438 "src/p2_parser.y"
                                             { 
        checkBoolExpr((yyvsp[-2].expr_info), "while", yylineno); 
    }
#line 1792 "src/y.tab.cpp"
    break;

  case 52: /* loop_stmt: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 441 "src/p2_parser.y"
                                                           {
        checkBoolExpr((yyvsp[-2].expr_info), "do while", yylineno);
    }
#line 1800 "src/y.tab.cpp"
    break;

  case 53: /* loop_stmt: FOR LPAREN for_start_opt SEMICOLON expression SEMICOLON for_update_opt RPAREN statement  */
#line 444 "src/p2_parser.y"
                                                                                            {
        checkBoolExpr((yyvsp[-4].expr_info), "for", yylineno);
    }
#line 1808 "src/y.tab.cpp"
    break;

  case 54: /* loop_stmt: FOREACH LPAREN ID COLON expression DOT DOT expression RPAREN statement  */
#line 447 "src/p2_parser.y"
                                                                           {
        checkForeachRange((yyvsp[-5].expr_info), (yyvsp[-2].expr_info), yylineno);
        checkForeachIndex(symTab.lookup(*(yyvsp[-7].sval)), yylineno);
    }
#line 1817 "src/y.tab.cpp"
    break;

  case 59: /* for_update_opt: lvalue INC  */
#line 461 "src/p2_parser.y"
               {
        checkIncDecValid((yyvsp[-1].expr_info), "increment", yylineno);
    }
#line 1825 "src/y.tab.cpp"
    break;

  case 60: /* for_update_opt: lvalue DEC  */
#line 464 "src/p2_parser.y"
              {
        checkIncDecValid((yyvsp[-1].expr_info), "decrement", yylineno);
    }
#line 1833 "src/y.tab.cpp"
    break;

  case 61: /* assign_no_semi: lvalue ASSIGN expression  */
#line 470 "src/p2_parser.y"
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
    }
#line 1861 "src/y.tab.cpp"
    break;

  case 62: /* return_stmt: RETURN expression SEMICOLON  */
#line 497 "src/p2_parser.y"
                                 {
        returnsExpr.push_back(std::make_pair(*(yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 1870 "src/y.tab.cpp"
    break;

  case 63: /* expression: expression PLUS expression  */
#line 505 "src/p2_parser.y"
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
#line 1893 "src/y.tab.cpp"
    break;

  case 64: /* expression: expression MINUS expression  */
#line 523 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPSUB,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1899 "src/y.tab.cpp"
    break;

  case 65: /* expression: expression MUL expression  */
#line 524 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPMUL,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1905 "src/y.tab.cpp"
    break;

  case 66: /* expression: expression DIV expression  */
#line 525 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPDIV,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1911 "src/y.tab.cpp"
    break;

  case 67: /* expression: expression MOD expression  */
#line 526 "src/p2_parser.y"
                                  { (yyval.expr_info) = numericResult(OPMOD,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1917 "src/y.tab.cpp"
    break;

  case 68: /* expression: expression LT expression  */
#line 528 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPLT, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1923 "src/y.tab.cpp"
    break;

  case 69: /* expression: expression LE expression  */
#line 529 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPLE, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1929 "src/y.tab.cpp"
    break;

  case 70: /* expression: expression GT expression  */
#line 530 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPGT, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1935 "src/y.tab.cpp"
    break;

  case 71: /* expression: expression GE expression  */
#line 531 "src/p2_parser.y"
                                  { (yyval.expr_info) = relResult(OPGE, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1941 "src/y.tab.cpp"
    break;

  case 72: /* expression: expression EQ expression  */
#line 533 "src/p2_parser.y"
                                  { (yyval.expr_info) = eqResult(true,  (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1947 "src/y.tab.cpp"
    break;

  case 73: /* expression: expression NEQ expression  */
#line 534 "src/p2_parser.y"
                                  { (yyval.expr_info) = eqResult(false, (yyvsp[-2].expr_info),(yyvsp[0].expr_info),typePool,yylineno); }
#line 1953 "src/y.tab.cpp"
    break;

  case 74: /* expression: expression AND expression  */
#line 535 "src/p2_parser.y"
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
#line 1971 "src/y.tab.cpp"
    break;

  case 75: /* expression: expression OR expression  */
#line 548 "src/p2_parser.y"
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
#line 1989 "src/y.tab.cpp"
    break;

  case 76: /* expression: NOT expression  */
#line 561 "src/p2_parser.y"
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
#line 2006 "src/y.tab.cpp"
    break;

  case 77: /* expression: MINUS expression  */
#line 573 "src/p2_parser.y"
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
#line 2027 "src/y.tab.cpp"
    break;

  case 78: /* expression: PLUS expression  */
#line 589 "src/p2_parser.y"
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
#line 2049 "src/y.tab.cpp"
    break;

  case 79: /* expression: LPAREN expression RPAREN  */
#line 606 "src/p2_parser.y"
                                   { (yyval.expr_info) = (yyvsp[-1].expr_info); }
#line 2055 "src/y.tab.cpp"
    break;

  case 80: /* expression: lvalue  */
#line 607 "src/p2_parser.y"
                                   { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2061 "src/y.tab.cpp"
    break;

  case 81: /* expression: const_expr  */
#line 608 "src/p2_parser.y"
                                   { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2067 "src/y.tab.cpp"
    break;

  case 82: /* expression: func_call  */
#line 609 "src/p2_parser.y"
                                   { (yyval.expr_info) = (yyvsp[0].expr_info); }
#line 2073 "src/y.tab.cpp"
    break;

  case 83: /* const_expr: INT_LIT  */
#line 614 "src/p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Int), true);
        expr->setInt((yyvsp[0].ival));
        (yyval.expr_info) = expr;
    }
#line 2083 "src/y.tab.cpp"
    break;

  case 84: /* const_expr: REAL_LIT  */
#line 619 "src/p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Double), true);
        expr->setFloat((yyvsp[0].fval));
        (yyval.expr_info) = expr;
    }
#line 2093 "src/y.tab.cpp"
    break;

  case 85: /* const_expr: STRING_LIT  */
#line 624 "src/p2_parser.y"
                  { 
        ExprInfo* expr = new ExprInfo(typePool.make(BK_String), true);
        expr->setString(*(yyvsp[0].sval));
        (yyval.expr_info) = expr;
        delete (yyvsp[0].sval);
    }
#line 2104 "src/y.tab.cpp"
    break;

  case 86: /* const_expr: BOOL_LIT  */
#line 630 "src/p2_parser.y"
                  {
        ExprInfo* expr = new ExprInfo(typePool.make(BK_Bool), true);
        expr->setBool((yyvsp[0].bval));
        (yyval.expr_info) = expr;
    }
#line 2114 "src/y.tab.cpp"
    break;

  case 87: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 638 "src/p2_parser.y"
                                  {
        Symbol* symbol = symTab.lookup(*(yyvsp[-3].sval));
        checkFuncCall(symbol, *(yyvsp[-3].sval), (yyvsp[-1].expr_info_list), yylineno);
        (yyval.expr_info) = new ExprInfo(symbol->type->ret);
        delete (yyvsp[-3].sval);
    }
#line 2125 "src/y.tab.cpp"
    break;

  case 88: /* proc_call: ID LPAREN arg_list_opt RPAREN  */
#line 646 "src/p2_parser.y"
                                  {
        Symbol* symbol = symTab.lookup(*(yyvsp[-3].sval));
        checkFuncCall(symbol, *(yyvsp[-3].sval), (yyvsp[-1].expr_info_list), yylineno);
        delete (yyvsp[-3].sval);
    }
#line 2135 "src/y.tab.cpp"
    break;

  case 89: /* arg_list_opt: %empty  */
#line 653 "src/p2_parser.y"
               { 
        (yyval.expr_info_list) = new std::vector<ExprInfo*>();
    }
#line 2143 "src/y.tab.cpp"
    break;

  case 90: /* arg_list_opt: arg_list  */
#line 656 "src/p2_parser.y"
             { (yyval.expr_info_list) = (yyvsp[0].expr_info_list); }
#line 2149 "src/y.tab.cpp"
    break;

  case 91: /* arg_list: expression  */
#line 660 "src/p2_parser.y"
                {
        (yyval.expr_info_list) = new std::vector<ExprInfo*>;
        (yyval.expr_info_list)->push_back((yyvsp[0].expr_info));
     }
#line 2158 "src/y.tab.cpp"
    break;

  case 92: /* arg_list: arg_list COMMA expression  */
#line 664 "src/p2_parser.y"
                              {
        (yyval.expr_info_list) = (yyvsp[-2].expr_info_list);
        (yyval.expr_info_list)->push_back((yyvsp[0].expr_info));
  }
#line 2167 "src/y.tab.cpp"
    break;

  case 93: /* array_dims: LBRACK expression RBRACK  */
#line 672 "src/p2_parser.y"
                              {
        (yyval.int_list) = new std::vector<int>;
        (yyval.int_list)->push_back(checkArrayDimExpr((yyvsp[-1].expr_info), yylineno));
     }
#line 2176 "src/y.tab.cpp"
    break;

  case 94: /* array_dims: array_dims LBRACK expression RBRACK  */
#line 676 "src/p2_parser.y"
                                         {
        (yyval.int_list) = (yyvsp[-3].int_list);
        (yyval.int_list)->push_back(checkArrayDimExpr((yyvsp[-1].expr_info), yylineno));
     }
#line 2185 "src/y.tab.cpp"
    break;

  case 95: /* array_ref: LBRACK expression RBRACK  */
#line 683 "src/p2_parser.y"
                              {
        (yyval.int_list) = new std::vector<int>;
        (yyval.int_list)->push_back(extractArrayIndexOrZero((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 2195 "src/y.tab.cpp"
    break;

  case 96: /* array_ref: array_ref LBRACK expression RBRACK  */
#line 688 "src/p2_parser.y"
                                        {
        (yyval.int_list) = (yyvsp[-3].int_list);
        (yyval.int_list)->push_back(extractArrayIndexOrZero((yyvsp[-1].expr_info), yylineno));
        delete (yyvsp[-1].expr_info);
     }
#line 2205 "src/y.tab.cpp"
    break;

  case 97: /* type_spec: INT_TOK  */
#line 697 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Int);   }
#line 2211 "src/y.tab.cpp"
    break;

  case 98: /* type_spec: FLOAT  */
#line 698 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Float); }
#line 2217 "src/y.tab.cpp"
    break;

  case 99: /* type_spec: DOUBLE  */
#line 699 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Double); }
#line 2223 "src/y.tab.cpp"
    break;

  case 100: /* type_spec: BOOL  */
#line 700 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_Bool);  }
#line 2229 "src/y.tab.cpp"
    break;

  case 101: /* type_spec: STRING_TOK  */
#line 701 "src/p2_parser.y"
                 { (yyval.type) = typePool.make(BK_String);}
#line 2235 "src/y.tab.cpp"
    break;


#line 2239 "src/y.tab.cpp"

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

#line 704 "src/p2_parser.y"
 

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
