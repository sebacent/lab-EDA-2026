// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// linea.c
// Modulo de implementacion de línea.

#include "definiciones.h"
#include "linea.h"

struct nodo_linea{
	Cadena palabras[MAX_CANT_PALABRAS_X_LINEA]; // Cantidad de palabras fijas
	unsigned int cantidad;
};

linea CrearLinea(){
// Crea la estructura linea.
	linea nueva_linea = new nodo_linea(); // () inicializa palabras en NULL y cantidad en 0
	return nueva_linea;
}

unsigned int CantidadPalabrasLinea(linea l){
// Pre: l fue creada con CrearLinea
// Post: devuelve la cantidad de palabras de la línea l.
	return l->cantidad;
}

