#include <iostream>
using namespace std;

// Clase abstracta base: define el comportamiento general de una mascota
class Mascota {
public:
    // Método virtual puro: obliga a las clases hijas a implementarlo
    virtual void sonido() = 0;
    // Destructor virtual recomendado en herencia
    virtual ~Mascota() {}
};

// Clase derivada: Perro
class Perro : public Mascota {
public:
    void sonido() override {
        cout << "El perro hace: Guau Guau!" << endl;
    }
};

// Clase derivada: Gato
class Gato : public Mascota {
public:
    void sonido() override {
        cout << "El gato hace: Miau!" << endl;
    }
};

// Clase derivada: Vaca
class Vaca : public Mascota {
public:
    void sonido() override {
        cout << "La vaca hace: Muu!" << endl;
    }
};

int main() {
    // Puntero de la clase base: puede apuntar a cualquier tipo de mascota
    Mascota* m;
    int opcion;

    // Menú de selección
    cout << "1. Perro" << endl;
    cout << "2. Gato" << endl;
    cout << "3. Vaca" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    // Asignar el puntero según la elección del usuario
    if (opcion == 1) {
        Perro p;
        m = &p;
    } 
    else if (opcion == 2) {
        Gato g;
        m = &g;
    } 
    else if (opcion == 3) {
        Vaca v;
        m = &v;
    } 
    else {
        cout << "Opción no válida." << endl;
        return 0;
    }

    // Mostrar el sonido de la mascota seleccionada (polimorfismo)
    m->sonido();

    return 0;
}