#ifndef LINEA_H
#define LINEA_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// linea.h
// Modulo de especificacion de texto.

#include "definiciones.h"
#include "diccionario.h"
#include <iostream>

using namespace std;

typedef struct nodo_linea * linea;

linea CrearLinea();
// Crea la estructura linea

linea InsertarFinal(linea l);
// Crea una nueva linea vacia a continuacion de l y la retorna
// Pre: l es NULL o es la ultima linea (l->sig == NULL)

linea SiguienteLinea(linea l);
// Retorna la linea siguiente a l (NULL si es la ultima)
// Pre: l != NULL

void SetSiguienteLinea(linea l, linea sig);
// Hace que la siguiente de l sea sig
// Pre: l != NULL

int CantidadPalabras(linea l);
// Retorna la cantidad de palabras de l
// Pre: l != NULL

Cadena InsertarPalabra_linea(linea l, Posicion pos, Cadena palabra);
// Inserta palabra en la posicion pos de l, corriendo las siguientes un lugar
// La linea pasa a ser duena de palabra (no se copia)
// Si la linea estaba llena, retorna la palabra que quedo afuera (la ultima),
// si no retorna NULL
// Pre: l != NULL, 1 <= pos <= CantPalabras(l) + 1

Cadena SacarPrimeraPalabra(linea l);
// Quita la primera palabra de l (sin liberarla) y la retorna,
// corriendo las demas un lugar hacia adelante
// Pre: l != NULL, CantPalabras(l) > 0

void BorrarPalabra_linea(linea l, Posicion pos);
// Borra (y libera) la palabra en la posicion pos de l,
// corriendo las siguientes un lugar hacia adelante
// Pre: l != NULL, 1 <= pos <= CantPalabras(l)

void BorrarOcurrencias_linea(linea l, Cadena palabra);
// Borra todas las ocurrencias de palabra en l, sin distinguir
// mayusculas y minusculas
// Pre: l != NULL

void ImprimirLinea_linea(linea l, int pos);
// Imprime la linea l con el numero pos adelante. Ej: "2: Hola que tal"
// Pre: l != NULL

void ImprimirLineas(linea p, int pos);
// Imprime las lineas a partir de p, pos es la
// posicion de la linea, debe ponerse en 1 la primera vez

void ImprimirLineaIncorrecta_linea(linea l, int pos, diccionario d);
// Imprime la linea l con el numero pos adelante, mostrando solo las palabras
// que no estan en d. Ej: "2: Hola"
// Pre: l != NULL

void DestruirLinea(linea l);
// Libera la linea l y todas sus palabras (no toca las siguientes)
// Pre: l != NULL

#endif
