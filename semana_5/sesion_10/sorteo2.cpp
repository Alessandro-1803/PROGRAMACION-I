#include <iostream>
#include <algorithm> // Para ordenar
#include <iomanip>   // Para formato de decimales
using namespace std;

// Calcula el promedio de las calificaciones
float obtenerPromedio(float calificaciones[], int cantidad) {
    float sumaTotal = 0;
    for (int i = 0; i < cantidad; i++) {
        sumaTotal += calificaciones[i];
    }
    return sumaTotal / cantidad;
}

// Encuentra la calificación más alta
float obtenerMaxima(float calificaciones[], int cantidad) {
    float mayor = calificaciones[0];
    for (int i = 1; i < cantidad; i++) {
        if (calificaciones[i] > mayor) {
            mayor = calificaciones[i];
        }
    }
    return mayor;
}

// Muestra las calificaciones en ambos sentidos
void presentarResultados(float calificaciones[], int cantidad) {
    cout << "\n--- Calificaciones de menor a mayor ---" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "• " << calificaciones[i] << endl;
    }

    cout << "\n--- Calificaciones de mayor a menor ---" << endl;
    for (int i = cantidad - 1; i >= 0; i--) {
        cout << "• " << calificaciones[i] << endl;
    }
}

int main() {
    float notas[3];
    int totalNotas = 3;

    cout << "===== REGISTRO DE CALIFICACIONES =====" << endl;
    cout << "Rango válido: 0 a 20 puntos\n" << endl;

    // Ingreso validado de cada nota
    for (int indice = 0; indice < totalNotas; indice++) {
        do {
            cout << "Escribe la nota " << indice + 1 << ": ";
            cin >> notas[indice];

            if (notas[indice] < 0 || notas[indice] > 20) {
                cout << "⚠️ Valor inválido. Intenta nuevamente.\n";
            }
        } while (notas[indice] < 0 || notas[indice] > 20);
    }

    // Ordenar el arreglo
    sort(notas, notas + totalNotas);

    // Mostrar listas ordenadas
    presentarResultados(notas, totalNotas);

    // Mostrar estadísticas finales
    cout << "\n--- ESTADÍSTICAS ---" << endl;
    cout << fixed << setprecision(2);
    cout << "📊 Promedio obtenido: " << obtenerPromedio(notas, totalNotas) << endl;
    cout << "🔝 Nota más alta: " << obtenerMaxima(notas, totalNotas) << endl;

    return 0;
} 