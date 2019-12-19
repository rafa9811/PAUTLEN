 /*Sección de definiciones*/

%{
#include "y.tab.h"
int ncol = 0;
int nlin = 0;
int is_morpho = 0;

char *yytext;
extern FILE *out;

void yyerror(const char * s);
%}

%option noyywrap

%%
main {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_MAIN;}
int {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_INT;}
boolean {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_BOOLEAN;}
array {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_ARRAY;}
function {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_FUNCTION;}
if {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_IF;}
else {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_ELSE;}
while {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); ncol+=yyleng; return TOK_WHILE;}
scanf {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_SCANF;}
printf {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_PRINTF;}
return {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_RETURN;}

";" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_PUNTOYCOMA;}
"," {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_COMA;}
"(" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_PARENTESISIZQUIERDO;}
")" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_PARENTESISDERECHO;}
"[" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_CORCHETEIZQUIERDO;}
"]" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_CORCHETEDERECHO;}
"{" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_LLAVEIZQUIERDA;}
"}" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_LLAVEDERECHA;}
"=" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_ASIGNACION;}
"+" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_MAS;}
"-" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_MENOS;}
"/" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_DIVISION;}
"*" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_ASTERISCO;}
"&&" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_AND;}
"||" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_OR;}
"!" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_NOT;}
"==" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_IGUAL;}
"!=" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_DISTINTO;}
"<=" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_MENORIGUAL;}
">=" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_MAYORIGUAL;}
"<" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_MENOR;}
">" {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_MAYOR;}

" " {ncol++;}
\t {ncol++;}
\n {nlin++;ncol=0;}
"//".*\n {ncol=0; nlin++;}
true {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_TRUE;}
false {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); return TOK_FALSE;}
[A-Za-z][A-Za-z0-9]{0,99} {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); strcpy(yylval.atributos.lexema, yytext); return TOK_IDENTIFICADOR;}
[A-Za-z][A-Za-z0-9]{100,} {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); is_morpho =1; return TOK_ERROR;}
[0-9]+ {ncol+=yyleng; fprintf(out, ";D:\t%s\n", yytext); yylval.atributos.valor_entero = atoi(yytext); return TOK_CONSTANTE_ENTERA;}

. {ncol+=yyleng; is_morpho = 1; printf("****Error sintactico en [lin %d, col %d]\n", nlin, ncol); return TOK_ERROR;}

%%
