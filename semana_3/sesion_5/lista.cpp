#include <iostream>
#include <algorithm> // Biblioteca para ordenar
#include <iomanip>   // Para mostrar decimales ordenados
using namespace std;

int main() {
    float valores[4];
    float total = 0;
    float promedio;

    // Solicitar los 4 números
    cout << "Escribe 4 valores numéricos:\n";
    for (int indice = 0; indice < 4; indice++) {
        cout << "Valor " << indice + 1 << ": ";
        cin >> valores[indice];
        total += valores[indice]; // Acumular la suma
    }

    // Ordenar de menor a mayor
    sort(valores, valores + 4);

    // Calcular promedio con formato de 2 decimales
    promedio = total / 4;
    cout << fixed << setprecision(2);

    // Mostrar resultados
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "🔹 Valor más pequeño: " << valores[0] << endl;
    cout << "🔹 Valor más grande: " << valores[3] << endl;
    cout << "🔹 Suma total: " << total << endl;
    cout << "🔹 Promedio: " << promedio << endl;

    cout << "\n📋 Valores ordenados de menor a mayor: ";
    for (int indice = 0; indice < 4; indice++) {
        cout << valores[indice] << "  ";
    }

    return 0;
}