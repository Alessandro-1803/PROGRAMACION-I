#include <iostream>
using namespace std;

//Vehiculo es la clase base que declara una operación común para sus derivados
class Vehiculo{
public:
    virtual void mostrar() {
        //comportamiento por defecto cuando no hay una clase más específica
        cout << "Vehiculo";
    }
};

//Automovil hereda de Vehiculo y redefine el método mostrar
class Automovil : public Vehiculo{
public:
    void mostrar() override {
        //esta versión se usa cuando el objeto es un Automovil
        cout << "Automóvil";
    }
};

int main() {
    Vehiculo* v1 = new Vehiculo();
    Vehiculo* v2 = new Automovil();

    //invoca la implementación correspondiente según el tipo real del objeto
    v1->mostrar();
    cout << endl;
    v2->mostrar();
    cout << endl;

    delete v1; //libera la memoria asignada a v1
    delete v2; //libera la memoria asignada a v2

    return 0;
}