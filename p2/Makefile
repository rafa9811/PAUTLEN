
all: lex.yy.c lex.yy.o pruebaMorfo

lex.yy.c: especificacion.l
	flex especificacion.l

lex.yy.o: lex.yy.c
	gcc -g -Wall -c lex.yy.c -o lex.yy.o

pruebaMorfo: pruebaMorfo.c lex.yy.o
	gcc -g -Wall -o pruebaMorfo pruebaMorfo.c lex.yy.o

clean:
	rm lex.yy.c lex.yy.o pruebaMorfo
