#include <iostream>
#include <iomanip> // Para mostrar montos con dos decimales
using namespace std;

int main() {
    double montoCompra;
    double descuentoAplicado;
    double totalFinal;

    cout << "========================================" << endl;
    cout << "      CALCULADOR DE DESCUENTOS      " << endl;
    cout << "========================================" << endl;

    // Solicitar el monto total
    cout << "\nEscribe el monto total de tu compra: S/ ";
    cin >> montoCompra;

    cout << fixed << setprecision(2); // Formato de moneda

    // Aplicar descuento según el tramo
    if (montoCompra >= 500) {
        descuentoAplicado = montoCompra * 0.05;
        cout << "\n✅ Descuento aplicado: 5% (compras mayores a S/ 500)" << endl;
    }
    else if (montoCompra >= 200) {
        descuentoAplicado = montoCompra * 0.02;
        cout << "\n✅ Descuento aplicado: 2% (compras entre S/ 200 y S/ 499.99)" << endl;
    }
    else if (montoCompra >= 100) {
        descuentoAplicado = montoCompra * 0.01;
        cout << "\n✅ Descuento aplicado: 1% (compras entre S/ 100 y S/ 199.99)" << endl;
    }
    else {
        descuentoAplicado = 0;
        cout << "\nℹ️ No aplica descuento (compras menores a S/ 100)" << endl;
    }

    // Calcular y mostrar resultados
    totalFinal = montoCompra - descuentoAplicado;
    cout << "Monto del descuento: S/ " << descuentoAplicado << endl;
    cout << "Total a pagar: S/ " << totalFinal << endl;

    return 0;
}