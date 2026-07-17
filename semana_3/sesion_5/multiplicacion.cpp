#include <iostream>
#include <iomanip> // Para alinear los resultados visualmente
using namespace std;

int main() {
    int valor;

    // Título y solicitud de dato
    cout << "========================================" << endl;
    cout << "      GENERADOR DE TABLAS DE MULTIPLICAR      " << endl;
    cout << "========================================" << endl;

    // Validación para asegurar que ingrese un número positivo
    do {
        cout << "\nIngresa un número entero positivo: ";
        cin >> valor;

        if (valor <= 0) {
            cout << "⚠️ Error: El número debe ser mayor a cero. Inténtalo nuevamente." << endl;
        }
    } while (valor <= 0);

    // Encabezado de la tabla
    cout << "\n----------------------------------------" << endl;
    cout << "            TABLA DEL " << setw(2) << valor << "           " << endl;
    cout << "----------------------------------------" << endl;

    // Generación de la tabla del 1 al 12 con formato alineado
    for (int contador = 1; contador <= 12; contador++) {
        int resultado = valor * contador;
        cout << setw(2) << valor << "  ×  " << setw(2) << contador << "  =  " << setw(3) << resultado << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << "✅ Tabla generada correctamente" << endl;

    return 0;
}