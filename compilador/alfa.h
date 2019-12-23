#ifndef _ALFA_H
#define _ALFA_H
#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64

#include "generacion.h"
#include "tablasimbolos.h"


/* otros defines */
/*Aquí definimos todos los atributos que vamos a utilizar para el sintáctico.*/
/*Lexema: Lo utilizamos para almacenar el nombre si es dirección.*/
/*Valor_entero: Lo utilizamos para el valor del índice de un vector cuando es entero.*/
/*es_direccion: saber si es dirección o no*/
/*etiqueta: Para propagar correctamente el valor de la etiqueta en casos de condicionales y while*/
/*indice_lexema: En caso de que el índice sea dirección almacenamos aquí su lexema*/
/*indice_es_direccion: Para saber si el índice es dirección o no.*/
struct _tipo_atributos {
 char lexema[MAX_LONG_ID+1];
 int tipo;
 int valor_entero;
 int es_direccion;
 int etiqueta;
 char indice_lexema[MAX_LONG_ID+1];
 int indice_es_direccion;
};

typedef struct _tipo_atributos tipo_atributos;

#endif
