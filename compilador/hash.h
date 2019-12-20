#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux.  See feature_test_macros(7) */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define VARIABLE 0
#define PARAMETRO 1
#define FUNCION 2
/* Categoría de un símbolo: variable, parámetro de función o función */
// typedef enum { VARIABLE, PARAMETRO, FUNCION } CATEGORIA_SIMBOLO;

#define ENTERO 1
#define BOOLEANO 0
/* Tipo de un símbolo: sólo se trabajará con enteros y booleanos */
// typedef enum { BOOLEANO, ENTERO } TIPO;

/* Categoría de la variable: puede ser variable atómicas (escalar) o lista/array (vector) */
// typedef enum { ESCALAR, VECTOR } CATEGORIA;
#define ESCALAR 0
#define VECTOR 1

/* Información de un símbolo */
typedef struct simbolo_s {
    char *identificador;                /* identificador */
    int cat_simbolo;      /* categoría del simbolo */
    int tipo;                          /* tipo */
    int categoria;                /* categoria de la variable */
    int valor;                          /* valor si escalar */
    int longitud;                       /* longitud si vector */
    int num_parametros;                 /* número de parámetros si función */
    int posicion;                       /* posición en llamada a función si parámetro, posición de declaración si variable local de función */
    int num_var_locales;                /* número de variables locales si función */
} SIMBOLO;

typedef struct entry_s entry_t;
typedef struct hashtable_s hashtable_t;

hashtable_t *ht_create( int size );
int ht_hash( hashtable_t *hashtable, char *key );
entry_t *ht_newpair( char *key, SIMBOLO *value );
int ht_set( hashtable_t *hashtable, char *key, SIMBOLO *value );
SIMBOLO *ht_get( hashtable_t *hashtable, char *key );
