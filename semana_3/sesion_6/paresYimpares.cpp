#include <iostream>
using namespace std;

int main() {
    int inicio, fin;
    int sumaPares = 0, sumaImpares = 0;
    int cantidadPares = 0, cantidadImpares = 0;

    cout << "========================================" << endl;
    cout << "   SUMA Y ANÁLISIS DE PARES E IMPARES   " << endl;
    cout << "========================================\n" << endl;

    // El usuario define el rango
    cout << "Escribe el número de inicio del rango: ";
    cin >> inicio;
    cout << "Escribe el número final del rango: ";
    cin >> fin;

    // Validación del rango
    if (inicio > fin) {
        cout << "\n⚠️ Error: El número de inicio no puede ser mayor al final." << endl;
        return 1;
    }

    // Recorrido y clasificación
    for (int num = inicio; num <= fin; num++) {
        if (num % 2 == 0) {
            sumaPares += num;
            cantidadPares++;
        } else {
            sumaImpares += num;
            cantidadImpares++;
        }
    }

    // Cálculo de promedios
    float promedioPares = (cantidadPares > 0) ? (float)sumaPares / cantidadPares : 0;
    float promedioImpares = (cantidadImpares > 0) ? (float)sumaImpares / cantidadImpares : 0;

    // Resultados completos
    cout << "\n--- RESULTADOS DEL RANGO [" << inicio << " → " << fin << "] ---" << endl;
    cout << "📌 Números pares: " << cantidadPares << "  |  Suma: " << sumaPares << "  |  Promedio: " << promedioPares << endl;
    cout << "📌 Números impares: " << cantidadImpares << "  |  Suma: " << sumaImpares << "  |  Promedio: " << promedioImpares << endl;

    return 0;
}