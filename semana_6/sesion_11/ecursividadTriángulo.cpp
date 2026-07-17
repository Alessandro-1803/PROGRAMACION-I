#include <iostream>
using namespace std;

// Función recursiva para calcular el factorial
int calcularFactorial(int numero) {
    // Caso base: factorial de 1 es 1
    if (numero == 1) {
        cout << "1";
        return 1;
    }

    // Mostramos la secuencia de multiplicación
    cout << numero << " × ";
    return numero * calcularFactorial(numero - 1);
}

int main() {
    int valor;

    cout << "===== CÁLCULO DE FACTORIAL =====" << endl;
    cout << "Escribe un número entero positivo: ";
    cin >> valor;

    // Validación de entrada
    if (valor <= 0) {
        cout << "❌ Error: Debes ingresar un número mayor a 0." << endl;
        return 1;
    }

    cout << "\nSecuencia: ";
    int resultado = calcularFactorial(valor);
    cout << " = " << resultado << endl;

    return 0;
}