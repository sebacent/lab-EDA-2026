#ifndef DICCIONARIO_H
#define DICCIONARIO_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// diccionario.h
// Modulo de especificacion de diccionario (ABB de palabras).
// Las palabras se comparan sin distinguir mayusculas y minusculas (strcasecmp),
// pero se guardan y se imprimen tal cual fueron ingresadas.

#include "definiciones.h"

typedef struct nodo_diccionario * diccionario;

diccionario CrearDiccionario();
// Post: devuelve un diccionario vacio.

bool EsVacioDiccionario(diccionario d);
// Post: devuelve true si d no tiene palabras.

bool PerteneceDiccionario(diccionario d, Cadena palabra);
// Pre: palabra no es NULL.
// Post: devuelve true si palabra esta en d (sin distinguir mayusculas).
//       O(log n) promedio.

void InsertarPalabra_diccionario(diccionario & d, Cadena palabra);
// Pre: palabra no es NULL y no pertenece a d.
// Post: agrega una copia de palabra a d (d no se queda con palabra).
//       O(log n) promedio.

void BorrarPalabra_diccionario(diccionario & d, Cadena palabra);
// Pre: palabra no es NULL y pertenece a d.
// Post: quita palabra de d y libera su memoria.

void ImprimirPalabras_diccionario(diccionario d);
// Post: imprime las palabras de d en orden alfabetico, una por renglon,
//       cada una con un tabulador adelante: "\tBosque\n". O(n) peor caso.
//       Si d es vacio no imprime nada.

void DestruirDiccionario(diccionario & d);
// Post: libera todas las palabras y nodos de d. d queda en NULL.

#endif
