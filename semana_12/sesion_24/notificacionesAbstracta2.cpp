#include <iostream>
using namespace std;

// Clase base abstracta para todos los tipos de notificación
class Notificacion {
public:
    // Método virtual puro: obliga a las clases hijas a implementarlo
    virtual void enviarMensaje() = 0;
    // Destructor virtual recomendado en herencia
    virtual ~Notificacion() {}
};

// Notificación por correo
class Correo : public Notificacion {
public:
    void enviarMensaje() override {
        cout << "Mensaje enviado por Correo." << endl;
    }
};

// Notificación por SMS
class SMS : public Notificacion {
public:
    void enviarMensaje() override {
        cout << "Mensaje enviado por SMS." << endl;
    }
};

// Notificación por WhatsApp
class WhatsApp : public Notificacion {
public:
    void enviarMensaje() override {
        cout << "Mensaje enviado por WhatsApp." << endl;
    }
};

int main() {
    // Puntero de la clase base (funciona con cualquier tipo de notificación)
    Notificacion* n;

    // Objetos de cada tipo
    Correo c;
    SMS s;
    WhatsApp w;

    // Envía el mensaje usando Correo
    n = &c;
    n->enviarMensaje();

    // Envía el mensaje mediante SMS
    n = &s;
    n->enviarMensaje();

    // Finalmente envía por WhatsApp
    n = &w;
    n->enviarMensaje();

    return 0;
}