all:
	gcc -c generacion.c
	gcc ej2.c generacion.o -o ej2_gen
	./ej2_gen ej2.asm
	nasm -g -o ej2.o -f elf32 ej2.asm
	gcc -m32 -o ej2 ej2.o alfalib.o

clean:
	rm ej2 ej2.asm ej2.o ej2_gen
