#ifndef TEXTO_H
#define TEXTO_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// texto.h
// Modulo de especificacion de texto.

#include "definiciones.h"
#include <iostream>

using namespace std;


typedef struct nodo_texto * texto;

texto CrearTexto();
// Crea la estructura texto.

void ImprimirTexto_Texto(texto t);
// Imprime el texto.

texto InsertarLinea_texto(texto t);
// Inserta una nueva linea al final del texto.


#endif

