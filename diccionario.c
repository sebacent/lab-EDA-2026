// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// diccionario.c
// Modulo de implementacion de diccionario (ABB de palabras).

#include "definiciones.h"
#include "diccionario.h"
#include <iostream>
#include <string.h>
#include <strings.h>

using namespace std;

// TODO Seba: definir el nodo del ABB.
struct nodo_diccionario{
};

diccionario CrearDiccionario(){
	return NULL;
}

bool EsVacioDiccionario(diccionario d){
	return d == NULL;
}

bool PerteneceDiccionario(diccionario d, Cadena palabra){
	// TODO Seba
	return false;
}

void InsertarPalabra_diccionario(diccionario & d, Cadena palabra){
	// TODO Seba
}

void BorrarPalabra_diccionario(diccionario & d, Cadena palabra){
	// TODO Seba
}

void ImprimirPalabras_diccionario(diccionario d){
	// TODO Seba
}

void DestruirDiccionario(diccionario & d){
	// TODO Seba
	d = NULL;
}
