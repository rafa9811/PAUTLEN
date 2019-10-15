/*********************************************************************************
** PRÁCTICA 1 PROYECTO DE AUTÓMATAS Y LENGUAJES. UNIVERSIDAD AUTÓNOMA DE MADRID **
** AUTORES:                                                                     **
**		- Rafael Hidalgo Alejo. (rafael.hidalgoa@estudiante.uam.es)               **
**		- Carlos Molinero Alvarado. (carlos.molineoa@estudiante.uam.es)           **
** ÚLTIMA MODIFICACIÓN: 30 de septiembre de 2019.                               **
**********************************************************************************/

#include <stdio.h>
#include "generacion.h"

/** Declaraciones de funciones que utilizaremos: **/
void escribir_cabecera_bss(FILE* fpasm);
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano);
void escribir_segmento_codigo(FILE* fpasm);
void escribir_subseccion_data(FILE* fpasm);
void escribir_inicio_main(FILE* fpasm);
void escribir_operando(FILE* fpasm, char* nombre, int es_variable);
void asignar(FILE* fpasm, char* nombre, int es_variable);
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void leer(FILE* fpasm, char* nombre, int tipo);
void escribir(FILE* fpasm, int es_variable, int tipo);
void sumar(FILE* fpasm, int es_variable1, int es_variable2);
void escribir_fin(FILE* fpasm);

/** Main: **/
int main(int argc, char **argv) {
  FILE *fpasm = NULL;
  int num = 0;

  if (argc != 2) {
    fprintf(stdout, "Error: pocos argumentos\n");
    return -1;
  }

  fpasm = fopen(argv[1], "w");

  escribir_subseccion_data(fpasm);
  escribir_cabecera_bss(fpasm);

  declarar_variable(fpasm, "x", ENTERO, 1);
  declarar_variable(fpasm, "y", ENTERO, 1);

  escribir_segmento_codigo(fpasm);

  escribir_inicio_main(fpasm);

  suma_iterativa(fpasm, "x", "y");

  escribir_fin(fpasm);

  fclose(fpasm);

  return 0;
}

