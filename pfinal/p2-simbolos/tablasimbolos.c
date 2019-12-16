#include "hash.h"

//Variables globales que accederemos desde las distintas funciones.
int flaglocal = 0;
hashtable_t *hash_local, *hash_global;
FILE *in, *out;



//Función que interactua con las tablas hash dependiendo de lo que leemos.
int interactuarTabla(char *buffer){
  SIMBOLO *value;
  SIMBOLO *value_res;
  char *token1, *token2;
  int resultado_int;

  value = calloc(1, sizeof(SIMBOLO));

  //Delimitamos por tabulador y por el \n del final.
  token1 = strtok(buffer, "\t\n");

  //Queremos que coja el siguiente token de nuestra cadena, que sabemos que está separada por tabulador.
  token2 = strtok(NULL, "\t\n");
  printf("token1: %s token2: %s \n", token1, token2);
  //Lo primero que hemos de hacer es comprobar si estamos en ámbito local.
  if(flaglocal == 1){
    //En este caso, tenemos que interactuar con la tabla hash local.
    //Hemos de observar si token2 es NULL.
    if(token2 == NULL){
      //Si es NULL, hemos de realizar búsqueda en la tabla local. Usaremos nuestra primitiva get.
      //Hemos de pasar como clave a hashear lo primero que hemos leído de la línea.
      value_res = ht_get(hash_local, token1);
      if(value_res == NULL){
        //Si no hemos encontrado nada en la tabla local, buscamos también en la global que es accesible desde
        //un ámbito local.

        value_res = ht_get(hash_global, token1);
        if(value_res == NULL){
          fprintf(out, "%s -1\n", token1);
          fflush(out);
        }
        else{
          //Hemos encontrado con éxito en la global.
          fprintf(out, "%s %s\n", token1, value_res->identificador);
          fflush(out);
        }

      }
      else{
        //Imprimimos éxito en la búsqueda.
        fprintf(out, "%s %s\n", token1, value_res->identificador);
        fflush(out);
      }
    }
    else{
      //Si token2 no es NULL, hemos de insertar o bien cerrar nuestro ámbito local.
      //Lo comprobaremos observando si recibimos "cierre -999".
      if(strcmp(token1, "cierre")==0 && strcmp(token2,"-999")==0){
        //Ponemos nuestra flag de ámbito local a 0.
        flaglocal = 0;
        //TODO liberar memoria del hash_local. De momento hacemos solo free del puntero.
        free(hash_local);
        fprintf(out, "cierre\n");
        fflush(out);
      }
      else{
        //En este caso tan solo hemos de insertar en la tabla local.
        value->identificador = strdup(token2);
        resultado_int = ht_set( hash_local, token1, value );
        //Comprobamos si ha habido error en la inserción porque ya existía en la tabla.
        if(resultado_int == -1){
          //Hemos de imprimir fallo de inserción.
          fprintf(out, "-1 %s\n", token1);
          fflush(out);
        }
        else{
          //Si no ha habido fallo en la inserción, imprimimos con éxito.
          fprintf(out, "%s\n", token1);
          fflush(out);
        }
      }
    }
  }
  else{
    //En este caso estamos en la tabla global.
    //Hemos de observar si token2 es NULL.
    if(token2 == NULL){


      //Si es NULL, hemos de realizar búsqueda en la tabla global.
      value_res = ht_get(hash_global, token1);

      if(value_res == NULL){

        //Hemos de imprimir fallo de búsqueda.
          fprintf(out, "%s -1\n", token1);
          fflush(out);
      }
      else{
        //Imprimimos éxito en la búsqueda.
        fprintf(out, "%s %s\n", token1, value_res->identificador);
        fflush(out);
      }
    }

    else{

      //Si no es NULL, es decir, hemos recibido un número, identificador, es porque hemos de insertar en
      //la tabla global o crear un ámbito local. Comprobaremos esto mirando si es positivo o negativo.
      if(atoi(token2)>0){
        value->identificador = strdup(token2);
        resultado_int = ht_set( hash_global, token1, value );
        printf("resultado : %d\n", resultado_int);
        fflush(stdout);
        //Comprobamos si ha habido error en la inserción porque ya existía en la tabla.
        if(resultado_int == -1){
          //Hemos de imprimir fallo de inserción.
          fprintf(out, "-1 %s\n", token1);
          fflush(out);
        }
        else{
          //Si no ha habido fallo en la inserción, imprimimos con éxito.

          fprintf(out, "%s\n", token1);
          fflush(out);
        }
      }

      else{
        //Insertamos en el global antes de nada.
        value->identificador = strdup(token2);
        resultado_int = ht_set( hash_global, token1, value );
        printf("resultado : %d\n", resultado_int);
        fflush(out);
        //En este caso, al ser el identificador negativo, hemos de pasar a ámbito local.
        //Cambiamos nuestra flag a local.
        flaglocal = 1;
        //Creamos la tabla local.
        hash_local = ht_create(65536);
        //Insertamos en la tabla local. No hace falta comprobar la inserción puesto que la acabamos de crear.
        value->identificador = strdup(token2);
        ht_set( hash_local, token1, value );
        fprintf(out, "%s\n", token1);
        fflush(out);
      }
    }
  }
}





int main(int argc, char** argv) {

   char* entrada, *salida;
   char *buffer;
   int bufsize = 32;
   char* leido;


   if (argc != 3){
      fprintf(stderr, "Error en el número de parámetros de entrada");
      return -1;
   }
   entrada = argv[1];
   fprintf(stdout, "%s\n", entrada);
   fflush(stdout);
   salida = argv[2];
   fprintf(stdout, "%s\n", salida);
   fflush(stdout);
   in = fopen(entrada, "r");
   if(!in) {
      fprintf(stderr, "No se encuentra el fichero de entrada\n");
      return -1;
   }
   out = fopen(salida, "w");
   if(!out) {
      fprintf(stderr, "No se encuentra el fichero de salida\n");
      return -1;
   }

   //Nada más empezar, nos creamos nuestro ámbito global.
   hash_global = ht_create(65536);

   //Ahora leemos de fichero la primera línea.


    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    leido = fgets(buffer, bufsize, in);

    while(leido){
      printf("%s", leido);
      interactuarTabla(buffer);
      leido = fgets(buffer, bufsize, in);
    }

   fclose(in);
   fclose(out);

   return 0;

}
