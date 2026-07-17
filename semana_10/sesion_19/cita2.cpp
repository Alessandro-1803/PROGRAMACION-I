#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Clase Persona (corrige los errores de tu imagen)
class Persona {
private:
    string dni;
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;

public:
    // Constructor vacío
    Persona() {
        dni = "";
        nombre = "";
        apellidoPaterno = "";
        apellidoMaterno = "";
    }

    // Constructor parametrizado
    Persona(string _dni, string _nombre, string _paterno, string _materno) {
        dni = _dni;
        nombre = _nombre;
        apellidoPaterno = _paterno;
        apellidoMaterno = _materno;
    }

    // Getters
    string get_dni() { return dni; }
    string get_nombre() { return nombre; }
    string get_paterno() { return apellidoPaterno; }
    string get_materno() { return apellidoMaterno; }

    // Setters
    void set_dni(string _dni) { dni = _dni; }
    void set_nombre(string _nombre) { nombre = _nombre; }
    void set_paterno(string _paterno) { apellidoPaterno = _paterno; }
    void set_materno(string _materno) { apellidoMaterno = _materno; }

    // Método para mostrar datos
    void saludar() {
        cout << "DNI: " << dni << " | " << nombre << " " << apellidoPaterno << " " << apellidoMaterno << "\n";
    }
};

// Clase Curso (corrige la lógica de tu imagen)
class Curso {
private:
    int id;
    string nombre;
    int credito;
    Persona docente;
    Persona estudiantes[5];
    int total_alumnos;

public:
    // Constructor vacío
    Curso() {
        id = 0;
        credito = 0;
        total_alumnos = 0;
    }

    // Constructor parametrizado
    Curso(int _id, string _nombre, int _credito) {
        id = _id;
        nombre = _nombre;
        credito = _credito;
        total_alumnos = 0;
    }

    // Getters y Setters
    int get_id() { return id; }
    void set_id(int _id) { id = _id; }

    string get_nombre() { return nombre; }
    void set_nombre(string _nombre) { nombre = _nombre; }

    int get_credito() { return credito; }
    void set_credito(int _credito) { credito = _credito; }

    // Guardar curso en archivo
    void guardar_curso_txt() {
        ofstream archivo("Curso.txt");
        archivo << id << ";" << nombre << ";" << credito << "\n";
        archivo.close();
        cout << "✅ Curso guardado.\n";
    }

    // Guardar docente en archivo
    void guardar_docente_txt() {
        ofstream archivo("Docente.txt");
        archivo << docente.get_dni() << ";" << docente.get_nombre() << ";"
                << docente.get_paterno() << ";" << docente.get_materno() << "\n";
        archivo.close();
        cout << "✅ Docente guardado.\n";
    }

    // Guardar alumno en archivo
    void guardar_alumno_txt(Persona alumno) {
        ofstream archivo("Alumno.txt", ios::app);
        archivo << alumno.get_dni() << ";" << alumno.get_nombre() << ";"
                << alumno.get_paterno() << ";" << alumno.get_materno() << "\n";
        archivo.close();
    }

    // Registrar curso
    void registrar_curso() {
        cout << "\n=== REGISTRAR CURSO ===\n";
        cout << "Ingrese ID: ";
        cin >> id;
        cin.ignore();
        cout << "Ingrese nombre: ";
        getline(cin, nombre);
        do {
            cout << "Ingrese creditos: ";
            cin >> credito;
            cin.ignore();
        } while (credito <= 0);
        guardar_curso_txt();
    }

    // Agregar docente
    void agregar_docente() {
        string d, n, p, m;
        cout << "\n=== AGREGAR DOCENTE ===\n";
        do {
            cout << "DNI (8 digitos): ";
            getline(cin, d);
        } while (d.size() != 8);
        cout << "Nombre: "; getline(cin, n);
        cout << "Apellido paterno: "; getline(cin, p);
        cout << "Apellido materno: "; getline(cin, m);
        docente = Persona(d, n, p, m);
        guardar_docente_txt();
    }

    // Agregar alumno
    void agregar_alumno() {
        if (total_alumnos >= 5) {
            cout << "❌ No hay mas cupos.\n";
            return;
        }
        string d, n, p, m;
        cout << "\n=== AGREGAR ALUMNO ===\n";
        do {
            cout << "DNI (8 digitos): ";
            getline(cin, d);
        } while (d.size() != 8);
        cout << "Nombre: "; getline(cin, n);
        cout << "Apellido paterno: "; getline(cin, p);
        cout << "Apellido materno: "; getline(cin, m);
        estudiantes[total_alumnos] = Persona(d, n, p, m);
        guardar_alumno_txt(estudiantes[total_alumnos]);
        total_alumnos++;
        cout << "✅ Alumno agregado.\n";
    }

    // Listar alumnos
    void listar_alumnos() {
        cout << "\n=== LISTA DE ALUMNOS ===\n";
        if (total_alumnos == 0) {
            cout << "Sin alumnos registrados.\n";
            return;
        }
        for (int i = 0; i < total_alumnos; i++) {
            estudiantes[i].saludar();
        }
    }

    // Leer alumnos desde archivo
    void leer_alumnos_txt() {
        cout << "\n=== ALUMNOS EN ARCHIVO ===\n";
        ifstream archivo("Alumno.txt");
        if (!archivo) {
            cout << "No hay archivo guardado.\n";
            return;
        }
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << "\n";
        }
        archivo.close();
    }

    // Eliminar alumno
    void eliminar_alumno_txt() {
        string dniElim;
        cout << "\n=== ELIMINAR ALUMNO ===\n";
        cout << "Ingrese DNI: ";
        getline(cin, dniElim);
        ifstream orig("Alumno.txt");
        ofstream temp("temp.txt");
        string d, n, p, m;
        while (getline(orig, d, ';') && getline(orig, n, ';') && getline(orig, p, ';') && getline(orig, m)) {
            if (d != dniElim) {
                temp << d << ";" << n << ";" << p << ";" << m << "\n";
            }
        }
        orig.close(); temp.close();
        remove("Alumno.txt"); rename("temp.txt", "Alumno.txt");
        cout << "✅ Alumno eliminado.\n";
    }

    // Actualizar alumno
    void actualizar_alumno_txt() {
        string dniBuscar;
        cout << "\n=== ACTUALIZAR ALUMNO ===\n";
        cout << "Ingrese DNI: ";
        getline(cin, dniBuscar);
        ifstream orig("Alumno.txt");
        ofstream temp("temp.txt");
        string d, n, p, m;
        while (getline(orig, d, ';') && getline(orig, n, ';') && getline(orig, p, ';') && getline(orig, m)) {
            if (d == dniBuscar) {
                cout << "Nuevo nombre: "; getline(cin, n);
                cout << "Nuevo apellido paterno: "; getline(cin, p);
                cout << "Nuevo apellido materno: "; getline(cin, m);
            }
            temp << d << ";" << n << ";" << p << ";" << m << "\n";
        }
        orig.close(); temp.close();
        remove("Alumno.txt"); rename("temp.txt", "Alumno.txt");
        cout << "✅ Datos actualizados.\n";
    }

    // Mostrar docente
    void mostrar_docente() {
        cout << "\n=== DOCENTE ===\n";
        docente.saludar();
    }

    // Mostrar total alumnos
    void mostrar_total_alumnos() {
        cout << "\nTotal alumnos: " << total_alumnos << "/5\n";
    }

    // Imprimir resumen completo
    void imprimir() {
        cout << "\n===========================\n";
        cout << "Curso: " << nombre << "\n";
        cout << "Creditos: " << credito << "\n";
        cout << "Docente: "; docente.saludar();
        cout << "Alumnos:\n";
        listar_alumnos();
        cout << "===========================\n";
    }
};

// Menú principal
int main() {
    Curso curso;
    int opcion;

    do {
        cout << "\n===== SISTEMA DE GESTION DE CURSOS =====\n";
        cout << "1. Registrar curso\n";
        cout << "2. Agregar docente\n";
        cout << "3. Agregar alumno\n";
        cout << "4. Listar alumnos\n";
        cout << "5. Leer alumnos del archivo\n";
        cout << "6. Eliminar alumno\n";
        cout << "7. Actualizar alumno\n";
        cout << "8. Mostrar docente\n";
        cout << "9. Mostrar total alumnos\n";
        cout << "10. Resumen completo\n";
        cout << "11. Salir\n";
        cout << "Elija opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: curso.registrar_curso(); break;
            case 2: curso.agregar_docente(); break;
            case 3: curso.agregar_alumno(); break;
            case 4: curso.listar_alumnos(); break;
            case 5: curso.leer_alumnos_txt(); break;
            case 6: curso.eliminar_alumno_txt(); break;
            case 7: curso.actualizar_alumno_txt(); break;
            case 8: curso.mostrar_docente(); break;
            case 9: curso.mostrar_total_alumnos(); break;
            case 10: curso.imprimir(); break;
            case 11: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 11);

    return 0;
}