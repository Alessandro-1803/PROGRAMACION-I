#include <iostream>
#include <string>
using namespace std;

int main() {
    // Credenciales correctas predefinidas
    const string usuarioValido = "admin_sistema";
    const string claveValida = "Acceso2026!";

    string usuarioIngresado, claveIngresada;

    do {
        cout << "=== INICIO DE SESIÓN ===" << endl;
        cout << "Escribe tu nombre de usuario: ";
        cin >> usuarioIngresado;
        cout << "Escribe tu contraseña: ";
        cin >> claveIngresada;

        // Verificación parcial y mensajes diferenciados
        if (usuarioIngresado != usuarioValido) {
            cout << "❌ Usuario no reconocido. Inténtalo nuevamente.\n" << endl;
        }
        else if (claveIngresada != claveValida) {
            cout << "❌ Contraseña incorrecta. Inténtalo nuevamente.\n" << endl;
        }

    // Repite mientras cualquiera de los dos datos sea erróneo
    } while (usuarioIngresado != usuarioValido || claveIngresada != claveValida);

    cout << "\n✅ ¡Acceso concedido! Bienvenido al sistema." << endl;
    return 0;
}