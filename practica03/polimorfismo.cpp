#include <iostream>
using namespace std;

// La clase base define un método virtual para mostrar datos
// La versión por defecto sirve cuando no hay un tipo más concreto
class DispositivoElectronico {
public:
    virtual void mostrarDetalles() const {
        cout << "Dispositivo electrónico genérico" << endl;
    }
    virtual ~DispositivoElectronico() = default;
};

// El teléfono hereda y cambia la forma de mostrar su información
class TelefonoInteligente : public DispositivoElectronico {
public:
    void mostrarDetalles() const override {
        cout << "Teléfono inteligente: incluye cámara y conectividad móvil" << endl;
    }
};

// La tableta también hereda y usa su propia versión del método
class TabletaDigital : public DispositivoElectronico {
public:
    void mostrarDetalles() const override {
        cout << "Tableta digital: pantalla táctil de gran tamaño" << endl;
    }
};

int main() {
    DispositivoElectronico* disp;
    TelefonoInteligente celular;
    TabletaDigital pantalla;

    // Primero apuntamos al teléfono
    // Gracias al virtual, se ejecuta el método de la clase correcta
    disp = &celular;
    disp->mostrarDetalles();

    // Luego apuntamos a la tableta
    // El mismo puntero usa la versión adecuada automáticamente
    disp = &pantalla;
    disp->mostrarDetalles();

    return 0;
}