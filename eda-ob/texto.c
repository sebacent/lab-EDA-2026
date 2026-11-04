// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// texto.c
// Modulo de implmentacion de texto.

#include "definiciones.h"
#include "texto.h"
#include "linea.h"


struct nodo_texto{
	linea p; // Primer Linea
	linea u; // Ultima Linea
};

texto CrearTexto(){
// Crea la estructura texto.
	texto t = new(nodo_texto);
	t->p = NULL;
	t->u = NULL;
	return t;
}

void ImprimirTexto_Texto(texto t){
// Imprime el texto.
	if (t->p == NULL)
		cout << "\tTexto vacío\n";
	else{
		// TODO S6 ImprimirLineas(t->p, 1);
	}

}

texto InsertarLinea_texto(texto t){
// Inserta una nueva linea al final del texto.
	// TODO S6  t->u = InsertarFinal(t->u);
	if (t->p == NULL)
		t->p = t->u;
	return t;
}




