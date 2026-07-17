#include <iostream>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // Definimos cada evento: (nombre, fecha, hora)
    tuple<string, string, string> examen1 = {
        "Parcial 3 de Física",
        "Martes 20 de junio",
        "16:00 horas"
    };

    tuple<string, string, string> examen2 = {
        "Parcial 4 de Álgebra Lineal",
        "Jueves 22 de junio",
        "10:00 a.m."
    };

    // Encabezado ordenado
    cout << "\n========================================" << endl;
    cout << "         AGENDA DE EVENTOS              " << endl;
    cout << "========================================\n" << endl;

    // Mostrar primer evento
    cout << "📌 Evento 1" << endl;
    cout << "   Asignatura: " << get<0>(examen1) << endl;
    cout << "   Fecha:      " << get<1>(examen1) << endl;
    cout << "   Hora:       " << get<2>(examen1) << "\n" << endl;

    // Mostrar segundo evento
    cout << "📌 Evento 2" << endl;
    cout << "   Asignatura: " << get<0>(examen2) << endl;
    cout << "   Fecha:      " << get<1>(examen2) << endl;
    cout << "   Hora:       " << get<2>(examen2) << endl;

    return 0;
}