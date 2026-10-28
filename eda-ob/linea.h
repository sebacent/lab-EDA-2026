#ifndef LINEA_H
#define LINEA_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica 
//
// linea.h
// Modulo de especificacion de linea.

#include "definiciones.h"

typedef struct nodo_linea * linea;

linea CrearLinea();
// Post: devuelve una línea vacía.

unsigned int CantidadPalabrasLinea(linea l);
// Pre: l fue creada con CrearLinea
// Post: devuelve la cantidad de palabras de la línea l.

Cadena CopiarPalabra(Cadena p);
// Pre: p no es NULL.
// Post: devuelve una copia nueva de p sin los espacios del principio.
//       Quien la recibe es responsable de liberarla con delete[].

Cadena InsertarPalabraLinea(linea l, Posicion pos, Cadena p);
// Pre: l fue creada con CrearLinea. 1 <= pos <= CantidadPalabrasLinea(l) + 1.
//      p es memoria dinámica que no pertenece a otra estructura.
// Post: p queda en la posición pos de l, y las palabras que estaban desde pos
//       en adelante se corren una posición. Si l queda con más de
//       MAX_CANT_PALABRAS_X_LINEA palabras, se quita la última y se devuelve;
//       si no, devuelve NULL. La línea pasa a ser dueña de p (no la copia).

void BorrarPalabraLinea(linea l, Posicion pos);
// Pre: l fue creada con CrearLinea. 1 <= pos <= CantidadPalabrasLinea(l).
// Post: quita la palabra de la posición pos; las siguientes palabras retroceden.
//       La memoria de la palabra borrada se libera.

void BorrarOcurrenciasLinea(linea l, Cadena p);
// Pre: l fue creada con CrearLinea. p no es NULL.
// Post: quita de l todas las palabras iguales a p, sin diferenciar mayúsculas y
//       minúsculas, y omite los espacios del principio de p. Las restantes
//       quedan en posiciones consecutivas desde 1. Libera la memoria de las ocurrencias.
//       Si p no está en l, no hace nada.

void ImprimirPalabrasLinea(linea l);
// Pre: l fue creada con CrearLinea.
// Post: muestra las palabras de l en orden, cada una precedida por un espacio,
//       sin espacios al final ni salto de línea. No modifica l.

void DestruirLinea(linea & l);
// Pre: l fue creada con CrearLinea.
// Post: libera las palabras y la línea. l queda en null.

#endif
