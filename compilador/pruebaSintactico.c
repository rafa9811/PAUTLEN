
#include "y.tab.h"
#include <stdio.h>

#define OK 0
#define ERROR -1

FILE *out;


int main(int argc, char** argv) {
   extern int nlin, ncol, yyleng;
   extern FILE* yyin;
   extern char* yytext;
   char* entrada, *salida;
   FILE *in;
   int leido;
   if (argc != 3){
      fprintf(stderr, "Error en el número de parámetros de entrada");
      return -1;
   }
   entrada = argv[1];
   fprintf(stdout, "%s\n", entrada);
   salida = argv[2];
   fprintf(stdout, "%s\n", salida);
   in = fopen(entrada, "r");
   if(!in) {
      fprintf(stderr, "No se encuentra el fichero de entrada\n");
      return ERROR;
   }
   out = fopen(salida, "w");
   if(!out) {
      fprintf(stderr, "No se encuentra el fichero de salida\n");
      return ERROR;
   }

   yyin = in;

   yyparse();

   fclose(in);
   fclose(out);

   return OK;

}
