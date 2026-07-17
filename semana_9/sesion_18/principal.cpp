#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// CLASE PERSONA DENTRO DEL MISMO ARCHIVO
class Persona {
public:
    string dni;
    string nombre;
    string paterno;
    string materno;
};

// CLASE CURSO
class Curso {
private:
    int codigo;
    string nombreCurso;
    int creditos;
    Persona profe;
    Persona lista[5];
    int cantidad;

public:
    Curso() {
        codigo = 0;
        creditos = 0;
        cantidad = 0;
    }

    void registrarCurso() {
        cout << "Ingrese codigo del curso: ";
        cin >> codigo;
        cin.ignore();
        cout << "Ingrese nombre del curso: ";
        getline(cin, nombreCurso);
        cout << "Ingrese creditos: ";
        cin >> creditos;
        cin.ignore();
        cout << "Curso guardado.\n";
    }

    void agregarProfe() {
        cout << "\nDNI profesor: ";
        getline(cin, profe.dni);
        cout << "Nombre: ";
        getline(cin, profe.nombre);
        cout << "Apellido paterno: ";
        getline(cin, profe.paterno);
        cout << "Apellido materno: ";
        getline(cin, profe.materno);
        cout << "Profesor guardado.\n";
    }

    void agregarAlumno() {
        if (cantidad >= 5) {
            cout << "No hay cupos.\n";
            return;
        }
        cout << "\nDNI alumno: ";
        getline(cin, lista[cantidad].dni);
        cout << "Nombre: ";
        getline(cin, lista[cantidad].nombre);
        cout << "Apellido paterno: ";
        getline(cin, lista[cantidad].paterno);
        cout << "Apellido materno: ";
        getline(cin, lista[cantidad].materno);
        cantidad++;
        cout << "Alumno agregado. Total: " << cantidad << "\n";
    }

    void mostrarLista() {
        cout << "\n=== LISTA DE ALUMNOS ===\n";
        if (cantidad == 0) {
            cout << "Sin alumnos.\n";
            return;
        }
        for (int i = 0; i < cantidad; i++) {
            cout << i+1 << ". " << lista[i].dni << " - " << lista[i].nombre << " " << lista[i].paterno << "\n";
        }
    }

    void guardarArchivo() {
        ofstream arc("alumnos.txt");
        for (int i = 0; i < cantidad; i++) {
            arc << lista[i].dni << ";" << lista[i].nombre << ";" << lista[i].paterno << ";" << lista[i].materno << "\n";
        }
        arc.close();
        cout << "Guardado en archivo.\n";
    }

    void mostrarResumen() {
        cout << "\n=== RESUMEN ===\n";
        cout << "Codigo: " << codigo << "\n";
        cout << "Curso: " << nombreCurso << "\n";
        cout << "Creditos: " << creditos << "\n";
        cout << "Profesor: " << profe.nombre << " " << profe.paterno << "\n";
        cout << "Total alumnos: " << cantidad << "/5\n";
    }
};

// PROGRAMA PRINCIPAL
int main() {
    Curso miCurso;
    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar curso\n";
        cout << "2. Agregar profesor\n";
        cout << "3. Agregar alumno\n";
        cout << "4. Ver lista alumnos\n";
        cout << "5. Guardar en archivo\n";
        cout << "6. Ver resumen\n";
        cout << "7. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) miCurso.registrarCurso();
        else if (opcion == 2) miCurso.agregarProfe();
        else if (opcion == 3) miCurso.agregarAlumno();
        else if (opcion == 4) miCurso.mostrarLista();
        else if (opcion == 5) miCurso.guardarArchivo();
        else if (opcion == 6) miCurso.mostrarResumen();
        else if (opcion == 7) cout << "Saliendo...\n";
        else cout << "Opcion invalida.\n";

    } while (opcion != 7);

    return 0;
}