%{
#include <stdint.h>
#include "error.h"
#include "y.tab.h"

#define LIST                strCat(yytext)
#define token(t)            {LIST; if (OptTok) printf("<%s>\n", #t);}
#define tokenChar(t)       {LIST; if (OptTok) printf("<%c>\n", (t));}
#define TOKEN_STRING(t, s)  {LIST; if (OptTok) printf("<%s: %s>\n", #t, (s));}
#define MAX_LINE_LENG       512

int32_t LineNum = 1;
char Buffer[MAX_LINE_LENG];

static int32_t OptSrc = 1;
static int32_t OptTok = 1;
static char StringLiteral[MAX_LINE_LENG];
static char *BufferPtr = Buffer;

static void strCat(const char *Text);

%}

integer 0|[1-9][0-9]*
float {integer}\.(0|[0-9]*[1-9])

%x CCOMMENT

%%

","     { tokenChar(','); return DOT;}
";"     { tokenChar(';'); return FAN;}
":"     { tokenChar(':'); return MO;}
"("     { tokenChar('('); return LEG;}
")"     { tokenChar(')'); return RIG;}
"["     { tokenChar('['); return LEC;}
"]"     { tokenChar(']'); return RIC;}

"+"     { tokenChar('+'); return ADD;}
"-"     { tokenChar('-'); return MINUS;}
"*"     { tokenChar('*'); return STAR;}
"/"     { tokenChar('/'); return SHOE;}
":="    { token(:=); return ME;}
"<"     { tokenChar('<'); return ST;}
"<="    { token(<=); return SET;}
"<>"    { token(<>); return SB;}
">="    { token(>=); return BET;}
">"     { tokenChar('>'); return BT;}
"="     { tokenChar('='); return EQUAL;}
"and"   { token(and); return AND;}
"or"    { token(or); return OR;}
"not"   { token(not); return NOT;}
"mod"   { token(mod); return MOD;}

"array"     { token(KWarray); return KWARRAY;}
"begin"     { token(KWbegin); return KWBEGIN;}
"boolean"   { token(KWboolean); return KWBOOLEAN;}
"def"       { token(KWdef); return KWDEF;}
"do"        { token(KWdo); return KWDO;}
"else"      { token(KWelse); return KWELSE;}
"end"       { token(KWend); return KWEND;}
"false"     { token(KWfalse); return KWFALSE;}
"for"       { token(KWfor); return KWFOR;}
"integer"   { token(KWinteger); return KWINTEGER;}
"if"        { token(KWif); return KWIF;}
"of"        { token(KWof); return KWOF;}
"print"     { token(KWprint); return KWPRINT;}
"read"      { token(KWread); return KWREAD;}
"real"      { token(KWreal); return KWREAL;}
"string"    { token(KWstring); return KWSTRING;}
"then"      { token(KWthen); return KWTHEN;}
"to"        { token(KWto); return KWTO;}
"true"      { token(KWtrue); return KWTRUE;}
"return"    { token(KWreturn); return KWRETURN;}
"var"       { token(KWvar); return KWVAR;}
"while"     { token(KWwhile); return KWWHILE;}


    /* Identifier */
[a-zA-Z][a-zA-Z0-9]* { TOKEN_STRING(id, yytext); return ID;}

    /* Integer (decimal/octal) */
{integer} { TOKEN_STRING(integer, yytext); return INTEGER;}
0[0-7]+   { TOKEN_STRING(oct_integer, yytext); return OCTNUM;}

    /* Floating-Point */
{float} { TOKEN_STRING(float, yytext); return FLOAT;}

    /* Scientific Notation [Ee][+-]?[0-9]+ */
({integer}|{float})[Ee][+-]?({integer}) { TOKEN_STRING(scientific, yytext); return SCIENTIFIC;}

    /* String */
\"([^"\n]|\"\")*\" {
    char *YytextPtr = yytext;
    char *StrPtr = StringLiteral;

    /* Condition guard of the end of string literal
       Check only when *YytextPtr == '"' */
    while (*(YytextPtr + 1) != '\0') {
        ++YytextPtr;

        /* Handle the situation of double quotes */
        if (*YytextPtr == '"' && *(YytextPtr + 1) != '\0')
            *StrPtr++ = *YytextPtr++;

        while (*YytextPtr != '"')
            *StrPtr++ = *YytextPtr++;
    }
    *StrPtr = '\0';
    TOKEN_STRING(string, StringLiteral);
    return STRING;
}
    /* Whitespace */
[ \t]+ { LIST; }

    /* Pseudocomment */
"//&"[ST][+-].* {
    LIST;
    char option = yytext[3];
    switch (option) {
    case 'S':
        OptSrc = (yytext[4] == '+') ? 1 : 0;
        break;
    case 'T':
        OptTok = (yytext[4] == '+') ? 1 : 0;
        break;
    }
}

    /* C++ Style Comment */
"//".* { LIST; }

    /* C Style Comment */
"/*"           { LIST; BEGIN(CCOMMENT); }
<CCOMMENT>"*/" { LIST; BEGIN(INITIAL); }
<CCOMMENT>.    { LIST; }

    /* Newline */
<INITIAL,CCOMMENT>\n {
    if (OptSrc)
        printf("%d: %s\n", LineNum, Buffer);
    ++LineNum;
    Buffer[0] = '\0';
    BufferPtr = Buffer;
}

    /* Catch the character which is not accepted by rules above */


%%

static void strCat(const char *Text) {
    while (*Text) {
        *BufferPtr++ = *Text++;
    }
    *BufferPtr = '\0';
}