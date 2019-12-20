/*********************************************************************
** PROYECTO DE AUTÓMATAS Y LENGUAJES - PRÁCTICA 1
** generacion.h
** AUTORES:
**  - Carlos Molinero Alvarado - carlos.molineroa@estudiante.uam.es
**  - Rafael Hidalgo Alejo - rafael.hidalgoa@estudiante.uam.es
** ÚLTIMA MODIFICACIÓN: 28 de octubre de 2019.
**********************************************************************/

#ifndef GENERACION_H
#define GENERACION_H

#include <stdio.h>
#include <stdlib.h>

/* Declaraciones de tipos de datos del compilador */
#define ENTERO 1
#define BOOLEANO 0
#define MAX_ETIQUETAS 100

/******************
** PRIMERA PARTE **
*******************/

void escribir_cabecera_bss(FILE* fpasm);
void escribir_subseccion_data(FILE* fpasm);
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano);
void escribir_segmento_codigo(FILE* fpasm);
void escribir_inicio_main(FILE* fpasm);
void escribir_fin(FILE* fpasm);
void asignar(FILE* fpasm, char* nombre, int es_variable);


/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
void sumar(FILE* fpasm, int es_variable1, int es_variable2);
void restar(FILE* fpasm, int es_variable_1, int es_variable_2);
void dividir(FILE* fpasm, int es_variable1, int es_variable2);
void multiplicar(FILE* fpasm, int es_variable1, int es_variable2);
void o(FILE* fpasm, int es_variable_1, int es_variable_2);
void y(FILE* fpasm, int es_variable_1, int es_variable_2);
void cambiar_signo(FILE* fpasm, int es_variable);
void no(FILE* fpasm, int es_variable, int cuantos_no);


/* FUNCIONES COMPARATIVAS */
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);


/* FUNCIONES DE ESCRITURA Y LECTURA */
void leer(FILE* fpasm, char* nombre, int tipo);
void escribir(FILE* fpasm, int es_variable, int tipo);


/******************
** SEGUNDA PARTE **
*******************/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable);
void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros);
void escribirVariableLocal(FILE* fpasm, int posicion_variable_local);
void declararFuncion(FILE * fpasm, char * nombre_funcion, int num_var_loc);

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
void ifthen_fin(FILE * fpasm, int etiqueta);
void ifthenelse_fin_then( FILE * fpasm, int etiqueta);
void ifthenelse_fin( FILE * fpasm, int etiqueta);

void while_inicio(FILE * fpasm, int etiqueta);
void while_exp_pila(FILE * fpasm, int exp_es_variable, int etiqueta);
void while_fin( FILE * fpasm, int etiqueta);

void escribir_elemento_vector(FILE * fpasm, char* nombre_vector, int tam_max, int exp_es_direccion);
void asignarDestinoEnPila(FILE* fpasm, int es_variable);
void llamarFuncion(FILE * fpasm, char * nombre_funcion, int num_argumentos);
void retornarFuncion(FILE * fpasm, int es_variable);
void operandoEnPilaAArgumento(FILE * fpasm, int es_variable);
void limpiarPila(FILE * fpasm, int num_argumentos);

#endif
