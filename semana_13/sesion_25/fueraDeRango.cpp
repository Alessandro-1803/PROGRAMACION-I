#include <iostream>
#include <string>
using namespace std;

// Clase Usuario (diferente a Estudiante)
class Usuario {
private:
    // Atributos distintos
    int edad;
    string nombre;
public:
    // Método para registrar datos con validación
    void registrarEdad(int edadIngresada, string nombreIngresado) {
        // Validación de rango DIFERENTE: edad entre 12 y 110 años
        if (edadIngresada < 12 || edadIngresada > 110) {
            throw "La edad debe estar entre 12 y 110 años.";
        }
        // Validación adicional: nombre no vacío
        if (nombreIngresado.empty()) {
            throw "El nombre no puede estar vacío.";
        }

        // Guardar datos si todo es correcto
        edad = edadIngresada;
        nombre = nombreIngresado;
        cout << "\n✅ Registro exitoso!" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;

        // Mensaje personalizado
        if (edad < 18) {
            cout << "Estado: Menor de edad (requiere autorización)." << endl;
        } else {
            cout << "Estado: Usuario adulto." << endl;
        }
    }
};

int main() {
    Usuario usuario;
    int edadIngresada;
    string nombreIngresado;

    // Pedir datos al usuario
    cout << "=== REGISTRO DE USUARIO ===" << endl;
    cout << "Ingrese su nombre completo: ";
    getline(cin, nombreIngresado);
    cout << "Ingrese su edad: ";
    cin >> edadIngresada;

    // Manejo de excepciones
    try {
        usuario.registrarEdad(edadIngresada, nombreIngresado);
    }
    catch (const char* mensajeError) {
        cout << "\n❌ Error: " << mensajeError << endl;
    }

    return 0;
}