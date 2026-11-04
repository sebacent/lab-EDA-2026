#include "linea.h"
#include <iostream>
using namespace std;

int main(){
    linea l = CrearLinea();
    cout << "cantidad: " << CantidadPalabrasLinea(l) << endl;   // esperado: 0
}