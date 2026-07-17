#include <iostream>
#include <string>
using namespace std;

// CLASE SERVICIO (corrige tu estructura)
class Servicio {
private:
    int idServicio;
    string nombreServicio;
    float precioServicio;

public:
    // Constructor vacío
    Servicio() {
        idServicio = 0;
        nombreServicio = "";
        precioServicio = 0.0f;
    }

    // Constructor parametrizado
    Servicio(int _id, string _nombre, float _precio) {
        idServicio = _id;
        nombreServicio = _nombre;
        precioServicio = _precio;
    }

    // Getters
    int getIdServicio() { return idServicio; }
    string getNombreServicio() { return nombreServicio; }
    float getPrecioServicio() { return precioServicio; }

    // Setters
    void setIdServicio(int _id) { idServicio = _id; }
    void setNombreServicio(string _nombre) { nombreServicio = _nombre; }
    void setPrecioServicio(float _precio) { precioServicio = _precio; }

    // Método para mostrar datos
    void mostrarServicio() {
        cout << "ID: " << idServicio << " | Servicio: " << nombreServicio << " | Precio: S/ " << precioServicio << "\n";
    }
};

// CLASE USUARIO
class Usuario {
private:
    int idUsuario;
    string nombreUsuario;
    string contrasena;
    Servicio servicioContratado;

public:
    // Constructor vacío
    Usuario() {
        idUsuario = 0;
        nombreUsuario = "";
        contrasena = "";
    }

    // Constructor parametrizado
    Usuario(int _id, string _nombre, string _pass) {
        idUsuario = _id;
        nombreUsuario = _nombre;
        contrasena = _pass;
    }

    // Getters y Setters
    int getIdUsuario() { return idUsuario; }
    void setIdUsuario(int _id) { idUsuario = _id; }

    string getNombreUsuario() { return nombreUsuario; }
    void setNombreUsuario(string _nombre) { nombreUsuario = _nombre; }

    string getContrasena() { return contrasena; }
    void setContrasena(string _pass) { contrasena = _pass; }

    // Asignar servicio al usuario
    void asignarServicio(Servicio s) {
        servicioContratado = s;
    }

    // Mostrar datos del usuario y su servicio
    void mostrarDatosUsuario() {
        cout << "\n=== DATOS DEL USUARIO ===\n";
        cout << "ID Usuario: " << idUsuario << "\n";
        cout << "Nombre: " << nombreUsuario << "\n";
        cout << "Servicio contratado:\n";
        servicioContratado.mostrarServicio();
    }
};

// FUNCIÓN PRINCIPAL
int main() {
    // Crear servicios disponibles
    Servicio internet(1, "Internet Básico", 59.90f);
    Servicio television(2, "Televisión Premium", 45.50f);
    Servicio telefonia(3, "Telefonía Fija", 29.90f);

    // Menú de registro
    int opcion;
    cout << "===== SISTEMA DE REGISTRO DE USUARIOS =====\n";
    cout << "1. Registrar nuevo usuario\n";
    cout << "2. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        int id;
        string nombre, pass;
        cout << "\n--- Datos del usuario ---\n";
        cout << "Ingrese ID: "; cin >> id; cin.ignore();
        cout << "Ingrese nombre de usuario: "; getline(cin, nombre);
        cout << "Ingrese contraseña: "; getline(cin, pass);

        Usuario nuevoUsuario(id, nombre, pass);

        // Elegir servicio
        cout << "\n--- Servicios disponibles ---\n";
        internet.mostrarServicio();
        television.mostrarServicio();
        telefonia.mostrarServicio();
        cout << "\nIngrese ID del servicio a contratar: ";
        int idServicio;
        cin >> idServicio;

        // Asignar servicio elegido
        if (idServicio == 1) nuevoUsuario.asignarServicio(internet);
        else if (idServicio == 2) nuevoUsuario.asignarServicio(television);
        else if (idServicio == 3) nuevoUsuario.asignarServicio(telefonia);
        else cout << "ID de servicio no válido.\n";

        // Mostrar resumen final
        nuevoUsuario.mostrarDatosUsuario();
    }
    else {
        cout << "Saliendo del sistema...\n";
    }

    return 0;
}