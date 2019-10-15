#include <stdio.h>
#include "generacion.h"
int main (int argc, char** argv)
{
  FILE * salida;
  int etiqueta = 0;
  int getiqueta = 0;
  int etiquetas[MAX_ETIQUETAS];
  int cima_etiquetas=-1;

  if (argc != 2) {
    fprintf (stdout, "ERROR POCOS ARGUMENTOS\n");
    return -1;
  }
  salida = fopen(argv[1],"w");
  escribir_subseccion_data(salida);
  escribir_cabecera_bss(salida);
  declarar_variable(salida, "b1", BOOLEANO, 1);
  declarar_variable(salida, "x", ENTERO, 1);
  escribir_segmento_codigo(salida);
  escribir_inicio_main(salida);
  /* b1 = true; */
  escribir_operando(salida, "1", 0);
  asignar(salida, "b1", 0);
  /* Incluye aqui el codigo necesario para
  while (b1) {
    scanf x;
    b1 = x > 4;
    if (b1) {
      printf x;
    }
    else {
      printf false;
    }
  }
  */
  //Antes de un while
  getiqueta++;
  cima_etiquetas++;
  etiquetas[cima_etiquetas]=getiqueta;
  etiqueta = getiqueta;
  while_inicio(salida, etiqueta);
  escribir_operando(salida, "b1", 1);
  escribir_operando(salida, "1", 0);
  igual(salida,1, 0, etiqueta);
  etiqueta = etiquetas[cima_etiquetas];
  while_exp_pila(salida, 0, etiqueta);
  //AHora hacemos lo que está dentro del while
  leer(salida, "x", ENTERO);
  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "4", 0);
  mayor(salida,1, 0, etiqueta);
  asignar(salida, "b1", 0);
  //Ahora entramos en el if
  getiqueta++;
  cima_etiquetas++;
  etiquetas[cima_etiquetas]=getiqueta;
  etiqueta = getiqueta;
  escribir_operando(salida, "b1", 1);
  escribir_operando(salida, "1", 0);
  igual(salida,1, 0, etiqueta);
  ifthenelse_inicio(salida, 0, etiqueta);
  //Ahora hacemos lo que está dentro del if si se cumple.
  escribir_operando(salida, "x", 1);
  escribir(salida, 1, ENTERO);

  etiqueta = etiquetas[cima_etiquetas];
  ifthenelse_fin_then(salida, etiqueta);

  escribir_operando(salida, "0", 0);
  escribir(salida, 0, BOOLEANO);
  //Terminamos if
  etiqueta = etiquetas[cima_etiquetas];
  ifthenelse_fin(salida, etiqueta);

  cima_etiquetas--;

  //Cerramos el while
  etiqueta = etiquetas[cima_etiquetas];
  while_fin(salida, etiqueta);
  cima_etiquetas--;

  escribir_fin(salida);
  fclose(salida);
  return 0;
}
