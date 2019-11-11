 /*Sección de definiciones*/

%{
#include <stdio.h>
int yyleng = 0;
int ncol = 0;
int nlin = 0;
%}

%option noyywrap


%%

main {ncol+=return TOK_MAIN;}
int {return TOK_INT;}
boolean {return TOK_BOOLEAN;}
array {return TOK_ARRAY;}
function {return TOK_FUNCTION;}
if {return TOK_IF;}
else {return TOK_ELSE;}
while {return TOK_WHILE;}
scanf {return TOK_SCANF;}
printf {return TOK_PRINTF;}
return {return TOK_RETURN;}




";" {return TOK_PUNTOYCOMA;}
"," {return TOK_PUNTOYCOMA;}
"(" {return TOK_PARENTESISIZQUIERDO;}
")" {return TOK_PARENTESISDERECHO;}
"[" {return TOK_CORCHETEIZQUIERDO;}
"]" {return TOK_CORCHETEDERECHO;}
"{" {return TOK_LLAVEIZQUIERDA;}
"}" {return TOK_LLAVEDERECHA;}
"=" {return TOK_ASIGNACION;}
"+" {return TOK_MAS;}
"-" {return TOK_MENOS;}
"/" {return TOK_DIVISION;}
"*" {return TOK_ASTERISCO;}
&& {return TOK_AND;}
|| {return TOK_OR;}
! {return TOK_NOT;}
== {return TOK_IGUAL;}
!= {return TOK_DISTINTO;}
<= {return TOK_MENORIGUAL;}
>= {return TOK_MAYORIGUAL;}
< {return TOK_MENOR;}
> {return TOK_MAYOR;}



[A-Za-z][A-Za-z0-9]* {return TOK_IDENTIFICADOR;}
" "
\t {return;}
\n
true {return TOK_TRUE;}
false {return TOK_FALSE;}

. {return TOK_ERROR;}
%%


}
