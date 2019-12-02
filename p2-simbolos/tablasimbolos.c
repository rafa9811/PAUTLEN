#include "hash.h"

//Variables globales que accederemos desde las distintas funciones.
int flaglocal = 0;
hashtable_t *hash_local, *hash_global;
FILE *in, *out;



//Función que interactua con las tablas hash dependiendo de lo que leemos.
int interactuarTabla(char *buffer){

  char *token1, *token2, *resultado;
  int resultado_int;

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
      //Si es NULL, hemos de realizar búsqueda en la tabla global. Usaremos nuestra primitiva get.
      //Hemos de pasar como clave a hashear lo primero que hemos leído de la línea.
      resultado = ht_get(hash_local, token1);
      if(resultado == NULL){
        //Hemos de imprimir fallo de búsqueda.
        fprintf(out, "%s -1\n", token1);
      }
      else{
        //Imprimimos éxito en la búsqueda.
        fprintf(out, "%s 1\n", resultado);
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
      }
      else{
        //En este caso tan solo hemos de insertar en la tabla local.
        resultado_int = ht_set( hash_local, token1, token2 );
        //Comprobamos si ha habido error en la inserción porque ya existía en la tabla.
        if(resultado_int == -1){
          //Hemos de imprimir fallo de inserción.
          fprintf(out, "-1 %s\n", token1);
        }
        else{
          //Si no ha habido fallo en la inserción, imprimimos con éxito.
          fprintf(out, "%s\n", token1);
        }
      }
    }
  }
  else{
    //En este caso estamos en la tabla global.
    //Hemos de observar si token2 es NULL.
    if(token2 == NULL){


      //Si es NULL, hemos de realizar búsqueda en la tabla global.
      resultado = ht_get(hash_global, token1);
      fprintf(out, "%s -1\n", token1);
      if(resultado == NULL){

        //Hemos de imprimir fallo de búsqueda.

      }
      else{
        //Imprimimos éxito en la búsqueda.
        fprintf(out, "%s 1\n", resultado);
      }
    }

    else{

      //Si no es NULL, es decir, hemos recibido un número, identificador, es porque hemos de insertar en
      //la tabla global o crear un ámbito local. Comprobaremos esto mirando si es positivo o negativo.
      if(atoi(token2)>0){
        resultado_int = ht_set( hash_global, token1, token2 );
        printf("resultado : %d\n", resultado_int);
        //Comprobamos si ha habido error en la inserción porque ya existía en la tabla.
        if(resultado_int == -1){
          //Hemos de imprimir fallo de inserción.
          fprintf(out, "-1 %s\n", token1);
        }
        else{
          //Si no ha habido fallo en la inserción, imprimimos con éxito.

          fprintf(out, "%s\n", token1);
        }
      }

      else{
        //En este caso, al ser el identificador negativo, hemos de pasar a ámbito local.
        //Cambiamos nuestra flag a local.
        flaglocal = 1;
        //Creamos la tabla local.
        hash_local = ht_create(1000);
        //Insertamos en la tabla local. No hace falta comprobar la inserción puesto que la acabamos de crear.
        ht_set( hash_local, token1, token2 );
        fprintf(out, "%s\n", token1);
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
   salida = argv[2];
   fprintf(stdout, "%s\n", salida);
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
   hash_global = ht_create(1000);

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
