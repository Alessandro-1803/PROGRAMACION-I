#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double precioBase;
    double valorDescuento;
    double totalPagar;
    int tipoCliente;

    cout << "========================================" << endl;
    cout << "      CALCULADOR DE DESCUENTOS POR CLIENTE      " << endl;
    cout << "========================================\n" << endl;

    // Mostrar opciones de membresía
    cout << "Elige tu tipo de cliente:" << endl;
    cout << "1 → Cliente Regular (sin descuento)" << endl;
    cout << "2 → Cliente VIP (20% de descuento)" << endl;
    cout << "3 → Cliente Premium (30% de descuento)" << endl;
    cout << "\nIngresa el número de tu opción: ";
    cin >> tipoCliente;

    // Solicitar el precio base
    cout << "Ingresa el monto total de tu compra: S/ ";
    cin >> precioBase;

    cout << fixed << setprecision(2); // Formato de moneda

    // Aplicar descuento según la opción elegida
    switch (tipoCliente) {
        case 1:
            totalPagar = precioBase;
            cout << "\n✅ Tipo: Cliente Regular" << endl;
            cout << "Total a pagar: S/ " << totalPagar << endl;
            break;

        case 2:
            valorDescuento = precioBase * 0.20;
            totalPagar = precioBase - valorDescuento;
            cout << "\n✅ Tipo: Cliente VIP" << endl;
            cout << "Descuento aplicado (20%): S/ " << valorDescuento << endl;
            cout << "Total a pagar: S/ " << totalPagar << endl;
            break;

        case 3:
            valorDescuento = precioBase * 0.30;
            totalPagar = precioBase - valorDescuento;
            cout << "\n✅ Tipo: Cliente Premium" << endl;
            cout << "Descuento aplicado (30%): S/ " << valorDescuento << endl;
            cout << "Total a pagar: S/ " << totalPagar << endl;
            break;

        default:
            cout << "\n❌ ERROR: La opción ingresada no es válida. Elige entre 1 y 3." << endl;
    }

    return 0;
}