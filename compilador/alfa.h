#ifndef _ALFA_H
#define _ALFA_H
#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64

#include "generacion.h"
#include "tablasimbolos.h"


/* otros defines */
struct _tipo_atributos {
 char lexema[MAX_LONG_ID+1];
 int tipo;
 int valor_entero;
 int es_direccion;
 int etiqueta;
};

typedef struct _tipo_atributos tipo_atributos;

#endif
