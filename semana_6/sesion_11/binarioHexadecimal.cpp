#include <iostream>
using namespace std;

// Convierte un número entero a su representación BINARIA (recursivo)
void convertirBinario(int valor) {
    if (valor < 2) {
        cout << valor;
        return;
    }
    convertirBinario(valor / 2);
    cout << (valor % 2);
}

// Convierte un número entero a su representación HEXADECIMAL (recursivo)
void convertirHexadecimal(int valor) {
    if (valor < 16) {
        if (valor < 10)
            cout << valor;
        else
            cout << (char)('A' + valor - 10);
        return;
    }
    convertirHexadecimal(valor / 16);
    int resto = valor % 16;
    if (resto < 10)
        cout << resto;
    else
        cout << (char)('A' + resto - 10);
}

int main() {
    int numero;

    cout << "===== CONVERSOR DE SISTEMAS NUMÉRICOS =====" << endl;
    cout << "Escribe un número entero positivo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "⚠️ Solo se admiten valores positivos." << endl;
        return 1;
    }

    cout << "\n🔹 Representación en BINARIO: ";
    convertirBinario(numero);

    cout << "\n🔹 Representación en HEXADECIMAL: ";
    convertirHexadecimal(numero);

    cout << endl;
    return 0;
}