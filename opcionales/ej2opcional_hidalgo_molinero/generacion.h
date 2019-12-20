#ifndef GENERACION_H
#define GENERACION_H

/* Declaraciones de tipos de datos del compilador */
#define ENTERO 1
#define BOOLEANO 0
#define MAX_ETIQUETAS 100

#include <stdio.h>






/* OBSERVACIÓN GENERAL A TODAS LAS FUNCIONES:
   Todas ellas escriben el código NASM a un FILE* proporcionado como primer argumento.
*/

void escribir_cabecera_bss(FILE* fpasm);
/*
   Código para el principio de la sección .bss.
   Con seguridad sabes que deberás reservar una variable entera para guardar el puntero de pila extendido (esp). Se te sugiere el nombre __esp para esta variable.
*/

void escribir_subseccion_data(FILE* fpasm);
/*
   Declaración (con directiva db) de las variables que contienen el texto de los mensajes para la identificación de errores en tiempo de ejecución.
   En este punto, al menos, debes ser capaz de detectar la división por 0.
*/

void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano);
/*
   Para ser invocada en la sección .bss cada vez que se quiera declarar una variable:
    • El argumento nombre es el de la variable.
    • tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes del principio del fichero).
    • Esta misma función se invocará cuando en el compilador se declaren vectores, por eso se adjunta un argumento final (tamano) que para esta primera práctica siempre recibirá el valor 1.
*/

void escribir_segmento_codigo(FILE* fpasm);
/*
   Para escribir el comienzo del segmento .text, básicamente se indica que se exporta la etiqueta main y que se usarán las funciones declaradas en la librería olib.o
*/

void escribir_inicio_main(FILE* fpasm);
/*
   En este punto se debe escribir, al menos, la etiqueta main y la sentencia que guarda el puntero de pila en su variable (se recomienda usar __esp).
*/

void escribir_operando(FILE* fpasm, char* nombre, int es_variable);

void asignar(FILE* fpasm, char* nombre, int es_variable);

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

void escribir_fin(FILE* fpasm);
/*
   Al final del programa se escribe:
    • El código NASM para salir de manera controlada cuando se detecta un error en tiempo de ejecución (cada error saltará a una etiqueta situada en esta zona en la que se imprimirá el correspondiente mensaje y se saltará a la zona de finalización del programa).
    • En el final del programa se debe:
         ·Restaurar el valor del puntero de pila (a partir de su variable __esp)
         ·Salir del programa (ret).
*/
void leer(FILE* fpasm, char* nombre, int tipo);

void escribir(FILE* fpasm, int es_variable, int tipo);

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

void suma_iterativa(FILE *fpasm, char *nombre1, char *nombre2);
/*
Genera el código NASM necesario para:

 * leer al menos dos operandos enteros del teclado
 * si el segundo operando es igual a 0, no hace nada más
 * si el segundo operando es distinto de 0
     * realizar y presentar por el terminal el resultado de la suma de los dos operandos
     * seguir leyendo operandos, acumulando la suma de cada operando al resultado y presentando este resultado por pantalla para cada operando introducido, hasta que el usuario introduzca un operando de valor igual a 0
*/

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

#endif
