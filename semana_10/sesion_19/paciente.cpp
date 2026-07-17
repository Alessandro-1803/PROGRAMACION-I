#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// CLASE PERSONA (corrige tu estructura)
class Persona {
private:
    string dni;
    string nombres;
    string apellidoPaterno;
    string apellidoMaterno;

public:
    // Constructor vacío
    Persona() {
        dni = "";
        nombres = "";
        apellidoPaterno = "";
        apellidoMaterno = "";
    }

    // Constructor parametrizado
    Persona(string _dni, string _nombres, string _paterno, string _materno) {
        dni = _dni;
        nombres = _nombres;
        apellidoPaterno = _paterno;
        apellidoMaterno = _materno;
    }

    // Getters
    string getDni() { return dni; }
    string getNombres() { return nombres; }
    string getApellidoPaterno() { return apellidoPaterno; }
    string getApellidoMaterno() { return apellidoMaterno; }

    // Setters
    void setDni(string _dni) { dni = _dni; }
    void setNombres(string _nombres) { nombres = _nombres; }
    void setApellidoPaterno(string _paterno) { apellidoPaterno = _paterno; }
    void setApellidoMaterno(string _materno) { apellidoMaterno = _materno; }

    // Mostrar datos
    void mostrar() {
        cout << "DNI: " << dni << " | " << nombres << " " << apellidoPaterno << " " << apellidoMaterno << "\n";
    }
};

// CLASE CURSO
class Curso {
private:
    int codigo;
    string nombreCurso;
    int creditos;
    Persona docente;
    Persona alumnos[5];
    int totalAlumnos;

public:
    // Constructor vacío
    Curso() {
        codigo = 0;
        creditos = 0;
        totalAlumnos = 0;
    }

    // Métodos para guardar en archivos
    void guardarCursoArchivo() {
        ofstream arc("curso.txt");
        arc << codigo << ";" << nombreCurso << ";" << creditos << "\n";
        arc.close();
    }

    void guardarDocenteArchivo() {
        ofstream arc("docente.txt");
        arc << docente.getDni() << ";" << docente.getNombres() << ";"
            << docente.getApellidoPaterno() << ";" << docente.getApellidoMaterno() << "\n";
        arc.close();
    }

    void guardarAlumnoArchivo(Persona p) {
        ofstream arc("alumnos.txt", ios::app);
        arc << p.getDni() << ";" << p.getNombres() << ";"
            << p.getApellidoPaterno() << ";" << p.getApellidoMaterno() << "\n";
        arc.close();
    }

    // Registrar curso
    void registrarCurso() {
        cout << "\n=== REGISTRAR CURSO ===\n";
        cout << "Código: "; cin >> codigo; cin.ignore();
        cout << "Nombre: "; getline(cin, nombreCurso);
        do {
            cout << "Créditos: "; cin >> creditos; cin.ignore();
        } while (creditos <= 0);
        guardarCursoArchivo();
        cout << "✅ Curso registrado.\n";
    }

    // Asignar docente
    void asignarDocente() {
        string d, n, p, m;
        cout << "\n=== ASIGNAR DOCENTE ===\n";
        do { cout << "DNI (8 dígitos): "; getline(cin, d); } while (d.size() != 8);
        cout << "Nombres: "; getline(cin, n);
        cout << "Apellido paterno: "; getline(cin, p);
        cout << "Apellido materno: "; getline(cin, m);
        docente = Persona(d, n, p, m);
        guardarDocenteArchivo();
        cout << "✅ Docente asignado.\n";
    }

    // Agregar alumno
    void agregarAlumno() {
        if (totalAlumnos >= 5) { cout << "❌ Sin cupos.\n"; return; }
        string d, n, p, m;
        cout << "\n=== AGREGAR ALUMNO ===\n";
        do { cout << "DNI (8 dígitos): "; getline(cin, d); } while (d.size() != 8);
        cout << "Nombres: "; getline(cin, n);
        cout << "Apellido paterno: "; getline(cin, p);
        cout << "Apellido materno: "; getline(cin, m);
        alumnos[totalAlumnos] = Persona(d, n, p, m);
        guardarAlumnoArchivo(alumnos[totalAlumnos]);
        totalAlumnos++;
        cout << "✅ Alumno agregado.\n";
    }

    // Listar alumnos
    void listarAlumnos() {
        cout << "\n=== LISTA DE ALUMNOS ===\n";
        if (totalAlumnos == 0) { cout << "Sin alumnos.\n"; return; }
        for (int i = 0; i < totalAlumnos; i++) {
            cout << i+1 << ". "; alumnos[i].mostrar();
        }
    }

    // Leer archivo
    void leerArchivo() {
        cout << "\n=== ARCHIVO DE ALUMNOS ===\n";
        ifstream arc("alumnos.txt");
        if (!arc) { cout << "Archivo no encontrado.\n"; return; }
        string linea;
        while (getline(arc, linea)) cout << linea << "\n";
        arc.close();
    }

    // Eliminar alumno
    void eliminarAlumno() {
        string dni;
        cout << "\n=== ELIMINAR ALUMNO ===\n";
        cout << "DNI: "; getline(cin, dni);
        ifstream orig("alumnos.txt");
        ofstream temp("temp.txt");
        string d, n, p, m;
        while (getline(orig, d, ';') && getline(orig, n, ';') && getline(orig, p, ';') && getline(orig, m)) {
            if (d != dni) temp << d << ";" << n << ";" << p << ";" << m << "\n";
        }
        orig.close(); temp.close();
        remove("alumnos.txt"); rename("temp.txt", "alumnos.txt");
        cout << "✅ Alumno eliminado.\n";
    }

    // Actualizar alumno
    void actualizarAlumno() {
        string dni;
        cout << "\n=== ACTUALIZAR ALUMNO ===\n";
        cout << "DNI: "; getline(cin, dni);
        ifstream orig("alumnos.txt");
        ofstream temp("temp.txt");
        string d, n, p, m;
        while (getline(orig, d, ';') && getline(orig, n, ';') && getline(orig, p, ';') && getline(orig, m)) {
            if (d == dni) {
                cout << "Nuevo nombre: "; getline(cin, n);
                cout << "Nuevo apellido paterno: "; getline(cin, p);
                cout << "Nuevo apellido materno: "; getline(cin, m);
            }
            temp << d << ";" << n << ";" << p << ";" << m << "\n";
        }
        orig.close(); temp.close();
        remove("alumnos.txt"); rename("temp.txt", "alumnos.txt");
        cout << "✅ Datos actualizados.\n";
    }

    // Resumen
    void mostrarResumen() {
        cout << "\n=== RESUMEN ===\n";
        cout << "Curso: " << nombreCurso << "\n";
        cout << "Créditos: " << creditos << "\n";
        cout << "Docente: "; docente.mostrar();
        cout << "Total alumnos: " << totalAlumnos << "/5\n";
    }
};

// MENÚ PRINCIPAL
int main() {
    Curso c;
    int op;
    do {
        cout << "\n===== MENÚ =====\n";
        cout << "1. Registrar curso\n";
        cout << "2. Asignar docente\n";
        cout << "3. Agregar alumno\n";
        cout << "4. Listar alumnos\n";
        cout << "5. Leer archivo\n";
        cout << "6. Eliminar alumno\n";
        cout << "7. Actualizar alumno\n";
        cout << "8. Resumen\n";
        cout << "9. Salir\n";
        cout << "Opción: "; cin >> op; cin.ignore();

        switch(op) {
            case 1: c.registrarCurso(); break;
            case 2: c.asignarDocente(); break;
            case 3: c.agregarAlumno(); break;
            case 4: c.listarAlumnos(); break;
            case 5: c.leerArchivo(); break;
            case 6: c.eliminarAlumno(); break;
            case 7: c.actualizarAlumno(); break;
            case 8: c.mostrarResumen(); break;
            case 9: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (op != 9);
    return 0;
}