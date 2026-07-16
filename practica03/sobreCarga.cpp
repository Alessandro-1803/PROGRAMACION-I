#include <iostream>
using namespace std;

// Clase base con sobrecarga de métodos
class Libro {
public:
    // Primera versión: muestra solo el nombre básico
    void mostrar() {
        cout << "📖 Libro en general" << endl;
    }

    // Segunda versión: sobrecargada, muestra detalles completos o abreviados
    void mostrar(bool detallado) {
        if (detallado) {
            cout << "📚 Libro completo: incluye título, autor, editorial y género" << endl;
        } else {
            // Reutiliza la versión simple cuando no se piden detalles
            mostrar();
        }
    }
};

int main() {
    Libro miLibro;

    // Llamada a la versión básica sin parámetros
    cout << "--- Versión simple ---" << endl;
    miLibro.mostrar();

    // Llamadas a la versión sobrecargada con valor booleano
    cout << "\n--- Versión detallada ---" << endl;
    miLibro.mostrar(true);

    cout << "\n--- Versión abreviada ---" << endl;
    miLibro.mostrar(false);

    return 0;
}