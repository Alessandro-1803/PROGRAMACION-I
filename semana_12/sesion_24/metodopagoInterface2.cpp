#include <iostream>
using namespace std;

// INTERFAZ / CLASE ABSTRACTA: obliga a implementar procesarPago()
class MetodoPago {
public:
    // Método virtual puro = hace que la clase sea abstracta
    virtual void procesarPago(double montoPago) = 0;
    // Destructor virtual recomendado en herencia
    virtual ~MetodoPago() {}
};

// IMPLEMENTACIÓN: Pago con Tarjeta de Crédito
class TarjetaCredito : public MetodoPago {
public:
    void procesarPago(double montoPago) override {
        cout << "Pago de S/ " << montoPago 
             << " realizado con Tarjeta de Crédito." << endl;
    }
};

// IMPLEMENTACIÓN: Pago por Transferencia
class Transferencia : public MetodoPago {
public:
    void procesarPago(double montoPago) override {
        cout << "Pago de S/ " << montoPago 
             << " realizado mediante Transferencia." << endl;
    }
};

// IMPLEMENTACIÓN: Pago con Yape
class Yape : public MetodoPago {
public:
    void procesarPago(double montoPago) override {
        cout << "Pago de S/ " << montoPago 
             << " realizado mediante Yape." << endl;
    }
};

int main() {
    // Puntero de tipo clase base (permite usar cualquier método de pago)
    MetodoPago* pago;

    // Objetos de cada tipo de pago
    TarjetaCredito tc;
    Transferencia tr;
    Yape yp;

    // Puntero apunta a TarjetaCredito
    pago = &tc;
    pago->procesarPago(250.50);

    // Ahora apunta a Transferencia
    pago = &tr;
    pago->procesarPago(180.00);

    // Ahora apunta a Yape
    pago = &yp;
    pago->procesarPago(75.90);

    return 0;
}