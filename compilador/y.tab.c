/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "alfa.y" /* yacc.c:339  */

#include "alfa.h"
#define MAX 64

int yylex();
void yyerror(const char * s);

//Variables externas
extern FILE *out;
extern int nlin;
extern int ncol;
extern int is_morpho;
//Aquí tenemos nuestras tablas de símbolos y la flag local para saber en cuál nos encontramos.
extern tablas_simbolos hashes;

//Variables auxiliares a la hora de copiar strings, obtener símbolos de la tabla hash...
char buff[64];
SIMBOLO *aux;
int i;

int tipo_actual;
int clase_actual;
int longitud_actual;

int num_parametros_actual = 0;
int num_var_locales_actual = 1;
int posicion_variable_local = 1;
int posicion_parametro = 0;
int num_parametros_llamada = 0;

//Contador para controlar las etiquetas de condicionales y comparaciones.
int etiqueta = 0;


//Utilizamos estas variables globales para controlar ciertos matices:

//Que en una función haya al menos un retorno.
int flagretorno = 0;

//Indicar que ahora mismo esta en la declaración y definición de una función.
//Lo utilizamos para no declarar variables cuando sean locales, o que a la hora de asignación
//utilizar escribirParametro o escribirVariableLocal
int flag_definicion_funcion = 0;

//Para saber que estamos realizando una llamada a una función y que por tanto en casos de direcciones
//hay que llamar a operandoEnPilaAArgumento
int flag_llamada_funcion = 0;


#line 116 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_IDENTIFICADOR = 258,
    TOK_CONSTANTE_ENTERA = 259,
    TOK_MAIN = 260,
    TOK_INT = 261,
    TOK_BOOLEAN = 262,
    TOK_ARRAY = 263,
    TOK_FUNCTION = 264,
    TOK_IF = 265,
    TOK_ELSE = 266,
    TOK_WHILE = 267,
    TOK_SCANF = 268,
    TOK_PRINTF = 269,
    TOK_RETURN = 270,
    TOK_ERROR = 271,
    TOK_PUNTOYCOMA = 272,
    TOK_COMA = 273,
    TOK_PARENTESISIZQUIERDO = 274,
    TOK_PARENTESISDERECHO = 275,
    TOK_CORCHETEIZQUIERDO = 276,
    TOK_CORCHETEDERECHO = 277,
    TOK_LLAVEIZQUIERDA = 278,
    TOK_LLAVEDERECHA = 279,
    TOK_ASIGNACION = 280,
    TOK_MAS = 281,
    TOK_MENOS = 282,
    TOK_DIVISION = 283,
    TOK_ASTERISCO = 284,
    TOK_AND = 285,
    TOK_OR = 286,
    TOK_NOT = 287,
    TOK_IGUAL = 288,
    TOK_DISTINTO = 289,
    TOK_MENORIGUAL = 290,
    TOK_MAYORIGUAL = 291,
    TOK_MENOR = 292,
    TOK_MAYOR = 293,
    TOK_TRUE = 294,
    TOK_FALSE = 295
  };
#endif
/* Tokens.  */
#define TOK_IDENTIFICADOR 258
#define TOK_CONSTANTE_ENTERA 259
#define TOK_MAIN 260
#define TOK_INT 261
#define TOK_BOOLEAN 262
#define TOK_ARRAY 263
#define TOK_FUNCTION 264
#define TOK_IF 265
#define TOK_ELSE 266
#define TOK_WHILE 267
#define TOK_SCANF 268
#define TOK_PRINTF 269
#define TOK_RETURN 270
#define TOK_ERROR 271
#define TOK_PUNTOYCOMA 272
#define TOK_COMA 273
#define TOK_PARENTESISIZQUIERDO 274
#define TOK_PARENTESISDERECHO 275
#define TOK_CORCHETEIZQUIERDO 276
#define TOK_CORCHETEDERECHO 277
#define TOK_LLAVEIZQUIERDA 278
#define TOK_LLAVEDERECHA 279
#define TOK_ASIGNACION 280
#define TOK_MAS 281
#define TOK_MENOS 282
#define TOK_DIVISION 283
#define TOK_ASTERISCO 284
#define TOK_AND 285
#define TOK_OR 286
#define TOK_NOT 287
#define TOK_IGUAL 288
#define TOK_DISTINTO 289
#define TOK_MENORIGUAL 290
#define TOK_MAYORIGUAL 291
#define TOK_MENOR 292
#define TOK_MAYOR 293
#define TOK_TRUE 294
#define TOK_FALSE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 53 "alfa.y" /* yacc.c:355  */

 tipo_atributos atributos;

#line 240 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 255 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   135,   143,   149,   155,   159,   166,   168,
     172,   177,   179,   184,   190,   203,   204,   206,   207,   209,
     248,   279,   307,   308,   311,   312,   315,   323,   324,   327,
     328,   331,   332,   335,   336,   337,   338,   341,   342,   345,
     395,   445,   493,   499,   506,   518,   525,   532,   541,   552,
     571,   580,   595,   615,   637,   660,   682,   704,   723,   743,
     764,   813,   823,   830,   835,   877,   904,   913,   920,   923,
     927,   930,   952,   975,  1000,  1023,  1047,  1073,  1078,  1085,
    1092,  1101,  1113,  1145
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_IDENTIFICADOR",
  "TOK_CONSTANTE_ENTERA", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_ERROR", "TOK_PUNTOYCOMA",
  "TOK_COMA", "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE", "TOK_FALSE", "$accept", "programa",
  "escritura_ini", "escritura1", "escritura2", "declaraciones",
  "declaracion", "clase", "clase_escalar", "tipo", "clase_vector",
  "identificadores", "funciones", "funcion", "fn_declaration", "fn_name",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "if_exp",
  "if_exp_sentencias", "bucle", "while", "while_exp", "lectura",
  "escritura", "retorno_funcion", "exp", "flag_llamada_regla",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", "identificador",
  "idpf", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -38,    10,    20,   -38,     5,    13,   -38,   -38,     8,   -38,
      13,    31,   -38,   -38,   -38,    18,    50,   -38,   -38,    49,
      60,    64,     8,   -38,    50,    32,    69,   -38,    31,    67,
      87,    32,   -38,   -12,    72,    73,    91,    66,    66,    71,
      32,    79,   -38,   -38,    74,   -38,    32,    76,   -38,    66,
      32,   -38,   -38,   -38,     8,   -38,   -38,   -38,    77,    66,
      66,    66,   -38,   -38,    19,   -38,    66,    66,    66,   -38,
     -38,   -38,   -23,   -38,   -38,   -38,   -23,   -38,   -38,   -38,
      66,   -38,    86,   116,    78,   100,    88,    90,   -38,    45,
     -23,   128,    92,    97,    93,    27,    56,    66,    66,    66,
      66,    66,    66,   -23,    89,    95,   -38,   -38,   -38,    96,
       8,   -38,   -38,    99,    66,   -38,    66,    66,    66,    66,
      66,    66,   -38,    27,    27,    56,    56,    83,   -38,    32,
     -38,    13,    90,   -38,    23,   109,   -23,   -23,   -23,   -23,
     -23,   -23,   113,   -38,   -38,   -38,    66,   -38,   -38,   -38,
      23,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    12,    13,     0,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    82,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
      29,     0,    32,    33,     0,    37,     0,     0,    38,     0,
       0,    34,    35,    36,    23,    16,    14,    21,     0,     0,
       0,     0,    47,    49,    60,    81,     0,     0,     0,    79,
      80,    64,    50,    61,    77,    78,    51,    19,    30,    31,
       0,    45,    42,     0,     0,     0,     0,    25,     2,     0,
      39,     0,     0,     0,     0,    56,    59,     0,     0,     0,
       0,     0,     0,    40,     0,     0,    46,    83,    26,     0,
       0,    22,    41,     0,    68,    62,     0,     0,     0,     0,
       0,     0,    63,    52,    53,    54,    55,    57,    58,     0,
      48,    28,    25,    44,    70,     0,    71,    72,    73,    74,
      75,    76,     0,    27,    20,    24,     0,    67,    65,    43,
      70,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -38,   -38,   -38,   -10,   -38,   -38,   -38,    -6,
     -38,    82,   114,   -38,   -38,   -38,   -38,     7,    30,   -38,
     -13,   -38,   -38,   -38,   -38,   -14,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -37,   -38,   -38,   -30,   -38,
     -38,   -38,   -38,   -38,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    31,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    86,   111,    87,   144,
      39,    40,    41,    42,    43,    71,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    72,    92,   135,   147,    94,
      73,    74,    75,    20,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    76,    15,    97,    98,    99,   100,   101,   102,    59,
       3,    44,    83,    60,     6,     7,    30,    44,    58,     6,
       7,     8,    89,    90,    91,     4,    44,    78,     5,    93,
      95,    96,    44,    81,    18,    33,    44,    84,   -66,    21,
      59,   146,    34,   103,    35,    36,    37,    38,    85,    97,
      98,    99,   100,   101,   102,    99,   100,   101,   102,    22,
     123,   124,   125,   126,   127,   128,    27,   112,    29,    64,
      65,    97,    98,    99,   100,   101,   102,   134,    28,   136,
     137,   138,   139,   140,   141,    66,   101,   102,    54,    56,
      57,    61,    62,    67,    63,    77,    79,   104,    68,    80,
      82,    88,   106,   107,    85,    69,    70,   110,   109,   150,
      55,   114,   129,   122,   102,    44,   142,   115,   130,   131,
     151,   143,   133,    97,    98,    99,   100,   101,   102,   148,
     116,   117,   118,   119,   120,   121,   105,   149,    32,   145,
     132,     0,    97,    98,    99,   100,   101,   102,   113,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102
};

static const yytype_int16 yycheck[] =
{
      10,    38,     8,    26,    27,    28,    29,    30,    31,    21,
       0,    25,    49,    25,     6,     7,    22,    31,    31,     6,
       7,     8,    59,    60,    61,     5,    40,    40,    23,    66,
      67,    68,    46,    46,     3,     3,    50,    50,    19,    21,
      21,    18,    10,    80,    12,    13,    14,    15,    54,    26,
      27,    28,    29,    30,    31,    28,    29,    30,    31,     9,
      97,    98,    99,   100,   101,   102,    17,    22,     4,     3,
       4,    26,    27,    28,    29,    30,    31,   114,    18,   116,
     117,   118,   119,   120,   121,    19,    30,    31,    19,    22,
       3,    19,    19,    27,     3,    24,    17,    11,    32,    25,
      24,    24,    24,     3,   110,    39,    40,    17,    20,   146,
      28,    19,    23,    20,    31,   129,   129,    20,    23,    23,
     150,   131,    23,    26,    27,    28,    29,    30,    31,    20,
      33,    34,    35,    36,    37,    38,    20,    24,    24,   132,
     110,    -1,    26,    27,    28,    29,    30,    31,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     5,    23,     6,     7,     8,    46,
      47,    48,    49,    50,    51,    50,    44,    46,     3,    52,
      84,    21,     9,    53,    54,    55,    56,    17,    18,     4,
      50,    45,    53,     3,    10,    12,    13,    14,    15,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    19,    52,    22,     3,    61,    21,
      25,    19,    19,     3,     3,     4,    19,    27,    32,    39,
      40,    66,    76,    81,    82,    83,    76,    24,    61,    17,
      25,    61,    24,    76,    61,    50,    57,    59,    24,    76,
      76,    76,    77,    76,    80,    76,    76,    26,    27,    28,
      29,    30,    31,    76,    11,    20,    24,     3,    85,    20,
      17,    58,    22,    20,    19,    20,    33,    34,    35,    36,
      37,    38,    20,    76,    76,    76,    76,    76,    76,    23,
      23,    23,    59,    23,    76,    78,    76,    76,    76,    76,
      76,    76,    61,    46,    60,    58,    18,    79,    20,    24,
      76,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      55,    56,    57,    57,    58,    58,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     0,     0,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       6,     3,     2,     0,     3,     0,     2,     1,     0,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     2,     6,     5,     2,     3,     2,     4,     2,
       2,     2,     3,     3,     3,     3,     2,     3,     3,     2,
       1,     1,     3,     3,     1,     5,     0,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 128 "alfa.y" /* yacc.c:1646  */
    {
            fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
            fprintf( out, ";escribir_fin\n" );
            escribir_fin( out );
          }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 135 "alfa.y" /* yacc.c:1646  */
    {
                 fprintf( out, ";escribir_subseccion_data\n" );
                 escribir_subseccion_data( out );
                 fprintf( out, ";escribir_cabecera_bss\n" );
                 escribir_cabecera_bss( out );
               }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "alfa.y" /* yacc.c:1646  */
    {
              fprintf( out, ";escribir_segmento_codigo\n" );
              escribir_segmento_codigo( out );
            }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "alfa.y" /* yacc.c:1646  */
    {
              fprintf( out, ";escribir_inicio_main\n" );
              escribir_inicio_main( out );
            }
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 155 "alfa.y" /* yacc.c:1646  */
    {
	fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");

	}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 159 "alfa.y" /* yacc.c:1646  */
    {

			 	fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");


			 }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 166 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 168 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n");
          clase_actual = ESCALAR;
       }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 172 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n");
          clase_actual = VECTOR;
       }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 177 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out, ";R10:\t<tipo> ::= int\n");
        tipo_actual = VECTOR;
		longitud_actual = 1;
      }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 184 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out, ";R11:\t<tipo> ::= boolean\n");
        tipo_actual = BOOLEANO;
		longitud_actual = 1;
      }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera]\n");
                //EN $4.valor TENEMOS EL TAMAÑO DEL VECTOR
                //COMPROBACIONES SEMANTICAS (TAMANO > 0 y TAMANO < MAX) Y PROPAGACION EN $$.valor
				if((yyvsp[-1].atributos).valor_entero <=0 || (yyvsp[-1].atributos).valor_entero > MAX){
					printf("****Error semantico en lin %d: El tamanyo del vector <nombre_vector> excede los limites permitidos (1,64).\n", nlin);
					return -1;
				}
				(yyval.atributos).valor_entero = (yyvsp[-1].atributos).valor_entero;
				longitud_actual = (yyvsp[-1].atributos).valor_entero;
              }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 203 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 204 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 206 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 207 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R21:\t<funciones> ::= \n");}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 209 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(out, ";R22:\t<funcion> ::= function <tipo> <identificador ( <parametros_funcion ) { <declaraciones_funcion> <sentencias> }\n");
          //COMPROBACIONES SEMANTICAS
          //ERROR SI LA FUNCION NO TIENE SENTENCIA DE RETORNO
          //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
          //CIERRE DE AMBITO, ETC
		  if(flagretorno==0){
		  	printf("****Error semantico en lin %d: Funcion <nombre_funcion> sin sentencia de retorno\n", nlin);
			return -1;
		  }

		  if(cerrarAmbito(&hashes)==-1){
		  printf("Error. La funcion no se ha le ha podido cerrar el ámbito.\n");
		  return -1;
		  }
		  printf("%s Ya hecho cierre con flaglocal %d\n", (yyvsp[-2].atributos).lexema, hashes.flaglocal);

		  aux = buscarTabla(&hashes, (yyvsp[-2].atributos).lexema);
		  if(aux==NULL){
			printf("Error. La funcion ya estaba declarada pero no la encontramos.\n");
			return -1;
		  }
		  printf("%d\n", num_parametros_actual);
		  printf("%d\n", aux->num_parametros);

		  aux = new_simbolo((yyvsp[-2].atributos).lexema, FUNCION, aux->tipo, -1, -1, -1, num_parametros_actual, -1, num_var_locales_actual);
		  printf("Insertando con flag_local %d y con esta clave %s\n", hashes.flaglocal, (yyvsp[-2].atributos).lexema);
		  insertarTabla(&hashes, (yyvsp[-2].atributos).lexema, aux);
		  //Volvemos a cerrarAmbito porque por defecto se abre para una función pero no lo queremos.
		  if(cerrarAmbito(&hashes)==-1){
		  printf("Error. La funcion no se ha le ha podido cerrar el ámbito.\n");
		  return -1;
		  }
		  flag_definicion_funcion = 0;


        }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "alfa.y" /* yacc.c:1646  */
    {
                  //COMPROBACIONES SEMANTICAS
                  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema



				  strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
                  (yyval.atributos).tipo = (yyvsp[-5].atributos).tipo;

                  //GENERACION DE CODIGO
				  fprintf(out, ";declararFuncion\n");
				  declararFuncion(out, (yyvsp[-5].atributos).lexema, num_var_locales_actual);

				 //Actualizamos también la función en la tabla local con número de parámetros por si la queremos llamar otra vez.
				 aux = buscarTabla(&hashes, (yyvsp[-5].atributos).lexema);
				 if(aux==NULL){
				   printf("Error. La función ya estaba declarada pero no la encontramos.\n");
				   return -1;
				 }
				 printf("%d\n", num_parametros_actual);
				 printf("%d\n", aux->num_parametros);

				 aux = new_simbolo((yyvsp[-5].atributos).lexema, FUNCION, aux->tipo, -1, -1, -1, num_parametros_actual, -1, num_var_locales_actual);
				 printf("Insertando con flag_local %d y con esta clave %s\n", hashes.flaglocal, (yyvsp[-5].atributos).lexema);
				 insertarTabla(&hashes, (yyvsp[-5].atributos).lexema, aux);



                }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 279 "alfa.y" /* yacc.c:1646  */
    {
          //COMPROBACIONES SEMANTICAS
          //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.lexema


		  aux = buscarTabla(&hashes, (yyvsp[0].atributos).lexema);
		  if(aux!=NULL){
		  	printf("****Error semantico en lin %d: Declaracion de función duplicada.\n", nlin);
			return -1;
		  }

		  aux = new_simbolo((yyvsp[0].atributos).lexema, FUNCION, tipo_actual, -1, -1, -1, -1, -1, -1);
		  printf("Insertando %s con esta flag %d", (yyvsp[0].atributos).lexema, hashes.flaglocal);
		  insertarTabla(&hashes, (yyvsp[0].atributos).lexema, aux);
		  num_parametros_actual = 0;
		  num_var_locales_actual = 1;
		  posicion_variable_local = 1;
		  posicion_parametro = 0;
		  flag_definicion_funcion = 1;
		  flagretorno = 0;
		  (yyval.atributos).tipo = tipo_actual;
		  strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
          //ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.lexema
          //RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
          //posicion_variable_local, num_variables_locales, posicion_parametro, num_parametros
        }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 307 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R25:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 308 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R24:\t<parametros_funcion> ::= \n");}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 311 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 312 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R26:\t<resto_parametros_funcion> ::= \n");}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 315 "alfa.y" /* yacc.c:1646  */
    {
                    fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                    //INCREMENTAR CONTADORES, POR EJEMPLO
                    num_parametros_actual++;
                    posicion_parametro++;
                   }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 323 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 324 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R29:\t<declaraciones_funcion> ::= \n");}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 327 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 328 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 331 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 332 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R33:\t<sentencia> ::= <bloque>\n");}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 335 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 336 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 337 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 338 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 341 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 342 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 345 "alfa.y" /* yacc.c:1646  */
    {

    fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
	printf("flaglocal antes de buscar:%d y con esta clave %s\n", hashes.flaglocal, (yyvsp[-2].atributos).lexema);
    aux = buscarTabla(&hashes, (yyvsp[-2].atributos).lexema);
  if (  aux == NULL){
      printf("Error a la hora de asignacion. No esta en la tabla 1\n");
      return -1;
  }

    if (aux->cat_simbolo == FUNCION){
	    printf("Error a la hora de asignacion. Es una funcion");
	    return -1;
    }


    if (aux->categoria == VECTOR){
      printf("Error a la hora de asignacion. Es una vector");
      return -1;
    }

    if (aux->tipo != (yyvsp[0].atributos).tipo){
	  printf("%d %d\n", aux->tipo, (yyvsp[0].atributos).tipo);
      printf("****Error semantico en lin %d a la hora de asignacion. No es el mismo tipo\n", nlin);
      return -1;
    }

	if(flag_definicion_funcion == 1){

		if(aux->cat_simbolo == PARAMETRO){
			fprintf(out, ";escribirParametro\n");
			escribirParametro(out, aux->posicion, num_parametros_actual);
		}
		else{
			fprintf(out, ";escribirVariableLocal\n");
			printf("POSICION: %d\n", aux->posicion);
			escribirVariableLocal(out, aux->posicion);

		}

		fprintf(out, ";asignarDestinoEnPila\n");
		asignarDestinoEnPila(out, (yyvsp[0].atributos).es_direccion);
	}

	else{
		fprintf(out, ";asignar\n");
		asignar(out, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion);
	}

   }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 395 "alfa.y" /* yacc.c:1646  */
    {
              fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");

              //COMPROBACIONES SEMANTICAS (VER SI $1.tipo == $3.tipo)
			  if((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo){
			  	printf("****Error semantico en linea %d en asignacion de vector. No son del mismo tipo\n", nlin);
				return -1;
			  }

			  aux = buscarTabla(&hashes, (yyvsp[-2].atributos).lexema);
			  if (  aux == NULL){
				  printf("Error a la hora de asignacion. No esta en la tabla");
				  return -1;
			  }
			  if (aux->cat_simbolo == FUNCION){
				printf("****Error semantico en línea %d a la hora de asignacion. Es una funcion", nlin);
				return -1;
			  }
			  if (aux->categoria != VECTOR){
		        printf("****Error semantico en linea %d a la hora de asignacion. No es un vector.", nlin);
		        return -1;
		      }


			  //Hemos ahora de volcar en pila el índice del elemento_vector.
			  //Para ello lo que haremos será ver si su índice es variable o no, que lo hemos propagado.

			  if((yyvsp[-2].atributos).indice_es_direccion == 0){
			  	//Si no es dirección, escribimos su valor entero como string en pila, y llamamos a
				//escribir_elemento_vector indicando que el índice es un valor.
				  sprintf( buff, "%d", (yyvsp[-2].atributos).valor_entero );
				  fprintf(out, ";escribir_operando\n");
				  escribir_operando(out, buff, 0);
				  fprintf(out, ";escribir_elemento_vector\n");
				  escribir_elemento_vector(out, (yyvsp[-2].atributos).lexema, aux->longitud, 0);

			  }
			  if((yyvsp[-2].atributos).indice_es_direccion == 1){
			  	//Si sí es variable, llamamos a escribir_operando con el lexema del índice que hemos propagado,
				//y escribimos el vector indicando que el índice es variable.
				  fprintf(out, ";escribir_operando\n");
				  escribir_operando(out, (yyvsp[-2].atributos).indice_lexema, 1);
				  escribir_elemento_vector(out, (yyvsp[-2].atributos).lexema, aux->longitud, 1);
			  }
			  fprintf(out, ";asignarDestinoEnPila\n");
			  //Por último, asignamos el destino la expresión al vector.
              asignarDestinoEnPila(out, (yyvsp[0].atributos).es_direccion);
            }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 445 "alfa.y" /* yacc.c:1646  */
    {

                   fprintf(out, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");

                   //COMPROBACIONES SEMANTICAS PARA EL SIMBOLO CON IDENTIFICADOR $1.lexema

				  aux = buscarTabla(&hashes, (yyvsp[-3].atributos).lexema);
	 			  if (  aux == NULL){
	 				  printf("****Error semantico en lin %d a la hora de asignacion. No esta en la tabla", nlin);
	 				  return -1;
	 			  }
	 			  if (aux->cat_simbolo == FUNCION){
	 				printf("Error a la hora de asignacion. Es una función");
	 				return -1;
	 			  }
	 			  if (aux->categoria != VECTOR){
	 		        printf("****Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.",nlin);
	 		        return -1;
	 		      }
				  if((yyvsp[-1].atributos).tipo != ENTERO){
				  	printf("****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n",nlin);
					return -1;
				  }
				  //fprintf(out, ";escribir_elemento_vector\n");
                  //escribir_elemento_vector(out, $1.lexema, aux->longitud, $3.es_direccion);


				  //Necesitamos propagar en elemento_vector si su índice es dirección o no,
				  //y en este caso, almacenar el lexema en un atributo.
				  if((yyvsp[-1].atributos).es_direccion == 1){
				  	(yyval.atributos).indice_es_direccion = 1;
					strcpy((yyval.atributos).indice_lexema, (yyvsp[-1].atributos).lexema);
				  }
				  //Si es un valor, lo indicamos y almacenamos el valor en otro atributo.
				  if((yyvsp[-1].atributos).es_direccion == 0){
				  	(yyval.atributos).indice_es_direccion = 0;
				  	(yyval.atributos).valor_entero = (yyvsp[-1].atributos).valor_entero;
				  }
				  //No es necesario llamar ahora a escribir_elemento_vector porque lo haremos
				  //en la regla de producción exp:elemento_vector, o bien en asignacion:elemento_vector = exp.

				  //Propagamos el resto de la información.
				  (yyval.atributos).tipo = aux->tipo;
				  (yyval.atributos).es_direccion = 1;
				  strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
                  }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 493 "alfa.y" /* yacc.c:1646  */
    {
               fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
               fprintf(out,";ifthenelse_fin\n");
               ifthenelse_fin(out, (yyvsp[-1].atributos).etiqueta);
              }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 499 "alfa.y" /* yacc.c:1646  */
    {
               fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
               fprintf(out,";ifthenelse_fin\n");
               ifthenelse_fin(out, (yyvsp[-5].atributos).etiqueta);
              }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 506 "alfa.y" /* yacc.c:1646  */
    {
          //Comprb semanticas, y gestion de etiqueta.
          if((yyvsp[-2].atributos).tipo != BOOLEANO){
            printf("****Error semantico en linea %d. Condicional con condicion de tipo int. \n", nlin);
            return -1;
          }
          (yyval.atributos).etiqueta = etiqueta++;
          fprintf(out,";ifthen_inicio\n");
          ifthen_inicio(out, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
        }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 518 "alfa.y" /* yacc.c:1646  */
    {
                     (yyval.atributos).etiqueta = (yyvsp[-1].atributos).etiqueta;
                     fprintf(out,";ifthenelse_fin_then\n");
                     ifthenelse_fin_then(out, (yyval.atributos).etiqueta);
                   }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 525 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
        fprintf(out,";while_fin\n");
        while_fin(out, (yyvsp[-2].atributos).etiqueta);
        }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 532 "alfa.y" /* yacc.c:1646  */
    {
        //GESTION ETIQUETA
        (yyval.atributos).etiqueta = etiqueta++;
        fprintf(out,";while_inicio\n");
        while_inicio(out, (yyval.atributos).etiqueta);
        }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 541 "alfa.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].atributos).tipo != BOOLEANO){
               printf("****Error semantico en lin %d: Condicional con condicion de tipo int.\n", nlin);
               return -1;
            }
            (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
            fprintf(out,";while_exp_pila\n");
            while_exp_pila(out, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
            }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 552 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R54:\t<lectura> ::= scanf <identificador>\n");

          aux = buscarTabla(&hashes, (yyvsp[0].atributos).lexema);
          if(aux==NULL){
            printf("****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", nlin, (yyvsp[0].atributos).lexema);
            return -1;
          }
          if(aux->cat_simbolo == FUNCION || aux->categoria != ESCALAR){
            printf("****Error semántico en lin %d, no scanf de vector.\n", nlin);
            return -1;
          }
          fprintf(out, ";leer\n");
          leer(out, (yyvsp[0].atributos).lexema ,aux->tipo);



          }
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 571 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R56:\t<escritura> ::= printf <exp>\n");

            fprintf(out, ";escribir\n");
            escribir(out, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);


    }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 580 "alfa.y" /* yacc.c:1646  */
    {
	//Debemos de indicar de alguna forma que la función tiene retorno. Activamos aquí la flag.
	if (flag_definicion_funcion == 0){
		printf("****Error semantico en lin %d.  Sentencia de retorno fuera del cuerpo de una funcion.\n", nlin);
		return -1;
	}
	flagretorno  = 1;
	fprintf(out, ";retornarFuncion\n");
	retornarFuncion(out, (yyvsp[0].atributos).es_direccion);
	fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");


}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 595 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R72:\t<exp> ::= <exp> + <exp>\n");

      if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

        printf("****Error semantico en lin %d, la suma es entre dos booleanos.\n", nlin);
        return -1;
      }

      if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
        {
        fprintf(out, ";sumar \n");
        sumar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);


        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
		(yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero + (yyvsp[0].atributos).valor_entero;
        }

  }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 615 "alfa.y" /* yacc.c:1646  */
    {

      fprintf(out, ";R73:\t<exp> ::= <exp> - <exp>\n");

      if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

        printf("****Error semantico en lin %d, la resta es entre dos booleanos.\n", nlin);
        return -1;
      }

      if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
        {
        fprintf(out, ";restar \n");
        restar(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion);


        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
		(yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero - (yyvsp[0].atributos).valor_entero;
        }

   }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 637 "alfa.y" /* yacc.c:1646  */
    {
      fprintf(out, ";R74:\t<exp> ::= <exp> / <exp>\n");
      if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

        printf("****Error semantico en lin %d, la división es entre dos booleanos.\n", nlin);
        return -1;
      }

      if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
        {
        fprintf(out, ";dividir \n");
        dividir(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion);


        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
		if((yyvsp[0].atributos).valor_entero!=0){
			(yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero / (yyvsp[0].atributos).valor_entero;
		}

        }

   }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 660 "alfa.y" /* yacc.c:1646  */
    {
      fprintf(out, ";R75:\t<exp> ::= <exp> * <exp>\n");
      if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

        printf("****Error semantico en lin %d, la multiplicación es entre dos booleanos.\n", nlin);
        return -1;
      }

      if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
        {
        fprintf(out, ";multiplicar \n");
        multiplicar(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion);

        /* Propaga correctamente los atributos*/
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
		(yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero * (yyvsp[0].atributos).valor_entero;
        }



   }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 682 "alfa.y" /* yacc.c:1646  */
    {
         fprintf(out, ";R76:\t<exp> ::= - <exp>\n");
         if (((yyvsp[0].atributos).tipo == BOOLEANO)){

           printf("****Error semantico en lin %d, el cambiar_signo es sobre un booleano.\n", nlin);
           return -1;
         }

         if (((yyvsp[0].atributos).tipo == ENTERO))
           {
           fprintf(out, ";cambiar_signo\n");
           cambiar_signo(out,(yyvsp[0].atributos).es_direccion);

           /* Propaga correctamente los atributos*/
           (yyval.atributos).tipo = ENTERO;
           (yyval.atributos).es_direccion = 0;
		   (yyval.atributos).valor_entero = -(yyval.atributos).valor_entero;
           }



   }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 704 "alfa.y" /* yacc.c:1646  */
    {
         fprintf(out, ";R77:\t<exp> ::= <exp> && <exp>\n");
         if (((yyvsp[-2].atributos).tipo == ENTERO) || ((yyvsp[0].atributos).tipo == ENTERO)){

           printf("****Error semantico en lin %d, la suma es entre dos booleanos.\n", nlin);
           return -1;
         }

         if (((yyvsp[-2].atributos).tipo == BOOLEANO) && ((yyvsp[0].atributos).tipo == BOOLEANO))
           {
           fprintf(out, ";y \n");
           y(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion);

           /* Propaga correctamente los atributos*/
           (yyval.atributos).tipo = BOOLEANO;
           (yyval.atributos).es_direccion = 0;
           }

   }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 723 "alfa.y" /* yacc.c:1646  */
    {
         fprintf(out, ";R78:\t<exp> ::= <exp> || <exp>\n");
         if (((yyvsp[-2].atributos).tipo == ENTERO) || ((yyvsp[0].atributos).tipo == ENTERO)){

           printf("****Error semantico, la or es entre dos int.\n");
           return -1;
         }

         if (((yyvsp[-2].atributos).tipo == BOOLEANO) && ((yyvsp[0].atributos).tipo == BOOLEANO))
           {

           fprintf(out, ";o \n");
           o(out,(yyvsp[-2].atributos).es_direccion,(yyvsp[0].atributos).es_direccion);

           /* Propaga correctamente los atributos*/
           (yyval.atributos).tipo = BOOLEANO;
           (yyval.atributos).es_direccion = 0;
           }

   }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 743 "alfa.y" /* yacc.c:1646  */
    {
         fprintf(out, ";R79:\t<exp> ::= ! <exp>\n");
         if (((yyvsp[0].atributos).tipo == ENTERO)){

           printf("****Error semantico en lin %d, la negación es sobre un entero.\n", nlin);
           return -1;
         }

         if (((yyvsp[0].atributos).tipo == BOOLEANO))
           {

           fprintf(out, ";no \n");
           no(out,(yyvsp[0].atributos).es_direccion,1);


           (yyval.atributos).tipo = BOOLEANO;
           (yyval.atributos).es_direccion = 0;
           }


   }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 764 "alfa.y" /* yacc.c:1646  */
    {
      fprintf(out, ";R80:\t<exp> ::= <identificador>\n");
      aux = buscarTabla(&hashes, (yyvsp[0].atributos).lexema);

      if(aux == NULL){
         printf("****Error semantico en lin %d. No se ha declarado previamente.\n", nlin);
         return -1;
      }

      if(aux->cat_simbolo == FUNCION){
         printf("****Error semantico en  lin %d. El identificador es una funcion.\n", nlin);
         return -1;
      }

      if(aux->categoria == VECTOR){
         printf("****Error semantico en %d. No se puede usar un vector sin indexar.\n", nlin);
         return -1;
      }

      (yyval.atributos).tipo = aux->tipo;
      (yyval.atributos).es_direccion = 1;
	  if(flag_definicion_funcion == 1){
	  		if(aux->cat_simbolo == PARAMETRO){
				fprintf(out, ";escribirParametro\n");
				escribirParametro(out, aux->posicion, num_parametros_actual);
			}
			else{
				fprintf(out, ";escribirVariableLocal\n");
				escribirVariableLocal(out, aux->posicion);
			}

	  }
	  else{
		  fprintf(out, ";escribir_operando\n");
		  escribir_operando(out, (yyvsp[0].atributos).lexema, 1);
	  }
	  if(flag_llamada_funcion == 1){
	  	fprintf(out, ";operandoEnPilaAArgumento\n");
	  	operandoEnPilaAArgumento(out, 1);
		//Hemos de indicar que lo que ya tenemos aquí no es una dirección, sino un valor fijo.
		(yyval.atributos).es_direccion = 0;
	  }






   }
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 813 "alfa.y" /* yacc.c:1646  */
    {
       fprintf(out, ";R81:\t<exp> ::= <constante>\n");
       (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
       (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
	   if(flag_llamada_funcion == 1){
	   	fprintf(out, ";operandoEnPilaAArgumento\n");
 	  	operandoEnPilaAArgumento(out, 0);
 	  }
     }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 823 "alfa.y" /* yacc.c:1646  */
    {

         fprintf(out, ";R82:\t<exp> ::= ( <exp> )\n");
         (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
         (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;

   }
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 830 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out, ";R83:\t<exp> ::= ( <comparacion )\n");
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
   }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 835 "alfa.y" /* yacc.c:1646  */
    {
   			fprintf(out, ";R84:\t<exp> ::= <elemento_vector>\n");

			(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
			(yyval.atributos).es_direccion = 1;
			(yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
			strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);

			aux = buscarTabla(&hashes, (yyvsp[0].atributos).lexema);

			if (  aux == NULL){
				printf("****Error semantico en lin %d a la hora de asignacion\n", nlin);
				return -1;
			}
			if (aux->cat_simbolo == FUNCION){
			  printf("Error a la hora de asignacion. Es una funcion");
			  return -1;
			}
			if (aux->categoria != VECTOR){
			  printf("Error a la hora de asignacion. No es un vector.");
			  return -1;
			}




			fprintf(out, ";escribir_elemento_vector\n");
			escribir_elemento_vector(out, (yyvsp[0].atributos).lexema, aux->longitud, (yyvsp[0].atributos).indice_es_direccion);


			if(flag_llamada_funcion == 1){

			fprintf(out,";operandoEnPilaAArgumento\n");
	  	  	operandoEnPilaAArgumento(out, 1);
			//Hemos de indicar que lo que ya tenemos aquí no es una dirección, sino un valor fijo.
			(yyval.atributos).es_direccion = 0;
	  	  }




   	}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 877 "alfa.y" /* yacc.c:1646  */
    {
   		fprintf(out, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
		aux = buscarTabla(&hashes, (yyvsp[-4].atributos).lexema);
		if(aux == NULL){
		printf("****Error semantico en lin %d. No existe la funcion a la que se refiere.\n", nlin);
		return -1;
		}
		if(num_parametros_llamada != aux->num_parametros){
		printf("llamada %d  declaracion %d en clave %s\n", num_parametros_llamada, aux->num_parametros, aux->identificador);
			printf("****Error semantico en lin %d. La llamada a funcion no tiene el numero necesario de argumentos.\n", nlin);
			return -1;
		}

		fprintf(out, ";llamarFuncion\n");
		llamarFuncion(out, (yyvsp[-4].atributos).lexema, num_parametros_llamada);
		fprintf(out, ";limpiarPila\n");
		limpiarPila(out, num_parametros_llamada);
		num_parametros_llamada = 0;
		(yyval.atributos).es_direccion = 0;
		flag_llamada_funcion = 0;
		(yyval.atributos).tipo = aux->tipo;



   }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 904 "alfa.y" /* yacc.c:1646  */
    {
	if(flag_llamada_funcion==1){
		printf("****Error semantico en lin %d. No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n",nlin);
		return -1;
	}
	flag_llamada_funcion = 1;}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 913 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
		num_parametros_llamada ++;



		}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 920 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R90:\t<lista_expresiones> ::= \n");}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 923 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= TOK_COMA <exp> <resto_lista_expresiones>\n");

	num_parametros_llamada++;
	}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 927 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R92:\t<resto_lista_expresiones> ::= \n");}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 930 "alfa.y" /* yacc.c:1646  */
    {

        fprintf(out, ";R93:\t<comparacion> ::= <exp> == <exp>\n");

        if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

          printf("****Error semantico en lin %d, la comparacion es entre dos booleanos.\n", nlin);
          return -1;
        }

        if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
          {

          fprintf(out, ";igual\n");
          igual(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);

          /* Propaga correctamente los atributos*/
          etiqueta++;
          (yyval.atributos).tipo = BOOLEANO;
          (yyval.atributos).es_direccion = 0;
          }
  }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 952 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R94:\t<comparacion> ::= <exp> != <exp>\n");

           if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

             printf("****Error semantico en %d, la comparacion es entre dos booleanos.\n", nlin);
             return -1;
           }

           if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
             {

             fprintf(out, ";distinto\n");
             distinto(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             (yyval.atributos).tipo = BOOLEANO;
             (yyval.atributos).es_direccion = 0;
             }



           }
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 975 "alfa.y" /* yacc.c:1646  */
    {

           fprintf(out, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");

           if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

             printf("****Error semantico en lin %d, la comparacion es entre dos booleanos.\n", nlin);
             return -1;
           }

           if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
             {
             fprintf(out, ";menor_igual\n");
             menor_igual(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             (yyval.atributos).tipo = BOOLEANO;
             (yyval.atributos).es_direccion = 0;
             }




           }
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1000 "alfa.y" /* yacc.c:1646  */
    {

           fprintf(out, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
           if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

             printf("****Error semantico en lin %d, la comparacion es entre dos booleanos.\n", nlin);
             return -1;
           }

           if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
             {
             fprintf(out, ";mayor_igual\n");
             mayor_igual(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             (yyval.atributos).tipo = BOOLEANO;
             (yyval.atributos).es_direccion = 0;
             }



           }
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1023 "alfa.y" /* yacc.c:1646  */
    {

           fprintf(out, ";R97:\t<comparacion> ::= <exp> <= <exp>\n");
           if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

             printf("****Error semantico en lin %d, la comparacion es entre dos booleanos.\n", nlin);
             return -1;
           }

           if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
             {
             fprintf(out, ";menor\n");
             menor(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             (yyval.atributos).tipo = BOOLEANO;
             (yyval.atributos).es_direccion = 0;
             }




           }
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1047 "alfa.y" /* yacc.c:1646  */
    {

           fprintf(out, ";R98:\t<comparacion> ::= <exp> >= <exp>\n");
           if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){

             printf("****Error semantico en lin %d, la comparacion es entre dos booleanos.\n", nlin);
             return -1;
           }

           if (((yyvsp[-2].atributos).tipo == ENTERO) && ((yyvsp[0].atributos).tipo == ENTERO))
             {
             fprintf(out, ";mayor\n");
             mayor(out,(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             (yyval.atributos).tipo = BOOLEANO;
             (yyval.atributos).es_direccion = 0;
             }




           }
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1073 "alfa.y" /* yacc.c:1646  */
    {
      fprintf(out, ";R99:\t<constante> ::= <constante_logica>\n");
      (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
      (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
}
#line 2703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1078 "alfa.y" /* yacc.c:1646  */
    {
             (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
             (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
             fprintf(out, ";R100:\t<constante> ::= <constante_entera>\n");
           }
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1085 "alfa.y" /* yacc.c:1646  */
    {
                    fprintf(out, ";R102:\t<constante_logica> ::= true\n");
                    (yyval.atributos).tipo = BOOLEANO;
                    (yyval.atributos).es_direccion = 0;
					fprintf(out, ";escribir_operando\n");
                    escribir_operando( out, "1" , 0 );
                  }
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1092 "alfa.y" /* yacc.c:1646  */
    {
                    fprintf(out, ";R103:\t<constante_logica> ::= false\n");
                    (yyval.atributos).tipo = BOOLEANO;
                    (yyval.atributos).es_direccion = 0;
					fprintf(out, ";escribir_operando\n");
                    escribir_operando( out, "0" , 0 );
                  }
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1101 "alfa.y" /* yacc.c:1646  */
    {
                    fprintf( out, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n" );
                    (yyval.atributos).tipo = ENTERO;
                    (yyval.atributos).es_direccion = 0;
                    (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;

                    sprintf( buff, "%d", (yyval.atributos).valor_entero );
					fprintf(out, ";escribir_operando\n");
                    escribir_operando( out, buff , 0 );
                  }
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1113 "alfa.y" /* yacc.c:1646  */
    {
                 fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                 if( buscarTabla( &hashes, (yyvsp[0].atributos).lexema ) != NULL ) {
                    printf( "****Error semantico en linea %d. Declaracion duplicada.", nlin);
                    return -1;
                 } else {

					if(flag_definicion_funcion==1){
						printf("clase actual %d y con lexema %s\n", clase_actual, (yyvsp[0].atributos).lexema);
						 if (clase_actual != ESCALAR){
						 	printf("****Error semantico en lin %d. Variable local de tipo no escalar.\n",nlin);
							return -1;
						 }
						 aux = new_simbolo((yyvsp[0].atributos).lexema, VARIABLE, tipo_actual, ESCALAR, -1, 1, -1, num_var_locales_actual, -1);
						 insertarTabla( &hashes, (yyvsp[0].atributos).lexema, aux );
						 num_var_locales_actual++;
					 }
					 else{
						 aux = new_simbolo((yyvsp[0].atributos).lexema, VARIABLE, tipo_actual, clase_actual, -1, longitud_actual, -1, -1, -1);
						 printf("flaglocal antes de insertar:%d y este key %s\n",hashes.flaglocal, (yyvsp[0].atributos).lexema);
						 insertarTabla( &hashes, (yyvsp[0].atributos).lexema, aux );
						 fprintf(out, ";declarar_variable\n");
						 declarar_variable( out, (yyvsp[0].atributos).lexema, tipo_actual, longitud_actual);

					 }



                 }
               }
#line 2787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1145 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
				aux = buscarTabla(&hashes, (yyvsp[0].atributos).lexema);
				if(aux != NULL){
					printf("****Error semantico en lin %d. El parametro ya esta declarado en el ambito local.\n", nlin);
					return -1;
				}
				aux = new_simbolo((yyvsp[0].atributos).lexema, PARAMETRO, tipo_actual, ESCALAR, -1, 1, -1, posicion_parametro, -1);
				printf("flaglocal antes de insertar:%d y este key %s\n",hashes.flaglocal, (yyvsp[0].atributos).lexema);
				insertarTabla( &hashes, (yyvsp[0].atributos).lexema, aux );


              }
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2809 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 1159 "alfa.y" /* yacc.c:1906  */


void yyerror(const char * s) {
    if(!is_morpho) {
        printf("****Error sintactico en [lin %d, col %d]\n", nlin, ncol);
    }
}
