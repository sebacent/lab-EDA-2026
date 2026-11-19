// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// editor.c
// Modulo de implementacion de editor.

#include "editor.h"
#include "diccionario.h"
// Incluir los modulos realizados.
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_editor{
	texto t;
	diccionario d;
	// UltPal up
	/* acá deben figurar los campos/estructuras que usted considere necesarios
	para implementar el editor. Ej: texto, diccionario, etc. Recordar que cada módulo
	debe implementarse independientemente e incluirse */
};


editor CrearEditor(){
// Crea la estructura editor.
	editor e = new(nodo_editor);
	e->t = CrearTexto();
	e->d = CrearDiccionario();
	//e->up = CrearUltimasPalabras()
	/* crear el resto de las estructuras que se incluyan en el editor
	usando las funciones correspondientes de cada modulo */
	return e;
}

TipoRetorno InsertarLinea(editor & e){
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.
	InsertarLinea_texto(e->t);
	return OK;
}

TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea){
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	if (posicionLinea < 1 || posicionLinea > CantidadLineas(e->t) + 1) {
		return ERROR;
	}

	if (posicionLinea == CantidadLineas(e->t) + 1) {
		InsertarLinea(e);
		return OK;
	}

	InsertarLineaEnPosicion_texto(e->t, posicionLinea);
	return OK;
}

TipoRetorno BorrarLinea(editor & e, Posicion posicionLinea){
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	if (posicionLinea < 1 || posicionLinea > CantidadLineas(e->t)) {
		return ERROR;
	}

	BorrarLinea_texto(e->t, posicionLinea);
	return OK;
}

TipoRetorno BorrarTodo(editor & e){
// Borra todas las líneas del texto.
// Ver más detalles en la letra del obligatorio.
	BorrarTodo_texto(e->t);
	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor & e, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en el texto.
// Ver más detalles en la letra del obligatorio.
	BorrarOcurrenciasPalabraEnTexto_texto(e->t, palabraABorrar);
	return OK;
}

TipoRetorno ImprimirTexto(editor & e){
// Imprime el texto por pantalla.
// Ver más detalles en la letra del obligatorio.
	ImprimirTexto_Texto(e->t);
	return OK;
}

TipoRetorno ComprimirTexto(editor & e){
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.
	if (posicionLinea < 1 || posicionLinea > CantidadLineas(e->t)) {
		return ERROR;
	}

	if (posicionPalabra < 1 || posicionPalabra > CantidadPalabrasLinea(e->t, posicionLinea) + 1) {
		return ERROR;
	}

	InsertarPalabra_texto(e->t, posicionLinea, posicionPalabra, palabraAIngresar);
	return OK;
}

TipoRetorno BorrarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra){
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.
	if (posicionLinea < 1 || posicionLinea > CantidadLineas(e->t)) {
		return ERROR;
	}

	if (posicionPalabra < 1 || posicionPalabra > CantidadPalabrasLinea(e->t, posicionLinea)) {
		return ERROR;
	}

	BorrarPalabra_texto(e->t, posicionLinea, posicionPalabra);

	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor & e, Posicion posicionLinea, Cadena palabraABorrar){
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.
	if (posicionLinea < 1 || posicionLinea > CantidadLineas(e->t)) {
		return ERROR;
	}

	// El main no corta por espacios aca, asi que la palabra llega como " Palabra"
	while (palabraABorrar[0] == ' ')
		palabraABorrar++;


	BorrarOcurrenciasPalabraEnLinea_texto(e->t, posicionLinea, palabraABorrar);
	return OK;
}

TipoRetorno ImprimirLinea(editor & e, Posicion posicionLinea){
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.
	if (posicionLinea < 1 || posicionLinea > (Posicion) CantidadLineas(e->t))
		return ERROR;

	ImprimirLinea_texto(e->t, posicionLinea);
	return OK;
}

TipoRetorno IngresarPalabraDiccionario(editor & e, Cadena palabraAIngresar){
// Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.
// Ver más detalles en la letra del obligatorio.
	if (PerteneceDiccionario(e->d, palabraAIngresar))
		return ERROR;

	InsertarPalabra_diccionario(e->d, palabraAIngresar);
	return OK;
}

TipoRetorno BorrarPalabraDiccionario(editor & e, Cadena palabraABorrar){
// Borra una palabra del diccionario.
// Ver más detalles en la letra del obligatorio.
	if (!PerteneceDiccionario(e->d, palabraABorrar))
		return ERROR;

	BorrarPalabra_diccionario(e->d, palabraABorrar);
	return OK;
}

TipoRetorno ImprimirDiccionario(editor & e){
// Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.
// Ver más detalles en la letra del obligatorio.
	if (EsVacioDiccionario(e->d))
		cout << "\tDiccionario vacio\n";
	else
		ImprimirPalabras_diccionario(e->d);
	return OK;
}

TipoRetorno ImprimirTextoIncorrecto(editor & e){
// Muestra las palabras del texto que no se encuentran en el diccionario.
// Ver más detalles en la letra del obligatorio.
	ImprimirTextoIncorrecto_texto(e->t, e->d);
	return OK;
}

TipoRetorno ImprimirUltimasPalabras(editor & e){
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno DestruirEditor(editor & e){
// Destruye la estructura editor y libera la memoria asociada.
	DestruirTexto(e->t);
	DestruirDiccionario(e->d);
	delete e;
	e = NULL;
	return OK;
}


