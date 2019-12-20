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
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	}
;R2:	<declaraciones> ::= <declaracion>
;escribir_segmento_codigo
segment .text
global main
extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string
;R21:	<funciones> ::= 
;escribir_inicio_main
main:
mov dword [__esp], esp
