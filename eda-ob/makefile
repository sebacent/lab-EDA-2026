todo: main.o editor.o texto.o linea.o
	g++ -Wall -o main main.o editor.o texto.o linea.o
main.o: main.c
	g++ -Wall -c main.c
editor.o: editor.h editor.c
	g++ -Wall -c editor.c
texto.o: texto.h texto.c
	g++ -Wall -c texto.c
linea.o: linea.h linea.c
	g++ -Wall -c linea.c
# se deben agregar aca las reglas de compilacion para los modulos que agreguen
# agregar tambien las dependencias en la regla todo:
clean:
	rm -f main
	rm -f *.o

