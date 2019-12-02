################################################################################


################################################################################
all: tablasimbolos

hash.o: hash.c
	gcc -g -Wall -c hash.c

tablasimbolos.o: tablasimbolos.c hash.c
	gcc -g -Wall -c tablasimbolos.c

tablasimbolos: tablasimbolos.c hash.o tablasimbolos.o
	gcc -g -Wall -o tablasimbolos tablasimbolos.o hash.o

clean:
	rm tablasimbolos tablasimbolos.o hash.o
