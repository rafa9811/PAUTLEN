Mensaje1 db “División por cero”, 0
segment .bss
__esp resd 1
b1 resd 1x resd 1segment .text
global main
extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string
main:
mov dword [__esp], esp
push dword 1
pop dword [_b1]
inicio_while_1
push dword _b1
push dword 1
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax edx
je near igual_1
push dword 0
jmp near fin_igual_1
igual_1:
push dword 1
fin_igual_1:
pop eax
cmp eax, 0
je fin_while_1
push dword x
call scan_int
pop dword eax
push dword _b1
push dword 4
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax edx
jg near mayor_1
push dword 0
jmp near fin_mayor_1
mayor_1:
push dword 1
fin_mayor_1:
pop dword [_b1]
push dword _b1
push dword 1
pop dword edx
pop dword eax
mov dword eax, [eax]
cmp dword eax edx
je near igual_2
push dword 0
jmp near fin_igual_2
igual_2:
push dword 1
fin_igual_2:
pop eax
cmp eax, 0
je fin_then_2
push dword _x
jmp near fin_ifelse_2
fin_then_2:
push dword 0
fin_ifelse_2
jmp near inicio_while_1
jmp while_fin_1:
mov dword esp, [__esp]
ret
