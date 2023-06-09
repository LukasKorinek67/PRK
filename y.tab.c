/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     BINARY = 259,
     HEXA = 260,
     ARRAY_START = 261,
     ARRAY_END = 262,
     PLUS = 263,
     MPY = 264,
     TILDE = 265,
     L_BR = 266,
     R_BR = 267,
     RAND = 268,
     SEPARATOR = 269,
     INT_TYPE = 270,
     BIN_TYPE = 271,
     HEX_TYPE = 272,
     LINE_END = 273
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define BINARY 259
#define HEXA 260
#define ARRAY_START 261
#define ARRAY_END 262
#define PLUS 263
#define MPY 264
#define TILDE 265
#define L_BR 266
#define R_BR 267
#define RAND 268
#define SEPARATOR 269
#define INT_TYPE 270
#define BIN_TYPE 271
#define HEX_TYPE 272
#define LINE_END 273




/* Copy the first part of user declarations.  */
#line 1 "my_language.y"

/* Original EBNF

MyLang ::= expression

expression ::= term,expression2
expression2 ::= "+",term,expression2 
expression2 ::= ""
term ::= term2,term3
term2 ::= factor,operation
term3 ::= "*", term, term3
term3 ::= ""
operation ::= "~",factor,operation
operation ::= ""

term2 ::= "*",factor,term2
term2 ::= term3
term2 ::= ""
term3 ::= "~",factor,term3
term3 ::= ""
factor ::= "("expression")"
factor ::= integer
factor ::= binary
factor ::= hexa
factor ::= array
factor ::= rand

digits ::={"0","1","2","3","4","5","6","7","8","9"}
integer ::= digits+
binary ::= "b",("0"|"1")+
hexa ::= "0x",hexdigits+
hexdigits ::= {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","A","B","C","D","E","F"}
array ::= "[",arrayNumbers,"]"
arrayNumbers ::= integerArray
arrayNumbers ::= binaryArray
arrayNumbers ::= hexaArray
integerArray ::= integer
integerArray ::= integerArray,separator,integer
binaryArray ::= binary
binaryArray ::= binaryArray,separator,binary
hexaArray ::= hexa
hexaArray ::= hexaArray,separator,hexa
separator = ","

rand ::= "rand(",rand_arguments,")"
rand_arguments ::= ""
rand_arguments ::= data_type
rand_arguments ::= integer,separator,integer
rand_arguments ::= integer,separator,integer,separator,data_type
rand_arguments ::= integer
rand_arguments ::= integer,separator,data_type
rand_arguments ::= integer,separator,integer,separator,integer
rand_arguments ::= integer,separator,integer,separator,integer,separator,data_type

data_type ::= "int"
data_type ::= "bin"
data_type ::= "hex"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int yylex();
void yyerror(const char *s);
extern int yylineno;

char* intToBinary(int n);
char* intToHexa(int n);
struct Number plusOperation(struct Number firstNumber, struct Number secondNumber);
struct Number multiplyOperation(struct Number firstNumber, struct Number secondNumber);
struct Number tildeOperation(struct Number firstNumber, struct Number secondNumber);
int* sumTwoArrays(int *firstArray, int *secondArray, int size);
int* sumNumWithArray(int number, int *array, int size);
int* multiplyTwoArrays(int *firstArray, int *secondArray, int size);
int* multiplyNumWithArray(int number, int *array, int size);
int* tildeTwoArrays(int *firstArray, int *secondArray, int size);
int* tildeNumWithArray(int number, int *array, int size);
char* getNumberType(char* firstType, char* secondType);
int generateRandomNumber();
int generateRandomNumberWithBounds(int min, int max);
int* generateRandomArray(int n);
int* generateRandomArrayWithBounds(int n, int min, int max);
int* addNumberToArray(int number, int *arrayNumbers, int arraySize);
void printResult(struct Number number);
void printNumber(int value, char* numberType);
void printArray(int *arrayNumbers, int arraySize, char* numberType);
void printArrayInt(int *arrayNumbers, int arraySize);
void printArrayBin(int *arrayNumbers, int arraySize);
void printArrayHexa(int *arrayNumbers, int arraySize);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 96 "my_language.y"
{
  struct Number {
    char* type;
    int value;
    int isArray;
    int arraySize;
    int *arrayNumbers;
  } number;
  int integer;
}
/* Line 193 of yacc.c.  */
#line 238 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 251 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   59

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNRULES -- Number of states.  */
#define YYNSTATES  61

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      15,    16,    17,    18
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    13,    17,    18,    21,    24,
      28,    29,    33,    34,    38,    40,    42,    44,    46,    48,
      52,    54,    56,    58,    60,    64,    66,    70,    72,    76,
      80,    82,    86,    92,    94,    98,   104,   112,   113,   115,
     117
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      20,     0,    -1,    20,    21,    18,    -1,    21,    18,    -1,
      23,    22,    -1,     8,    23,    22,    -1,    -1,    24,    25,
      -1,    27,    26,    -1,     9,    23,    25,    -1,    -1,    10,
      27,    26,    -1,    -1,    11,    21,    12,    -1,     3,    -1,
       4,    -1,     5,    -1,    28,    -1,    33,    -1,     6,    29,
       7,    -1,    30,    -1,    31,    -1,    32,    -1,     3,    -1,
      30,    14,     3,    -1,     4,    -1,    31,    14,     4,    -1,
       5,    -1,    32,    14,     5,    -1,    13,    34,    12,    -1,
      35,    -1,     3,    14,     3,    -1,     3,    14,     3,    14,
      35,    -1,     3,    -1,     3,    14,    35,    -1,     3,    14,
       3,    14,     3,    -1,     3,    14,     3,    14,     3,    14,
      35,    -1,    -1,    15,    -1,    16,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   133,   140,   146,   150,   159,   165,   171,
     175,   184,   188,   197,   201,   208,   215,   222,   225,   231,
     237,   243,   251,   262,   280,   291,   309,   320,   338,   349,
     355,   365,   373,   383,   394,   405,   416,   427,   437,   440,
     443
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "BINARY", "HEXA",
  "ARRAY_START", "ARRAY_END", "PLUS", "MPY", "TILDE", "L_BR", "R_BR",
  "RAND", "SEPARATOR", "INT_TYPE", "BIN_TYPE", "HEX_TYPE", "LINE_END",
  "$accept", "MyLang", "expression", "expression2", "term", "term2",
  "term3", "operation", "factor", "array", "arrayNumbers", "integerArray",
  "binaryArray", "hexaArray", "random", "rand_args", "data_type", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    19,    20,    20,    21,    22,    22,    23,    24,    25,
      25,    26,    26,    27,    27,    27,    27,    27,    27,    28,
      29,    29,    29,    30,    30,    31,    31,    32,    32,    33,
      34,    34,    34,    34,    34,    34,    34,    34,    35,    35,
      35
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     3,     0,     2,     2,     3,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     5,     1,     3,     5,     7,     0,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,    15,    16,     0,     0,    37,     0,     0,     6,
      10,    12,    17,    18,    23,    25,    27,     0,    20,    21,
      22,     0,    33,    38,    39,    40,     0,    30,     1,     0,
       3,     0,     4,     0,     7,     0,     8,    19,     0,     0,
       0,    13,     0,    29,     2,     6,    10,    12,    24,    26,
      28,    31,    34,     5,     9,    11,     0,    35,    32,     0,
      36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,    32,     9,    10,    34,    36,    11,    12,
      17,    18,    19,    20,    13,    26,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int8 yypact[] =
{
      31,   -43,   -43,   -43,    -2,    31,     3,    27,   -14,     5,
       2,    18,   -43,   -43,   -43,   -43,   -43,     8,    15,    25,
      29,     4,    34,   -43,   -43,   -43,    37,   -43,   -43,    23,
     -43,    31,   -43,    31,   -43,    31,   -43,   -43,    47,    48,
      46,   -43,     6,   -43,   -43,     5,     2,    18,   -43,   -43,
     -43,    39,   -43,   -43,   -43,   -43,     9,    40,   -43,    30,
     -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,     0,    10,   -23,   -43,    11,    12,    21,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    14,    15,    16,    30,    21,    22,    29,    45,    51,
      46,    33,    57,    31,    58,    37,    41,    60,    23,    24,
      25,    23,    24,    25,    23,    24,    25,    28,    35,    38,
       1,     2,     3,     4,     1,     2,     3,     4,     5,    39,
       6,    44,     5,    40,     6,    23,    24,    25,    42,    43,
      48,    50,    49,    56,    59,    53,    47,    54,     0,    55
};

static const yytype_int8 yycheck[] =
{
      42,     3,     4,     5,    18,     5,     3,     7,    31,     3,
      33,     9,     3,     8,    56,     7,    12,    59,    15,    16,
      17,    15,    16,    17,    15,    16,    17,     0,    10,    14,
       3,     4,     5,     6,     3,     4,     5,     6,    11,    14,
      13,    18,    11,    14,    13,    15,    16,    17,    14,    12,
       3,     5,     4,    14,    14,    45,    35,    46,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    11,    13,    20,    21,    23,
      24,    27,    28,    33,     3,     4,     5,    29,    30,    31,
      32,    21,     3,    15,    16,    17,    34,    35,     0,    21,
      18,     8,    22,     9,    25,    10,    26,     7,    14,    14,
      14,    12,    14,    12,    18,    23,    23,    27,     3,     4,
       5,     3,    35,    22,    25,    26,    14,     3,    35,    14,
      35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 129 "my_language.y"
    {
        printResult((yyvsp[(2) - (3)].number));
        printf("---------------- OK ----------------\n");
    }
    break;

  case 3:
#line 133 "my_language.y"
    {
        printResult((yyvsp[(1) - (2)].number));
        printf("---------------- OK ----------------\n");
    }
    break;

  case 4:
#line 140 "my_language.y"
    {
        (yyval.number) = plusOperation((yyvsp[(1) - (2)].number), (yyvsp[(2) - (2)].number));
    }
    break;

  case 5:
#line 146 "my_language.y"
    {
        printf("Operator +\n");
        (yyval.number) = plusOperation((yyvsp[(2) - (3)].number), (yyvsp[(3) - (3)].number));
    }
    break;

  case 6:
#line 150 "my_language.y"
    {
        (yyval.number).type = "none";
        (yyval.number).value = 0;
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
    }
    break;

  case 7:
#line 159 "my_language.y"
    {
        (yyval.number) = multiplyOperation((yyvsp[(1) - (2)].number), (yyvsp[(2) - (2)].number));
    }
    break;

  case 8:
#line 165 "my_language.y"
    {
        (yyval.number) = tildeOperation((yyvsp[(1) - (2)].number), (yyvsp[(2) - (2)].number));
    }
    break;

  case 9:
#line 171 "my_language.y"
    {
        printf("Operator * \n");
        (yyval.number) = multiplyOperation((yyvsp[(2) - (3)].number), (yyvsp[(3) - (3)].number));
    }
    break;

  case 10:
#line 175 "my_language.y"
    {
        (yyval.number).type = "none";
        (yyval.number).value = 0;
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
    }
    break;

  case 11:
#line 184 "my_language.y"
    {
        printf("Operator ~ \n");
        (yyval.number) = tildeOperation((yyvsp[(2) - (3)].number), (yyvsp[(3) - (3)].number));
    }
    break;

  case 12:
#line 188 "my_language.y"
    {
        (yyval.number).type = "none";
        (yyval.number).value = 0;
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
    }
    break;

  case 13:
#line 197 "my_language.y"
    {
        printf("Závorky\n");
        (yyval.number) = (yyvsp[(2) - (3)].number);
    }
    break;

  case 14:
#line 201 "my_language.y"
    {
        printf("INTEGER (%d)\n", (yyvsp[(1) - (1)].integer));
        (yyval.number).type = "int";
        (yyval.number).value = (yyvsp[(1) - (1)].integer);
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
    }
    break;

  case 15:
#line 208 "my_language.y"
    {
        printf("BINARY (%s) -> int hodnota %d\n", intToBinary((yyvsp[(1) - (1)].integer)), (yyvsp[(1) - (1)].integer));
        (yyval.number).type = "bin";
        (yyval.number).value = (yyvsp[(1) - (1)].integer);
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
    }
    break;

  case 16:
#line 215 "my_language.y"
    {
        printf("HEXA (%s) -> int hodnota %d\n", intToHexa((yyvsp[(1) - (1)].integer)), (yyvsp[(1) - (1)].integer));
        (yyval.number).type = "hex";
        (yyval.number).value = (yyvsp[(1) - (1)].integer);
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
    }
    break;

  case 17:
#line 222 "my_language.y"
    {
        (yyval.number)=(yyvsp[(1) - (1)].number);
    }
    break;

  case 18:
#line 225 "my_language.y"
    {
        (yyval.number)=(yyvsp[(1) - (1)].number);
    }
    break;

  case 19:
#line 231 "my_language.y"
    {
        (yyval.number) = (yyvsp[(2) - (3)].number);
    }
    break;

  case 20:
#line 237 "my_language.y"
    {
        printf("INT array ");
        printArrayInt((yyvsp[(1) - (1)].number).arrayNumbers, (yyvsp[(1) - (1)].number).arraySize);
        printf("\n");
        (yyval.number) = (yyvsp[(1) - (1)].number);
    }
    break;

  case 21:
#line 243 "my_language.y"
    {
        printf("BIN array ");
        printArrayBin((yyvsp[(1) - (1)].number).arrayNumbers, (yyvsp[(1) - (1)].number).arraySize);
        printf(" -> int hodnoty ");
        printArrayInt((yyvsp[(1) - (1)].number).arrayNumbers, (yyvsp[(1) - (1)].number).arraySize);
        printf("\n");
        (yyval.number) = (yyvsp[(1) - (1)].number);
    }
    break;

  case 22:
#line 251 "my_language.y"
    {
        printf("HEX array ");
        printArrayHexa((yyvsp[(1) - (1)].number).arrayNumbers, (yyvsp[(1) - (1)].number).arraySize);
        printf(" -> int hodnoty ");
        printArrayInt((yyvsp[(1) - (1)].number).arrayNumbers, (yyvsp[(1) - (1)].number).arraySize);
        printf("\n");
        (yyval.number) = (yyvsp[(1) - (1)].number);
    }
    break;

  case 23:
#line 262 "my_language.y"
    {
        if (((yyval.number).isArray == 0) && ((yyval.number).arraySize == 0)) {
            (yyval.number).type = "int";
            (yyval.number).value = 0;
            (yyval.number).isArray = 1;
            (yyval.number).arraySize = 1;
            int* array = malloc(1 * sizeof(int));
            array[0] = (yyvsp[(1) - (1)].integer);
            (yyval.number).arrayNumbers = array;
        } else {
            (yyval.number).type = "int";
            (yyval.number).value = 0;
            (yyval.number).isArray = 1;
            int lastSize = (yyval.number).arraySize;
            (yyval.number).arraySize = lastSize + 1;
            (yyval.number).arrayNumbers = addNumberToArray((yyvsp[(1) - (1)].integer), (yyval.number).arrayNumbers, lastSize);
        }
    }
    break;

  case 24:
#line 280 "my_language.y"
    {
        (yyval.number).type = "int";
        (yyval.number).value = 0;
        (yyval.number).isArray = 1;
        int lastSize = (yyval.number).arraySize;
        (yyval.number).arraySize = lastSize + 1;
        (yyval.number).arrayNumbers = addNumberToArray((yyvsp[(3) - (3)].integer), (yyval.number).arrayNumbers, lastSize);
    }
    break;

  case 25:
#line 291 "my_language.y"
    {
        if (((yyval.number).isArray == 0) && ((yyval.number).arraySize == 0)) {
            (yyval.number).type = "bin";
            (yyval.number).value = 0;
            (yyval.number).isArray = 1;
            (yyval.number).arraySize = 1;
            int* array = malloc(1 * sizeof(int));
            array[0] = (yyvsp[(1) - (1)].integer);
            (yyval.number).arrayNumbers = array;
        } else {
            (yyval.number).type = "bin";
            (yyval.number).value = 0;
            (yyval.number).isArray = 1;
            int lastSize = (yyval.number).arraySize;
            (yyval.number).arraySize = lastSize + 1;
            (yyval.number).arrayNumbers = addNumberToArray((yyvsp[(1) - (1)].integer), (yyval.number).arrayNumbers, lastSize);
        }
    }
    break;

  case 26:
#line 309 "my_language.y"
    {
        (yyval.number).type = "bin";
        (yyval.number).value = 0;
        (yyval.number).isArray = 1;
        int lastSize = (yyval.number).arraySize;
        (yyval.number).arraySize = lastSize + 1;
        (yyval.number).arrayNumbers = addNumberToArray((yyvsp[(3) - (3)].integer), (yyval.number).arrayNumbers, lastSize);
    }
    break;

  case 27:
#line 320 "my_language.y"
    {
        if (((yyval.number).isArray == 0) && ((yyval.number).arraySize == 0)) {
            (yyval.number).type = "hex";
            (yyval.number).value = 0;
            (yyval.number).isArray = 1;
            (yyval.number).arraySize = 1;
            int* array = malloc(1 * sizeof(int));
            array[0] = (yyvsp[(1) - (1)].integer);
            (yyval.number).arrayNumbers = array;
        } else {
            (yyval.number).type = "hex";
            (yyval.number).value = 0;
            (yyval.number).isArray = 1;
            int lastSize = (yyval.number).arraySize;
            (yyval.number).arraySize = lastSize + 1;
            (yyval.number).arrayNumbers = addNumberToArray((yyvsp[(1) - (1)].integer), (yyval.number).arrayNumbers, lastSize);
        }
    }
    break;

  case 28:
#line 338 "my_language.y"
    {
        (yyval.number).type = "hex";
        (yyval.number).value = 0;
        (yyval.number).isArray = 1;
        int lastSize = (yyval.number).arraySize;
        (yyval.number).arraySize = lastSize + 1;
        (yyval.number).arrayNumbers = addNumberToArray((yyvsp[(3) - (3)].integer), (yyval.number).arrayNumbers, lastSize);
    }
    break;

  case 29:
#line 349 "my_language.y"
    {
        (yyval.number) = (yyvsp[(2) - (3)].number);
    }
    break;

  case 30:
#line 355 "my_language.y"
    {
        (yyval.number).type = (yyvsp[(1) - (1)].number).type;
        (yyval.number).value = generateRandomNumber();
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
        printf("rand(type)\n");
        printf("rand(%s) -> number ", (yyvsp[(1) - (1)].number).type);
        printNumber((yyval.number).value, (yyval.number).type);
        printf("\n");
    }
    break;

  case 31:
#line 365 "my_language.y"
    {
        (yyval.number).type = "int";
        (yyval.number).value = generateRandomNumberWithBounds((yyvsp[(1) - (3)].integer), (yyvsp[(3) - (3)].integer));
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
        printf("rand(x,y)\n");
        printf("rand(%d,%d) -> number %d\n", (yyvsp[(1) - (3)].integer), (yyvsp[(3) - (3)].integer), (yyval.number).value);
    }
    break;

  case 32:
#line 373 "my_language.y"
    {
        (yyval.number).type = (yyvsp[(5) - (5)].number).type;
        (yyval.number).value = generateRandomNumberWithBounds((yyvsp[(1) - (5)].integer), (yyvsp[(3) - (5)].integer));
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
        printf("rand(x,y,type)\n");
        printf("rand(%d,%d,%s) -> number ", (yyvsp[(1) - (5)].integer), (yyvsp[(3) - (5)].integer), (yyvsp[(5) - (5)].number).type);
        printNumber((yyval.number).value, (yyval.number).type);
        printf("\n");
    }
    break;

  case 33:
#line 383 "my_language.y"
    {
        (yyval.number).type = "int";
        (yyval.number).value = 0;
        (yyval.number).isArray = 1;
        (yyval.number).arraySize = (yyvsp[(1) - (1)].integer);
        (yyval.number).arrayNumbers = generateRandomArray((yyvsp[(1) - (1)].integer));
        printf("rand(n)\n");
        printf("rand(%d) -> array ", (yyvsp[(1) - (1)].integer));
        printArray((yyval.number).arrayNumbers, (yyval.number).arraySize, (yyval.number).type);
        printf("\n");
    }
    break;

  case 34:
#line 394 "my_language.y"
    {
        (yyval.number).type = (yyvsp[(3) - (3)].number).type;
        (yyval.number).value = 0;
        (yyval.number).isArray = 1;
        (yyval.number).arraySize = (yyvsp[(1) - (3)].integer);
        (yyval.number).arrayNumbers = generateRandomArray((yyvsp[(1) - (3)].integer));
        printf("rand(n,type)\n");
        printf("rand(%d,%s) -> array ", (yyvsp[(1) - (3)].integer), (yyvsp[(3) - (3)].number).type);
        printArray((yyval.number).arrayNumbers, (yyval.number).arraySize, (yyval.number).type);
        printf("\n");
    }
    break;

  case 35:
#line 405 "my_language.y"
    {
        (yyval.number).type = "int";
        (yyval.number).value = 0;
        (yyval.number).isArray = 1;
        (yyval.number).arraySize = (yyvsp[(5) - (5)].integer);
        (yyval.number).arrayNumbers = generateRandomArrayWithBounds((yyvsp[(5) - (5)].integer), (yyvsp[(1) - (5)].integer), (yyvsp[(3) - (5)].integer));
        printf("rand(x,y,n)\n");
        printf("rand(%d,%d,%d) -> array ", (yyvsp[(1) - (5)].integer), (yyvsp[(3) - (5)].integer), (yyvsp[(5) - (5)].integer));
        printArray((yyval.number).arrayNumbers, (yyval.number).arraySize, (yyval.number).type);
        printf("\n");
    }
    break;

  case 36:
#line 416 "my_language.y"
    {
        (yyval.number).type = (yyvsp[(7) - (7)].number).type;
        (yyval.number).value = 0;
        (yyval.number).isArray = 1;
        (yyval.number).arraySize = (yyvsp[(5) - (7)].integer);
        (yyval.number).arrayNumbers = generateRandomArrayWithBounds((yyvsp[(5) - (7)].integer), (yyvsp[(1) - (7)].integer), (yyvsp[(3) - (7)].integer));
        printf("rand(x,y,n,type)\n");
        printf("rand(%d,%d,%d,%s) -> array ", (yyvsp[(1) - (7)].integer), (yyvsp[(3) - (7)].integer), (yyvsp[(5) - (7)].integer), (yyvsp[(7) - (7)].number).type);
        printArray((yyval.number).arrayNumbers, (yyval.number).arraySize, (yyval.number).type);
        printf("\n");
    }
    break;

  case 37:
#line 427 "my_language.y"
    {
        (yyval.number).type = "int";
        (yyval.number).value = generateRandomNumber();
        (yyval.number).isArray = 0;
        (yyval.number).arraySize = 0;
        printf("rand() -> number %d\n", (yyval.number).value);
    }
    break;

  case 38:
#line 437 "my_language.y"
    {
        (yyval.number).type = "int";
    }
    break;

  case 39:
#line 440 "my_language.y"
    {
        (yyval.number).type = "bin";
    }
    break;

  case 40:
#line 443 "my_language.y"
    {
        (yyval.number).type = "hex";
    }
    break;


/* Line 1267 of yacc.c.  */
#line 1922 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 447 "my_language.y"



void yyerror(const char* s) {   
    printf("%s\n",s);
}

int main(){
    // yydebug = 1;
    yyparse();
}


char* intToBinary(int n) {
    int bit_count = 0;
    int temp = n;
    while (temp != 0) {
        temp /= 2;
        bit_count++;
    }
    bit_count = bit_count == 0 ? 1 : bit_count;
    char* binary_str = (char*)malloc(sizeof(char) * (bit_count + 1));
    memset(binary_str, '0', bit_count);
    binary_str[bit_count] = '\0';

    int i = bit_count - 1;
    while (n != 0) {
        binary_str[i--] = (n % 2) + '0';
        n /= 2;
    }
    int first_nonzero_index = 0;
    while (binary_str[first_nonzero_index] == '0' && first_nonzero_index < bit_count - 1) {
        first_nonzero_index++;
    }
    char* result = (char*)malloc(sizeof(char) * (bit_count - first_nonzero_index + 2));
    sprintf(result, "b%s", &binary_str[first_nonzero_index]);
    free(binary_str);
    return result;
}

char* intToHexa(int n) {
    char* hexa = malloc(sizeof(char) * 20);
    sprintf(hexa, "0x%X", n);
    return hexa;
}

struct Number plusOperation(struct Number firstNumber, struct Number secondNumber) {
    // PLUS:
    struct Number result;
    if (strcmp(secondNumber.type, "none") == 0) {
        result = firstNumber;   
    } else if (firstNumber.isArray && secondNumber.isArray) {
        result.type = firstNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = 0;
        if(firstNumber.arraySize == secondNumber.arraySize) {
            size = firstNumber.arraySize;
        } else {
            //error
            yyerror("Nelze provádět operace mezi různě velkými poli!");
            exit(1);
        }
        result.arraySize = size;
        result.arrayNumbers = sumTwoArrays(firstNumber.arrayNumbers, secondNumber.arrayNumbers, size);
    } else if (firstNumber.isArray && !(secondNumber.isArray)) {
        result.type = firstNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = firstNumber.arraySize;
        result.arraySize = size;
        result.arrayNumbers = sumNumWithArray(secondNumber.value, firstNumber.arrayNumbers, size);
    } else if (!(firstNumber.isArray) && secondNumber.isArray) {
        result.type = secondNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = secondNumber.arraySize;
        result.arraySize = size;
        result.arrayNumbers = sumNumWithArray(firstNumber.value, secondNumber.arrayNumbers, size);
    } else {
        result.type = firstNumber.type;
        result.value = firstNumber.value + secondNumber.value;
        result.isArray = 0;
        result.arraySize = 0;
    }
    return result;
}

struct Number multiplyOperation(struct Number firstNumber, struct Number secondNumber) {
    // MULTIPLY:
    struct Number result;
    if (strcmp(secondNumber.type, "none") == 0) {
        result = firstNumber;   
    } else if (firstNumber.isArray && secondNumber.isArray) {
        result.type = firstNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = 0;
        if(firstNumber.arraySize == secondNumber.arraySize) {
            size = firstNumber.arraySize;
        } else {
            //error
            yyerror("Nelze provádět operace mezi různě velkými poli!");
            exit(1);
        }
        result.arraySize = size;
        result.arrayNumbers = multiplyTwoArrays(firstNumber.arrayNumbers, secondNumber.arrayNumbers, size);
    } else if (firstNumber.isArray && !(secondNumber.isArray)) {
        result.type = firstNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = firstNumber.arraySize;
        result.arraySize = size;
        result.arrayNumbers = multiplyNumWithArray(secondNumber.value, firstNumber.arrayNumbers, size);
    } else if (!(firstNumber.isArray) && secondNumber.isArray) {
        result.type = secondNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = secondNumber.arraySize;
        result.arraySize = size;
        result.arrayNumbers = multiplyNumWithArray(firstNumber.value, secondNumber.arrayNumbers, size);
    } else {
        result.type = firstNumber.type;
        result.value = firstNumber.value * secondNumber.value;
        result.isArray = 0;
        result.arraySize = 0;
    }
    return result;
}

struct Number tildeOperation(struct Number firstNumber, struct Number secondNumber) {
    // TILDE:
    struct Number result;
    if (strcmp(secondNumber.type, "none") == 0) {
        result = firstNumber;   
    } else if (firstNumber.isArray && secondNumber.isArray) {
        result.type = firstNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = 0;
        if(firstNumber.arraySize == secondNumber.arraySize) {
            size = firstNumber.arraySize;
        } else {
            //error
            yyerror("Nelze provádět operace mezi různě velkými poli!");
            exit(1);
        }
        result.arraySize = size;
        result.arrayNumbers = tildeTwoArrays(firstNumber.arrayNumbers, secondNumber.arrayNumbers, size);
    } else if (firstNumber.isArray && !(secondNumber.isArray)) {
        result.type = firstNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = firstNumber.arraySize;
        result.arraySize = size;
        result.arrayNumbers = tildeNumWithArray(secondNumber.value, firstNumber.arrayNumbers, size);
    } else if (!(firstNumber.isArray) && secondNumber.isArray) {
        result.type = secondNumber.type;
        result.value = 0;
        result.isArray = 1;
        int size = secondNumber.arraySize;
        result.arraySize = size;
        result.arrayNumbers = tildeNumWithArray(firstNumber.value, secondNumber.arrayNumbers, size);
    } else {
        result.type = firstNumber.type;
        result.value = ((firstNumber.value * secondNumber.value) + firstNumber.value + secondNumber.value);
        result.isArray = 0;
        result.arraySize = 0;
    }
    return result;
}

int* sumTwoArrays(int *firstArray, int *secondArray, int size) {
    int* resultArray = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        resultArray[i] = firstArray[i] + secondArray[i];
    }
    return resultArray;
}

int* sumNumWithArray(int number, int *array, int size) {
    int* resultArray = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        resultArray[i] = array[i] + number;
    }
    return resultArray;
}

int* multiplyTwoArrays(int *firstArray, int *secondArray, int size) {
    int* resultArray = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        resultArray[i] = firstArray[i] * secondArray[i];
    }
    return resultArray;
}

int* multiplyNumWithArray(int number, int *array, int size) {
    int* resultArray = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        resultArray[i] = array[i] * number;
    }
    return resultArray;
}

int* tildeTwoArrays(int *firstArray, int *secondArray, int size) {
    int* resultArray = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        resultArray[i] = (firstArray[i] * secondArray[i]) + firstArray[i] + secondArray[i];
    }
    return resultArray;
}

int* tildeNumWithArray(int number, int *array, int size) {
    int* resultArray = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        resultArray[i] = (number * array[i]) + number + array[i];
    }
    return resultArray;
}

char* getNumberType(char* firstType, char* secondType) {
    if (strcmp(secondType, "array") == 0) {
        return secondType;
    } else {
        return firstType;
    }
}

int generateRandomNumber() {
    int min = 0;
    int max = 100;
    srand(time(NULL));
    int randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

int generateRandomNumberWithBounds(int min, int max) {
    srand(time(NULL));
    int randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

int* generateRandomArray(int n) {
    int min = 0;
    int max = 100;
    int* array = malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % (max - min + 1)) + min;
    }
    return array;
}

int* generateRandomArrayWithBounds(int n, int min, int max) {
    int* array = malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % (max - min + 1)) + min;
    }
    return array;
}

int* addNumberToArray(int number, int *arrayNumbers, int arraySize) {
    arrayNumbers = (int*) realloc(arrayNumbers, (arraySize + 1) * sizeof(int));
    arrayNumbers[arraySize] = number;
    return arrayNumbers;
}

void printResult(struct Number number) {
    printf("\n");
    if (number.isArray == 0) {
        if (strcmp(number.type, "int") == 0) {
            printf("RESULT: %d\n", number.value);
        } else if (strcmp(number.type, "bin") == 0) {
            char* binary = intToBinary(number.value);
            printf("RESULT: %s (hodnota %d)\n", binary, number.value);
            //free(binary);
        } else if (strcmp(number.type, "hex") == 0) {
            char* hexa = intToHexa(number.value);
            printf("RESULT: %s (hodnota %d)\n", hexa, number.value);
            //free(hexa);
        } else {
            printf("RESULT: %d (Ani jedno ze 3)\n", number.value);
        }
    } else {
        if (strcmp(number.type, "int") == 0) {
            printf("RESULT: ");
            printArrayInt(number.arrayNumbers, number.arraySize);
            printf("\n");
        } else if (strcmp(number.type, "bin") == 0) {
            printf("RESULT: ");
            printArrayBin(number.arrayNumbers, number.arraySize);
            printf(" - int hodnoty: ");
            printArrayInt(number.arrayNumbers, number.arraySize);
            printf("\n");
        } else if (strcmp(number.type, "hex") == 0) {
            printf("RESULT: ");
            printArrayHexa(number.arrayNumbers, number.arraySize);
            printf(" - int hodnoty: ");
            printArrayInt(number.arrayNumbers, number.arraySize);
            printf("\n");
        } else {
            printf("RESULT: ");
            printArrayInt(number.arrayNumbers, number.arraySize);
            printf(" (Ani jedno ze 3)\n");
        }
    }
}

void printNumber(int value, char* numberType) {
    if (strcmp(numberType, "int") == 0) {
        printf("%d", value);
    } else if (strcmp(numberType, "bin") == 0) {
        printf("%s", intToBinary(value));
    } else if (strcmp(numberType, "hex") == 0) {
        printf("%s", intToHexa(value));
    }
}

void printArray(int *arrayNumbers, int arraySize, char* numberType) {
    if (strcmp(numberType, "int") == 0) {
        printArrayInt(arrayNumbers, arraySize);
    } else if (strcmp(numberType, "bin") == 0) {
        printArrayBin(arrayNumbers, arraySize);
    } else if (strcmp(numberType, "hex") == 0) {
        printArrayHexa(arrayNumbers, arraySize);
    }
}

void printArrayInt(int *arrayNumbers, int arraySize) {
    printf("[");
    for (int i = 0; i < arraySize; i++) {
        printf("%d", arrayNumbers[i]);
        if (i != arraySize - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void printArrayBin(int *arrayNumbers, int arraySize) {
    printf("[");
    for (int i = 0; i < arraySize; i++) {
        printf("%s", intToBinary(arrayNumbers[i]));
        if (i != arraySize - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void printArrayHexa(int *arrayNumbers, int arraySize) {
    printf("[");
    for (int i = 0; i < arraySize; i++) {
        printf("%s", intToHexa(arrayNumbers[i]));
        if (i != arraySize - 1) {
            printf(", ");
        }
    }
    printf("]");
}


