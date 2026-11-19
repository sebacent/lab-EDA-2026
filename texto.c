// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// texto.c
// Modulo de implmentacion de texto.

#include "definiciones.h"
#include "texto.h"
#include "linea.h"
#include <string.h>

static linea BuscarLinea(texto t, Posicion pos);
static Cadena CopiarCadena(Cadena c);


struct nodo_texto {
    linea p; // Primer Linea
    linea u; // Ultima Linea
    int cant; // Cantidad de lineas
};

texto CrearTexto() {
    // Crea la estructura texto
    texto t = new(nodo_texto);
    t->p = NULL;
    t->u = NULL;
    t->cant = 0;
    return t;
}

int CantidadLineas(texto t) {
    // Retorna la cantidad de lineas del texto
    return t->cant;
}

int CantidadPalabrasLinea(texto t, Posicion posicionLinea) {
    // Pre: la linea indicada existe

    linea l = t->p;
    for (Posicion i = 1; i < posicionLinea; i++)
        l = SiguienteLinea(l);

    return CantidadPalabras(l);
}

void ImprimirTexto_Texto(texto t) {
    // Imprime el texto
    if (t->p == NULL)
        cout << "\tTexto vacio\n";
    else {
        ImprimirLineas(t->p, 1);
    }
}

void InsertarLinea_texto(texto t) {
    // Inserta una nueva linea al final del texto
    t->u = InsertarFinal(t->u);
    if (t->p == NULL)
        t->p = t->u;
    t->cant++;
}

void InsertarLineaEnPosicion_texto(texto t, Posicion posicionLinea) {
    // Inserta una linea vacia en la posicion indicada
    linea nueva = CrearLinea();
    if (posicionLinea == 1) { // Si es la primera linea, la nueva linea pasa a ser la primera
        SetSiguienteLinea(nueva, t->p);
        t->p = nueva;
    } else { // Si no es la primera linea, busco la linea anterior a la posicion indicada y hago que apunte a la nueva linea
        linea ant = t->p;
        for (Posicion i = 1; i < posicionLinea - 1; i++)
            ant = SiguienteLinea(ant);

        SetSiguienteLinea(nueva, SiguienteLinea(ant));
        SetSiguienteLinea(ant, nueva);
    }

    t->cant++;
}

void BorrarLinea_texto(texto t, Posicion posicionLinea) {
    // Borra la linea en la posicion indicada
    linea borrar;
    if (posicionLinea == 1) { // Si es la primera linea, la nueva primera linea pasa a ser la siguiente de la que se borra
        borrar = t->p;
        t->p = SiguienteLinea(borrar);
        if (t->p == NULL)
            t->u = NULL;
    } else { // Si no es la primera linea, busco la linea anterior a la posicion indicada y hago que apunte a la siguiente de la que se borra
        linea ant = t->p;
        for (Posicion i = 1; i < posicionLinea - 1; i++)
            ant = SiguienteLinea(ant);

        borrar = SiguienteLinea(ant);
        SetSiguienteLinea(ant, SiguienteLinea(borrar));
        if (borrar == t->u)
            t->u = ant;
    }

    DestruirLinea(borrar);
    t->cant--;
}

void BorrarTodo_texto(texto t) {
    // Borra todas las lineas del texto
    if (t->p == NULL)
        return;

    while (t->p != NULL) {
        linea borrar = t->p;
        t->p = SiguienteLinea(borrar);
        DestruirLinea(borrar);
    }

    t->u = NULL;
    t->cant = 0;
}

void BorrarOcurrenciasPalabraEnTexto_texto(texto t, Cadena palabra) {
    // Borra todas las ocurrencias de palabra en todas las lineas
    for (linea l = t->p; l != NULL; l = SiguienteLinea(l))
        BorrarOcurrencias_linea(l, palabra);
}

void InsertarPalabra_texto(texto t, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabra) {
    // Inserta una palabra en una línea.
    // Pre: la linea existe y la posicion de la palabra es valida
    linea l = t->p;
    for (Posicion i = 1; i < posicionLinea; i++)
        l = SiguienteLinea(l);

    Cadena copia = new char [strlen(palabra) + 1];
    strcpy(copia, palabra);

    Cadena sobra = InsertarPalabra_linea(l, posicionPalabra, copia);
    // Si sobro una palabra, va al principio de la linea siguiente (y asi en cascada)
    while (sobra != NULL) {
        if (SiguienteLinea(l) == NULL)
            InsertarLinea_texto(t);
        l = SiguienteLinea(l);
        sobra = InsertarPalabra_linea(l, 1, sobra);
    }
}

void BorrarPalabra_texto(texto t, Posicion posicionLinea, Posicion posicionPalabra) {
    // Borra la palabra en la posición indicada
    linea l = t->p;
    for (Posicion i = 1; i < posicionLinea; i++)
        l = SiguienteLinea(l);

    BorrarPalabra_linea(l, posicionPalabra);
}

void BorrarOcurrenciasPalabraEnLinea_texto(texto t, Posicion posicionLinea, Cadena palabra) {
    // Borra todas las ocurrencias de palabra en la linea indicada
    linea l = t->p;
    for (Posicion i = 1; i < posicionLinea; i++)
        l = SiguienteLinea(l);

    BorrarOcurrencias_linea(l, palabra);
}

void ImprimirLinea_texto(texto t, Posicion posicionLinea) {
    // Imprime la linea indicada con su numero
    // Pre: la linea indicada existe
    linea l = t->p;
    for (Posicion i = 1; i < posicionLinea; i++)
        l = SiguienteLinea(l);

    ImprimirLinea_linea(l, posicionLinea);
}

void ImprimirTextoIncorrecto_texto(texto t, diccionario d) {
    // Imprime las lineas con solo las palabras que no estan en d
    if (t->p == NULL) {
        cout << "\tTexto vacio\n";
        return;
    }
    int pos = 1;
    for (linea l = t->p; l != NULL; l = SiguienteLinea(l)) {
        ImprimirLineaIncorrecta_linea(l, pos, d);
        pos++;
    }
}

void DestruirTexto(texto t) {
    // Libera todas las lineas y la estructura texto.
    BorrarTodo_texto(t);
    delete t;
}

