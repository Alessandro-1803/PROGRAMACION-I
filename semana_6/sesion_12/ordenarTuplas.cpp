#include <iostream>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Definimos el arreglo: (nombre, edad, promedio)
    tuple<string, int, float> alumnos[] = {
        {"Juan", 20, 15.5f},
        {"María", 19, 18.2f},
        {"Pedro", 21, 14.8f},
        {"Yago", 20, 19.5f}
    };
    int total = 4;

    // Ordenar por promedio de MAYOR a MENOR
    sort(alumnos, alumnos + total,
         [](const tuple<string, int, float>& a, const tuple<string, int, float>& b) {
             return get<2>(a) > get<2>(b);
         });

    // Encabezado ordenado
    cout << "========================================================" << endl;
    cout << "           LISTA DE ESTUDIANTES (POR PROMEDIO)          " << endl;
    cout << "========================================================" << endl;
    cout << fixed << setprecision(1);

    // Mostrar cada registro
    for (int i = 0; i < total; i++) {
        cout << "🔹 Nombre:    " << get<0>(alumnos[i]) << endl;
        cout << "   Edad:      " << get<1>(alumnos[i]) << " años" << endl;
        cout << "   Promedio:  " << get<2>(alumnos[i]) << "\n" << endl;
    }

    return 0;
}