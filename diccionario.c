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

struct nodo_diccionario{
    Cadena palabra;
    diccionario menor;
    diccionario mayor;

};

diccionario CrearDiccionario(){
    // Post: devuelve un diccionario vacio
	return NULL;
}

bool EsVacioDiccionario(diccionario d){
    // Post: devuelve true si d no tiene palabras.
	return d == NULL;
}

bool PerteneceDiccionario(diccionario d, Cadena palabra){
    // Pre: palabra no es NULL.
    // Post: devuelve true si palabra esta en d (sin distinguir mayusculas).
    //       O(log n) promedio.
    if (EsVacioDiccionario(d))
        return false;

    int encontre = strcasecmp(palabra, d->palabra);
    if (encontre == 0)
        return true;
    else if (encontre < 0)
        return PerteneceDiccionario(d->menor, palabra);
    else
        return PerteneceDiccionario(d->mayor, palabra);
}


void InsertarPalabra_diccionario(diccionario & d, Cadena palabra){
    // Pre: palabra no es NULL y no pertenece a d.
    // Post: agrega una copia de palabra a d (d no se queda con palabra).
    //       O(log n) promedio.
    if (EsVacioDiccionario(d)){
        d = new nodo_diccionario;
        d->palabra = new char[strlen(palabra) + 1]; // copia: la de main se pisa
        strcpy(d->palabra, palabra);
        d->mayor = NULL;
        d->menor = NULL;
    }
    else if (strcasecmp(palabra, d->palabra) < 0)
        InsertarPalabra_diccionario(d->menor, palabra);
    else
        InsertarPalabra_diccionario(d->mayor, palabra);
}

static diccionario SacarMinimo(diccionario & d){
    // Pre: d no es vacio.
    // Post: desengancha de d el nodo con la menor palabra y lo devuelve
    //       (no lo libera). En su lugar queda su hijo mayor.
    if (EsVacioDiccionario(d->menor)){
        diccionario min = d;
        d = d->mayor;
        return min;
    }
    return SacarMinimo(d->menor);
}

void BorrarPalabra_diccionario(diccionario & d, Cadena palabra){
    // Pre: palabra no es NULL y pertenece a d.
    // Post: quita palabra de d y libera su memoria.
    int cmp = strcasecmp(palabra, d->palabra);
    if (cmp < 0)
        BorrarPalabra_diccionario(d->menor, palabra);
    else if (cmp > 0)
        BorrarPalabra_diccionario(d->mayor, palabra);
    else {
        diccionario borrar = d;
        if (EsVacioDiccionario(d->menor))      // hoja o solo hijo mayor
            d = d->mayor;
        else if (EsVacioDiccionario(d->mayor)) // solo hijo menor
            d = d->menor;
        else {                                 // dos hijos
            diccionario min = SacarMinimo(d->mayor);
            min->menor = d->menor;
            min->mayor = d->mayor;
            d = min;
        }
        delete[] borrar->palabra;
        delete borrar;
    }
}

void ImprimirPalabras_diccionario(diccionario d){
    // Post: imprime las palabras de d en orden alfabetico (recorrido en orden) y con un tab.
    if (!EsVacioDiccionario(d)){
        ImprimirPalabras_diccionario(d->menor);
        cout << "\t" << d->palabra << endl;
        ImprimirPalabras_diccionario(d->mayor);
    }
}

void DestruirDiccionario(diccionario & d){
    // Post: libera todas las palabras y nodos de d. d queda en NULL.
    if (!EsVacioDiccionario(d)){
        DestruirDiccionario(d->menor);
        DestruirDiccionario(d->mayor);
        delete[] d->palabra;
        delete d;
        d = NULL;
    }
}
