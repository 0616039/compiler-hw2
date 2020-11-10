#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "error.h"


extern int LineNum;         /* declared in lex.l */
extern char Buffer[512];       /* declared in lex.l */
extern FILE *yyin;          /* declared by lex.l */
extern char *yytext;        /* declared by lex.l */

extern int yylex(void); 
static void yyerror(const char *msg);
#line 33 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define DOT 258
#define FAN 259
#define MO 260
#define LEG 261
#define RIG 262
#define LEC 263
#define RIC 264
#define ME 265
#define KWARRAY 266
#define KWBEGIN 267
#define KWBOOLEAN 268
#define KWDEF 269
#define KWDO 270
#define KWELSE 271
#define KWEND 272
#define KWFALSE 273
#define KWFOR 274
#define KWINTEGER 275
#define KWIF 276
#define KWOF 277
#define KWPRINT 278
#define KWREAD 279
#define KWREAL 280
#define KWSTRING 281
#define KWTHEN 282
#define KWTO 283
#define KWTRUE 284
#define KWRETURN 285
#define KWVAR 286
#define KWWHILE 287
#define INTEGER 288
#define OCTNUM 289
#define FLOAT 290
#define SCIENTIFIC 291
#define STRING 292
#define OR 293
#define AND 294
#define NOT 295
#define ST 296
#define SET 297
#define EQUAL 298
#define BET 299
#define BT 300
#define SB 301
#define ADD 302
#define MINUS 303
#define STAR 304
#define SHOE 305
#define MOD 306
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    3,    2,    5,    5,    7,    7,    8,    8,
    9,    9,   11,   11,   12,   10,   10,   10,   10,   14,
   14,   15,   16,   16,   16,   16,    4,    4,   17,   17,
   18,   18,   19,   19,   20,   13,   13,   21,   21,   21,
   21,   21,   21,   21,    6,   22,   22,   23,   23,   24,
   24,   24,   24,   24,   24,   24,   25,   25,   25,   31,
   31,   33,   33,   34,   34,   34,   34,   36,   36,   36,
   36,   36,   36,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   32,   32,   32,   32,   26,   26,
   27,   28,   29,   35,   30,   37,   37,   38,   38,
};
static const short yylen[] = {                            2,
    5,    1,    1,    3,    1,    0,    2,    1,   10,    8,
    1,    0,    3,    1,    3,    1,    1,    1,    1,    1,
    1,    6,    1,    1,    1,    1,    1,    0,    2,    1,
    1,    1,    5,    5,    5,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    4,    1,    0,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    3,    3,    2,
    1,    4,    3,    1,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    2,    3,    3,    3,    3,    3,    1,
    3,    3,    3,    2,    1,    1,    1,    1,    8,    6,
    6,   10,    3,    4,    2,    1,    0,    3,    1,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    2,    0,    0,    0,    0,    0,   30,
   31,   32,   37,    0,    0,    0,    0,    0,    8,   29,
    0,    0,    1,    0,    0,    4,    7,   36,    0,   18,
   43,   16,   19,   17,   42,   38,   44,   40,   41,   39,
    0,    0,    0,    0,    0,   14,    0,    0,   23,   24,
   25,   26,    0,   33,   34,   35,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   50,    0,    0,   49,
   51,   52,   53,   54,   55,   56,    0,    0,    0,    0,
    0,   13,   20,   15,   21,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   80,
    0,    0,    0,    0,    0,   45,   48,    0,   95,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   58,   59,   93,    0,    0,
    0,    0,    0,   94,    0,   63,    0,    0,   81,    0,
    0,    0,    0,    0,   77,   78,   79,    0,   64,   67,
   68,   66,   69,   70,   71,   72,   73,    0,   57,   22,
   10,    0,    0,   62,    0,    0,    0,    0,    0,    0,
    0,   90,   91,    9,    0,    0,    0,   89,    0,   92,
};
static const short yydgoto[] = {                          2,
    3,    7,    4,    8,   17,   67,   18,   19,   44,   83,
   45,   46,   94,   84,   85,   53,    9,   10,   11,   12,
   95,   68,   69,   70,   71,   72,   73,   74,   75,   76,
   96,   97,   88,   98,   99,  100,  114,  115,
};
static const short yysindex[] = {                      -248,
    0,    0, -229,    0, -274, -231, -239, -213, -274,    0,
    0,    0,    0, -243, -248, -190, -178, -213,    0,    0,
 -167,  284,    0, -231, -274,    0,    0,    0, -196,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -156, -155, -153, -154, -152,    0, -202,  282,    0,    0,
    0,    0, -174,    0,    0,    0, -200, -231,  -54, -198,
 -140,   99,   99, -136,   99,   99,    0, -149,  282,    0,
    0,    0,    0,    0,    0,    0, -145, -135, -196, -178,
 -234,    0,    0,    0,    0,   99,   99, -138, -139, -198,
   99,   99,   99, -123,    0,    0,  288,  -68,    0,    0,
 -227, -127, -121, -137, -266,    0,    0,   99,    0, -134,
 -131, -112,  293, -109, -108,  139,   99, -196,  -38,  108,
 -256,  282,   99,   99,   99,   99,   99,   99,   99,  217,
  217,  217,  217,  217,  217,    0,    0,    0,  282,  -86,
  -54,  -99, -178,    0,   99,    0,  156, -124,    0, -203,
  132,  108, -256, -256,    0,    0,    0, -123,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -101,    0,    0,
    0,  -98,  293,    0, -196,  282, -114, -107,  -93,  -95,
  -87,    0,    0,    0,  282,  -79,  -71,    0,  -66,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -247,    0,    0,  -65,  245,    0,
    0,    0,    0,    0,    0,    0,    0,  -61,    0,    0,
    0,    0,    0,  -53,  259,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -52,    0,    0,  -57,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -43,
    0,    0,    0,    0,    0,    0,    0,    0, -199,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -49,    0, -110,    0,  -59,
    0,    0,    0,   65,  -10,   15,    0,    0,   40,    0,
    0,  -23,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -240,    0,  -37,    0,    0,    0,    0,  193,
  115, -191,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  221,  206,  122,  137,    0,    0,    0, -251,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -233,    0,    0,  -57,    0,    0,    0,    0,
    0,    0,    0,    0,  -57,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  235,    0,    0,  226,    0,  -16,    0,  239,    0,  -19,
    0,  195,   -1,  117,  237,  -73,    0,  252,    0,    0,
  -20, -115,    0,  194,    0,    0,    0,    0,    0,    0,
  -48,   53,    0,  218,  -34,    0,    0,    0,
};
#define YYTABLESIZE 599
static const short yytable[] = {                         77,
   26,   43,   41,  139,   14,  110,  150,   65,    1,   28,
   65,    6,   65,   78,   21,  103,   22,   99,   65,   28,
   77,   99,   47,  168,   98,   13,  123,  124,   98,    5,
   65,  136,   15,   30,   78,  125,  126,  127,  128,  129,
   32,   65,   65,   16,  148,   33,   34,  127,  128,  129,
   65,   65,   65,   65,   65,   21,   47,   59,   80,   81,
  181,  112,   86,  111,   87,  123,  124,  176,  177,  187,
   24,   46,   46,   77,  125,  126,  127,  128,  129,   47,
   47,  160,  160,  160,  160,  160,  160,   78,   25,   28,
   77,   49,   50,   51,   52,  162,  162,  162,  162,  162,
  162,  180,   54,   55,   78,   56,   58,   57,   79,  159,
  159,  159,  159,  159,  159,  101,   89,  104,  105,  108,
  102,  138,  106,  109,  117,  118,  172,   77,  158,  158,
  158,  158,  158,  158,   21,   87,   77,  137,  113,  116,
  142,   78,  141,  119,  120,  121,  143,   60,   60,  145,
   78,   60,  144,   60,   60,  123,  124,  171,  175,   60,
  140,  182,  183,  184,  125,  126,  127,  128,  129,  147,
  178,   60,  169,  179,  185,  151,  152,  153,  154,  155,
  156,  157,   60,   60,  186,   60,   60,   60,   60,   60,
   60,   60,   60,   60,   60,   60,  188,  173,   37,   37,
  189,    6,   37,  190,   37,    5,  123,  124,   12,   11,
   37,   29,   97,   30,   47,  125,  126,  127,  128,  129,
   32,   61,   37,  149,   96,   33,   34,  130,  131,  132,
  133,  134,  135,   37,   37,   61,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   85,   85,   23,
   48,   85,   82,   85,  123,  124,   27,  170,   42,   85,
   20,    0,  107,  125,  126,  127,  128,  129,    0,    0,
    0,   85,   88,   88,    0,    0,   88,    0,   88,    0,
    0,    0,   85,   85,   88,   64,   64,   64,   64,   64,
   64,   85,   85,   85,   85,   85,   88,   87,   87,    0,
    0,   87,    0,   87,    0,    0,    0,   88,   88,   87,
   67,   67,   67,   67,   67,   67,   88,   88,   88,   88,
   88,   87,    0,   86,    0,    0,   86,    0,   86,    0,
    0,    0,   87,   87,   86,   66,   66,   66,   66,   66,
   66,   87,   87,   87,   87,   87,   86,  161,  163,  164,
  165,  166,  167,    0,    0,   90,    0,   86,   86,   91,
   65,   65,   65,   65,   65,   65,   86,   86,   86,   86,
   86,   31,   74,   74,    0,    0,   74,    0,   74,   75,
   75,    0,   35,   75,   74,   75,   36,   37,   38,   39,
   40,   75,    0,   92,   76,   76,   74,    0,   76,    0,
   76,   93,  146,   75,    0,    0,   76,   74,   74,  125,
  126,  127,  128,  129,   75,   75,   74,   74,   76,  174,
    0,    0,    0,   75,   75,  124,    0,    0,    0,   76,
   76,  123,  124,  125,  126,  127,  128,  129,   76,   76,
  125,  126,  127,  128,  129,    0,    0,    0,  123,  124,
   84,   84,    0,    0,   84,    0,   84,  125,  126,  127,
  128,  129,   84,   82,   82,    0,    0,   82,    0,   82,
    0,    0,    0,   90,   84,   82,    0,    0,   83,   83,
    0,    0,   83,    0,   83,   84,   84,   82,    0,   31,
   83,    0,    0,    0,    0,    0,    0,    0,   82,   82,
   35,   27,   83,    0,   36,   37,   38,   39,   40,    0,
    0,   27,    0,   83,    0,   28,   27,    0,   27,    0,
   27,    0,   27,   27,    0,   28,    0,    0,    0,   27,
   28,   27,   28,    0,   28,    0,   28,   28,   60,    0,
    0,    0,    0,   28,    0,   28,    0,    0,   25,   29,
    0,   30,    0,    0,    0,   61,   31,   62,   32,   63,
   64,    0,    0,   33,   34,    0,   65,   35,   66,  122,
    0,   36,   37,   38,   39,   40,    0,    0,    0,    0,
  123,  124,    0,    0,    0,  123,  124,    0,    0,  125,
  126,  127,  128,  129,  125,  126,  127,  128,  129,
};
static const short yycheck[] = {                         48,
   17,   22,   22,  270,    6,   79,  122,  259,  257,  257,
  262,  286,  264,   48,  258,   64,  260,  258,  270,  267,
   69,  262,   24,  139,  258,  257,  293,  294,  262,  259,
  282,  259,  272,  268,   69,  302,  303,  304,  305,  306,
  275,  293,  294,  257,  118,  280,  281,  304,  305,  306,
  302,  303,  304,  305,  306,  258,   58,  260,  259,  260,
  176,   81,  261,   80,  263,  293,  294,  271,  272,  185,
  261,  271,  272,  122,  302,  303,  304,  305,  306,  271,
  272,  130,  131,  132,  133,  134,  135,  122,  267,  257,
  139,  288,  289,  290,  291,  130,  131,  132,  133,  134,
  135,  175,  259,  259,  139,  259,  259,  262,  283,  130,
  131,  132,  133,  134,  135,   63,  257,   65,   66,  265,
  257,  259,  272,  259,  263,  265,  143,  176,  130,  131,
  132,  133,  134,  135,  258,  263,  185,  259,   86,   87,
  272,  176,  277,   91,   92,   93,  259,  258,  259,  258,
  185,  262,  262,  264,  265,  293,  294,  257,  283,  270,
  108,  276,  270,  257,  302,  303,  304,  305,  306,  117,
  272,  282,  259,  272,  270,  123,  124,  125,  126,  127,
  128,  129,  293,  294,  272,  296,  297,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  276,  145,  258,  259,
  272,  267,  262,  270,  264,  267,  293,  294,  262,  262,
  270,  266,  262,  268,  272,  302,  303,  304,  305,  306,
  275,  265,  282,  262,  262,  280,  281,  296,  297,  298,
  299,  300,  301,  293,  294,  259,  296,  297,  298,  299,
  300,  301,  302,  303,  304,  305,  306,  258,  259,   15,
   25,  262,   58,  264,  293,  294,   18,  141,   22,  270,
    9,   -1,   69,  302,  303,  304,  305,  306,   -1,   -1,
   -1,  282,  258,  259,   -1,   -1,  262,   -1,  264,   -1,
   -1,   -1,  293,  294,  270,  296,  297,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  282,  258,  259,   -1,
   -1,  262,   -1,  264,   -1,   -1,   -1,  293,  294,  270,
  296,  297,  298,  299,  300,  301,  302,  303,  304,  305,
  306,  282,   -1,  259,   -1,   -1,  262,   -1,  264,   -1,
   -1,   -1,  293,  294,  270,  296,  297,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  282,  130,  131,  132,
  133,  134,  135,   -1,   -1,  257,   -1,  293,  294,  261,
  296,  297,  298,  299,  300,  301,  302,  303,  304,  305,
  306,  273,  258,  259,   -1,   -1,  262,   -1,  264,  258,
  259,   -1,  284,  262,  270,  264,  288,  289,  290,  291,
  292,  270,   -1,  295,  258,  259,  282,   -1,  262,   -1,
  264,  303,  264,  282,   -1,   -1,  270,  293,  294,  302,
  303,  304,  305,  306,  293,  294,  302,  303,  282,  264,
   -1,   -1,   -1,  302,  303,  294,   -1,   -1,   -1,  293,
  294,  293,  294,  302,  303,  304,  305,  306,  302,  303,
  302,  303,  304,  305,  306,   -1,   -1,   -1,  293,  294,
  258,  259,   -1,   -1,  262,   -1,  264,  302,  303,  304,
  305,  306,  270,  258,  259,   -1,   -1,  262,   -1,  264,
   -1,   -1,   -1,  257,  282,  270,   -1,   -1,  258,  259,
   -1,   -1,  262,   -1,  264,  293,  294,  282,   -1,  273,
  270,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  293,  294,
  284,  257,  282,   -1,  288,  289,  290,  291,  292,   -1,
   -1,  267,   -1,  293,   -1,  257,  272,   -1,  274,   -1,
  276,   -1,  278,  279,   -1,  267,   -1,   -1,   -1,  285,
  272,  287,  274,   -1,  276,   -1,  278,  279,  257,   -1,
   -1,   -1,   -1,  285,   -1,  287,   -1,   -1,  267,  266,
   -1,  268,   -1,   -1,   -1,  274,  273,  276,  275,  278,
  279,   -1,   -1,  280,  281,   -1,  285,  284,  287,  282,
   -1,  288,  289,  290,  291,  292,   -1,   -1,   -1,   -1,
  293,  294,   -1,   -1,   -1,  293,  294,   -1,   -1,  302,
  303,  304,  305,  306,  302,  303,  304,  305,  306,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","DOT","FAN","MO","LEG","RIG",
"LEC","RIC","ME","KWARRAY","KWBEGIN","KWBOOLEAN","KWDEF","KWDO","KWELSE",
"KWEND","KWFALSE","KWFOR","KWINTEGER","KWIF","KWOF","KWPRINT","KWREAD","KWREAL",
"KWSTRING","KWTHEN","KWTO","KWTRUE","KWRETURN","KWVAR","KWWHILE","INTEGER",
"OCTNUM","FLOAT","SCIENTIFIC","STRING","OR","AND","NOT","ST","SET","EQUAL",
"BET","BT","SB","ADD","MINUS","STAR","SHOE","MOD",
};
static const char *yyrule[] = {
"$accept : program",
"program : program_name FAN programbody KWEND program_name",
"program_name : identifier",
"identifier : ID",
"programbody : data_declarations functions compound_statement",
"functions : funs",
"functions :",
"funs : funs function_declaration",
"funs : function_declaration",
"function_declaration : ID LEG arguments RIG MO scalar_type FAN compound_statement KWEND ID",
"function_declaration : ID LEG arguments RIG FAN compound_statement KWEND ID",
"arguments : arg",
"arguments :",
"arg : arg FAN arglist",
"arg : arglist",
"arglist : idlist MO type",
"scalar_type : KWINTEGER",
"scalar_type : KWSTRING",
"scalar_type : KWBOOLEAN",
"scalar_type : KWREAL",
"type : scalar_type",
"type : array",
"array : KWARRAY integer KWTO integer KWOF type",
"integer : INTEGER",
"integer : OCTNUM",
"integer : FLOAT",
"integer : SCIENTIFIC",
"data_declarations : datas",
"data_declarations :",
"datas : datas data_declaration",
"datas : data_declaration",
"data_declaration : var_declaration",
"data_declaration : con_declaration",
"var_declaration : KWVAR idlist MO scalar_type FAN",
"var_declaration : KWVAR idlist MO array FAN",
"con_declaration : KWVAR idlist MO litcons FAN",
"idlist : idlist DOT ID",
"idlist : ID",
"litcons : INTEGER",
"litcons : STRING",
"litcons : FLOAT",
"litcons : SCIENTIFIC",
"litcons : KWTRUE",
"litcons : KWFALSE",
"litcons : OCTNUM",
"compound_statement : KWBEGIN data_declarations statements KWEND",
"statements : ss",
"statements :",
"ss : ss statement",
"ss : statement",
"statement : compound_statement",
"statement : simple_statement",
"statement : condition",
"statement : while",
"statement : for",
"statement : return",
"statement : stfuncinvo",
"simple_statement : var_ref ME expr FAN",
"simple_statement : KWPRINT expr FAN",
"simple_statement : KWREAD var_ref FAN",
"var_ref : ID array_ref",
"var_ref : ID",
"array_ref : array_ref LEC expr RIC",
"array_ref : LEC expr RIC",
"operand : litcons",
"operand : idlist",
"operand : funcinvo",
"operand : var_ref",
"boolexpr : operand ST operand",
"boolexpr : operand SET operand",
"boolexpr : operand EQUAL operand",
"boolexpr : operand BET operand",
"boolexpr : operand BT operand",
"boolexpr : operand SB operand",
"expr : MINUS expr",
"expr : expr ADD expr",
"expr : expr MINUS expr",
"expr : expr STAR expr",
"expr : expr SHOE expr",
"expr : expr MOD expr",
"expr : boolexpr",
"expr : LEG expr RIG",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",
"expr : litcons",
"expr : idlist",
"expr : funcinvo",
"expr : var_ref",
"condition : KWIF expr KWTHEN statements KWELSE statements KWEND KWIF",
"condition : KWIF expr KWTHEN statements KWEND KWIF",
"while : KWWHILE expr KWDO statements KWEND KWDO",
"for : KWFOR ID ME integer KWTO integer KWDO statements KWEND KWDO",
"return : KWRETURN expr FAN",
"funcinvo : ID LEG exprss RIG",
"stfuncinvo : funcinvo FAN",
"exprss : exprs",
"exprss :",
"exprs : exprs DOT expr",
"exprs : expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 198 "parser.y"

void yyerror(const char *msg) {

    fprintf(stderr,
            "\n"
            "|-----------------------------------------------------------------"
            "---------\n"
            "| Error found in Line #%d: %s\n"
            "|\n"
            "| Unmatched token: %s\n"
            "|-----------------------------------------------------------------"
            "---------\n",
            LineNum, Buffer, yytext);
    exit(-1);
}

int main(int argc, const char *argv[]) {
    
    CHECK(argc == 2, "Usage: ./parser <filename>\n");

    FILE *fp = fopen(argv[1], "r");

    
    CHECK(fp != NULL, "fopen() fails.\n");
    yyin = fp;
    
    
    yyparse();

    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");
    return 0;
}
#line 540 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
