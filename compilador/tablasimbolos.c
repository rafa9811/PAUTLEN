#include "tablasimbolos.h"

//Variables globales que accederemos desde las distintas funciones.


int cerrarAmbito( tablas_simbolos *hashes) {
  if( hashes->flaglocal == 0 ) return -1;

  else {
    free( hashes->hash_local );
    hashes->flaglocal = 0;
  }
}


int insertarTabla( tablas_simbolos *hashes, char *key, SIMBOLO *valor ) {
  int value_res;
  if( hashes->flaglocal == 1 ) {
      // En este caso, tenemos que interactuar con la tabla hash local.
      value_res = ht_set( hashes->hash_local, key, valor );
      // Si no hemos logrado insertar, devolvemos -1.
      if( value_res == -1 ) return -1;
      // Devolvemos éxito en la inserción.
      else return 0;
  }
  else {
    // En este caso estamos en la tabla global.
    value_res = ht_set( hashes->hash_global, key, valor );

    if( value_res == -1 ) return -1;

    if( valor->cat_simbolo == FUNCION ) {
      // Creamos la tabla local para abrir ámbito.
      if( hashes->flaglocal != 0 ) return -1;
      hashes->flaglocal = 1;
      hashes->hash_local = ht_create( 65536 );

      value_res = ht_set( hashes->hash_local, key, valor );
      // Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
      // un ámbito local.
      if( value_res == -1 ) return -1;
    }
    return 0;
  }
}


SIMBOLO* buscarTabla(  tablas_simbolos *hashes, char *key ) {
  SIMBOLO *value_res;

  if( hashes->flaglocal == 1 ) {
    //En este caso, tenemos que interactuar con la tabla hash local.
      value_res = ht_get( hashes->hash_local, key );
      if( value_res == NULL ) {
        //Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
        //un ámbito local.
        value_res = ht_get( hashes->hash_global, key );
        if( value_res == NULL ) return NULL;
        //Hemos encontrado con éxito en la global.
        else return value_res;
      }
      else return value_res;
  }
  else {
    //En este caso estamos en la tabla global.
    //Si es NULL, hemos de realizar búsqueda en la tabla global.
    value_res = ht_get( hashes->hash_global, key );

    if( value_res == NULL ) return NULL;
    // Imprimimos éxito en la búsqueda.
    else return value_res;
  }
}
