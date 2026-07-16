#include <iostream>
#include <string>
using namespace std;

// Clase base: define el comportamiento general
class MedioComunicacion {
public:
    // Método virtual base
    virtual void mostrarTipo() {
        cout << "Medio de comunicación genérico";
    }

    // Método adicional para mostrar uso
    virtual void mostrarUso() {
        cout << "Sirve para transmitir información";
    }

    // Destructor virtual obligatorio para manejo correcto de memoria
    virtual ~MedioComunicacion() {
        cout << "\n→ Se liberó el recurso del medio genérico";
    }
};

// Clase derivada 1: Mensajería
class Mensajeria : public MedioComunicacion {
public:
    // Redefinición del método principal
    void mostrarTipo() override {
        cout << "Mensajería instantánea";
    }

    // Redefinición del método adicional
    void mostrarUso() override {
        cout << "Permite enviar mensajes y archivos al instante";
    }

    // Destructor específico
    ~Mensajeria() override {
        cout << "\n→ Se liberó el recurso de mensajería";
    }
};

// Clase derivada 2: Emisora
class EmisoraRadio : public MedioComunicacion {
public:
    void mostrarTipo() override {
        cout << "Emisora de radio";
    }

    void mostrarUso() override {
        cout << "Difunde contenido en tiempo real a gran audiencia";
    }

    ~EmisoraRadio() override {
        cout << "\n→ Se liberó el recurso de emisora de radio";
    }
};

// Clase derivada extra: Videollamada (agregado nuevo)
class Videollamada : public MedioComunicacion {
public:
    void mostrarTipo() override {
        cout << "Videollamada";
    }

    void mostrarUso() override {
        cout << "Combina audio y video para encuentros presenciales a distancia";
    }

    ~Videollamada() override {
        cout << "\n→ Se liberó el recurso de videollamada";
    }
};

int main() {
    // Punteros a la clase base (asignación dinámica)
    MedioComunicacion* medio1 = new MedioComunicacion();
    MedioComunicacion* medio2 = new Mensajeria();
    MedioComunicacion* medio3 = new EmisoraRadio();
    MedioComunicacion* medio4 = new Videollamada(); // Nuevo objeto

    // Llamadas polimórficas
    cout << "=== Primer medio ===" << endl;
    medio1->mostrarTipo();
    cout << " → ";
    medio1->mostrarUso();
    cout << endl << endl;

    cout << "=== Segundo medio ===" << endl;
    medio2->mostrarTipo();
    cout << " → ";
    medio2->mostrarUso();
    cout << endl << endl;

    cout << "=== Tercer medio ===" << endl;
    medio3->mostrarTipo();
    cout << " → ";
    medio3->mostrarUso();
    cout << endl << endl;

    cout << "=== Cuarto medio (nuevo) ===" << endl;
    medio4->mostrarTipo();
    cout << " → ";
    medio4->mostrarUso();
    cout << endl << endl;

    // Liberación de memoria (se ejecutan los destructores correctos)
    cout << "=== Liberando recursos ===" << endl;
    delete medio1;
    delete medio2;
    delete medio3;
    delete medio4;

    return 0;
}