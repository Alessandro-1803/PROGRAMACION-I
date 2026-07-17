#include <iostream>
using namespace std;

int main() {
    int valor;
    long long factorial = 1; // Usamos long long para evitar desbordamiento

    cout << "Escribe un número entero positivo para calcular su factorial: ";
    cin >> valor;

    // Validación de entrada
    if (valor < 0) {
        cout << "❌ No se puede calcular el factorial de un número negativo." << endl;
        return 1;
    }

    cout << "\nProceso: " << valor << "! = ";

    // Cálculo del factorial con bucle
    for (int cont = 1; cont <= valor; cont++) {
        cout << cont;
        if (cont < valor) cout << " × ";
        factorial *= cont;
    }

    cout << "\n✅ El resultado es: " << factorial << endl;

    return 0;
}