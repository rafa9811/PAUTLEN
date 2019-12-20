#include "generacion.h"
#include <stdlib.h>
#include <stdio.h>


/** Implementación de funciones necesarias previamente especificadas: **/
void escribir_cabecera_bss(FILE* fpasm) {
  if(!fpasm) {
    printf("escribir cabecera");
    return;
  }
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "__esp resd 1\n");
  return;
}


void declarar_variable(FILE* fpasm, char* nombre,  int tipo,  int tamano) {
  if(!fpasm || !nombre) {
    printf("declarar variable");
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
    printf("escribir segmento codigo");
    return;
  }
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "global main\n");
  fprintf(fpasm, "extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string\n");
}


void escribir_subseccion_data(FILE* fpasm) {
  if(!fpasm) {
    printf("escribir segmento data");
    return;
  }
  fprintf(fpasm, "segment .data\n");
  fprintf(fpasm, "msg_error_division db \"División por cero\",0\n");
  fprintf(fpasm, "msg_error_indice_vector db \"Error en el indice del vector\", 0\n");
}


void escribir_inicio_main(FILE* fpasm) {
  if(!fpasm) {
    printf("escribir_inicio_main");
	  return;
  }
  fprintf(fpasm, "%s", "main:\n");
  fprintf(fpasm, "%s", "mov dword [__esp], esp\n");
}


void escribir_operando(FILE* fpasm, char* nombre, int es_variable) {
  if(!fpasm || !nombre || (es_variable!=0 && es_variable!=1)) {
    printf("escribir_operando");
	  return;
  }
  if(es_variable == 1) {
    fprintf(fpasm, "push dword _%s\n", nombre);
  }
  else {
    fprintf(fpasm, "push dword %s\n", nombre);
  }
}


void asignar(FILE* fpasm, char* nombre, int es_variable) {
  if(!fpasm || !nombre || (es_variable!=0 && es_variable!=1)) {
    printf("asignar");
	  return;
  }
  if(es_variable == 1) {
    fprintf(fpasm, "pop dword _%s\n", nombre);
  }
  else {
    fprintf(fpasm, "pop dword [_%s]\n", nombre);
  }
}


void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
    printf("igual");
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
    printf("distinto");
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


void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
   if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
     printf("mayor");
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


void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
   if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
     printf("menor");
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


void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {

  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
    printf("mayorigual");
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


void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {

  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
    printf("menorigual");
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


void leer(FILE* fpasm, char* nombre, int tipo) {
  if(!fpasm || !nombre) {
    printf("leer");
	  return;
  }
  fprintf(fpasm, "push dword _%s\n", nombre);
  if(tipo == ENTERO){
    fprintf(fpasm, "call scan_int\n");
  } else {
    fprintf(fpasm, "call scan_boolean\n");
    //Entiendo que se limpia pila almacenando en eax
  }
  fprintf(fpasm, "add dword esp, 4\n");
}


void escribir(FILE* fpasm, int es_variable, int tipo) {
  if(!fpasm || (es_variable!=0 && es_variable!=1)) {
    printf("escribir");
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


void sumar(FILE* fpasm, int es_variable1, int es_variable2) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
  	printf("sumar");
  	return;
  }
  fprintf(fpasm, "pop dword edx\n");
  fprintf(fpasm, "pop dword eax\n");
  if(es_variable1 == 1) {
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  if(es_variable2 == 1) {
    fprintf(fpasm, "mov dword edx, [edx]\n");
  }
  fprintf(fpasm, "add dword eax edx\n");
  fprintf(fpasm, "push dword eax\n");
}


void multiplicar(FILE* fpasm, int es_variable1, int es_variable2) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
  	fprintf(fpasm, "multiplicar");
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


void dividir(FILE* fpasm, int es_variable1, int es_variable2) {
  if(!fpasm || (es_variable1!=0 && es_variable1!=1) || (es_variable2!=0 && es_variable2!=1)) {
  	printf("dividir");
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


void escribir_fin(FILE* fpasm) {
  if(!fpasm) {
    printf("escribir_fin");
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


void suma_iterativa(FILE *fpasm, char *nombre1, char *nombre2) {
  //Lo primero que hacemos es leer de teclado dos operandos
  leer(fpasm, nombre1, ENTERO);
  leer(fpasm, nombre2, ENTERO);
  fprintf(fpasm, "mov dword eax, [_%s]\n", nombre1);
  //Etiqueta para cuando acabemos el programa.

  //Etiqueta para cuando queremos seguir porque no introducimos cero.
  fprintf(fpasm, "seguir_comprobando:\n");
  fprintf(fpasm, "mov dword edx, [_%s]\n", nombre2);
  fprintf(fpasm, "cmp dword edx, 0\n");
  fprintf(fpasm, "je acabar\n");
  //Ahora sumamos:
  fprintf(fpasm, "add eax, edx\n");
  fprintf(fpasm, "push dword eax\n");
  escribir(fpasm, 0, ENTERO);
  leer(fpasm, nombre2, ENTERO);
  fprintf(fpasm,"jmp seguir_comprobando\n");
  fprintf(fpasm, "acabar:\n");

}


//Funciones de la segunda semana.

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta) {

   fprintf(fpasm, "pop eax\n");
   if(exp_es_variable == 1){
      fprintf(fpasm, "mov eax, [eax]\n");
   }
   fprintf(fpasm, "cmp eax, 0\n");
   fprintf(fpasm, "je fin_then_%d\n", etiqueta);

}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta) {

   fprintf(fpasm, "pop eax\n");
   if(exp_es_variable == 1){
      fprintf(fpasm, "mov eax, [eax]\n");
   }
   fprintf(fpasm, "cmp eax, 0\n");
   fprintf(fpasm, "je fin_then_%d\n", etiqueta);

}

void ifthen_fin(FILE * fpasm, int etiqueta) {

   fprintf(fpasm, "fin_then_%d:\n", etiqueta);

}


void ifthenelse_fin_then( FILE * fpasm, int etiqueta) {

   fprintf(fpasm,"jmp near fin_ifelse_%d\n", etiqueta);
   fprintf(fpasm, "fin_then_%d:\n", etiqueta);

}

void ifthenelse_fin( FILE * fpasm, int etiqueta) {

   fprintf(fpasm, "fin_ifelse_%d:\n", etiqueta);

}

void while_inicio(FILE * fpasm, int etiqueta) {

   fprintf(fpasm, "inicio_while_%d:\n", etiqueta);

}

void while_exp_pila(FILE * fpasm, int exp_es_variable, int etiqueta) {

   fprintf(fpasm, "pop eax\n");
   if(exp_es_variable > 0) {
      fprintf(fpasm, "mov eax, [eax]\n");
   }
   fprintf(fpasm, "cmp eax, 0\n");
   fprintf(fpasm, "je fin_while_%d\n", etiqueta);

}

void while_fin( FILE * fpasm, int etiqueta) {

   fprintf(fpasm, "jmp near inicio_while_%d\n", etiqueta);
   fprintf(fpasm, "fin_while_%d:\n", etiqueta);

}

void escribir_elemento_vector(FILE * fpasm, char* nombre_vector, int tam_max, int exp_es_direccion) {

   fprintf(fpasm, "pop dword eax\n");
   if(exp_es_direccion == 1) {
      fprintf(fpasm, "mov dword eax, [eax]\n");
   }
   fprintf(fpasm, "cmp eax, 0\n");
   fprintf(fpasm, "jl nearfin_indice_fuera_rango\n");
   fprintf(fpasm, "cmp eax, %d\n", tam_max-1);
   fprintf(fpasm, "jg near fin_indice_fuera_rango\n");
   fprintf(fpasm, "mov dword edx\n");
   fprintf(fpasm, "lea eax, [edx + eax*4]\n");
   fprintf(fpasm, "push dword eax\n");

}

void asignarDestinoEnPila(FILE* fpasm, int es_variable) {

   fprintf(fpasm, "pop dword ebx\n");
   fprintf(fpasm, "pop dword eax\n");
   if(es_variable == 1) {
      fprintf(fpasm, "mov dword eax, [eax]\n");
   }
   fprintf(fpasm, "mov dword [ebx], eax\n");

}


void declararFuncion(FILE * fpasm, char * nombre_funcion, int num_var_loc) {

  fprintf(fpasm, "_%s:\n", nombre_funcion);
  fprintf(fpasm, "push ebp\n");
  fprintf(fpasm, "mov ebp, esp\n");
  fprintf(fpasm, "sub esp, %d\n", 4*num_var_loc);

}

void retornarFuncion(FILE * fpasm, int es_variable) {

  fprintf(fpasm, "pop eax\n");
  if(es_variable == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  fprintf(fpasm, "mov esp, ebp\n");
  fprintf(fpasm, "pop ebp\n");
  fprintf(fpasm, "ret\n");

}

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros) {
  int d_ebp;
  d_ebp = 4*(1 + (num_total_parametros - pos_parametro));
  fprintf(fpasm, "lea eax, [ebp + %d]\n", d_ebp);
  fprintf(fpasm, "push dword eax\n");

}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local) {
  int d_ebp;
  d_ebp = 4*posicion_variable_local;
  fprintf(fpasm, "lea eax, [ebp - %d]\n", d_ebp);
  fprintf(fpasm, "push dword eax\n");

}

void operandoEnPilaAArgumento(FILE * fpasm, int es_variable) {

  if(es_variable == 1) {
    fprintf(fpasm, "pop eax\n");
    fprintf(fpasm, "mov eax, [eax]\n");
    fprintf(fpasm, "push eax\n");
  }

}

void llamarFuncion(FILE * fpasm, char * nombre_funcion, int num_argumentos) {

  fprintf(fpasm, "call _%s\n", nombre_funcion);
  fprintf(fpasm, "add esp, %d\n", num_argumentos*4);
  fprintf(fpasm, "push dword eax\n");

}

void limpiarPila(FILE * fpasm, int num_argumentos) {

  fprintf(fpasm, "add esp, %d\n", num_argumentos*4);
  fprintf(fpasm, "push dword eax\n");

}
