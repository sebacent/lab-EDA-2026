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
// Crea la estructura texto (vacio, 0 lineas).

int CantidadLineas(texto t);
// Retorna la cantidad de lineas del texto.

int CantidadPalabrasLinea(texto t, Posicion posicionLinea);
// Retorna la cantidad de palabras de la linea indicada.

void ImprimirTexto_Texto(texto t);
// Imprime el texto. Si no tiene lineas imprime "Texto vacio".

void InsertarLinea_texto(texto t);
// Inserta una nueva linea al final del texto. O(1) peor caso.

void InsertarLineaEnPosicion_texto(texto t, Posicion posicionLinea);
// Inserta una linea vacia en la posicion indicada.

void BorrarLinea_texto(texto t, Posicion posicionLinea);
// Borra la linea en la posicion indicada.
// Pre: la posicion de la linea es valida.

void BorrarTodo_texto(texto t);
// Borra todas las lineas del texto (queda vacio).

void BorrarOcurrenciasPalabraEnTexto_texto(texto t, Cadena palabra);
// Borra todas las ocurrencias de palabra en todas las lineas.

void ComprimirTexto_texto(texto t);
// Llena todas las lineas (salvo quizas la ultima) manteniendo el orden
// de las palabras, y borra las lineas que quedan vacias.

void InsertarPalabra_texto(texto t, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabra);
// Inserta una copia de palabra en la linea y posicion indicadas. Si la linea
// se pasa del maximo, la ultima palabra baja a la linea siguiente (en cascada,
// creando una linea al final si hace falta).
// Pre: la linea existe y se cumple
// 1 <= posicionPalabra <= cantidad de palabras de la linea + 1.

void BorrarPalabra_texto(texto t, Posicion posicionLinea, Posicion posicionPalabra);
// Borra la palabra en la linea y posicion indicadas.
// Retorna ERROR si la linea o la palabra no existen.

void BorrarOcurrenciasPalabraEnLinea_texto(texto t, Posicion posicionLinea, Cadena palabra);
// Borra todas las ocurrencias de palabra en la linea indicada.
// Retorna ERROR si la linea no existe.

void ImprimirLinea_texto(texto t, Posicion posicionLinea);
// Imprime la linea indicada con su numero.
// Retorna ERROR si la linea no existe.

void DestruirTexto(texto t);
// Libera todas las lineas y la estructura texto.


#endif

