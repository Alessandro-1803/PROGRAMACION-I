#include <iostream>
using namespace std;

int main() {
    // Arreglo con los valores iniciales
    int datos[10] = {5,8,12,3,9,15,20,7,1,10};
    int* puntero = datos; // Apunta al primer elemento

    // Recorrido de PRIMERO a ÚLTIMO (avanzando el puntero)
    cout << "===== Recorrido: PRIMERO → ÚLTIMO =====" << endl;
    for (int i = 0; i < 10; i++) {
        cout << *puntero << "  ";
        puntero++; // Avanza a la siguiente posición
    }

    // Ubicamos el puntero al final del arreglo
    puntero = &datos[9];

    // Recorrido de ÚLTIMO a PRIMERO (retrocediendo el puntero)
    cout << "\n\n===== Recorrido: ÚLTIMO → PRIMERO =====" << endl;
    for (int i = 0; i < 10; i++) {
        cout << *puntero << "  ";
        puntero--; // Retrocede a la posición anterior
    }

    cout << endl;
    return 0;
}