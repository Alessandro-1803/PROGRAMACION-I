#include <iostream>
using namespace std;

// Función recursiva para encontrar y mostrar los divisores
void listarDivisores(int numeroObjetivo, int candidato) {
    // Condición de salida: si superamos el número objetivo, terminamos
    if (candidato > numeroObjetivo) {
        return;
    }

    // Si el resto es cero, el candidato es un divisor
    if (numeroObjetivo % candidato == 0) {
        cout << "• " << candidato << endl;
    }

    // Llamada recursiva: probamos el siguiente número
    listarDivisores(numeroObjetivo, candidato + 1);
}

int main() {
    int valor;

    cout << "===== BUSCADOR DE DIVISORES =====" << endl;
    cout << "Escribe un número entero positivo: ";
    cin >> valor;

    // Validación de entrada
    if (valor <= 0) {
        cout << "⚠️ Error: Debes ingresar un número mayor a cero." << endl;
        return 1;
    }

    cout << "\n✅ Los divisores de " << valor << " son:" << endl;
    // Iniciamos la búsqueda desde el número 1
    listarDivisores(valor, 1);

    return 0;
}