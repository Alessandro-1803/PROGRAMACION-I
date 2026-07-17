#include <iostream>
using namespace std;

// Función recursiva: analiza cada dígito desde el último al primero
void revisarDigitos(int numero) {
    // Caso base: ya no hay más dígitos
    if (numero == 0) {
        return;
    }

    // Primero llamamos recursivamente con el número sin el último dígito
    revisarDigitos(numero / 10);

    // Extraemos el dígito actual
    int digito = numero % 10;

    // Verificamos y mostramos el resultado
    if (digito % 2 == 0) {
        cout << "🔹 Dígito " << digito << " → PAR" << endl;
    } else {
        cout << "🔹 Dígito " << digito << " → IMPAR" << endl;
    }
}

int main() {
    int valor;

    cout << "===== ANÁLISIS DE DÍGITOS =====" << endl;
    cout << "Escribe un número entero: ";
    cin >> valor;

    // Validación básica
    if (valor < 0) {
        cout << "⚠️ Se usará el valor absoluto para el análisis" << endl;
        valor = -valor;
    }

    cout << "\n✅ Resultado por dígito:" << endl;
    revisarDigitos(valor);

    return 0;
}