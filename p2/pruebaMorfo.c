#include "tokens.h"
#include <stdio.h>
int yylex();


int main(int argc, char** argv){
   extern int yyleng;
   extern int nlin, ncol;
   extern FILE* yyin;
   extern char* yytext;
   char* entrada, *salida;
   FILE* fentrada, *fsalida;
   int leido;
   if (argc!=3){
      fprintf(stderr, "Error en el número de parámetros de entrada");
   }
   entrada = argv[1];
   salida = argv[2];
   fentrada = fopen(entrada, "r");
   fsalida = fopen(salida, "w");
   yyin = fentrada;
   //Damos valor inicial para que entre en el bucle:
   leido = 1;
   printf("HOL\n");
   //Si lo que hemos leído es cero, es que hemos terminado.
   while(leido != 0){
     printf("Ey\n");
      leido = yylex();
      printf("%d\n", leido);
      printf("%s\n",yytext);

      switch(leido){
      case TOK_MAIN:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_MAIN", TOK_MAIN, yytext);
         break;

      case TOK_INT:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_INT", TOK_INT, yytext);
         break;

      case TOK_BOOLEAN:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_BOOLEAN", TOK_BOOLEAN, yytext);
         break;


      case TOK_ARRAY:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_ARRAY", TOK_ARRAY, yytext);
         break;

      case TOK_FUNCTION:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_FUNCTION", TOK_FUNCTION, yytext);
         break;

      case TOK_IF:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_IF", TOK_IF, yytext);
         break;


      case TOK_ELSE:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_ELSE", TOK_ELSE, yytext);
         break;



      case TOK_WHILE:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_WHILE", TOK_WHILE, yytext);
         break;



      case TOK_SCANF:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_SCANF", TOK_SCANF, yytext);
         break;


      case TOK_PRINTF:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_PRINTF", TOK_PRINTF, yytext);
         break;

      case TOK_RETURN:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_RETURN", TOK_RETURN, yytext);
         break;

      case TOK_PUNTOYCOMA:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_PUNTOYCOMA", TOK_PUNTOYCOMA, yytext);
         break;

      case TOK_COMA:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_COMA", TOK_COMA, yytext);
         break;

      case TOK_PARENTESISIZQUIERDO:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_PARENTESISIZQUIERDO", TOK_PARENTESISIZQUIERDO, yytext);
         break;

      case TOK_PARENTESISDERECHO:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_PARENTESISDERECHO", TOK_PARENTESISDERECHO, yytext);
         break;


      case TOK_CORCHETEIZQUIERDO:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_CORCHETEIZQUIERDO", TOK_CORCHETEIZQUIERDO, yytext);
         break;

      case TOK_CORCHETEDERECHO:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_CORCHETEDERECHO", TOK_CORCHETEDERECHO, yytext);
         break;

      case TOK_LLAVEIZQUIERDA:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_LLAVEIZQUIERDA", TOK_LLAVEIZQUIERDA, yytext);
         break;

      case TOK_LLAVEDERECHA:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_LLAVEDERECHA", TOK_LLAVEDERECHA, yytext);
         break;

      case TOK_ASIGNACION:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_ASIGNACION", TOK_ASIGNACION, yytext);
         break;

      case TOK_MAS:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_MAS", TOK_MAS, yytext);
         break;

      case TOK_MENOS:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_MENOS", TOK_MENOS, yytext);
         break;

      case TOK_DIVISION:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_DIVISION", TOK_DIVISION, yytext);
         break;

      case TOK_ASTERISCO:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_ASTERISCO", TOK_ASTERISCO, yytext);
         break;


      case TOK_AND:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_AND", TOK_AND, yytext);
         break;

      case TOK_OR:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_OR", TOK_OR, yytext);
         break;

      case TOK_NOT:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_NOT", TOK_NOT, yytext);
         break;

      case TOK_IGUAL:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_IGUAL", TOK_IGUAL, yytext);
         break;

      case TOK_DISTINTO:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_DISTINTO", TOK_DISTINTO, yytext);
         break;

      case TOK_MENORIGUAL:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_MENORIGUAL", TOK_MENORIGUAL, yytext);
         break;

      case TOK_MAYORIGUAL:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_MAYORIGUAL", TOK_MAYORIGUAL, yytext);
         break;

      case TOK_MENOR:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_MENOR", TOK_MENOR, yytext);
         break;

      case TOK_MAYOR:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_MAYOR", TOK_MAYOR, yytext);
         break;

      case TOK_IDENTIFICADOR:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_IDENTIFICADOR", TOK_IDENTIFICADOR, yytext);
         break;

      case TOK_CONSTANTE_ENTERA:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_CONSTANTE_ENTERA", TOK_CONSTANTE_ENTERA, yytext);
         break;

      case TOK_TRUE:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_TRUE", TOK_TRUE, yytext);
         break;

      case TOK_FALSE:
         fprintf(fsalida, "%s\t%d\t%s\n", "TOK_FALSE", TOK_FALSE, yytext);
         break;

      case TOK_ERROR:
         if(yyleng >= 100){
            fprintf(stderr, "TOK_ERROR: IDENTIFICADOR DE LONGITUD > 100 en línea %d, columna %d\n", nlin, ncol);
         }
         else{
            fprintf(stderr, "TOK_ERROR: CADENA NO RECONOCIDA en línea %d, columna %d\n", nlin, ncol);
         }
         return 0;

      default:
         break;
      }
    }
      fclose(fentrada);
      fclose(fsalida);

      return 0;





}
