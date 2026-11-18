// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// linea.c
// Modulo de implementacion de linea.

#include "definiciones.h"
#include "linea.h"
#include <string.h>

struct nodo_linea{
	Cadena palabras[MAX_CANT_PALABRAS_X_LINEA]; // Ocupadas de 0 a cant-1
	int cant; // Cantidad de palabras
	linea sig;
};

linea CrearLinea(){
// Crea la estructura linea
	linea l = new(nodo_linea);
	l->cant = 0;
	l->sig = NULL;
	return l;
}

linea InsertarFinal(linea l){
// Crea una nueva linea al final de l
	linea u = CrearLinea();
	if (l != NULL)
		l->sig = u;
	return u;
}

linea SiguienteLinea(linea l){
// Retorna la linea siguiente a l (NULL si es la ultima)
	return l->sig;
}

void SetSiguienteLinea(linea l, linea sig){
// Hace que la siguiente de l sea sig
	l->sig = sig;
}

int CantidadPalabras(linea l){
// Retorna la cantidad de palabras de l
	return l->cant;
}

Cadena InsertarPalabra_linea(linea l, Posicion pos, Cadena palabra){
// Inserta palabra en la posicion pos de l, corriendo las siguientes un lugar
// Si la linea estaba llena, retorna la palabra que quedo afuera
	Cadena sobra = NULL;
	if (l->cant == MAX_CANT_PALABRAS_X_LINEA){
		if ((int)pos == l->cant + 1)
			return palabra; // queda afuera ella misma

		sobra = l->palabras[l->cant - 1]; // guardamos la ultima palabra
		l->cant--;
	}

	// es para correr las palabras a la derecha y hacer lugar para la nueva
	for (int i = l->cant; i > (int)pos - 1; i--)
		l->palabras[i] = l->palabras[i - 1];

	l->palabras[pos - 1] = palabra;
	l->cant++;

	return sobra;
}

Cadena SacarPrimeraPalabra(linea l){
// Quita la primera palabra de l (sin liberarla) y la retorna
	Cadena primera = l->palabras[0];
	for (int i = 0; i < l->cant - 1; i++)
		l->palabras[i] = l->palabras[i + 1];
	l->cant--;
	return primera;
}

void BorrarPalabra_linea(linea l, Posicion pos){
// Borra (y libera) la palabra en la posicion pos de l
// Pre: l != NULL
	delete[] l->palabras[pos - 1];
	// se corren las demas palabras hacia la izquierda para que no queden huecos
	for (int i = pos - 1; i < l->cant - 1; i++)
		l->palabras[i] = l->palabras[i + 1];

	l->cant--;
}

void BorrarOcurrencias_linea(linea l, Cadena palabra){
// Borra todas las ocurrencias de palabra en l (sin distinguir mayusculas)
// Pre: l != NULL
	int i = 0;
	while (i < l->cant) {
		if (strcasecmp(l->palabras[i], palabra) == 0)
			BorrarPalabra_linea(l, i + 1);
		else
			i++;
	}
}

void ImprimirLinea_linea(linea l, int pos){
// Imprime la linea l con el numero pos adelante
	cout << "\t" << pos << ":";
	for (int i = 0; i < l->cant; i++)
		cout << " " << l->palabras[i];
	cout << endl;
}

void ImprimirLineas(linea p, int pos){
// Imprime las lineas a partir de p, pos es la
// posicion de la linea, debe ponerse en 1 la primera vez
	if (p != NULL) {
		cout << "\t" << pos << ":";
		for (int i = 0; i < p->cant; i++)
			cout << " " << p->palabras[i];
		cout << endl;
		ImprimirLineas(p->sig, pos +1);
	}
}

void DestruirLinea(linea l){
// Libera la linea l y todas sus palabras
	for (int i = 0; i < l->cant; i++)
		delete[] l->palabras[i];
	delete l;
}
