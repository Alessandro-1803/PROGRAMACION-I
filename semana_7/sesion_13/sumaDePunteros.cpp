#include <iostream>
using namespace std;

int main() {
    // Variables con valores iniciales
    int numero1 = 2;
    int numero2 = 3;

    // Declaración de punteros
    int* ptrA;
    int* ptrB;

    // Asignar direcciones de memoria a los punteros
    ptrA = &numero1;
    ptrB = &numero2;

    // Mostrar los valores originales
    cout << "===== VALORES INICIALES =====" << endl;
    cout << "Número 1: " << numero1 << endl;
    cout << "Número 2: " << numero2 << "\n" << endl;

    // Sumar los valores accediendo a través de los punteros
    int sumaTotal = *ptrA + *ptrB;
    cout << "===== RESULTADO =====" << endl;
    cout << "La suma usando punteros es: " << sumaTotal << endl;

    return 0;
}