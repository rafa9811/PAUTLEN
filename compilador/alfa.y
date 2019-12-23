/* SECCION DE DEFINICIONES */
%{
#include "alfa.h"
#define MAX 64

int yylex();
void yyerror(const char * s);
extern FILE *out;
extern int nlin;
extern int ncol;
extern int is_morpho;
extern tablas_simbolos hashes;
char buff[64];
SIMBOLO *aux;

int tipo_actual;
int clase_actual;
int longitud_actual;

int num_parametros_actual = 0;
int num_var_locales_actual = 1;
int posicion_variable_local = 1;
int posicion_parametro = 0;
int num_parametros_llamada = 0;

int etiqueta = 0;
int i;
int flagretorno = 0;
int flag_declaracion_funcion = 0;
int flag_llamada_funcion = 0;

%}

%union
{
 tipo_atributos atributos;
}

%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA

%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> exp
%type <atributos> comparacion
%type <atributos> fn_declaration
%type <atributos> fn_name
%type <atributos> elemento_vector
%type <atributos> if_exp_sentencias
%type <atributos> if_exp
%type <atributos> while_exp
%type <atributos> while
%type <atributos> identificador
%type <atributos> clase_vector

/* Palabras reservadas */
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN
%token TOK_ERROR

/* Simbolos */
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

/* Constantes */
%token TOK_TRUE
%token TOK_FALSE

%start programa

%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%left TOK_NOT
%left TOK_DISTINTO
%left TOK_AND
%left TOK_OR
%%

/* SECCION DE REGLAS */
programa: escritura_ini TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escritura1 funciones escritura2 sentencias TOK_LLAVEDERECHA {
            fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
            fprintf( out, ";escribir_fin\n" );
            escribir_fin( out );
          }
  ;

escritura_ini: {
                 fprintf( out, ";escribir_subseccion_data\n" );
                 escribir_subseccion_data( out );
                 fprintf( out, ";escribir_cabecera_bss\n" );
                 escribir_cabecera_bss( out );
               }
  ;

escritura1: {
              fprintf( out, ";escribir_segmento_codigo\n" );
              escribir_segmento_codigo( out );
            }
  ;

escritura2: {
              fprintf( out, ";escribir_inicio_main\n" );
              escribir_inicio_main( out );
            }
  ;

declaraciones: declaracion {
	fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");

	}
             | declaracion declaraciones {

			 	fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");


			 }
	;
declaracion: clase identificadores TOK_PUNTOYCOMA {fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
	;
clase: clase_escalar {
          fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n");
          clase_actual = ESCALAR;
       }
     | clase_vector {
          fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n");
          clase_actual = VECTOR;
       }
	;
clase_escalar: tipo {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
	;
tipo: TOK_INT {
        fprintf(out, ";R10:\t<tipo> ::= int\n");
        tipo_actual = VECTOR;
		longitud_actual = 1;
      }
    | TOK_BOOLEAN {
        fprintf(out, ";R11:\t<tipo> ::= boolean\n");
        tipo_actual = BOOLEANO;
		longitud_actual = 1;
      }
	;
clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO {
                fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera]\n");
                //EN $4.valor TENEMOS EL TAMAÑO DEL VECTOR
                //COMPROBACIONES SEMANTICAS (TAMANO > 0 y TAMANO < MAX) Y PROPAGACION EN $$.valor
				if($4.valor_entero <=0 || $4.valor_entero > MAX){
					printf("Error semántico en la clase vector, se sale el tamaño.\n");
					return -1;
				}
				$$.valor_entero = $4.valor_entero;
				longitud_actual = $4.valor_entero;
              }
	;

identificadores: identificador {fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");}
               | identificador TOK_COMA identificadores {fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
	;
funciones: funcion funciones {fprintf(out, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
         | {fprintf(out, ";R21:\t<funciones> ::= \n");}
	;
funcion: fn_declaration sentencias TOK_LLAVEDERECHA {
          fprintf(out, ";R22:\t<funcion> ::= function <tipo> <identificador ( <parametros_funcion ) { <declaraciones_funcion> <sentencias> }\n");
          //COMPROBACIONES SEMANTICAS
          //ERROR SI LA FUNCION NO TIENE SENTENCIA DE RETORNO
          //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
          //CIERRE DE AMBITO, ETC
		  if(flagretorno==0){
		  	printf("Error semántico. La función no tiene retorno.\n");
			return -1;
		  }

		  if(cerrarAmbito(&hashes)==-1){
		  printf("Error semántico. La función no se ha le ha podido cerrar el ámbito.\n");
		  return -1;
		  }
		  aux = buscarTabla(&hashes, $1.lexema);
		  if(aux==NULL){
			printf("Error semántico. La función ya estaba declarada pero no la encontramos.\n");
			return -1;
		  }
		  printf("%d\n", num_parametros_actual);
		  printf("%d\n", aux->num_parametros);

		  aux = new_simbolo($1.lexema, FUNCION, aux->tipo, -1, -1, -1, num_parametros_actual, -1, num_var_locales_actual);
		  printf("Insertando con flag_local %d y con esta clave %s\n", hashes.flaglocal, $1.lexema);
		  insertarTabla(&hashes, $1.lexema, aux);
		  flag_declaracion_funcion = 0;


        }
  ;

fn_declaration: fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
                  //COMPROBACIONES SEMANTICAS
                  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema



				  strcpy($$.lexema, $1.lexema);
                  $$.tipo = $1.tipo;

                  //GENERACION DE CODIGO
				  fprintf(out, ";declararFuncion\n");
				  declararFuncion(out, $1.lexema, num_var_locales_actual);

				 //Actualizamos también la función en la tabla local con número de parámetros por si la queremos llamar otra vez.
				 aux = buscarTabla(&hashes, $1.lexema);
				 if(aux==NULL){
				   printf("Error semántico. La función ya estaba declarada pero no la encontramos.\n");
				   return -1;
				 }
				 printf("%d\n", num_parametros_actual);
				 printf("%d\n", aux->num_parametros);

				 aux = new_simbolo($1.lexema, FUNCION, aux->tipo, -1, -1, -1, num_parametros_actual, -1, num_var_locales_actual);
				 printf("Insertando con flag_local %d y con esta clave %s\n", hashes.flaglocal, $1.lexema);
				 insertarTabla(&hashes, $1.lexema, aux);



                }
  ;

fn_name: TOK_FUNCTION tipo TOK_IDENTIFICADOR {
          //COMPROBACIONES SEMANTICAS
          //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.lexema


		  aux = buscarTabla(&hashes, $3.lexema);
		  if(aux!=NULL){
		  	printf("Error semántico. La función ya estaba antes declarada.\n");
			return -1;
		  }
		  aux = new_simbolo($3.lexema, FUNCION, tipo_actual, -1, -1, -1, -1, -1, -1);
		  insertarTabla(&hashes, $3.lexema, aux);
		  num_parametros_actual = 0;
		  num_var_locales_actual = 1;
		  posicion_variable_local = 1;
		  posicion_parametro = 0;
		  flag_declaracion_funcion = 1;
		  $$.tipo = tipo_actual;
		  strcpy($$.lexema, $3.lexema);
          //ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.lexema
          //RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
          //posicion_variable_local, num_variables_locales, posicion_parametro, num_parametros
        }
  ;

parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(out, ";R25:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                  | {fprintf(out, ";R24:\t<parametros_funcion> ::= \n");}
	;

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
                        | {fprintf(out, ";R26:\t<resto_parametros_funcion> ::= \n");}
	;

parametro_funcion: tipo idpf {
                    fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                    //INCREMENTAR CONTADORES, POR EJEMPLO
                    num_parametros_actual++;
                    posicion_parametro++;
                   }
	;

declaraciones_funcion: declaraciones {fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
                     | {fprintf(out, ";R29:\t<declaraciones_funcion> ::= \n");}
	;

sentencias: sentencia {fprintf(out, ";R30:\t<sentencias> ::= <sentencia>\n");}
          | sentencia sentencias {fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
	;

sentencia: sentencia_simple TOK_PUNTOYCOMA {fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
         | bloque {fprintf(out, ";R33:\t<sentencia> ::= <bloque>\n");}
	;

sentencia_simple: asignacion {fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                | lectura {fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
                | escritura {fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
                | retorno_funcion {fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
	;

bloque: condicional {fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
      | bucle {fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");}
	;

asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp {

    fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
	printf("flaglocal antes de buscar:%d y con esta clave %s\n", hashes.flaglocal, $1.lexema);
    aux = buscarTabla(&hashes, $1.lexema);
  if (  aux == NULL){
      printf("Error a la hora de asignación. No está en la tabla 1\n");
      return -1;
  }

    if (aux->cat_simbolo == FUNCION){
	    printf("Error a la hora de asignación. Es una función");
	    return -1;
    }


    if (aux->categoria == VECTOR){
      printf("Error a la hora de asignación. Es una vector");
      return -1;
    }

    if (aux->tipo != $3.tipo){
	  printf("%d %d\n", aux->tipo, $3.tipo);
      printf("Error a la hora de asignación. No es el mismo tipo\n");
      return -1;
    }

	if(flag_declaracion_funcion == 1){

		if(aux->cat_simbolo == PARAMETRO){
			fprintf(out, ";escribirParametro\n");
			escribirParametro(out, aux->posicion, num_parametros_actual);
		}
		else{
			fprintf(out, ";escribirVariableLocal\n");
			printf("POSICION: %d\n", aux->posicion);
			escribirVariableLocal(out, aux->posicion);

		}

		fprintf(out, ";asignarDestinoEnPila\n");
		asignarDestinoEnPila(out, $3.es_direccion);
	}

	else{
		fprintf(out, ";asignar\n");
		asignar(out, $1.lexema, $3.es_direccion);
	}

   }
          | elemento_vector TOK_ASIGNACION exp {
              fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");

              //COMPROBACIONES SEMANTICAS (VER SI $1.tipo == $3.tipo)
			  if($1.tipo != $3.tipo){
			  	printf("Error semántico en asignación de vector. No son del mismo tipo\n");
				return -1;
			  }

			  aux = buscarTabla(&hashes, $1.lexema);
			  if (  aux == NULL){
				  printf("Error a la hora de asignación. No está en la tabla");
				  return -1;
			  }
			  if (aux->cat_simbolo == FUNCION){
				printf("Error a la hora de asignación. Es una función");
				return -1;
			  }
			  if (aux->categoria != VECTOR){
		        printf("Error a la hora de asignación. No es un vector.");
		        return -1;
		      }

              //$1.valor ES EL INDICE DEL VECTOR EN EL QUE QUEREMOS ASIGNAR exp

			  sprintf( buff, "%d", $1.valor_entero );
			  fprintf(out, ";escribir_operando\n");
              escribir_operando(out, buff, 0);
			  fprintf(out, ";escribir_elemento_vector\n");
              escribir_elemento_vector(out, $1.lexema, aux->longitud, 0);
			  fprintf(out, ";asignarDestinoEnPila\n");
              asignarDestinoEnPila(out, $3.es_direccion);
            }
  	;

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {

                   fprintf(out, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");

                   //COMPROBACIONES SEMANTICAS PARA EL SIMBOLO CON IDENTIFICADOR $1.lexema

				  aux = buscarTabla(&hashes, $1.lexema);
	 			  if (  aux == NULL){
	 				  printf("Error a la hora de asignación. No está en la tabla");
	 				  return -1;
	 			  }
	 			  if (aux->cat_simbolo == FUNCION){
	 				printf("Error a la hora de asignación. Es una función");
	 				return -1;
	 			  }
	 			  if (aux->categoria != VECTOR){
	 		        printf("Error a la hora de asignación. No es un vector.");
	 		        return -1;
	 		      }
				  //fprintf(out, ";escribir_elemento_vector\n");
                  //escribir_elemento_vector(out, $1.lexema, aux->longitud, $3.es_direccion);

				   //NECESITAMOS EN $$: tipo, es_direccion = 1, valor de $3 (ES EL INDICE DEL VECTOR)

				  $$.tipo = aux->tipo;
				  $$.es_direccion = 1;
				  $$.valor_entero = $3.valor_entero;
				  strcpy($$.lexema, $1.lexema);
                  }
	;

condicional: if_exp_sentencias TOK_LLAVEDERECHA {
               fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
               fprintf(out,";ifthenelse_fin\n");
               ifthenelse_fin(out, $1.etiqueta);
              }

           | if_exp_sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
               fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
               fprintf(out,";ifthenelse_fin\n");
               ifthenelse_fin(out, $1.etiqueta);
              }
	;

if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
          //Comprb semanticas, y gestion de etiqueta.
          if($3.tipo != BOOLEANO){
            printf("Error semántico. La exp de la condición del if no es BOOLEANO. \n");
            return -1;
          }
          $$.etiqueta = etiqueta++;
          fprintf(out,";ifthen_inicio\n");
          ifthen_inicio(out, $3.es_direccion, $$.etiqueta);
        }
  ;

if_exp_sentencias: if_exp sentencias {
                     $$.etiqueta = $1.etiqueta;
                     fprintf(out,";ifthenelse_fin_then\n");
                     ifthenelse_fin_then(out, $$.etiqueta);
                   }
  ;

bucle: while_exp sentencias TOK_LLAVEDERECHA {
        fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
        fprintf(out,";while_fin\n");
        while_fin(out, $1.etiqueta);
        }
	;

while: TOK_WHILE TOK_PARENTESISIZQUIERDO {
        //GESTION ETIQUETA
        $$.etiqueta = etiqueta++;
        fprintf(out,";while_inicio\n");
        while_inicio(out, $$.etiqueta);
        }

  ;

while_exp: while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
            if($2.tipo != BOOLEANO){
               printf("Error semántico. La exp de la condición del if no es BOOLEANO. \n");
               return -1;
            }
            $$.etiqueta = $1.etiqueta;
            fprintf(out,";while_exp_pila\n");
            while_exp_pila(out, $2.es_direccion, $$.etiqueta);
            }
  ;

lectura: TOK_SCANF TOK_IDENTIFICADOR {fprintf(out, ";R54:\t<lectura> ::= scanf <identificador>\n");

          aux = buscarTabla(&hashes, $2.lexema);
          if(aux==NULL){
            printf("Error semántico, no está en la tabla.\n");
            return -1;
          }
          if(aux->cat_simbolo == FUNCION || aux->categoria != ESCALAR){
            printf("Error semántico, no scanf de vector.\n");
            return -1;
          }
          fprintf(out, ";leer\n");
          leer(out, $2.lexema ,aux->tipo);



          }
	;

escritura: TOK_PRINTF exp {fprintf(out, ";R56:\t<escritura> ::= printf <exp>\n");

            fprintf(out, ";escribir\n");
            escribir(out, $2.es_direccion, $2.tipo);


    }
	;

retorno_funcion: TOK_RETURN exp {
	flagretorno  = 1;
	fprintf(out, ";retornarFuncion\n");
	retornarFuncion(out, $2.es_direccion);
	fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");


}
	;

exp: exp TOK_MAS exp {fprintf(out, ";R72:\t<exp> ::= <exp> + <exp>\n");

      if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

        printf("Error, la suma es entre dos booleanos.\n");
        return -1;
      }

      if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
        {
        fprintf(out, ";sumar \n");
        sumar(out, $1.es_direccion, $3.es_direccion);


        $$.tipo = ENTERO;
        $$.es_direccion = 0;
		$$.valor_entero = $1.valor_entero + $3.valor_entero;
        }

  }
   | exp TOK_MENOS exp {

      fprintf(out, ";R73:\t<exp> ::= <exp> - <exp>\n");

      if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

        printf("Error, la resta es entre dos booleanos.\n");
        return -1;
      }

      if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
        {
        fprintf(out, ";restar \n");
        restar(out,$1.es_direccion,$3.es_direccion);


        $$.tipo = ENTERO;
        $$.es_direccion = 0;
		$$.valor_entero = $1.valor_entero - $3.valor_entero;
        }

   }
   | exp TOK_DIVISION exp {
      fprintf(out, ";R74:\t<exp> ::= <exp> / <exp>\n");
      if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

        printf("Error, la división es entre dos booleanos.\n");
        return -1;
      }

      if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
        {
        fprintf(out, ";dividir \n");
        dividir(out,$1.es_direccion,$3.es_direccion);


        $$.tipo = ENTERO;
        $$.es_direccion = 0;
        }

   }
   | exp TOK_ASTERISCO exp {
      fprintf(out, ";R75:\t<exp> ::= <exp> * <exp>\n");
      if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

        printf("Error, la multiplicación es entre dos booleanos.\n");
        return -1;
      }

      if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
        {
        fprintf(out, ";multiplicar \n");
        multiplicar(out,$1.es_direccion,$3.es_direccion);

        /* Propaga correctamente los atributos*/
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
		$$.valor_entero = $1.valor_entero * $3.valor_entero;
        }



   }
   | TOK_MENOS exp {
         fprintf(out, ";R76:\t<exp> ::= - <exp>\n");
         if (($2.tipo == BOOLEANO)){

           printf("Error, el cambiar_signo es sobre un booleano.\n");
           return -1;
         }

         if (($2.tipo == ENTERO))
           {
           fprintf(out, ";cambiar_signo\n");
           cambiar_signo(out,$2.es_direccion);

           /* Propaga correctamente los atributos*/
           $$.tipo = ENTERO;
           $$.es_direccion = 0;
		   $$.valor_entero = -$$.valor_entero;
           }



   }
   | exp TOK_AND exp {
         fprintf(out, ";R77:\t<exp> ::= <exp> && <exp>\n");
         if (($1.tipo == ENTERO) || ($3.tipo == ENTERO)){

           printf("Error, la suma es entre dos booleanos.\n");
           return -1;
         }

         if (($1.tipo == BOOLEANO) && ($3.tipo == BOOLEANO))
           {
           fprintf(out, ";y \n");
           y(out,$1.es_direccion,$3.es_direccion);

           /* Propaga correctamente los atributos*/
           $$.tipo = BOOLEANO;
           $$.es_direccion = 0;
           }

   }
   | exp TOK_OR exp {
         fprintf(out, ";R78:\t<exp> ::= <exp> || <exp>\n");
         if (($1.tipo == ENTERO) || ($3.tipo == ENTERO)){

           printf("Error, la suma es entre dos booleanos.\n");
           return -1;
         }

         if (($1.tipo == BOOLEANO) && ($3.tipo == BOOLEANO))
           {

           fprintf(out, ";o \n");
           o(out,$1.es_direccion,$3.es_direccion);

           /* Propaga correctamente los atributos*/
           $$.tipo = BOOLEANO;
           $$.es_direccion = 0;
           }

   }
   | TOK_NOT exp {
         fprintf(out, ";R79:\t<exp> ::= ! <exp>\n");
         if (($2.tipo == ENTERO)){

           printf("Error, la negación es sobre un entero.\n");
           return -1;
         }

         if (($2.tipo == BOOLEANO))
           {

           fprintf(out, ";no \n");
           no(out,$2.es_direccion,1);


           $$.tipo = BOOLEANO;
           $$.es_direccion = 0;
           }


   }
   | TOK_IDENTIFICADOR {
      fprintf(out, ";R80:\t<exp> ::= <identificador>\n");
      aux = buscarTabla(&hashes, $1.lexema);

      if(aux == NULL){
         printf("Error semántico en expresión. No se encuentra el identificador en la tabla.");
         return -1;
      }

      if(aux->cat_simbolo == FUNCION){
         printf("Error semántico en expresión. El identificador es una función.");
         return -1;
      }

      if(aux->categoria == VECTOR){
         printf("Error semántico en expresión. La clase del identificador es vector.");
         return -1;
      }

      $$.tipo = aux->tipo;
      $$.es_direccion = 1;
	  if(flag_declaracion_funcion == 1){
	  		if(aux->cat_simbolo == PARAMETRO){
				fprintf(out, ";escribirParametro\n");
				escribirParametro(out, aux->posicion, num_parametros_actual);
			}
			else{
				fprintf(out, ";escribirVariableLocal\n");
				escribirVariableLocal(out, aux->posicion);
			}

	  }
	  else{
		  fprintf(out, ";escribir_operando\n");
		  escribir_operando(out, $1.lexema, 1);
	  }
	  if(flag_llamada_funcion == 1){
	  	fprintf(out, ";operandoEnPilaAArgumento\n");
	  	operandoEnPilaAArgumento(out, 1);
		//Hemos de indicar que lo que ya tenemos aquí no es una dirección, sino un valor fijo.
		$$.es_direccion = 0;
	  }






   }
   | constante {
       fprintf(out, ";R81:\t<exp> ::= <constante>\n");
       $$.tipo = $1.tipo;
       $$.es_direccion = $1.es_direccion;
	   if(flag_llamada_funcion == 1){
	   	fprintf(out, ";operandoEnPilaAArgumento\n");
 	  	operandoEnPilaAArgumento(out, 0);
 	  }
     }

   | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {

         fprintf(out, ";R82:\t<exp> ::= ( <exp> )\n");
         $$.tipo = $2.tipo;
         $$.es_direccion = $2.es_direccion;

   }
   | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
        fprintf(out, ";R83:\t<exp> ::= ( <comparacion )\n");
        $$.tipo = $2.tipo;
        $$.es_direccion = $2.es_direccion;
   }
   | elemento_vector {
   			fprintf(out, ";R84:\t<exp> ::= <elemento_vector>\n");

			$$.tipo = $1.tipo;
			$$.es_direccion = 1;
			$$.valor_entero = $1.valor_entero;
			strcpy($$.lexema, $1.lexema);

			aux = buscarTabla(&hashes, $1.lexema);

			if (  aux == NULL){
				printf("Error a la hora de asignación. No está en la tabla");
				return -1;
			}
			if (aux->cat_simbolo == FUNCION){
			  printf("Error a la hora de asignación. Es una función");
			  return -1;
			}
			if (aux->categoria != VECTOR){
			  printf("Error a la hora de asignación. No es un vector.");
			  return -1;
			}




			fprintf(out, ";escribir_elemento_vector\n");
			escribir_elemento_vector(out, $1.lexema, aux->longitud, 0);


			if(flag_llamada_funcion == 1){

			fprintf(out,";operandoEnPilaAArgumento\n");
	  	  	operandoEnPilaAArgumento(out, 1);
			//Hemos de indicar que lo que ya tenemos aquí no es una dirección, sino un valor fijo.
			$$.es_direccion = 0;
	  	  }




   	}
   | TOK_IDENTIFICADOR flag_llamada_regla TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {
   		fprintf(out, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
		aux = buscarTabla(&hashes, $1.lexema);
		if(aux == NULL){
		printf("Error semántico. No existe la función a la que se refiere.\n");
		return -1;
		}
		if(num_parametros_llamada != aux->num_parametros){
		printf("llamada %d  declaracion %d en clave %s\n", num_parametros_llamada, aux->num_parametros, aux->identificador);
			printf("Error semántico. La llamada a función no tiene el número necesario de argumentos.\n");
			return -1;
		}

		fprintf(out, ";llamarFuncion\n");
		llamarFuncion(out, $1.lexema, num_parametros_llamada);
		fprintf(out, ";limpiarPila\n");
		limpiarPila(out, num_parametros_llamada);
		num_parametros_llamada = 0;
		$$.es_direccion = 0;
		flag_llamada_funcion = 0;
		$$.tipo = aux->tipo;



   }
	;

flag_llamada_regla: {
flag_llamada_funcion = 1;}

	;

lista_expresiones: exp resto_lista_expresiones {
		fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
		num_parametros_llamada ++;



		}
                 | {fprintf(out, ";R90:\t<lista_expresiones> ::= \n");}
	;

resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= TOK_COMA <exp> <resto_lista_expresiones>\n");

	num_parametros_llamada++;
	}
                       | {fprintf(out, ";R92:\t<resto_lista_expresiones> ::= \n");}
	;

comparacion: exp TOK_IGUAL exp {

        fprintf(out, ";R93:\t<comparacion> ::= <exp> == <exp>\n");

        if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

          printf("Error, la comparación es entre dos booleanos.\n");
          return -1;
        }

        if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
          {

          fprintf(out, ";igual\n");
          igual(out,$1.es_direccion, $3.es_direccion, etiqueta);

          /* Propaga correctamente los atributos*/
          etiqueta++;
          $$.tipo = BOOLEANO;
          $$.es_direccion = 0;
          }
  }
           | exp TOK_DISTINTO exp {fprintf(out, ";R94:\t<comparacion> ::= <exp> != <exp>\n");

           if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

             printf("Error, la comparación es entre dos booleanos.\n");
             return -1;
           }

           if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
             {

             fprintf(out, ";distinto\n");
             distinto(out,$1.es_direccion, $3.es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             $$.tipo = BOOLEANO;
             $$.es_direccion = 0;
             }



           }
           | exp TOK_MENORIGUAL exp {

           fprintf(out, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");

           if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

             printf("Error, la comparación es entre dos booleanos.\n");
             return -1;
           }

           if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
             {
             fprintf(out, ";menor_igual\n");
             menor_igual(out,$1.es_direccion, $3.es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             $$.tipo = BOOLEANO;
             $$.es_direccion = 0;
             }




           }
           | exp TOK_MAYORIGUAL exp {

           fprintf(out, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
           if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

             printf("Error, la comparación es entre dos booleanos.\n");
             return -1;
           }

           if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
             {
             fprintf(out, ";mayor_igual\n");
             mayor_igual(out,$1.es_direccion, $3.es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             $$.tipo = BOOLEANO;
             $$.es_direccion = 0;
             }



           }
           | exp TOK_MENOR exp {

           fprintf(out, ";R97:\t<comparacion> ::= <exp> <= <exp>\n");
           if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

             printf("Error, la comparación es entre dos booleanos.\n");
             return -1;
           }

           if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
             {
             fprintf(out, ";menor\n");
             menor(out,$1.es_direccion, $3.es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             $$.tipo = BOOLEANO;
             $$.es_direccion = 0;
             }




           }
           | exp TOK_MAYOR exp {

           fprintf(out, ";R98:\t<comparacion> ::= <exp> >= <exp>\n");
           if (($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){

             printf("Error, la comparación es entre dos booleanos.\n");
             return -1;
           }

           if (($1.tipo == ENTERO) && ($3.tipo == ENTERO))
             {
             fprintf(out, ";mayor\n");
             mayor(out,$1.es_direccion, $3.es_direccion, etiqueta);

             /* Propaga correctamente los atributos*/
             etiqueta++;
             $$.tipo = BOOLEANO;
             $$.es_direccion = 0;
             }




           }
	;

constante: constante_logica {
      fprintf(out, ";R99:\t<constante> ::= <constante_logica>\n");
      $$.tipo = $1.tipo;
      $$.es_direccion = $1.es_direccion;
}
         | constante_entera {
             $$.tipo = $1.tipo;
             $$.es_direccion = $1.es_direccion;
             fprintf(out, ";R100:\t<constante> ::= <constante_entera>\n");
           }
	;

constante_logica: TOK_TRUE {
                    fprintf(out, ";R102:\t<constante_logica> ::= true\n");
                    $$.tipo = BOOLEANO;
                    $$.es_direccion = 0;
					fprintf(out, ";escribir_operando\n");
                    escribir_operando( out, "1" , 0 );
                  }
                | TOK_FALSE {
                    fprintf(out, ";R103:\t<constante_logica> ::= false\n");
                    $$.tipo = BOOLEANO;
                    $$.es_direccion = 0;
					fprintf(out, ";escribir_operando\n");
                    escribir_operando( out, "0" , 0 );
                  }
	;

constante_entera: TOK_CONSTANTE_ENTERA {
                    fprintf( out, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n" );
                    $$.tipo = ENTERO;
                    $$.es_direccion = 0;
                    $$.valor_entero = $1.valor_entero;

                    sprintf( buff, "%d", $$.valor_entero );
					fprintf(out, ";escribir_operando\n");
                    escribir_operando( out, buff , 0 );
                  }
	;

identificador: TOK_IDENTIFICADOR {
                 fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                 if( buscarTabla( &hashes, $1.lexema ) != NULL ) {
                    printf( "Error semántico en línea %d y columna %d", nlin, ncol );
                    return -1;
                 } else {

					if(flag_declaracion_funcion==1){
						 aux = new_simbolo($1.lexema, VARIABLE, tipo_actual, ESCALAR, -1, 1, -1, num_var_locales_actual, -1);
						 insertarTabla( &hashes, $1.lexema, aux );
						 num_var_locales_actual++;
					 }
					 else{
						 aux = new_simbolo($1.lexema, VARIABLE, tipo_actual, clase_actual, -1, longitud_actual, -1, -1, -1);
						 printf("flaglocal antes de insertar:%d y este key %s\n",hashes.flaglocal, $1.lexema);
						 insertarTabla( &hashes, $1.lexema, aux );
						 fprintf(out, ";declarar_variable\n");
						 declarar_variable( out, $1.lexema, tipo_actual, longitud_actual);

					 }



                 }
               }
  ;

idpf: TOK_IDENTIFICADOR {
                fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
				aux = buscarTabla(&hashes, $1.lexema);
				if(aux != NULL){
					printf("Error semántico. El parámetro ya está declarado en el ámbito local.\n");
					return -1;
				}
				aux = new_simbolo($1.lexema, PARAMETRO, tipo_actual, ESCALAR, -1, 1, -1, posicion_parametro, -1);
				printf("flaglocal antes de insertar:%d y este key %s\n",hashes.flaglocal, $1.lexema);
				insertarTabla( &hashes, $1.lexema, aux );


              }
	;
%%

void yyerror(const char * s) {
    if(!is_morpho) {
        printf("****Error sintactico en [lin %d, col %d]\n", nlin, ncol);
    }
}
