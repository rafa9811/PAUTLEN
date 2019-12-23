EXE = alfa fibonacci funciones condicionales funciones_vectores factorial indicesydivision dosfunciones

all: $(EXE)

alfa: alfa.c lex.yy.o y.tab.o generacion.o tablasimbolos.o hash.o
	gcc -Wall $^ -o $@

alfa.c:
	@echo "Empty" > /dev/null

fibonacci:
	./alfa fibonacci.alfa fibonacci.asm
	nasm -g -o fibonacci.o -f elf32 fibonacci.asm
	gcc -m32 -o fibonacci fibonacci.o ../alfalib.o

funciones:
	./alfa funciones.alfa funciones.asm
	nasm -g -o funciones.o -f elf32 funciones.asm
	gcc -m32 -o funciones funciones.o ../alfalib.o

condicionales:
	./alfa condicionales.alfa condicionales.asm
	nasm -g -o condicionales.o -f elf32 condicionales.asm
	gcc -m32 -o condicionales condicionales.o ../alfalib.o

funciones_vectores:
	./alfa funciones_vectores.alfa funciones_vectores.asm
	nasm -g -o funciones_vectores.o -f elf32 funciones_vectores.asm
	gcc -m32 -o funciones_vectores funciones_vectores.o ../alfalib.o

vectores:
	./alfa vectores.alfa vectores.asm
	nasm -g -o vectores.o -f elf32 vectores.asm
	gcc -m32 -o vectores vectores.o ../alfalib.o

factorial:
	./alfa factorial.alfa factorial.asm
	nasm -g -o factorial.o -f elf32 factorial.asm
	gcc -m32 -o factorial factorial.o ../alfalib.o

dosfunciones:
	./alfa dosfunciones.alfa dosfunciones.asm
	nasm -g -o dosfunciones.o -f elf32 dosfunciones.asm
	gcc -m32 -o dosfunciones dosfunciones.o ../alfalib.o

indicesydivision:
	./alfa indicesydivision.alfa indicesydivision.asm
	nasm -g -o indicesydivision.o -f elf32 indicesydivision.asm
	gcc -m32 -o indicesydivision indicesydivision.o ../alfalib.o


generacion.o: generacion.c generacion.h
	gcc -Wall -c $<

tablasimbolos.o: tablasimbolos.c tablasimbolos.h
	gcc -Wall -c $<

hash.o: hash.c hash.h
	gcc -Wall -c $<

lex.yy.o: lex.yy.c
	gcc -Wall -c $^

lex.yy.c: especificacion.l y.tab.h
	flex $<

y.tab.o: y.tab.c
	gcc -Wall -c $<

y.tab.c: alfa.y
	bison -d -y -v $^

y.tab.h: alfa.y
	bison -d -y -v $^


.PHONY: clean
clean:
	rm -rf *.o alfa lex.yy.* y.tab.* y.output *.asm $(EXE)
