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
#line 1 "syntacticParser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dlfcn.h>
#include "../includes/lexicalAnalysis.yy.h"
#include "../includes/symbolsTable.h"
#include "../includes/errorHandler.h"

void openFile(char* fileName);

int areNumbers(double a, double b);

void printPrompt();

void comparisonFunction(double a, int op, double b);
double operationFunction(double a, int op, double b);
void assignmentFunction(char* a, int op, double b, double* result);
double functionFunction(char* a, double*b,double*c);

void IMPORTCommand(char* library, char* functionName);
void ECHOCommand();
void HELPCommand();

void yyerror(char* s);

int echoControler = 1;
int printPromptControler = 1;


#line 103 "./src/syntacticParser.tab.c"

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

#include "syntacticParser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_FILE_TO_READ = 4,               /* FILE_TO_READ  */
  YYSYMBOL_LIBRARY_FILE = 5,               /* LIBRARY_FILE  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_WORKSPACE = 7,                  /* WORKSPACE  */
  YYSYMBOL_CLEAN_WORKSPACE = 8,            /* CLEAN_WORKSPACE  */
  YYSYMBOL_CLEAN_VAR = 9,                  /* CLEAN_VAR  */
  YYSYMBOL_IMPORT = 10,                    /* IMPORT  */
  YYSYMBOL_LOAD = 11,                      /* LOAD  */
  YYSYMBOL_HELP = 12,                      /* HELP  */
  YYSYMBOL_CLEAR = 13,                     /* CLEAR  */
  YYSYMBOL_ECHOPRINT = 14,                 /* ECHOPRINT  */
  YYSYMBOL_END_OF_FILE = 15,               /* END_OF_FILE  */
  YYSYMBOL_ASSIGN_OPERATOR = 16,           /* ASSIGN_OPERATOR  */
  YYSYMBOL_ADD_ASSIGN_OPERATOR = 17,       /* ADD_ASSIGN_OPERATOR  */
  YYSYMBOL_SUB_ASSIGN_OPERATOR = 18,       /* SUB_ASSIGN_OPERATOR  */
  YYSYMBOL_MUL_ASSIGN_OPERATOR = 19,       /* MUL_ASSIGN_OPERATOR  */
  YYSYMBOL_DIV_ASSIGN_OPERATOR = 20,       /* DIV_ASSIGN_OPERATOR  */
  YYSYMBOL_ADD_ADD_OPERATOR = 21,          /* ADD_ADD_OPERATOR  */
  YYSYMBOL_SUB_SUB_OPERATOR = 22,          /* SUB_SUB_OPERATOR  */
  YYSYMBOL_GREATER_EQUAL_OPERATOR = 23,    /* GREATER_EQUAL_OPERATOR  */
  YYSYMBOL_LESS_EQUAL_OPERATOR = 24,       /* LESS_EQUAL_OPERATOR  */
  YYSYMBOL_EQUAL_EQUAL_OPERATOR = 25,      /* EQUAL_EQUAL_OPERATOR  */
  YYSYMBOL_NOT_EQUAL_OPERATOR = 26,        /* NOT_EQUAL_OPERATOR  */
  YYSYMBOL_27_ = 27,                       /* '^'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_n_ = 35,                     /* '\n'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_input = 41,                     /* input  */
  YYSYMBOL_line = 42,                      /* line  */
  YYSYMBOL_expression = 43,                /* expression  */
  YYSYMBOL_operation = 44,                 /* operation  */
  YYSYMBOL_comparison = 45,                /* comparison  */
  YYSYMBOL_assignment = 46,                /* assignment  */
  YYSYMBOL_function = 47,                  /* function  */
  YYSYMBOL_commands = 48                   /* commands  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  81

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
      35,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      37,    38,    30,    28,    39,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      33,     2,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    80,    84,    85,    86,    87,    88,    89,
      93,    95,    96,    98,    99,   101,   102,   103,   104,   105,
     109,   110,   111,   112,   113,   117,   118,   119,   120,   121,
     122,   126,   127,   128,   129,   130,   131,   132,   136,   137,
     138,   142,   143,   144,   145,   146,   147,   148,   149
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "FILE_TO_READ",
  "LIBRARY_FILE", "NUMBER", "WORKSPACE", "CLEAN_WORKSPACE", "CLEAN_VAR",
  "IMPORT", "LOAD", "HELP", "CLEAR", "ECHOPRINT", "END_OF_FILE",
  "ASSIGN_OPERATOR", "ADD_ASSIGN_OPERATOR", "SUB_ASSIGN_OPERATOR",
  "MUL_ASSIGN_OPERATOR", "DIV_ASSIGN_OPERATOR", "ADD_ADD_OPERATOR",
  "SUB_SUB_OPERATOR", "GREATER_EQUAL_OPERATOR", "LESS_EQUAL_OPERATOR",
  "EQUAL_EQUAL_OPERATOR", "NOT_EQUAL_OPERATOR", "'^'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'<'", "'>'", "'\\n'", "';'", "'('", "')'", "','",
  "$accept", "input", "line", "expression", "operation", "comparison",
  "assignment", "function", "commands", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,    39,   -34,   -33,   -12,   -34,   -34,   -34,     8,    12,
      14,   -34,   -34,   -34,   -34,    72,    72,   -34,    72,   -34,
      87,   -34,   -34,   -34,   -34,   -34,   -34,    72,    72,    72,
      72,    72,   -34,   -34,    72,   -34,    23,   -34,   -10,   -10,
     101,   -34,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,   -34,     6,   133,    28,    28,    28,
      28,    65,   -34,   -34,    28,    28,    28,    28,    28,   -10,
     -10,   -34,   -34,   -34,   -34,   -34,   -34,   -34,    72,   117,
     -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    14,    13,    41,    42,     0,     0,
       0,    44,    45,    48,     8,     0,     0,     4,     0,     3,
       0,    15,    16,    17,    18,    19,     9,     0,     0,     0,
       0,     0,    36,    37,     0,    43,     0,    46,    11,    12,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,    31,    32,    33,    34,
      35,     0,    47,    10,    25,    26,    27,    28,    40,    20,
      21,    22,    23,    24,    29,    30,     5,    38,     0,     0,
      39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   -15,   -34,   -34,   -34,   -34,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    19,    20,    21,    22,    23,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    39,    26,    40,    27,    28,    29,    30,    31,    32,
      33,    35,    56,    57,    58,    59,    60,    36,    37,    61,
      49,    50,    51,    52,    53,    34,    62,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     2,
       3,    76,     4,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    46,    47,    48,    49,    50,
      51,    52,    53,    79,     0,     0,     0,    15,    16,     0,
       0,     0,     0,     0,    17,     4,    18,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      15,    16,    41,    77,    78,     0,     0,     0,     0,    18,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,    63,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,    80,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53
};

static const yytype_int8 yycheck[] =
{
      15,    16,    35,    18,    16,    17,    18,    19,    20,    21,
      22,     3,    27,    28,    29,    30,    31,     5,     4,    34,
      30,    31,    32,    33,    34,    37,     3,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       1,    35,     3,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    27,    28,    29,    30,    31,
      32,    33,    34,    78,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    35,     3,    37,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      28,    29,    15,    38,    39,    -1,    -1,    -1,    -1,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,     0,     1,     3,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    28,    29,    35,    37,    42,
      43,    44,    45,    46,    47,    48,    35,    16,    17,    18,
      19,    20,    21,    22,    37,     3,     5,     4,    43,    43,
      43,    15,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    43,    43,    43,    43,
      43,    43,     3,    38,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    35,    38,    39,    43,
      38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    42,    42,    42,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    44,    44,    44,    44,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    46,    46,    46,    46,    47,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     3,     2,     2,     1,     2,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     4,     6,
       3,     1,     1,     2,     1,     1,     2,     3,     1
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
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 74 "syntacticParser.y"
            {free(((*yyvaluep).stringToken));}
#line 943 "./src/syntacticParser.tab.c"
        break;

    case YYSYMBOL_FILE_TO_READ: /* FILE_TO_READ  */
#line 74 "syntacticParser.y"
            {free(((*yyvaluep).stringToken));}
#line 949 "./src/syntacticParser.tab.c"
        break;

    case YYSYMBOL_LIBRARY_FILE: /* LIBRARY_FILE  */
#line 74 "syntacticParser.y"
            {free(((*yyvaluep).stringToken));}
#line 955 "./src/syntacticParser.tab.c"
        break;

      default:
        break;
    }
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
  case 2: /* input: %empty  */
#line 79 "syntacticParser.y"
    {printPrompt();}
#line 1225 "./src/syntacticParser.tab.c"
    break;

  case 4: /* line: '\n'  */
#line 84 "syntacticParser.y"
          {printPrompt();}
#line 1231 "./src/syntacticParser.tab.c"
    break;

  case 5: /* line: expression ';' '\n'  */
#line 85 "syntacticParser.y"
                          {printPrompt();}
#line 1237 "./src/syntacticParser.tab.c"
    break;

  case 6: /* line: expression '\n'  */
#line 86 "syntacticParser.y"
                      {if(echoControler && printPromptControler){if(!isnan((yyvsp[-1].numberToken))){printf("%.4lf\n",(yyvsp[-1].numberToken));}}printPrompt();}
#line 1243 "./src/syntacticParser.tab.c"
    break;

  case 7: /* line: expression END_OF_FILE  */
#line 87 "syntacticParser.y"
                             {printPromptControler = 1;printPrompt();}
#line 1249 "./src/syntacticParser.tab.c"
    break;

  case 8: /* line: END_OF_FILE  */
#line 88 "syntacticParser.y"
                  {printPromptControler = 1;printPrompt();}
#line 1255 "./src/syntacticParser.tab.c"
    break;

  case 9: /* line: error '\n'  */
#line 89 "syntacticParser.y"
                 {printPrompt();}
#line 1261 "./src/syntacticParser.tab.c"
    break;

  case 10: /* expression: '(' expression ')'  */
#line 93 "syntacticParser.y"
                       { (yyval.numberToken) = (yyvsp[-1].numberToken);}
#line 1267 "./src/syntacticParser.tab.c"
    break;

  case 11: /* expression: '+' expression  */
#line 95 "syntacticParser.y"
                     {(yyval.numberToken) = (yyvsp[0].numberToken);}
#line 1273 "./src/syntacticParser.tab.c"
    break;

  case 12: /* expression: '-' expression  */
#line 96 "syntacticParser.y"
                     {(yyval.numberToken) = -(yyvsp[0].numberToken);}
#line 1279 "./src/syntacticParser.tab.c"
    break;

  case 13: /* expression: NUMBER  */
#line 98 "syntacticParser.y"
             {(yyval.numberToken) = (yyvsp[0].numberToken);}
#line 1285 "./src/syntacticParser.tab.c"
    break;

  case 14: /* expression: ID  */
#line 99 "syntacticParser.y"
         {if(isSymbol((yyvsp[0].stringToken),ID_TABLE)|isSymbol((yyvsp[0].stringToken),CONST_TABLE)){(yyval.numberToken) = recoverSymbol((yyvsp[0].stringToken));}else if(isSymbol((yyvsp[0].stringToken),FUNCTION_TABLE)){errorFunctionParameter(yylineno);(yyval.numberToken) = NAN;}else{errorVariableNotDeclared(yylineno);(yyval.numberToken) = NAN;}free((yyvsp[0].stringToken));}
#line 1291 "./src/syntacticParser.tab.c"
    break;

  case 20: /* operation: expression '+' expression  */
#line 109 "syntacticParser.y"
                              {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){(yyval.numberToken) = operationFunction((yyvsp[-2].numberToken),'+',(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);(yyval.numberToken) = NAN;}}
#line 1297 "./src/syntacticParser.tab.c"
    break;

  case 21: /* operation: expression '-' expression  */
#line 110 "syntacticParser.y"
                                {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){(yyval.numberToken) = operationFunction((yyvsp[-2].numberToken),'-',(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);(yyval.numberToken) = NAN;}}
#line 1303 "./src/syntacticParser.tab.c"
    break;

  case 22: /* operation: expression '*' expression  */
#line 111 "syntacticParser.y"
                                {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){(yyval.numberToken) = operationFunction((yyvsp[-2].numberToken),'*',(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);(yyval.numberToken) = NAN;}}
#line 1309 "./src/syntacticParser.tab.c"
    break;

  case 23: /* operation: expression '/' expression  */
#line 112 "syntacticParser.y"
                                {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){(yyval.numberToken) = operationFunction((yyvsp[-2].numberToken),'/',(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);(yyval.numberToken) = NAN;}}
#line 1315 "./src/syntacticParser.tab.c"
    break;

  case 24: /* operation: expression '%' expression  */
#line 113 "syntacticParser.y"
                                {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){(yyval.numberToken) = operationFunction((yyvsp[-2].numberToken),'%',(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);(yyval.numberToken) = NAN;}}
#line 1321 "./src/syntacticParser.tab.c"
    break;

  case 25: /* comparison: expression GREATER_EQUAL_OPERATOR expression  */
#line 117 "syntacticParser.y"
                                                 {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){comparisonFunction((yyvsp[-2].numberToken),GREATER_EQUAL_OPERATOR,(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);}(yyval.numberToken) = NAN;}
#line 1327 "./src/syntacticParser.tab.c"
    break;

  case 26: /* comparison: expression LESS_EQUAL_OPERATOR expression  */
#line 118 "syntacticParser.y"
                                                {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){comparisonFunction((yyvsp[-2].numberToken),LESS_EQUAL_OPERATOR,(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);}(yyval.numberToken) = NAN;}
#line 1333 "./src/syntacticParser.tab.c"
    break;

  case 27: /* comparison: expression EQUAL_EQUAL_OPERATOR expression  */
#line 119 "syntacticParser.y"
                                                 {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){comparisonFunction((yyvsp[-2].numberToken),EQUAL_EQUAL_OPERATOR,(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);}(yyval.numberToken) = NAN;}
#line 1339 "./src/syntacticParser.tab.c"
    break;

  case 28: /* comparison: expression NOT_EQUAL_OPERATOR expression  */
#line 120 "syntacticParser.y"
                                               {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){comparisonFunction((yyvsp[-2].numberToken),NOT_EQUAL_OPERATOR,(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);}(yyval.numberToken) = NAN;}
#line 1345 "./src/syntacticParser.tab.c"
    break;

  case 29: /* comparison: expression '<' expression  */
#line 121 "syntacticParser.y"
                                {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){comparisonFunction((yyvsp[-2].numberToken),'<',(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);}(yyval.numberToken) = NAN;}
#line 1351 "./src/syntacticParser.tab.c"
    break;

  case 30: /* comparison: expression '>' expression  */
#line 122 "syntacticParser.y"
                                {if(areNumbers((yyvsp[-2].numberToken),(yyvsp[0].numberToken))){comparisonFunction((yyvsp[-2].numberToken),'>',(yyvsp[0].numberToken));}else{errorOperationNoNumbers(yylineno);}(yyval.numberToken) = NAN;}
#line 1357 "./src/syntacticParser.tab.c"
    break;

  case 31: /* assignment: ID ASSIGN_OPERATOR expression  */
#line 126 "syntacticParser.y"
                                   {assignmentFunction((yyvsp[-2].stringToken),ASSIGN_OPERATOR,(yyvsp[0].numberToken),&((yyval.numberToken)));free((yyvsp[-2].stringToken));}
#line 1363 "./src/syntacticParser.tab.c"
    break;

  case 32: /* assignment: ID ADD_ASSIGN_OPERATOR expression  */
#line 127 "syntacticParser.y"
                                        {assignmentFunction((yyvsp[-2].stringToken),ADD_ASSIGN_OPERATOR,(yyvsp[0].numberToken),&((yyval.numberToken)));free((yyvsp[-2].stringToken));}
#line 1369 "./src/syntacticParser.tab.c"
    break;

  case 33: /* assignment: ID SUB_ASSIGN_OPERATOR expression  */
#line 128 "syntacticParser.y"
                                        {assignmentFunction((yyvsp[-2].stringToken),SUB_ASSIGN_OPERATOR,(yyvsp[0].numberToken),&((yyval.numberToken)));free((yyvsp[-2].stringToken));}
#line 1375 "./src/syntacticParser.tab.c"
    break;

  case 34: /* assignment: ID MUL_ASSIGN_OPERATOR expression  */
#line 129 "syntacticParser.y"
                                        {assignmentFunction((yyvsp[-2].stringToken),MUL_ASSIGN_OPERATOR,(yyvsp[0].numberToken),&((yyval.numberToken)));free((yyvsp[-2].stringToken));}
#line 1381 "./src/syntacticParser.tab.c"
    break;

  case 35: /* assignment: ID DIV_ASSIGN_OPERATOR expression  */
#line 130 "syntacticParser.y"
                                        {assignmentFunction((yyvsp[-2].stringToken),DIV_ASSIGN_OPERATOR,(yyvsp[0].numberToken),&((yyval.numberToken)));free((yyvsp[-2].stringToken));}
#line 1387 "./src/syntacticParser.tab.c"
    break;

  case 36: /* assignment: ID ADD_ADD_OPERATOR  */
#line 131 "syntacticParser.y"
                          {assignmentFunction((yyvsp[-1].stringToken),ADD_ADD_OPERATOR,1,&((yyval.numberToken)));free((yyvsp[-1].stringToken));}
#line 1393 "./src/syntacticParser.tab.c"
    break;

  case 37: /* assignment: ID SUB_SUB_OPERATOR  */
#line 132 "syntacticParser.y"
                          {assignmentFunction((yyvsp[-1].stringToken),SUB_SUB_OPERATOR,-1,&((yyval.numberToken)));free((yyvsp[-1].stringToken));}
#line 1399 "./src/syntacticParser.tab.c"
    break;

  case 38: /* function: ID '(' expression ')'  */
#line 136 "syntacticParser.y"
                          {(yyval.numberToken) = functionFunction((yyvsp[-3].stringToken),&((yyvsp[-1].numberToken)),NULL);free((yyvsp[-3].stringToken));}
#line 1405 "./src/syntacticParser.tab.c"
    break;

  case 39: /* function: ID '(' expression ',' expression ')'  */
#line 137 "syntacticParser.y"
                                           {(yyval.numberToken) = functionFunction((yyvsp[-5].stringToken),&((yyvsp[-3].numberToken)),&((yyvsp[-1].numberToken)));free((yyvsp[-5].stringToken));}
#line 1411 "./src/syntacticParser.tab.c"
    break;

  case 40: /* function: expression '^' expression  */
#line 138 "syntacticParser.y"
                                {char*aux = (char*)malloc(sizeof(char)*2);aux[0] ='^';aux[1] ='\0';(yyval.numberToken) = functionFunction(aux,&((yyvsp[-2].numberToken)),&((yyvsp[0].numberToken)));free(aux);}
#line 1417 "./src/syntacticParser.tab.c"
    break;

  case 41: /* commands: WORKSPACE  */
#line 142 "syntacticParser.y"
              {printSymbolsTable(); (yyval.numberToken) = NAN;}
#line 1423 "./src/syntacticParser.tab.c"
    break;

  case 42: /* commands: CLEAN_WORKSPACE  */
#line 143 "syntacticParser.y"
                      {clearSymbolsTable(); (yyval.numberToken) = NAN;}
#line 1429 "./src/syntacticParser.tab.c"
    break;

  case 43: /* commands: CLEAN_VAR ID  */
#line 144 "syntacticParser.y"
                   {if(isSymbol((yyvsp[0].stringToken),ID_TABLE)){removeSymbol((yyvsp[0].stringToken));}else{errorCleaningVariable(yylineno);} (yyval.numberToken) = NAN;free((yyvsp[0].stringToken));}
#line 1435 "./src/syntacticParser.tab.c"
    break;

  case 44: /* commands: HELP  */
#line 145 "syntacticParser.y"
           {HELPCommand(); (yyval.numberToken) = NAN;}
#line 1441 "./src/syntacticParser.tab.c"
    break;

  case 45: /* commands: CLEAR  */
#line 146 "syntacticParser.y"
            {system("clear"); (yyval.numberToken) = NAN;}
#line 1447 "./src/syntacticParser.tab.c"
    break;

  case 46: /* commands: LOAD FILE_TO_READ  */
#line 147 "syntacticParser.y"
                        {if(printPromptControler)printf("Loading %s ...\n\n\n",(yyvsp[0].stringToken)); openFile((yyvsp[0].stringToken)); (yyval.numberToken) = NAN;free((yyvsp[0].stringToken)); printPromptControler = 0;}
#line 1453 "./src/syntacticParser.tab.c"
    break;

  case 47: /* commands: IMPORT LIBRARY_FILE ID  */
#line 148 "syntacticParser.y"
                             {IMPORTCommand((yyvsp[-1].stringToken),(yyvsp[0].stringToken)); (yyval.numberToken) = NAN;free((yyvsp[-1].stringToken));free((yyvsp[0].stringToken));}
#line 1459 "./src/syntacticParser.tab.c"
    break;

  case 48: /* commands: ECHOPRINT  */
#line 149 "syntacticParser.y"
                {ECHOCommand(); (yyval.numberToken) = NAN;}
#line 1465 "./src/syntacticParser.tab.c"
    break;


#line 1469 "./src/syntacticParser.tab.c"

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

#line 150 "syntacticParser.y"


int areNumbers(double a, double b){
    if(isnan(a) || isnan(b)){
        return 0;
    }
    return 1;
}

void comparisonFunction(double a,int op,double b){
    int aux = 0;
    switch(op){
        case '>':
            if(a>b){aux = 1;break;}
            break;

        case '<':
            if(a<b){aux = 1;break;}
            break;

        case GREATER_EQUAL_OPERATOR:
            if(a>=b){aux = 1;break;}
            break;

        case LESS_EQUAL_OPERATOR:
            if(a<=b){aux = 1;break;}
            break;

        case EQUAL_EQUAL_OPERATOR:
            if(a==b){aux = 1;break;}
            break;

        case NOT_EQUAL_OPERATOR:
            if(a!=b){aux = 1;break;}
            break;

        default:
            errorInvalidOperator(yylineno);
            break;
    }

    if(echoControler){
        if(aux){
            printf("True\n");
            return;
        }
        printf("False\n");
        return;
    }

}

double operationFunction(double a,int op,double b){
    switch(op){
        case '+':
            return a+b;

        case '-':
            return a-b;

        case '*':
            return a*b;

        case '/':
            return a/b;

        case '%':
            return (int)a%(int)b;

        default:
            errorInvalidOperator(yylineno);
            return NAN;
    }
}

void assignmentFunction(char* a,int op,double b,double* result){
    if(isSymbol(a,CONST_TABLE)||isSymbol(a,FUNCTION_TABLE)){
        errorCantAssign(yylineno);
        *result = NAN;
        return;
    }
    if(op != ASSIGN_OPERATOR && !isSymbol(a,ID_TABLE)){
        errorVariableNotDeclared(yylineno);
        *result = NAN;
        return;
    }

    if(!areNumbers(b,b)){
        errorOperationNoNumbers(yylineno);
        *result = NAN;
        return;
    }

    switch(op){
        case ASSIGN_OPERATOR:
            insertSymbol(a,ID_TABLE,b,NULL);
            *result = b;

            return;

        case ADD_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)+b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case SUB_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)-b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case MUL_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)*b;
            insertSymbol(a,ID_TABLE,*result,NULL);
            
            return;

        case DIV_ASSIGN_OPERATOR:
            *result = recoverSymbol(a)/b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case ADD_ADD_OPERATOR:
            *result = recoverSymbol(a)+b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        case SUB_SUB_OPERATOR:
            *result = recoverSymbol(a)-b;
            insertSymbol(a,ID_TABLE,*result,NULL);

            return;

        default:
            errorInvalidOperator(yylineno);
            *result = NAN;
            return;
    }
}

double functionFunction(char* a,double* b,double* c){
    if(!isSymbol(a,FUNCTION_TABLE)){
        errorFunctionNotImported(yylineno);
        return NAN;
    }

    return callFunction(a, b, c);
}

void printPrompt(){
    if(printPromptControler){
        printf(">>>DPV>>>");
        yylineno = -1;
    }
        
}

void IMPORTCommand(char* library, char* functionName){
    printf("Importing %s from %s...\n",functionName,library);

    void *handle = dlopen(library, RTLD_LAZY);
    if (!handle) errorCannotImportLibrary(library,yylineno);
    
    double (*function) (double) = dlsym(handle, functionName);
    if (!function) errorCannotImportFunction(functionName,yylineno);

    insertSymbol(functionName,FUNCTION_TABLE,NAN,function);
}

void ECHOCommand(char* s){
    echoControler = (echoControler+1) % 2;
    if(echoControler){
        printf("Echo is ON\n");
    }else{
        printf("Echo is OFF\n");
    }
}

void HELPCommand(){
    printf(">>>DPV>>>Help:\n");
    printf(">>>DPV>>>This is a simple calculator that can do basic operations and comparisons.\n");
    printf(">>>DPV>>>You can assign values to variables and use them in the future.\n");
    printf(">>>DPV>>>You can use functions, at the start you can only use ^. To add more use import command.\n");
    printf(">>>DPV>>>You can use the following commands:\n");
    printf(">>>DPV>>>   echo: Turn on/off the echo.\n");
    printf(">>>DPV>>>   load <file.dpv>: Load a file.\n");
    printf(">>>DPV>>>   import <library.so> <function>: Import a function from a library.(Ex:import libm.so.6 cos).\n");
    printf(">>>DPV>>>   workspace: Print the current workspace.\n");
    printf(">>>DPV>>>   clean workspace: Clean the current workspace.\n");
    printf(">>>DPV>>>   clean <var>: Clean a variable.\n");
    printf(">>>DPV>>>   clear: Clear the screen.\n");
    printf(">>>DPV>>>   help: Print this help.\n");
    printf(">>>DPV>>>   exit: Exit the program.\n");
}

void yyerror(char* s){
    if(yylineno == 0 || yylineno == -1){
        printf("Error on command line: %s\n",s);
        return;
    }
    printf("Error on line %d: %s\n",yylineno,s);
}





