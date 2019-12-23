/*********************************************************************
** PROYECTO DE AUTÓMATAS Y LENGUAJES - PRÁCTICA 1
** generacion.c
** AUTORES:
**  - Carlos Molinero Alvarado - carlos.molineroa@estudiante.uam.es
**  - Rafael Hidalgo Alejo - rafael.hidalgoa@estudiante.uam.es
** ÚLTIMA MODIFICACIÓN: 28 de octubre de 2019.
**********************************************************************/

#include "generacion.h"

/******************
** PRIMERA PARTE **
*******************/

/** Implementación de funciones necesarias previamente especificadas: **/
void escribir_cabecera_bss(FILE* fpasm) {
  if(!fpasm) {
    fprintf(stderr, "escribir cabecera\n");
    return;
  }
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "__esp resd 1\n");
  return;
}


void escribir_subseccion_data(FILE* fpasm) {
  if(!fpasm) {
    fprintf(stderr, "escribir subseccion data\n");
    return;
  }
  fprintf(fpasm, "segment .data\n");
  fprintf(fpasm, "msg_error_division db \"División por cero\",0\n");
  fprintf(fpasm, "msg_error_indice_vector db \"Error en el indice del vector\", 0\n");
}


void declarar_variable(FILE* fpasm, char* nombre,  int tipo,  int tamano) {
  if(!fpasm || !nombre) {
    fprintf(stderr, "declarar variable\n");
	  return;
  }
  fprintf(fpasm,"_%s ", nombre);
  if(tipo == ENTERO || tipo == BOOLEANO) {
    fprintf(fpasm, "resd ");
  }
  fprintf(fpasm, "%d", tamano);
  fprintf(fpasm, "\n");
  return;
}


void escribir_segmento_codigo(FILE* fpasm) {
  if(!fpasm) {
    fprintf(stderr, "escribir_segmento_codigo\n");
    return;
  }
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "global main\n");
  fprintf(fpasm, "extern malloc, free\n");
  fprintf(fpasm, "extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string\n");
}


void escribir_inicio_main(FILE* fpasm) {
  if(!fpasm) {
    fprintf(stderr, "escribir_inicio_main\n");
	  return;
  }
  fprintf(fpasm, "%s", "main:\n");
  fprintf(fpasm, "%s", "mov dword [__esp], esp\n");
}


void escribir_fin(FILE* fpasm) {
  if(!fpasm) {
    fprintf(stderr, "escribir_fin\n");
    return;
  }
  fprintf(fpasm, "jmp near fin\n");
  fprintf(fpasm, "fin_error_division:\n");
  fprintf(fpasm, "push dword msg_error_division\n");
  fprintf(fpasm, "call print_string\n");
  fprintf(fpasm, "add esp, 4\n");
  fprintf(fpasm, "call print_endofline\n");
  fprintf(fpasm, "jmp near fin\n");
  fprintf(fpasm, "fin_indice_fuera_rango:\n");
  fprintf(fpasm, "push dword msg_error_indice_vector\n");
  fprintf(fpasm, "call print_string\n");
  fprintf(fpasm, "add esp, 4\n");
  fprintf(fpasm, "call print_endofline\n");
  fprintf(fpasm, "jmp near fin\n");
  fprintf(fpasm, "fin:\n");
  fprintf(fpasm, "mov esp, [__esp]\n");
  fprintf(fpasm, "ret\n");
}


void asignar(FILE* fpasm, char* nombre, int es_variable) {
  if(!fpasm || !nombre || (es_variable!=0 && es_variable!=1)) {
    fprintf(stderr, "asignar\n");
	  return;
  }
  if(es_variable == 1) {
	fprintf(fpasm, "pop dword eax\n");
    fprintf(fpasm, "mov dword _%s, eax\n", nombre);
  }
  else {
	fprintf(fpasm, "pop dword eax\n");
    fprintf(fpasm, "mov dword [_%s], eax\n", nombre);
  }
}


/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
void sumar(FILE* fpasm, int es_variable_1, int es_variable_2) {
  if(!fpasm || (es_variable_1!=0 && es_variable_1!=1) || (es_variable_2!=0 && es_variable_2!=1)) {
  	fprintf(stderr, "sumar\n");
  	return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable_1 == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable_2 == 1) {
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "add eax, edx\n");
  fprintf(fpasm, "push dword eax\n");
}


void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  if(!fpasm || (es_variable_1!=0 && es_variable_1!=1) || (es_variable_2!=0 && es_variable_2!=1)) {
  	fprintf(stderr, "sumar\n");
  	return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable_1 == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable_2 == 1) {
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "sub eax, edx\n");
  fprintf(fpasm, "push dword eax\n");
}


void dividir(FILE* fpasm, int es_variable1, int es_variable2) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
  	fprintf(stderr, "dividir\n");
  	return;
  }
  fprintf(fpasm, "pop dword ecx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable1 == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable2 == 1) {
    fprintf(fpasm, "mov dword ecx, [ecx]\n");
  }
  fprintf(fpasm, "cmp ecx, 0\n");
  fprintf(fpasm, "je fin_error_division\n");
  fprintf(fpasm, "cdq\n");
  fprintf(fpasm, "idiv dword ecx\n");
  fprintf(fpasm, "push dword eax\n");
}


void multiplicar(FILE* fpasm, int es_variable1, int es_variable2) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
  	fprintf(stderr, "multiplicar\n");
  	return;
  }
  fprintf(fpasm, "pop dword ecx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable1 == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable2 == 1) {
    fprintf(fpasm, "mov dword ecx, [ecx]\n");
  }
  fprintf(fpasm, "imul ecx\n");
  fprintf(fpasm, "cdq\n");
  fprintf(fpasm, "push dword eax\n");
}


void o(FILE* fpasm, int es_variable_1, int es_variable_2) {
  if(!fpasm || (es_variable_1!=0 && es_variable_1!=1) || (es_variable_2!=0 && es_variable_2!=1)) {
    fprintf(stderr, "o\n");
    return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable_1 == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable_2 == 1) {
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "or eax, edx\n");
  fprintf(fpasm, "push dword eax\n");
}


void y(FILE* fpasm, int es_variable_1, int es_variable_2) {
  if(!fpasm || (es_variable_1!=0 && es_variable_1!=1) || (es_variable_2!=0 && es_variable_2!=1)) {
    fprintf(stderr, "y\n");
    return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable_1 == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable_2 == 1) {
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "and eax, edx\n");
  fprintf(fpasm, "push dword eax\n");
}


void cambiar_signo(FILE* fpasm, int es_variable){
  if(!fpasm || (es_variable!=0 && es_variable!=1)) {
    fprintf(stderr, "cambiar_signo\n");
    return;
  }
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  fprintf(fpasm, "neg eax\n");
  fprintf(fpasm, "push dword eax\n");
}


void no(FILE* fpasm, int es_variable, int cuantos_no) {
  if(!fpasm || (es_variable!=0 && es_variable!=1)) {
    fprintf(stderr, "no\n");
    return;
  }
  fprintf(fpasm, "pop dword eax\n");

  if(es_variable == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  fprintf(fpasm, "or eax, eax\n");
  fprintf(fpasm, "jz near negar_falso_%d\n", cuantos_no);
  fprintf(fpasm, "mov dword eax, 0\n");
  fprintf(fpasm, "jmp near fin_negacion_%d\n", cuantos_no);
  fprintf(fpasm, "negar_falso_%d:\n", cuantos_no);
  fprintf(fpasm, "mov dword eax, 1\n");
  fprintf(fpasm, "fin_negacion_%d:\n", cuantos_no);
  fprintf(fpasm, "push dword eax\n");
}


/* FUNCIONES COMPARATIVAS */
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
    fprintf(stderr, "igual\n");
    return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable1 == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable2 == 1){
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "cmp dword eax, edx\n");
  fprintf(fpasm, "je near igual_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp near fin_igual_%d\n", etiqueta);
  fprintf(fpasm, "igual_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "fin_igual_%d:\n", etiqueta);
}


void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
    fprintf(stderr, "distinto\n");
    return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable1 == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable2 == 1){
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "cmp dword eax, edx\n");
  fprintf(fpasm, "jne near distinto_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp near fin_distinto_%d\n", etiqueta);
  fprintf(fpasm, "distinto_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "fin_distinto_%d:\n", etiqueta);
}


void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
    fprintf(stderr, "menorigual\n");
    return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable1 == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable2 == 1){
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "cmp dword eax, edx\n");
  fprintf(fpasm, "jle near menorigual_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp near fin_menorigual_%d\n", etiqueta);
  fprintf(fpasm, "menorigual_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "fin_menorigual_%d:\n", etiqueta);
}


void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
    fprintf(stderr, "mayorigual\n");
    return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable1 == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable2 == 1){
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "cmp dword eax, edx\n");
  fprintf(fpasm, "jge near mayorigual_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp near fin_mayorigual_%d\n", etiqueta);
  fprintf(fpasm, "mayorigual_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "fin_mayorigual_%d:\n", etiqueta);
}


void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
   if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
     fprintf(stderr, "menor\n");
     return;
   }
   fprintf(fpasm, "pop dword edx\n");
   fprintf(fpasm, "pop dword eax\n");
   if(es_variable1 == 1){
     fprintf(fpasm, "mov dword eax, [eax]\n");
   }
   if(es_variable2 == 1){
     fprintf(fpasm, "mov dword edx, [edx]\n");
   }
   fprintf(fpasm, "cmp dword eax, edx\n");
   fprintf(fpasm, "jl near menor_%d\n", etiqueta);
   fprintf(fpasm, "push dword 0\n");
   fprintf(fpasm, "jmp near fin_menor_%d\n", etiqueta);
   fprintf(fpasm, "menor_%d:\n", etiqueta);
   fprintf(fpasm, "push dword 1\n");
   fprintf(fpasm, "fin_menor_%d:\n", etiqueta);
}


void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
   if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
     fprintf(stderr, "mayor\n");
     return;
   }
   fprintf(fpasm, "pop dword edx\n");
   fprintf(fpasm, "pop dword eax\n");
   if(es_variable1 == 1){
     fprintf(fpasm, "mov dword eax, [eax]\n");
   }
   if(es_variable2 == 1){
     fprintf(fpasm, "mov dword edx, [edx]\n");
   }
   fprintf(fpasm, "cmp dword eax, edx\n");
   fprintf(fpasm, "jg near mayor_%d\n", etiqueta);
   fprintf(fpasm, "push dword 0\n");
   fprintf(fpasm, "jmp near fin_mayor_%d\n", etiqueta);
   fprintf(fpasm, "mayor_%d:\n", etiqueta);
   fprintf(fpasm, "push dword 1\n");
   fprintf(fpasm, "fin_mayor_%d:\n", etiqueta);
}


/* FUNCIONES DE ESCRITURA Y LECTURA */
void leer(FILE* fpasm, char* nombre, int tipo) {
  if(!fpasm || !nombre) {
    fprintf(stderr, "leer\n");
	  return;
  }
  fprintf(fpasm, "push dword _%s\n", nombre);
  if(tipo == ENTERO){
    fprintf(fpasm, "call scan_int\n");
  } else {
    fprintf(fpasm, "call scan_boolean\n");
  }
  fprintf(fpasm, "add dword esp, 4\n");
}


void escribir(FILE* fpasm, int es_variable, int tipo) {
  if(!fpasm || (es_variable!=0 && es_variable!=1)) {
    fprintf(stderr, "escribir\n");
  	return;
  }
  //Lo que hacemos es pop de lo que hay en pila. Dependiendo de lo que haya dentro,
  //hago el push para que almacene el valor, que es lo que espera recibir print.
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
    fprintf(fpasm, "push dword eax\n");
  }
  else {
    fprintf(fpasm, "push dword eax\n");
  }
  if(tipo == ENTERO) {
    fprintf(fpasm, "call print_int\n");
    fprintf(fpasm, "call print_endofline\n");
  }
  else {
    fprintf(fpasm, "call print_boolean\n");
    fprintf(fpasm, "call print_endofline\n");
  }
  fprintf(fpasm, "add dword esp, 4\n");
}

/******************
** SEGUNDA PARTE **
*******************/

/** Implementación de funciones necesarias previamente especificadas: **/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable) {
  if(!fpasm || !nombre || (es_variable!=0 && es_variable!=1)) {
    fprintf(stderr, "escribir_operando\n");
	  return;
  }
  if(es_variable == 1) {
    fprintf(fpasm, "push dword _%s\n", nombre);
  }
  else {
    fprintf(fpasm, "push dword %s\n", nombre);
  }
}


void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros) {
  if(!fpasm) {
    fprintf(stderr, "escribirParametro\n");
    return;
  }
  int d_ebp;
  d_ebp = 4*(1 + (num_total_parametros - pos_parametro));
  fprintf(fpasm, "lea eax, [ebp + %d]\n", d_ebp);
  fprintf(fpasm, "push dword eax\n");
}


void escribirVariableLocal(FILE* fpasm, int posicion_variable_local) {
  if(!fpasm) {
    fprintf(stderr, "escribirVariableLocal\n");
    return;
  }
  int d_ebp;
  d_ebp = 4*posicion_variable_local;
  fprintf(fpasm, "lea eax, [ebp - %d]\n", d_ebp);
  fprintf(fpasm, "push dword eax\n");
}


void declararFuncion(FILE * fpasm, char * nombre_funcion, int num_var_loc) {
  if(!fpasm || !nombre_funcion) {
    fprintf(stderr, "declararFuncion\n");
    return;
  }
  fprintf(fpasm, "_%s:\n", nombre_funcion);
  fprintf(fpasm, "push ebp\n");
  fprintf(fpasm, "mov ebp, esp\n");
  fprintf(fpasm, "sub esp, %d\n", 4*num_var_loc);
}


void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "ifthenelse_inicio\n");
    return;
  }
  fprintf(fpasm, "pop eax\n");
  if(exp_es_variable == 1){
    fprintf(fpasm, "mov eax, [eax]\n");
  }
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je fin_then_%d\n", etiqueta);
}


void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "ifthen_inicio\n");
    return;
  }
  fprintf(fpasm, "pop eax\n");
  if(exp_es_variable == 1){
    fprintf(fpasm, "mov eax, [eax]\n");
  }
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je fin_then_%d\n", etiqueta);
}


void ifthen_fin(FILE * fpasm, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "ifthen_fin\n");
    return;
  }
  fprintf(fpasm, "fin_then_%d:\n", etiqueta);
}


void ifthenelse_fin_then(FILE * fpasm, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "ifthenelse_fin_then\n");
    return;
  }
  fprintf(fpasm,"jmp near fin_ifelse_%d\n", etiqueta);
  fprintf(fpasm, "fin_then_%d:\n", etiqueta);
}


void ifthenelse_fin(FILE * fpasm, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "ifthenelse_fin\n");
    return;
  }
  fprintf(fpasm, "fin_ifelse_%d:\n", etiqueta);
}


void while_inicio(FILE * fpasm, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "while_inicio\n");
    return;
  }
  fprintf(fpasm, "inicio_while_%d:\n", etiqueta);
}


void while_exp_pila(FILE * fpasm, int exp_es_variable, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "while_exp_pila\n");
    return;
  }
  fprintf(fpasm, "pop eax\n");
  if(exp_es_variable > 0) {
    fprintf(fpasm, "mov eax, [eax]\n");
  }
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je fin_while_%d\n", etiqueta);
}


void while_fin(FILE * fpasm, int etiqueta) {
  if(!fpasm) {
    fprintf(stderr, "while_fin\n");
    return;
  }
  fprintf(fpasm, "jmp near inicio_while_%d\n", etiqueta);
  fprintf(fpasm, "fin_while_%d:\n", etiqueta);
}


void escribir_elemento_vector(FILE * fpasm, char* nombre_vector, int tam_max, int exp_es_direccion) {
  if(!fpasm || !nombre_vector) {
    fprintf(stderr, "escribir_elemento_vector\n");
    return;
  }
  fprintf(fpasm, "pop dword eax\n");
  if(exp_es_direccion == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "jl near fin_indice_fuera_rango\n");
  fprintf(fpasm, "cmp eax, %d\n", tam_max-1);
  fprintf(fpasm, "jg near fin_indice_fuera_rango\n");
  fprintf(fpasm, "mov dword edx, _%s\n", nombre_vector);
  fprintf(fpasm, "lea eax, [edx + eax*4]\n");
  fprintf(fpasm, "push dword eax\n");
}


void asignarDestinoEnPila(FILE* fpasm, int es_variable) {
  if(!fpasm || (es_variable!= 0 && es_variable!=1)) {
    fprintf(stderr, "asignarDestinoEnPila\n");
    return;
  }
  fprintf(fpasm, "pop dword ebx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  fprintf(fpasm, "mov dword [ebx], eax\n");
}


void llamarFuncion(FILE * fpasm, char * nombre_funcion, int num_argumentos) {
  if(!fpasm || !nombre_funcion) {
    fprintf(stderr, "llamarFuncion\n");
    return;
  }
  fprintf(fpasm, "call _%s\n", nombre_funcion);
}


void retornarFuncion(FILE * fpasm, int es_variable) {
  if(!fpasm || (es_variable!= 0 && es_variable!=1)) {
    fprintf(stderr, "retornarFuncion\n");
    return;
  }
  fprintf(fpasm, "pop eax\n");
  if(es_variable == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  fprintf(fpasm, "mov esp, ebp\n");
  fprintf(fpasm, "pop ebp\n");
  fprintf(fpasm, "ret\n");
}


void operandoEnPilaAArgumento(FILE * fpasm, int es_variable) {
  if(!fpasm || (es_variable!=0 && es_variable!=1)) {
    fprintf(stderr, "operandoEnPilaAArgumento\n");
    return;
  }
  if(es_variable == 1) {
    fprintf(fpasm, "pop eax\n");
    fprintf(fpasm, "mov eax, [eax]\n");
    fprintf(fpasm, "push eax\n");
  }
}


void limpiarPila(FILE * fpasm, int num_argumentos) {
  if(!fpasm) {
    fprintf(stderr, "limpiarPila\n");
    return;
  }
  fprintf(fpasm, "add esp, %d\n", num_argumentos*4);
  fprintf(fpasm, "push dword eax\n");
}
