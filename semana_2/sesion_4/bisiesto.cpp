#include <iostream>
using namespace std;

int main() {
    int anio;

    // Entrada con mensaje claro
    cout << "Ingresa un año para verificar: ";
    cin >> anio;

    // Validación de año positivo
    if (anio <= 0) {
        cout << "⚠️ Error: Ingresa un valor de año válido (mayor a 0)" << endl;
        return 1; // Termina el programa si el dato es incorrecto
    }

    // Regla oficial de año bisiesto:
    // Divisible entre 4, pero no entre 100, a menos que también sea entre 400
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        cout << "✅ El año " << anio << " ES BISIESTO" << endl;
    } else {
        cout << "❌ El año " << anio << " NO es bisiesto" << endl;
    }

    return 0;
}