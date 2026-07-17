#include <iostream>
using namespace std;

int main() {
    double saldo = 1500.0; // Saldo inicial distinto
    double monto;
    int opcion;

    cout << "===== CAJERO AUTOMATICO =====" << endl;
    cout << "Saldo disponible: S/ " << saldo << endl;
    cout << "\n1. Depositar dinero" << endl;
    cout << "2. Retirar dinero" << endl;
    cout << "Elija una operacion: ";
    cin >> opcion;

    try {
        if (opcion == 1) {
            cout << "\nIngrese el monto a depositar: ";
            cin >> monto;

            // Validación exclusiva para depósitos
            if (monto <= 0) {
                throw "El monto a depositar debe ser mayor a cero.";
            }
            if (monto > 10000) {
                throw "El monto máximo por deposito es S/ 10,000.";
            }

            saldo += monto;
            cout << "✅ Depósito realizado exitosamente." << endl;
            cout << "Nuevo saldo: S/ " << saldo << endl;
        }
        else if (opcion == 2) {
            cout << "\nIngrese el monto a retirar: ";
            cin >> monto;

            // Validaciones distintas al ejemplo original
            if (monto <= 0) {
                throw "El monto a retirar debe ser mayor a cero.";
            }
            if (monto > saldo) {
                throw "Saldo insuficiente para realizar el retiro.";
            }
            if (monto > 5000) {
                throw "El monto máximo por retiro es S/ 5,000.";
            }

            saldo -= monto;
            cout << "✅ Retiro realizado exitosamente." << endl;
            cout << "Saldo restante: S/ " << saldo << endl;
        }
        else {
            throw "Opción no válida, elija 1 o 2.";
        }
    }
    catch (const char* mensaje) {
        cout << "\n❌ Error: " << mensaje << endl;
    }

    return 0;
}