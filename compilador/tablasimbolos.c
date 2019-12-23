#include "tablasimbolos.h"


/* Con esta función cerramos ámbito cuando se nos lo indique.*/

int cerrarAmbito( tablas_simbolos *hashes) {
  if( hashes->flaglocal == 0 ) return -1;

  else {
    free( hashes->hash_local );
    hashes->flaglocal = 0;
	return 0;
  }
}

/*Insertamos en la tabla correspondiente comprobando el valor de la flag_local.
Si la clave ya estaba en la tabla, lo actualizamos.*/
int insertarTabla( tablas_simbolos *hashes, char *key, SIMBOLO *valor ) {
  int value_res;
  if( hashes->flaglocal == 1 ) {
      /* En este caso, tenemos que interactuar con la tabla hash local.*/
      value_res = ht_set( hashes->hash_local, key, valor );
      /* Si no hemos logrado insertar, devolvemos -1.*/
      if( value_res == -1 ) return -1;
      /* Devolvemos éxito en la inserción*/
      else return 0;
  }
  else {
    /* En este caso estamos en la tabla global.*/
    value_res = ht_set( hashes->hash_global, key, valor );

    if( value_res == -1 ) return -1;

    if( valor->cat_simbolo == FUNCION ) {
      /* Creamos la tabla local para abrir ámbito.*/
      if( hashes->flaglocal != 0 ) return -1;
      hashes->flaglocal = 1;
      hashes->hash_local = ht_create( 65536 );
	  /*Introducimos en la tabla local.*/
      value_res = ht_set( hashes->hash_local, key, valor );

      if( value_res == -1 ) return -1;
    }
    return 0;
  }
}

/*Función con la que buscamos en la tabla correspondiente dependiendo del valor de la flaglocal.
Si no encontramos nada devolvemos NULL. */
SIMBOLO* buscarTabla(  tablas_simbolos *hashes, char *key ) {
  SIMBOLO *value_res;

  if( hashes->flaglocal == 1 ) {
    /*En este caso, tenemos que interactuar con la tabla hash local.*/
      value_res = ht_get( hashes->hash_local, key );
      if( value_res == NULL ) {
        /*Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
        un ámbito local.*/
        value_res = ht_get( hashes->hash_global, key );
        if( value_res == NULL ) return NULL;
        /*Hemos encontrado con éxito en la global.*/
        else return value_res;
      }
      else return value_res;
  }
  else {
    /*En este caso estamos en la tabla global.*/
    /*Si es NULL, hemos de realizar búsqueda en la tabla global.*/
    value_res = ht_get( hashes->hash_global, key );

    if( value_res == NULL ) return NULL;
    /*Imprimimos éxito en la búsqueda.*/
    else return value_res;
  }
}
