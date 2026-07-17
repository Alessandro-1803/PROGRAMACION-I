#include <iostream>
#include <iomanip>
using namespace std;

// Función para calcular el promedio
float calcularPromedio(float datos[], int cantidad) {
    float sumaTotal = 0;
    for (int i = 0; i < cantidad; i++) {
        sumaTotal += datos[i];
    }
    return sumaTotal / cantidad;
}

// Función para hallar el valor máximo
float hallarMayor(float datos[], int cantidad) {
    float valorMaximo = datos[0];
    for (int i = 1; i < cantidad; i++) {
        if (datos[i] > valorMaximo) {
            valorMaximo = datos[i];
        }
    }
    return valorMaximo;
}

// Función nueva: hallar el valor mínimo
float hallarMenor(float datos[], int cantidad) {
    float valorMinimo = datos[0];
    for (int i = 1; i < cantidad; i++) {
        if (datos[i] < valorMinimo) {
            valorMinimo = datos[i];
        }
    }
    return valorMinimo;
}

int main() {
    float calificaciones[3] = {16.3, 12.5, 11.8};
    int totalNotas = 3;

    cout << "=== ANÁLISIS DE CALIFICACIONES ===" << endl;
    cout << "Notas registradas: ";
    for (int i = 0; i < totalNotas; i++) {
        cout << calificaciones[i] << "  ";
    }
    cout << "\n" << endl;

    cout << fixed << setprecision(2);
    cout << "📊 Promedio general: " << calcularPromedio(calificaciones, totalNotas) << endl;
    cout << "🔝 Nota más alta: " << hallarMayor(calificaciones, totalNotas) << endl;
    cout << "🔻 Nota más baja: " << hallarMenor(calificaciones, totalNotas) << endl;

    return 0;
}