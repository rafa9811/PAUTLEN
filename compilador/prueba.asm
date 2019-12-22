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
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;declarar_variable
_resultado resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;escribir_segmento_codigo
segment .text
global main
extern malloc, free
extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string
;D:	int
;R10:	<tipo> ::= int
;D:	fibonacci
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	res1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	res2
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	if
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
_fibonacci:
push ebp
mov ebp, esp
sub esp, 8
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= <identificador>
;escribirParametro
lea eax, [ebp + 8]
push dword eax
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
;D:	)
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_1
;D:	return
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;retornarFuncion
pop eax
mov esp, ebp
pop ebp
ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_1
fin_then_1:
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;ifthenelse_fin
fin_ifelse_1:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= <identificador>
;escribirParametro
lea eax, [ebp + 8]
push dword eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 1
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
;D:	{
;ifthen_inicio
pop eax
cmp eax, 0
je fin_then_3
;D:	return
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;retornarFuncion
pop eax
mov esp, ebp
pop ebp
ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;ifthenelse_fin_then
jmp near fin_ifelse_3
fin_then_3:
;D:	res1
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;ifthenelse_fin
fin_ifelse_3:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	=
;D:	fibonacci
;D:	(
;D:	num1
;D:	-
;R80:	<exp> ::= <identificador>
;escribirParametro
lea eax, [ebp + 8]
push dword eax
;operandoEnPilaAArgumento
pop eax
mov eax, [eax]
push eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;escribir_operando
push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;operandoEnPilaAArgumento
;D:	)
;R73:	<exp> ::= <exp> - <exp>
;restar 
pop dword edx
pop dword eax
mov dword eax, [eax]
sub eax, edx
push dword eax
;R92:	<resto_lista_expresiones> ::= 
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
