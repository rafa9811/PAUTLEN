/* SECCION DE DEFINICIONES */
%{
#include "alfa.h"


int yylex();
void yyerror(const char * s);
extern FILE *out;
extern int nlin;
extern int ncol;
extern int is_morpho;
extern hashtable_t *hash_local;

char buff[64];
SIMBOLO aux;

int tipo_actual;
int clase_actual;
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

declaraciones: declaracion {fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");}
             | declaracion declaraciones {fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
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
      }
    | TOK_BOOLEAN {
        fprintf(out, ";R11:\t<tipo> ::= boolean\n");
        tipo_actual = BOOLEANO;
      }
	;
clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO {
                fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera]\n");
                //EN $4.valor TENEMOS EL TAMAÑO DEL VECTOR
                //COMPROBACIONES SEMANTICAS (TAMANO > 0 y TAMANO < MAX) Y PROPAGACION EN $$.valor
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
          // simbolo->num_parametros = num_parametros;
        }
  ;

fn_declaration: fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
                  //COMPROBACIONES SEMANTICAS
                  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
                  // simbolo->num_parametros = num_parametros;
                  //strcpy($$.lexema, $1.lexema);
                  //$$.tipo = $1.tipo;
                  //GENERACION DE CODIGO
                }
  ;

fn_name: TOK_FUNCTION tipo TOK_IDENTIFICADOR {
          //COMPROBACIONES SEMANTICAS
          //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.lexema
          // simbolo.identificador = $3.lexema;
          //simbolo.cat_simbolo = FUNCION;
          //simbolo.tipo = tipo_actual;
          //$$.tipo = tipo_actual;
          //strcpy($$.lexema, $3.lexema);

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
                    // num_parametros++;
                    //posicion_parametro++;
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

asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp {fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");}
          | elemento_vector TOK_ASIGNACION exp {
              fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
              //COMPROBACIONES SEMANTICAS (VER SI $1.tipo == $3.tipo)
              //$1.valor ES EL INDICE DEL VECTOR EN EL QUE QUEREMOS ASIGNAR exp
              //escribir_operando(out, $1.valor, 0);
              //escribir_elemento_vector(out, $1.lexema, simbolo->longitud, $3.es_variable);
              //asignarDestinoEnPila(out, $3.es_variable);
            }
  	;

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
                   fprintf(out, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
                   //COMPROBACIONES SEMANTICAS PARA EL SIMBOLO CON IDENTIFICADOR $1.lexema
                   //NECESITAMOS EN $$: tipo, es_variable = 1, valor de $3 (ES EL INDICE DEL VECTOR)
                   // escribir_elemento_vector(out, $1.lexema, simbolo->longitud, $3.es_variable);
                  }
	;

condicional: if_exp_sentencias TOK_LLAVEDERECHA {
               fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
               //ifthenelse_fin(out, $1.etiqueta);
              }

           | TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
               fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
               // ifthenelse_fin(out, "$1.etiqueta");
              }
	;

if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
          //Comprb semanticas, y gestion de etiqueta.
          //ifthen_inicio(out, $3.es_variable, $$.etiqueta);
        }
  ;

if_exp_sentencias: if_exp sentencias {
                     //$$.etiqueta = $1.etiqueta;
                     //ifthenelse_fin_then(out, $$.etiqueta);
                   }
  ;

bucle: while_exp sentencias TOK_LLAVEDERECHA {
        fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
        // while_fin(out, $1.etiqueta);
        }
	;

while: TOK_WHILE TOK_PARENTESISIZQUIERDO {
        //GESTION ETIQUETA
        // while_inicio(out, $$.etiqueta);
        }

  ;

while_exp: while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
            //COMPR SEMANTICAS (ver si tipo de ex es boolean)
            //$$.etiqueta = $1.etiqueta;
            // while_exp_pila(out, $2.es_variable, $$.etiqueta);
            }
  ;

lectura: TOK_SCANF identificador {fprintf(out, ";R54:\t<lectura> ::= scanf <identificador>\n");}
	;

escritura: TOK_PRINTF exp {fprintf(out, ";R56:\t<escritura> ::= printf <exp>\n");}
	;

retorno_funcion: TOK_RETURN exp {fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
	;

exp: exp TOK_MAS exp {fprintf(out, ";R72:\t<exp> ::= <exp> + <exp>\n");}
   | exp TOK_MENOS exp {fprintf(out, ";R73:\t<exp> ::= <exp> - <exp>\n");}
   | exp TOK_DIVISION exp {fprintf(out, ";R74:\t<exp> ::= <exp> / <exp>\n");}
   | exp TOK_ASTERISCO exp {fprintf(out, ";R75:\t<exp> ::= <exp> * <exp>\n");}
   | TOK_MENOS exp {fprintf(out, ";R76:\t<exp> ::= - <exp>\n");}
   | exp TOK_AND exp {fprintf(out, ";R77:\t<exp> ::= <exp> && <exp>\n");}
   | exp TOK_OR exp {fprintf(out, ";R78:\t<exp> ::= <exp> || <exp>\n");}
   | TOK_NOT exp {fprintf(out, ";R79:\t<exp> ::= ! <exp>\n");}
   | TOK_IDENTIFICADOR {fprintf(out, ";R80:\t<exp> ::= <identificador>\n");}
   | constante {
       fprintf(out, ";R81:\t<exp> ::= <constante>\n");
       $$.tipo = $1.tipo;
       $$.es_direccion = $1.es_direccion;
     }
   | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {fprintf(out, ";R82:\t<exp> ::= ( <exp> )\n");}
   | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {fprintf(out, ";R83:\t<exp> ::= ( <comparacion )\n");}
   | elemento_vector {fprintf(out, ";R84:\t<exp> ::= <elemento_vector>\n");}
   | identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {fprintf(out, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
	;

lista_expresiones: exp resto_lista_expresiones {fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
                 | {fprintf(out, ";R90:\t<lista_expresiones> ::= \n");}
	;

resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= TOK_COMA <exp> <resto_lista_expresiones>\n");}
                       | {fprintf(out, ";R92:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
	;

comparacion: exp TOK_IGUAL exp {fprintf(out, ";R93:\t<comparacion> ::= <exp> == <exp>\n");}
           | exp TOK_DISTINTO exp {fprintf(out, ";R94:\t<comparacion> ::= <exp> != <exp>\n");}
           | exp TOK_MENORIGUAL exp {fprintf(out, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
           | exp TOK_MAYORIGUAL exp {fprintf(out, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
           | exp TOK_MENOR exp {fprintf(out, ";R97:\t<comparacion> ::= <exp> <= <exp>\n");}
           | exp TOK_MAYOR exp {fprintf(out, ";R98:\t<comparacion> ::= <exp> >= <exp>\n");}
	;

constante: constante_logica {fprintf(out, ";R99:\t<constante> ::= <constante_logica>\n");}
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

                    escribir_operando( out, "1" , 0 );
                  }
                | TOK_FALSE {
                    fprintf(out, ";R103:\t<constante_logica> ::= false\n");
                    $$.tipo = BOOLEANO;
                    $$.es_direccion = 0;

                    escribir_operando( out, "0" , 0 );
                  }
	;

constante_entera: TOK_CONSTANTE_ENTERA {
                    fprintf( out, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n" );
                    $$.tipo = ENTERO;
                    $$.es_direccion = 0;
                    $$.valor_entero = $1.valor_entero;

                    sprintf( buff, "%d", $$.valor_entero );
                    escribir_operando( out, buff , 0 );
                  }
	;

identificador: TOK_IDENTIFICADOR {
                 fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                 if( buscarTabla( $1.lexema ) != NULL ) {
                    printf( "Error semántico en línea %d y columna %d", nlin, ncol );
                 } else {
                    aux.identificador = $1.lexema;
                    aux.valor = -1;
                    aux.cat_simbolo = VARIABLE;
                    aux.tipo = tipo_actual;
                    aux.categoria = clase_actual;
                    aux.longitud = -1;
                    aux.num_parametros = -1;
                    aux.posicion = -1;
                    aux.num_var_locales = -1;
                    insertarTabla( $1.lexema, &aux );
                    declarar_variable( out, $1.lexema, tipo_actual, 1 );
                 }
               }
  ;

idpf: TOK_IDENTIFICADOR {
                fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                //COMPROBACIONES SEMANTICAS PARA $1.lexema
                //EN ESTE CASO SE MUESTRA ERROR SI EL NOMBRE DEL PARAMETRO YA SE HA UTILIZADO
                //simbolo.identificador = $1.lexema;
                //simbolo.cat_simbolo = PARAMETRO;
                //simbolo.tipo = tipo_actual;
                //simbolo.categoria = ESCALAR;
                //simbolo.posicion = posicion_parametro;

                //DECLARAR SIMBOLO EN LA TABLA
              }
	;
%%

void yyerror(const char * s) {
    if(!is_morpho) {
        printf("****Error sintactico en [lin %d, col %d]\n", nlin, ncol);
    }
}
