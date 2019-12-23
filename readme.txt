En el makefile, además de crear el ejecutable alfa,
también genero el ejecutable a partir del asm generado al ejecutar alfa
con algunos ficheros con los que he probado el compilador.

Si se quiere probar otro fichero nuevo,
ejecutamos tras hacer make ./alfa <nombre_fichero>.alfa <nombre_fichero>.asm
y lo compilamos con:


nasm -g -o <nombre_fichero>.o -f elf32 <nombre_fichero>.asm
gcc -m32 -o <nombre_fichero> <nombre_fichero>.o ../alfalib.o


para tener el ejecutable en nasm.
