#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// CLASE PERSONA (corrige toda la estructura de tu imagen)
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

    // Métodos GETTERS (leer atributos)
    string getDni() { return dni; }
    string getNombres() { return nombres; }
    string getApellidoPaterno() { return apellidoPaterno; }
    string getApellidoMaterno() { return apellidoMaterno; }

    // Métodos SETTERS (modificar atributos)
    void setDni(string _dni) { dni = _dni; }
    void setNombres(string _nombres) { nombres = _nombres; }
    void setApellidoPaterno(string _paterno) { apellidoPaterno = _paterno; }
    void setApellidoMaterno(string _materno) { apellidoMaterno = _materno; }

    // Mostrar datos completos
    void mostrarDatos() {
        cout << "DNI: " << dni << " | " << nombres << " " << apellidoPaterno << " " << apellidoMaterno << "\n";
    }
};

// CLASE CURSO
class Curso {
private:
    int idCurso;
    string nombreCurso;
    int creditos;
    Persona docente;
    Persona alumnos[5];
    int totalAlumnos;

public:
    // Constructor vacío
    Curso() {
        idCurso = 0;
        creditos = 0;
        totalAlumnos = 0;
    }

    // Constructor parametrizado
    Curso(int _id, string _nombre, int _creditos) {
        idCurso = _id;
        nombreCurso = _nombre;
        creditos = _creditos;
        totalAlumnos = 0;
    }

    // Getters y Setters del curso
    int getIdCurso() { return idCurso; }
    void setIdCurso(int _id) { idCurso = _id; }

    string getNombreCurso() { return nombreCurso; }
    void setNombreCurso(string _nombre) { nombreCurso = _nombre; }

    int getCreditos() { return creditos; }
    void setCreditos(int _creditos) { creditos = _creditos; }

    // Guardar curso en archivo
    void guardarCursoArchivo() {
        ofstream archivo("curso.txt");
        archivo << idCurso << ";" << nombreCurso << ";" << creditos << "\n";
        archivo.close();
        cout << "✅ Curso guardado en archivo.\n";
    }

    // Guardar docente en archivo
    void guardarDocenteArchivo() {
        ofstream archivo("docente.txt");
        archivo << docente.getDni() << ";" << docente.getNombres() << ";"
                << docente.getApellidoPaterno() << ";" << docente.getApellidoMaterno() << "\n";
        archivo.close();
        cout << "✅ Docente guardado en archivo.\n";
    }

    // Guardar alumno en archivo
    void guardarAlumnoArchivo(Persona alumno) {
        ofstream archivo("alumnos.txt", ios::app);
        archivo << alumno.getDni() << ";" << alumno.getNombres() << ";"
                << alumno.getApellidoPaterno() << ";" << alumno.getApellidoMaterno() << "\n";
        archivo.close();
    }

    // Registrar curso completo
    void registrarCurso() {
        cout << "\n=== REGISTRAR NUEVO CURSO ===\n";
        cout << "Ingrese ID del curso: ";
        cin >> idCurso;
        cin.ignore();
        cout << "Ingrese nombre del curso: ";
        getline(cin, nombreCurso);
        do {
            cout << "Ingrese cantidad de créditos: ";
            cin >> creditos;
            cin.ignore();
        } while (creditos <= 0);
        guardarCursoArchivo();
    }

    // Asignar docente al curso
    void asignarDocente() {
        string d, n, p, m;
        cout << "\n=== ASIGNAR DOCENTE ===\n";
        do {
            cout << "Ingrese DNI (8 dígitos): ";
            getline(cin, d);
        } while (d.size() != 8);
        cout << "Ingrese nombres: "; getline(cin, n);
        cout << "Ingrese apellido paterno: "; getline(cin, p);
        cout << "Ingrese apellido materno: "; getline(cin, m);
        docente = Persona(d, n, p, m);
        guardarDocenteArchivo();
    }

    // Agregar alumno al curso
    void agregarAlumno() {
        if (totalAlumnos >= 5) {
            cout << "❌ No hay cupos disponibles (máximo 5 alumnos).\n";
            return;
        }
        string d, n, p, m;
        cout << "\n=== AGREGAR ALUMNO ===\n";
        do {
            cout << "Ingrese DNI (8 dígitos): ";
            getline(cin, d);
        } while (d.size() != 8);
        cout << "Ingrese nombres: "; getline(cin, n);
        cout << "Ingrese apellido paterno: "; getline(cin, p);
        cout << "Ingrese apellido materno: "; getline(cin, m);
        alumnos[totalAlumnos] = Persona(d, n, p, m);
        guardarAlumnoArchivo(alumnos[totalAlumnos]);
        totalAlumnos++;
        cout << "✅ Alumno agregado correctamente (" << totalAlumnos << "/5).\n";
    }

    // Listar todos los alumnos
    void listarAlumnos() {
        cout << "\n=== LISTA DE ALUMNOS REGISTRADOS ===\n";
        if (totalAlumnos == 0) {
            cout << "No hay alumnos inscritos en el curso.\n";
            return;
        }
        for (int i = 0; i < totalAlumnos; i++) {
            cout << i+1 << ". ";
            alumnos[i].mostrarDatos();
        }
    }

    // Leer alumnos desde archivo
    void leerAlumnosArchivo() {
        cout << "\n=== ALUMNOS GUARDADOS EN ARCHIVO ===\n";
        ifstream archivo("alumnos.txt");
        if (!archivo.is_open()) {
            cout << "No se encontró el archivo de alumnos.\n";
            return;
        }
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << "\n";
        }
        archivo.close();
    }

    // Eliminar alumno por DNI
    void eliminarAlumnoArchivo() {
        string dniEliminar;
        cout << "\n=== ELIMINAR ALUMNO ===\n";
        cout << "Ingrese el DNI del alumno a eliminar: ";
        getline(cin, dniEliminar);

        // Buscar en memoria
        int posicion = -1;
        for (int i = 0; i < totalAlumnos; i++) {
            if (alumnos[i].getDni() == dniEliminar) {
                posicion = i;
                break;
            }
        }
        if (posicion == -1) {
            cout << "❌ No se encontró el alumno con ese DNI.\n";
            return;
        }

        // Eliminar y reordenar
        for (int i = posicion; i < totalAlumnos - 1; i++) {
            alumnos[i] = alumnos[i+1];
        }
        totalAlumnos--;

        // Actualizar archivo
        ofstream nuevoArchivo("alumnos.txt");
        for (int i = 0; i < totalAlumnos; i++) {
            nuevoArchivo << alumnos[i].getDni() << ";" << alumnos[i].getNombres() << ";"
                         << alumnos[i].getApellidoPaterno() << ";" << alumnos[i].getApellidoMaterno() << "\n";
        }
        nuevoArchivo.close();
        cout << "✅ Alumno eliminado correctamente.\n";
    }

    // Actualizar datos de alumno
    void actualizarAlumnoArchivo() {
        string dniBuscar;
        cout << "\n=== ACTUALIZAR DATOS DE ALUMNO ===\n";
        cout << "Ingrese el DNI del alumno a modificar: ";
        getline(cin, dniBuscar);

        int posicion = -1;
        for (int i = 0; i < totalAlumnos; i++) {
            if (alumnos[i].getDni() == dniBuscar) {
                posicion = i;
                break;
            }
        }
        if (posicion == -1) {
            cout << "❌ No se encontró el alumno con ese DNI.\n";
            return;
        }

        // Pedir nuevos datos
        string n, p, m;
        cout << "Ingrese nuevos nombres: "; getline(cin, n);
        cout << "Ingrese nuevo apellido paterno: "; getline(cin, p);
        cout << "Ingrese nuevo apellido materno: "; getline(cin, m);
        alumnos[posicion].setNombres(n);
        alumnos[posicion].setApellidoPaterno(p);
        alumnos[posicion].setApellidoMaterno(m);

        // Actualizar archivo
        ofstream nuevoArchivo("alumnos.txt");
        for (int i = 0; i < totalAlumnos; i++) {
            nuevoArchivo << alumnos[i].getDni() << ";" << alumnos[i].getNombres() << ";"
                         << alumnos[i].getApellidoPaterno() << ";" << alumnos[i].getApellidoMaterno() << "\n";
        }
        nuevoArchivo.close();
        cout << "✅ Datos del alumno actualizados.\n";
    }

    // Mostrar docente asignado
    void mostrarDocente() {
        cout << "\n=== DOCENTE DEL CURSO ===\n";
        docente.mostrarDatos();
    }

    // Mostrar total de alumnos
    void mostrarTotalAlumnos() {
        cout << "\nTotal de alumnos inscritos: " << totalAlumnos << " / 5 cupos máximos.\n";
    }

    // Imprimir resumen completo del curso
    void imprimirResumen() {
        cout << "\n=====================================\n";
        cout << "         RESUMEN DEL CURSO            \n";
        cout << "ID Curso:      " << idCurso << "\n";
        cout << "Nombre:        " << nombreCurso << "\n";
        cout << "Créditos:      " << creditos << "\n";
        cout << "Docente:       "; docente.mostrarDatos();
        cout << "Alumnos:       " << totalAlumnos << "/5\n";
        cout << "=====================================\n";
    }
};

// FUNCIÓN PRINCIPAL (MENÚ)
int main() {
    Curso miCurso;
    int opcion;

    do {
        cout << "\n===== SISTEMA DE GESTIÓN DE CURSOS =====\n";
        cout << "1. Registrar nuevo curso\n";
        cout << "2. Asignar docente al curso\n";
        cout << "3. Agregar alumno al curso\n";
        cout << "4. Listar alumnos registrados\n";
        cout << "5. Leer alumnos desde archivo\n";
        cout << "6. Eliminar alumno por DNI\n";
        cout << "7. Actualizar datos de alumno\n";
        cout << "8. Mostrar docente asignado\n";
        cout << "9. Mostrar total de alumnos\n";
        cout << "10. Ver resumen completo del curso\n";
        cout << "11. Salir del sistema\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: miCurso.registrarCurso(); break;
            case 2: miCurso.asignarDocente(); break;
            case 3: miCurso.agregarAlumno(); break;
            case 4: miCurso.listarAlumnos(); break;
            case 5: miCurso.leerAlumnosArchivo(); break;
            case 6: miCurso.eliminarAlumnoArchivo(); break;
            case 7: miCurso.actualizarAlumnoArchivo(); break;
            case 8: miCurso.mostrarDocente(); break;
            case 9: miCurso.mostrarTotalAlumnos(); break;
            case 10: miCurso.imprimirResumen(); break;
            case 11: cout << "Saliendo del sistema... ¡Hasta luego!\n"; break;
            default: cout << "Opción no válida, intente nuevamente.\n";
        }

    } while (opcion != 11);

    return 0;
}