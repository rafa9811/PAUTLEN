all:
	gcc -c generacion.c
	gcc ej3.c generacion.o -o ej3_gen
	./ej3_gen ej3.asm
	nasm -g -o ej3.o -f elf32 ej3.asm
	gcc -m32 -o ej3 ej3.o alfalib.o

clean:
	rm ej3 ej3.asm ej3.o ej3_gen
