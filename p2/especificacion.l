 /*Sección de definiciones*/

%{
#include "tokens.h"
int ncol = 0;
int nlin = 0;
%}

%option noyywrap


%%

main {ncol+=yyleng; return TOK_MAIN;}
int {ncol+=yyleng; return TOK_INT;}
boolean {ncol+=yyleng; return TOK_BOOLEAN;}
array {ncol+=yyleng; return TOK_ARRAY;}
function {ncol+=yyleng; return TOK_FUNCTION;}
if {ncol+=yyleng; return TOK_IF;}
else {ncol+=yyleng; return TOK_ELSE;}
while {ncol+=yyleng; ncol+=yyleng; return TOK_WHILE;}
scanf {ncol+=yyleng; return TOK_SCANF;}
printf {ncol+=yyleng; return TOK_PRINTF;}
return {ncol+=yyleng; return TOK_RETURN;}




";" {ncol+=yyleng; return TOK_PUNTOYCOMA;}
"," {ncol+=yyleng; return TOK_COMA;}
"(" {ncol+=yyleng; return TOK_PARENTESISIZQUIERDO;}
")" {ncol+=yyleng; return TOK_PARENTESISDERECHO;}
"[" {ncol+=yyleng; return TOK_CORCHETEIZQUIERDO;}
"]" {ncol+=yyleng; return TOK_CORCHETEDERECHO;}
"{" {ncol+=yyleng; return TOK_LLAVEIZQUIERDA;}
"}" {ncol+=yyleng; return TOK_LLAVEDERECHA;}
"=" {ncol+=yyleng; return TOK_ASIGNACION;}
"+" {ncol+=yyleng; return TOK_MAS;}
"-" {ncol+=yyleng; return TOK_MENOS;}
"/" {ncol+=yyleng; return TOK_DIVISION;}
"*" {ncol+=yyleng; return TOK_ASTERISCO;}
"&&" {ncol+=yyleng; return TOK_AND;}
"||" {ncol+=yyleng; return TOK_OR;}
"!" {ncol+=yyleng; return TOK_NOT;}
"==" {ncol+=yyleng; return TOK_IGUAL;}
"!=" {ncol+=yyleng; return TOK_DISTINTO;}
"<=" {ncol+=yyleng; return TOK_MENORIGUAL;}
">=" {ncol+=yyleng; return TOK_MAYORIGUAL;}
"<" {ncol+=yyleng; return TOK_MENOR;}
">" {ncol+=yyleng; return TOK_MAYOR;}



" " {ncol++;}
\t {ncol++;}
\n {nlin++;}
"//".*\n {ncol+=yyleng; nlin++;}
true {ncol+=yyleng; return TOK_TRUE;}
false {ncol+=yyleng; return TOK_FALSE;}
[A-Za-z][A-Za-z0-9]{0,99} {ncol+=yyleng; return TOK_IDENTIFICADOR;}
[A-Za-z][A-Za-z0-9]{100,1000} {ncol+=yyleng; return TOK_ERROR;}
[0-9]+ {ncol+=yyleng; return TOK_CONSTANTE_ENTERA;}

. {ncol+=yyleng; return TOK_ERROR;}
%%
