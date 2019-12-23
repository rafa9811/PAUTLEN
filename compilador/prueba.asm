;escribir_subseccion_data
segment .data
msg_error_division db "División por cero",0
msg_error_indice_vector db "Error en el indice del vector", 0
;escribir_cabecera_bss
segment .bss
__esp resd 1
;D:	main
;D:	{
;D:	array
;D:	int
;R10:	<tipo> ::= int
;D:	[
;D:	4
;D:	]
;R15:	<clase_vector> ::= array <tipo> [<constante_entera]
;R7:	<clase> ::= <clase_vector>
;D:	vector1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;declarar_variable
_vector1 resd 4
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	vector1
;R2:	<declaraciones> ::= <declaracion>
;escribir_segmento_codigo
segment .text
global main
extern malloc, free
extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string
;R21:	<funciones> ::= 
;escribir_inicio_main
main:
mov dword [__esp], esp
;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	10
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 10
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;escribir_operando
push dword 0
;escribir_elemento_vector
pop dword eax
cmp eax, 0
jl near fin_indice_fuera_rango
cmp eax, 3
jg near fin_indice_fuera_rango
mov dword edx, _vector1
lea eax, [edx + eax*4]
push dword eax
;asignarDestinoEnPila
pop dword ebx
pop dword eax
mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	*
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 3
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R75:	<exp> ::= <exp> * <exp>
;multiplicar 
pop dword ecx
pop dword eax
imul ecx
cdq
push dword eax
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	40
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 40
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;escribir_operando
push dword 3
;escribir_elemento_vector
pop dword eax
cmp eax, 0
jl near fin_indice_fuera_rango
cmp eax, 3
jg near fin_indice_fuera_rango
mov dword edx, _vector1
lea eax, [edx + eax*4]
push dword eax
;asignarDestinoEnPila
pop dword ebx
pop dword eax
mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	5
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 5
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;escribir_operando
push dword 1
;escribir_elemento_vector
pop dword eax
cmp eax, 0
jl near fin_indice_fuera_rango
cmp eax, 3
jg near fin_indice_fuera_rango
mov dword edx, _vector1
lea eax, [edx + eax*4]
push dword eax
;asignarDestinoEnPila
pop dword ebx
pop dword eax
mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R84:	<exp> ::= <elemento_vector>
;escribir_elemento_vector
pop dword eax
cmp eax, 0
jl near fin_indice_fuera_rango
cmp eax, 3
jg near fin_indice_fuera_rango
mov dword edx, _vector1
lea eax, [edx + eax*4]
push dword eax
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
mov dword eax, [eax]
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R84:	<exp> ::= <elemento_vector>
;escribir_elemento_vector
pop dword eax
cmp eax, 0
jl near fin_indice_fuera_rango
cmp eax, 3
jg near fin_indice_fuera_rango
mov dword edx, _vector1
lea eax, [edx + eax*4]
push dword eax
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
mov dword eax, [eax]
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 3
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R84:	<exp> ::= <elemento_vector>
;escribir_elemento_vector
pop dword eax
cmp eax, 0
jl near fin_indice_fuera_rango
cmp eax, 3
jg near fin_indice_fuera_rango
mov dword edx, _vector1
lea eax, [edx + eax*4]
push dword eax
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
mov dword eax, [eax]
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R1:	<programa> ::= main { <declaraciones> <funciones> <sentencias> }
;escribir_fin
jmp near fin
fin_error_division:
push dword msg_error_division
call print_string
add esp, 4
call print_endofline
jmp near fin
fin_indice_fuera_rango:
push dword msg_error_indice_vector
call print_string
add esp, 4
call print_endofline
jmp near fin
fin:
mov esp, [__esp]
ret
