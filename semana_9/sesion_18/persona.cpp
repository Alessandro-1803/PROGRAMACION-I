#include <iostream>
#include <string>
using namespace std;

class Persona
{
private:
    // Atributos privados (nombres claros y sin errores)
    string dni_persona;
    string nombre_persona;
    string apellido_paterno;
    string apellido_materno;

public:
    // 1. Constructor vacío (obligatorio para arreglos/objetos sin inicializar)
    Persona()
    {
        dni_persona = "";
        nombre_persona = "";
        apellido_paterno = "";
        apellido_materno = "";
    }

    // 2. Constructor parametrizado (inicializa todos los datos)
    Persona(string _dni, string _nombre, string _paterno, string _materno)
    {
        dni_persona = _dni;
        nombre_persona = _nombre;
        apellido_paterno = _paterno;
        apellido_materno = _materno;
    }

    // --- MÉTODOS GETTERS (leer datos) ---
    string get_dni()
    {
        return dni_persona;
    }

    string get_nombre()
    {
        return nombre_persona;
    }

    string get_paterno()
    {
        return apellido_paterno;
    }

    string get_materno()
    {
        return apellido_materno;
    }

    // --- MÉTODOS SETTERS (modificar datos) ---
    void set_dni(string _dni)
    {
        dni_persona = _dni;
    }

    void set_nombre(string _nombre)
    {
        nombre_persona = _nombre;
    }

    void set_paterno(string _paterno)
    {
        apellido_paterno = _paterno;
    }

    void set_materno(string _materno)
    {
        apellido_materno = _materno;
    }

    // Método adicional para mostrar datos completos
    void mostrar_datos()
    {
        cout << "DNI: " << dni_persona << " | "
             << nombre_persona << " "
             << apellido_paterno << " "
             << apellido_materno << endl;
    }
};