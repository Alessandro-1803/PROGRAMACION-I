#include <iostream>
using namespace std;

// Clase base
class Animal {
public:
    // Destructor virtual (buena práctica en herencia)
    virtual ~Animal() {}

    // Método virtual: se ejecuta el de la clase hija según el objeto real
    virtual void hablar() {
        cout << "Animal" << endl;
    }
};

// Clase derivada: hereda públicamente de Animal
class Perro : public Animal {
public:
    // Reemplazo (sobreescritura) del método de la clase padre
    void hablar() override {
        cout << "Guau" << endl;
    }
};

int main() {
    // Puntero de tipo clase base
    Animal* a;

    // El objeto creado realmente es de tipo Perro
    a = new Perro();

    // Gracias al método virtual, se detecta el tipo real y ejecuta Perro::hablar()
    a->hablar();

    // Liberar memoria asignada dinámicamente
    delete a;

    return 0;
}