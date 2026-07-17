#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string usuarioCorrecto = "cliente2026";
    string claveCorrecta = "acceso123";
    string usuarioIngresado, claveIngresada;
    double saldo = 1500.00; // Saldo inicial
    double monto;
    int opcion;

    // Validación de acceso
    cout << "===== INICIO DE SESIÓN =====" << endl;
    do {
        cout << "Usuario: ";
        cin >> usuarioIngresado;
        cout << "Contraseña: ";
        cin >> claveIngresada;

        if (usuarioIngresado != usuarioCorrecto || claveIngresada != claveCorrecta) {
            cout << "❌ Datos incorrectos. Inténtalo nuevamente.\n" << endl;
        }
    } while (usuarioIngresado != usuarioCorrecto || claveIngresada != claveCorrecta);

    cout << "\n✅ ¡Bienvenido al sistema bancario!\n" << endl;
    cout << fixed << setprecision(2);

    // Menú principal
    do {
        cout << "===== MENÚ DE OPERACIONES =====" << endl;
        cout << "1. Consultar saldo disponible" << endl;
        cout << "2. Realizar depósito" << endl;
        cout << "3. Realizar retiro" << endl;
        cout << "4. Salir del sistema" << endl;
        cout << "\nElige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n💵 Tu saldo actual es: S/ " << saldo << "\n" << endl;
                break;

            case 2:
                cout << "\nIngresa el monto a depositar: S/ ";
                cin >> monto;
                if (monto > 0) {
                    saldo += monto;
                    cout << "✅ Depósito exitoso. Nuevo saldo: S/ " << saldo << "\n" << endl;
                } else {
                    cout << "❌ El monto debe ser mayor a cero.\n" << endl;
                }
                break;

            case 3:
                cout << "\nIngresa el monto a retirar: S/ ";
                cin >> monto;
                if (monto <= 0) {
                    cout << "❌ Monto no válido.\n" << endl;
                } else if (monto > saldo) {
                    cout << "❌ Fondos insuficientes. Saldo disponible: S/ " << saldo << "\n" << endl;
                } else {
                    saldo -= monto;
                    cout << "✅ Retiro realizado. Saldo restante: S/ " << saldo << "\n" << endl;
                }
                break;

            case 4:
                cout << "\n👋 Gracias por usar nuestros servicios. ¡Hasta pronto!" << endl;
                break;

            default:
                cout << "\n⚠️ Opción no válida. Elige entre 1 y 4.\n" << endl;
        }
    } while (opcion != 4);

    return 0;
}