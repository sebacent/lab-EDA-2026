todo: main.o editor.o texto.o linea.o diccionario.o
	g++ -Wall -o main main.o editor.o texto.o linea.o diccionario.o
main.o: main.c editor.h texto.h definiciones.h
	g++ -Wall -c main.c
editor.o: editor.h editor.c texto.h diccionario.h definiciones.h
	g++ -Wall -c editor.c
texto.o: texto.h texto.c linea.h diccionario.h definiciones.h
	g++ -Wall -c texto.c
linea.o: linea.h linea.c diccionario.h definiciones.h
	g++ -Wall -c linea.c
diccionario.o: diccionario.h diccionario.c definiciones.h
	g++ -Wall -c diccionario.c
# se deben agregar aca las reglas de compilacion para los modulos que agreguen
# agregar tambien las dependencias en la regla todo:
clean:
	rm -f main
	rm -f *.o
