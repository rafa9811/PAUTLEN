
#include "y.tab.h"
#include <stdio.h>

FILE *out;


int main(int argc, char** argv){
   extern int yyleng;
   extern int nlin, ncol;
   extern FILE* yyin;
   extern char* yytext;
   char* entrada, *salida;
   FILE* fentrada, *out;
   int leido;
   if (argc!=3){
      fprintf(stderr, "Error en el número de parámetros de entrada");
      return -1;
   }
   entrada = argv[1];
   salida = argv[2];
   fentrada = fopen(entrada, "r");
   out = fopen(salida, "w");
   yyin = fentrada;

   yyparse();
   fclose(fentrada);
   fclose(out);

   return 0;





}
