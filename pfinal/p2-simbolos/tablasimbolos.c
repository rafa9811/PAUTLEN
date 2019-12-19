#include "hash.h"

//Variables globales que accederemos desde las distintas funciones.
extern int flaglocal;
extern hashtable_t *hash_local, *hash_global;
FILE *in, *out;



int cerrarAmbito(){
  if(flaglocal == 0){
    return -1;
  }
  else{
    free(hash_local);
    flaglocal = 0;
  }
}


int insertarTabla(char *key, SIMBOLO *valor){
  int value_res;
  if(flaglocal == 1){
    //En este caso, tenemos que interactuar con la tabla hash local.


      //hemos de realizar búsqueda en la tabla local. Usaremos nuestra primitiva get.
      //Hemos de pasar como clave a hashear lo primero que hemos leído de la línea.
      value_res = ht_set(hash_local, key, valor);
      if(value_res == -1){
        //Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
        //un ámbito local.
          return -1;

      }
      else{
        //Imprimimos éxito en la búsqueda.
        return 0;
      }


  }
  else{
    //En este caso estamos en la tabla global.

    value_res = ht_set(hash_global, key, valor);
    if(value_res == -1){
      //Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
      //un ámbito local.
        return -1;

    }

    if(valor->cat_simbolo == FUNCION){
      //Creamos la tabla local para abrir ámbito.
      flaglocal = 1;
      hash_local = ht_create(65536);

      value_res = ht_set(hash_local, key, valor);
      if(value_res == -1){
        //Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
        //un ámbito local.
          return -1;

      }
    }

    return 0;

  }
}



SIMBOLO* buscarTabla(char *key){
  SIMBOLO *value_res;

  if(flaglocal == 1){
    //En este caso, tenemos que interactuar con la tabla hash local.


      //hemos de realizar búsqueda en la tabla local. Usaremos nuestra primitiva get.
      //Hemos de pasar como clave a hashear lo primero que hemos leído de la línea.
      value_res = ht_get(hash_local, key);
      if(value_res == NULL){
        //Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
        //un ámbito local.

        value_res = ht_get(hash_global, key);
        if(value_res == NULL){
          return NULL;
        }
        else{
          //Hemos encontrado con éxito en la global.
          return value_res;

        }

      }
      else{
        //Imprimimos éxito en la búsqueda.
        return value_res;
      }


  }
  else{
    //En este caso estamos en la tabla global.




      //Si es NULL, hemos de realizar búsqueda en la tabla global.
      value_res = ht_get(hash_global, key);

      if(value_res == NULL){

        //Hemos de imprimir fallo de búsqueda.
          return NULL;
      }
      else{
        //Imprimimos éxito en la búsqueda.
        return value_res;
      }


    }
  }
