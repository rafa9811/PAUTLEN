################################################################################
CC = gcc
FLAGS = -g -Wall
################################################################################


all: y.tab.c lex.yy.c lex.yy.o pruebaSintactico y.tab.o

y.tab.c: alfa.y
	bison -d -y -v alfa.y

lex.yy.c: especificacion.l
	flex especificacion.l

y.tab.o: y.tab.c
	$(CC) $(FLAGS) -c y.tab.c -o y.tab.o

lex.yy.o: lex.yy.c
	$(CC) $(FLAGS) -c lex.yy.c -o lex.yy.o

pruebaSintactico: pruebaSintactico.c
	$(CC) $(FLAGS) -o pruebaSintactico pruebaSintactico.c lex.yy.c y.tab.c

clean:
	rm lex.yy.c *.o pruebaSintactico y.tab.c y.tab.h *.output
