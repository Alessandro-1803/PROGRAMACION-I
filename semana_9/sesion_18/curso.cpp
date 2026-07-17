#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Persona {
public:
    string dni;
    string nombre;
    string apePat;
    string apeMat;

    Persona() {
        dni = "";
        nombre = "";
        apePat = "";
        apeMat = "";
    }
};

class Curso {
private:
    int codigo;
    string nombreCurso;
    int creditos;
    Persona profe;
    Persona lista[5];
    int total = 0;

public:
    void registrarCurso() {
        cout << "Ingrese codigo del curso: ";
        cin >> codigo;
        cin.ignore();
        cout << "Ingrese nombre del curso: ";
        getline(cin, nombreCurso);
        cout << "Ingrese creditos: ";
        cin >> creditos;
        cin.ignore();

        ofstream arc("curso.txt");
        arc << codigo << ";" << nombreCurso << ";" << creditos << endl;
        arc.close();
        cout << "Curso guardado.\n";
    }

    void agregarProfe() {
        cout << "\nDNI del profesor (8 digitos): ";
        getline(cin, profe.dni);
        cout << "Nombre: "; getline(cin, profe.nombre);
        cout << "Apellido paterno: "; getline(cin, profe.apePat);
        cout << "Apellido materno: "; getline(cin, profe.apeMat);

        ofstream arc("profe.txt");
        arc << profe.dni << ";" << profe.nombre << ";" << profe.apePat << ";" << profe.apeMat << endl;
        arc.close();
        cout << "Profesor asignado.\n";
    }

    void agregarAlumno() {
        if (total >= 5) {
            cout << "No hay mas cupos.\n";
            return;
        }
        Persona nuevo;
        cout << "\nDNI del alumno (8 digitos): ";
        getline(cin, nuevo.dni);
        cout << "Nombre: "; getline(cin, nuevo.nombre);
        cout << "Apellido paterno: "; getline(cin, nuevo.apePat);
        cout << "Apellido materno: "; getline(cin, nuevo.apeMat);

        lista[total] = nuevo;
        total++;

        ofstream arc("alumnos.txt", ios::app);
        arc << nuevo.dni << ";" << nuevo.nombre << ";" << nuevo.apePat << ";" << nuevo.apeMat << endl;
        arc.close();
        cout << "Alumno agregado.\n";
    }

    void mostrarTodo() {
        cout << "\n===== DATOS DEL CURSO =====\n";
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombreCurso << endl;
        cout << "Creditos: " << creditos << endl;
        cout << "Profesor: " << profe.nombre << " " << profe.apePat << endl;
        cout << "Alumnos: " << total << "/5\n";
        for (int i = 0; i < total; i++) {
            cout << i+1 << ". " << lista[i].dni << " - " << lista[i].nombre << " " << lista[i].apePat << endl;
        }
    }
};

int main() {
    Curso c;
    int op;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Registrar curso\n";
        cout << "2. Asignar profesor\n";
        cout << "3. Agregar alumno\n";
        cout << "4. Ver datos completos\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if (op == 1) c.registrarCurso();
        else if (op == 2) c.agregarProfe();
        else if (op == 3) c.agregarAlumno();
        else if (op == 4) c.mostrarTodo();
        else if (op == 5) cout << "Saliendo...\n";
        else cout << "Opcion invalida.\n";
    } while (op != 5);

    return 0;
}