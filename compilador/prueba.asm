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
;declarar_variable
_x resd 1
;D:	,
;D:	y
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;declarar_variable
_y resd 1
;D:	,
;D:	z
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;declarar_variable
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
;escribir_operando
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
;escribir_operando
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
;escribir_operando
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
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_3
;D:	printf
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_3
fin_then_3:
;D:	else
;D:	{
;D:	if
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_4
push dword 0
jmp near fin_mayor_4
mayor_4:
push dword 1
fin_mayor_4:
;R83:	<exp> ::= ( <comparacion )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_5
push dword 0
jmp near fin_mayor_5
mayor_5:
push dword 1
fin_mayor_5:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;y 
pop dword edx
pop dword eax
and eax, edx
push dword eax
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_6
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_7
push dword 0
jmp near fin_mayor_7
mayor_7:
push dword 1
fin_mayor_7:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_8
;D:	printf
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_8
fin_then_8:
;D:	else
;D:	{
;D:	printf
;D:	5
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 5
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;ifthenelse_fin
fin_ifelse_8:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_6
fin_then_6:
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;ifthenelse_fin
fin_ifelse_6:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> <= <exp>
;menor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jl near menor_9
push dword 0
jmp near fin_menor_9
menor_9:
push dword 1
fin_menor_9:
;R83:	<exp> ::= ( <comparacion )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_10
push dword 0
jmp near fin_mayor_10
mayor_10:
push dword 1
fin_mayor_10:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;y 
pop dword edx
pop dword eax
and eax, edx
push dword eax
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_11
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_12
push dword 0
jmp near fin_mayor_12
mayor_12:
push dword 1
fin_mayor_12:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_13
;D:	printf
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 2
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_13
fin_then_13:
;D:	else
;D:	{
;D:	printf
;D:	6
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 6
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;ifthenelse_fin
fin_ifelse_13:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_11
fin_then_11:
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;ifthenelse_fin
fin_ifelse_11:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> <= <exp>
;menor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jl near menor_14
push dword 0
jmp near fin_menor_14
menor_14:
push dword 1
fin_menor_14:
;R83:	<exp> ::= ( <comparacion )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> <= <exp>
;menor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jl near menor_15
push dword 0
jmp near fin_menor_15
menor_15:
push dword 1
fin_menor_15:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;y 
pop dword edx
pop dword eax
and eax, edx
push dword eax
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_16
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_17
push dword 0
jmp near fin_mayor_17
mayor_17:
push dword 1
fin_mayor_17:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_18
;D:	printf
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 3
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_18
fin_then_18:
;D:	else
;D:	{
;D:	printf
;D:	7
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 7
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;ifthenelse_fin
fin_ifelse_18:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_16
fin_then_16:
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;ifthenelse_fin
fin_ifelse_16:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_19
push dword 0
jmp near fin_mayor_19
mayor_19:
push dword 1
fin_mayor_19:
;R83:	<exp> ::= ( <comparacion )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> <= <exp>
;menor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jl near menor_20
push dword 0
jmp near fin_menor_20
menor_20:
push dword 1
fin_menor_20:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;y 
pop dword edx
pop dword eax
and eax, edx
push dword eax
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_21
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
;escribir_operando
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> >= <exp>
;mayor
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax, edx
jg near mayor_22
push dword 0
jmp near fin_mayor_22
mayor_22:
push dword 1
fin_mayor_22:
;R83:	<exp> ::= ( <comparacion )
;D:	)
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_23
;D:	printf
;D:	4
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 4
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_23
fin_then_23:
;D:	else
;D:	{
;D:	printf
;D:	8
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 8
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
;escribir
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;ifthenelse_fin
fin_ifelse_23:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_21
fin_then_21:
;D:	}
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;ifthenelse_fin
fin_ifelse_21:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
;ifthenelse_fin
fin_ifelse_3:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
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
