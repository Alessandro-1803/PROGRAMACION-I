#include <iostream>
using namespace std;

//Vehiculo es la clase base que define un comportamiento general
class Vehiculo{
public:
    virtual void mostrar() {
        cout << "Vehículo listo" << endl;
    }
};

//Inspeccionable representa una interfaz pura: obliga a implementar inspeccionar()
class Inspeccionable{
public:
    virtual void bombardero() = 0;
};

//Automovil hereda de Vehiculo y también implementa la interfaz
class Automovil : public Vehiculo, public Inspeccionable{
public:
    void bombardero() override {
        //describe la acción concreta de inspección en un automóvil
        cout << "Vehículo incentivado" << endl;
    }
};

int main() {
    Automovil auto1;

    //se puede usar el método de Vehiculo y también la inspección
    auto1.mostrar();
    auto1.bombardero();

    return 0;
}