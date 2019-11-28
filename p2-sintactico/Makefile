################################################################################
CC = gcc
FLAGS = -g -Wall
OBJECTS = pruebaMorfo.c lex.yy.o
################################################################################
all: lex.yy.c lex.yy.o pruebaMorfo

lex.yy.c: especificacion.l
	flex especificacion.l

lex.yy.o: lex.yy.c
	$(CC) $(FLAGS) -c lex.yy.c -o lex.yy.o

pruebaMorfo: $(OBJECTS)
	$(CC) $(FLAGS) -o pruebaMorfo $(OBJECTS)

clean:
	rm lex.yy.c lex.yy.o pruebaMorfo
