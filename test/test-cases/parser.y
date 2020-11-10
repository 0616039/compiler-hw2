%{
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
%}

%token ID
%token DOT
%token FAN
%token MO
%token LEG
%token RIG
%token LEC
%token RIC
%token ME
%token KWARRAY
%token KWBEGIN
%token KWBOOLEAN
%token KWDEF
%token KWDO
%token KWELSE
%token KWEND
%token KWFALSE
%token KWFOR
%token KWINTEGER
%token KWIF
%token KWOF
%token KWPRINT
%token KWREAD
%token KWREAL
%token KWSTRING
%token KWTHEN
%token KWTO
%token KWTRUE
%token KWRETURN
%token KWVAR
%token KWWHILE
%token INTEGER
%token OCTNUM
%token FLOAT
%token SCIENTIFIC
%token STRING


%left OR
%left AND
%left NOT
%left ST SET EQUAL BET BT SB
%left ADD MINUS
%left STAR SHOE MOD
%%

//program
program : program_name FAN programbody KWEND ID
        ;
program_name: identifier
        ;

identifier  : ID
        ;
programbody : data_declarations functions compound_statement 
            ;
//function
function_declaration: ID LEG arguments RIG MO scalar_type FAN compound_statement KWEND ID
                    | ID LEG arguments RIG FAN compound_statement KWEND ID
                    ;
functions: functions function_declaration
         | function_declaration
         |
         ;
arguments : arglist MO scalar_type
          |
          ;
arglist : arglist DOT ID
        | ID
        ;
scalar_type: KWINTEGER | KWSTRING | KWBOOLEAN | KWREAL | array;

array: KWARRAY integer KWTO integer KWOF scalar_type
     ;

integer: INTEGER | OCTNUM | FLOAT | SCIENTIFIC;

//Data Types and Declarations
data_declaration: var_declaration | con_declaration
                ;
var_declaration : KWVAR idlist MO scalar_type FAN
                | KWVAR idlist MO array FAN
                ;
con_declaration : KWVAR idlist MO litcons FAN
                ;
idlist  : idlist DOT ID
        | ID
        ;

litcons : INTEGER | STRING | FLOAT | SCIENTIFIC | KWTRUE | KWFALSE | OCTNUM
        ;

//Statements
compound_statement  : KWBEGIN data_declarations statements KWEND
                    ;
data_declarations: data_declarations data_declaration 
                 | data_declaration
                 | 
                 ;
statements: statements statement 
          | statement
          | 
          ;
statement: compound_statement| simple_statement| condition | while | for | return |stfuncinvo;

simple_statement: var_ref ME expr FAN
                | KWPRINT var_ref FAN
                | KWPRINT expr FAN
                | KWREAD var_ref FAN
                ;
var_ref : ID array_ref
        | ID
        ; 
array_ref: array_ref LEC expr RIC 
         | LEC expr RIC array_ref
         ;
operand : litcons
        | funcinvo
        | var_ref
        ;
boolexpr : operand ST operand 
         | operand SET operand 
         | operand  EQUAL operand
         | operand BET operand
         | operand BT operand
         | operand SB operand
         ;
expr: expr MINUS expr
    | expr ADD expr
    | MINUS expr 
    | expr STAR expr
    | expr SHOE expr
    | expr MOD expr
    | LEG expr RIG
    | expr AND expr
    | expr OR expr
    | MINUS expr %prec STAR
    | NOT expr
    | boolexpr
    | litcons
    | funcinvo
    | var_ref
    | integer
    ;

condition: KWIF expr KWTHEN statements KWELSE statements KWEND KWIF
         | KWIF expr KWTHEN statements KWEND KWIF
         ;
while: KWWHILE expr KWDO statements KWEND KWDO
     ;

for : KWFOR ID ME  integer KWTO integer KWDO statements KWEND KWDO
    ;

return : KWRETURN expr FAN
       ;
funcinvo: ID LEG exprss RIG
        ;
stfuncinvo  : funcinvo FAN
        ;
exprss  : exprss DOT expr
        | expr
        |
        ;

%%

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
