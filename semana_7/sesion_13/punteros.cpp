#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int listaNumeros[10];
    int* puntero = listaNumeros; // Apunta al primer elemento
    int totalSuma = 0;
    int valorMayor, valorMenor;

    cout << "===== ANÁLISIS DE 10 NÚMEROS (usando punteros) =====" << endl;
    cout << "Ingresa 10 valores enteros:\n" << endl;

    // Leer los 10 números usando puntero
    for (int indice = 0; indice < 10; indice++) {
        cout << "Número " << indice + 1 << ": ";
        cin >> *(puntero + indice);
    }

    // Inicializar mayor y menor con el primer elemento
    valorMayor = valorMenor = *puntero;

    // Recorrer para calcular suma, mayor y menor
    for (int indice = 0; indice < 10; indice++) {
        int numeroActual = *(puntero + indice);
        totalSuma += numeroActual;

        if (numeroActual > valorMayor) {
            valorMayor = numeroActual;
        }
        if (numeroActual < valorMenor) {
            valorMenor = numeroActual;
        }
    }

    // Calcular promedio
    float promedio = static_cast<float>(totalSuma) / 10;

    // Mostrar resultados
    cout << "\n==================== RESULTADOS ====================" << endl;
    cout << fixed << setprecision(2);
    cout << "🔢 Suma total:     " << totalSuma << endl;
    cout << "📈 Valor mayor:    " << valorMayor << endl;
    cout << "📉 Valor menor:    " << valorMenor << endl;
    cout << "📊 Promedio:       " << promedio << endl;

    return 0;
}