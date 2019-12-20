#include <stdio.h>
#include <stdlib.h>
#include "alfa.h"

/* Tabla de símbolos global */
hashtable_t *hash_global;
hashtable_t *hash_local;
int flaglocal;
FILE *out;


int main(int argc, char **argv) {

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
  if( !in ) {
    fprintf(stderr, "No se encuentra el fichero de entrada\n");
    return -1;
  }
  out = fopen(salida, "w");
  if( !out ) {
    fprintf(stderr, "No se encuentra el fichero de salida\n");
    return -1;
  }

  yyin = in;

  hash_global = ht_create( 65536 );
  flaglocal = 0;

  yyparse();

  fclose(in);
  fclose(out);

  return 0;
}
