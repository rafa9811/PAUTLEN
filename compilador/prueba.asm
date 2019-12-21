;escribir_subseccion_data
segment .data
msg_error_division db "División por cero",0
msg_error_indice_vector db "Error en el indice del vector", 0
;escribir_cabecera_bss
segment .bss
__esp resd 1
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_x resd 1
;D:	,
;D:	y
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_y resd 1
;D:	,
;D:	z
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_z resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
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
;D:	x
;R54:	<lectura> ::= scanf <identificador>
;leer
push dword _x
call scan_int
add dword esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	y
;R54:	<lectura> ::= scanf <identificador>
;leer
push dword _y
call scan_int
add dword esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	z
;R54:	<lectura> ::= scanf <identificador>
;leer
push dword _z
call scan_int
add dword esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	if
;D:	(
;D:	(
;D:	x
;D:	==
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
;igual
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
je near igual_0
push dword 0
jmp near fin_igual_0
igual_0:
push dword 1
fin_igual_0:
;R83:	<exp> ::= ( <comparacion )
;D:	&&
;D:	(
;D:	y
;D:	==
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
;igual
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
je near igual_1
push dword 0
jmp near fin_igual_1
igual_1:
push dword 1
fin_igual_1:
;R83:	<exp> ::= ( <comparacion )
;D:	&&
;R77:	<exp> ::= <exp> && <exp>
;y 
pop dword edx
pop dword eax
and eax, edx
push dword eax
;D:	(
;D:	z
;D:	==
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
;igual
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
je near igual_2
push dword 0
jmp near fin_igual_2
igual_2:
push dword 1
fin_igual_2:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;y 
pop dword edx
pop dword eax
and eax, edx
push dword eax
;D:	{
pop eax
cmp eax, 0
je fin_then_3
;D:	printf
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
jmp near fin_ifelse_3
fin_then_3:
;D:	}
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_ifelse_3:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;R30:	<sentencias> ::= <sentencia>
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
