
all: pruebaMorfo

pruebaMorfo: pruebaMorfo.o lex.yy.o
	gcc -o pruebaMorfo pruebaMorfo.o lex.yy.o

pruebaMorfo.o: pruebaMorfo.c tokens.h
	gcc -c pruebaMorfo.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

