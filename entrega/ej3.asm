segment .data
msg_error_division db "División por cero",0
msg_error_indice_vector db "Error en el indice del vector", 0
segment .bss
__esp resd 1
_z resd 1
segment .text
global main
extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string
_doble:
push ebp
mov ebp, esp
sub esp, 4
lea eax, [ebp + 8]
push dword eax
lea eax, [ebp - 4]
push dword eax
pop dword ebx
pop dword eax
mov dword eax, [eax]
mov dword [ebx], eax
push dword 2
lea eax, [ebp + 8]
push dword eax
pop dword ecx
pop dword eax
mov dword ecx, [ecx]
imul ecx
cdq
push dword eax
pop eax
mov esp, ebp
pop ebp
ret
main:
mov dword [__esp], esp
push dword 2
pop dword [_z]
push dword _z
pop eax
mov eax, [eax]
push eax
call _doble
add esp, 4
push dword eax
pop dword eax
push dword eax
call print_int
call print_endofline
add dword esp, 4
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
