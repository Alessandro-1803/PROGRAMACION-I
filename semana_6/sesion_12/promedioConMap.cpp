#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // Estructura: clave = nombre del alumno, valor = diccionario {materia: nota}
    map<string, map<string, float>> registroAcademico;

    // Cargar notas de Juan
    registroAcademico["Juan"]["Matemáticas"] = 18;
    registroAcademico["Juan"]["Física"] = 15;
    registroAcademico["Juan"]["Programación"] = 20;

    // Cargar notas de María
    registroAcademico["María"]["Matemáticas"] = 16;
    registroAcademico["María"]["Física"] = 17;
    registroAcademico["María"]["Programación"] = 18;

    // Cargar notas de Pedro
    registroAcademico["Pedro"]["Matemáticas"] = 14;
    registroAcademico["Pedro"]["Física"] = 19;
    registroAcademico["Pedro"]["Programación"] = 15;

    // Formato de decimales
    cout << fixed << setprecision(1);
    cout << "========================================================" << endl;
    cout << "      REPORTE DE NOTAS Y PROMEDIOS POR ALUMNO            " << endl;
    cout << "========================================================\n" << endl;

    // Recorrer cada alumno
    for (const auto& alumno : registroAcademico) {
        float sumaTotal = 0;
        int cantidadMaterias = 0;

        cout << "📌 Alumno: " << alumno.first << endl;
        cout << "   ------------------------------" << endl;

        // Recorrer sus materias y notas
        for (const auto& nota : alumno.second) {
            cout << "   " << nota.first << ": " << nota.second << endl;
            sumaTotal += nota.second;
            cantidadMaterias++;
        }

        // Calcular y mostrar promedio
        float promedio = sumaTotal / cantidadMaterias;
        cout << "\n   📊 Promedio general: " << promedio << "\n" << endl;
    }

    return 0;
}