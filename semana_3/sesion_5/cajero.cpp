#include <iostream>
#include <iomanip> // Para mostrar montos con dos decimales
using namespace std;

int main() {
    double saldo = 1500.00; // Saldo inicial
    double monto;
    int opcion;

    do {
        cout << "\n===== CAJERO AUTOMÁTICO DIGITAL =====" << endl;
        cout << "1. Consultar saldo disponible" << endl;
        cout << "2. Agregar depósito" << endl;
        cout << "3. Realizar retiro" << endl;
        cout << "4. Salir del sistema" << endl;
        cout << "Elige una opción (1-4): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << fixed << setprecision(2); // Formato de moneda
                cout << "\n💵 Tu saldo actual es: S/ " << saldo << endl;
                break;

            case 2:
                cout << "\nEscribe el monto que deseas depositar: S/ ";
                cin >> monto;
                if (monto > 0) {
                    saldo += monto;
                    cout << "✅ Depósito exitoso. Nuevo saldo: S/ " << saldo << endl;
                } else {
                    cout << "❌ Error: El monto debe ser mayor a cero." << endl;
                }
                break;

            case 3:
                cout << "\nEscribe el monto que deseas retirar: S/ ";
                cin >> monto;
                if (monto <= 0) {
                    cout << "❌ Error: No puedes retirar montos negativos o cero." << endl;
                } else if (monto > saldo) {
                    cout << "❌ Fondos insuficientes. Tu saldo es S/ " << saldo << endl;
                } else {
                    saldo -= monto;
                    cout << "✅ Retiro realizado. Saldo restante: S/ " << saldo << endl;
                }
                break;

            case 4:
                cout << "\n👋 Gracias por usar nuestro servicio. ¡Hasta pronto!" << endl;
                break;

            default:
                cout << "\n⚠️ Opción no válida. Ingresa un número entre 1 y 4." << endl;
        }
        cout << "----------------------------------------";

    } while (opcion != 4);

    return 0;
}