MINI = prueba
EXE = alfa $(MINI)

all: $(EXE)

alfa: alfa.c lex.yy.o y.tab.o generacion.o tablasimbolos.o hash.o
	gcc -Wall $^ -o $@

generacion.o: generacion.c generacion.h
	gcc -Wall -c $<

tablasimbolos.o: tablasimbolos.c tablasimbolos.h
	gcc -Wall -c $<

hash.o: hash.c hash.h
	gcc -Wall -c $<

lex.yy.o: lex.yy.c
	gcc -Wall -c $^

y.tab.o: y.tab.c
	gcc -Wall -c $<

lex.yy.c: especificacion.l y.tab.h
	flex $<

y.tab.c: alfa.y
	bison -d -y -v $^

y.tab.h: alfa.y
	bison -d -y -v $^

${MINI}: %: alfa %.alfa
	./alfa $@.alfa $@.asm
	nasm -g -o $@.o -f elf32 $@.asm
	gcc -m32 -o $@ $@.o ../alfalib.o

alfa.c:
	@echo "Empty" > /dev/null

.PHONY: clean
clean:
	rm -rf *.o alfa lex.yy.* y.tab.* y.output $(EXE)
