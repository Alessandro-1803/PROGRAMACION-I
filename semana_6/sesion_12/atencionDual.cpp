#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
    // Definimos las colas de atención y el historial
    queue<string> fila1, fila2;
    queue<string> registro;
    stack<string> historialInverso;

    // Cargamos personas en la fila 1
    fila1.push("Ana");
    fila1.push("Luis");
    fila1.push("Carla");
    fila1.push("Jorge");

    // Cargamos personas en la fila 2
    fila2.push("María");
    fila2.push("José");

    // ==============================
    // 1. Mostrar estado inicial de las filas
    // ==============================
    cout << "===== ESTADO INICIAL DE LA FILA 1 =====" << endl;
    while (!fila1.empty()) {
        cout << "→ " << fila1.front() << endl;
        fila1.pop(); // Vaciamos para luego reconstruir
    }

    // Recargamos la fila 1
    fila1.push("Ana");
    fila1.push("Luis");
    fila1.push("Carla");
    fila1.push("Jorge");

    cout << "\n===== ESTADO INICIAL DE LA FILA 2 =====" << endl;
    while (!fila2.empty()) {
        cout << "→ " << fila2.front() << endl;
        fila2.pop(); // Vaciamos para luego reconstruir
    }

    // Recargamos la fila 2
    fila2.push("María");
    fila2.push("José");

    // ==============================
    // 2. Atención equilibrada: se atiende quien esté primero en cualquiera de las dos
    // ==============================
    cout << "\n===== INICIO DE ATENCIÓN =====" << endl;
    while (!fila1.empty() || !fila2.empty()) {
        // Atender 2 personas de la fila 1 si hay
        for (int i = 0; i < 2 && !fila1.empty(); i++) {
            cout << "✅ Atendiendo de fila 1: " << fila1.front() << endl;
            registro.push(fila1.front());
            fila1.pop();
        }

        // Atender 1 persona de la fila 2 si hay
        if (!fila2.empty()) {
            cout << "✅ Atendiendo de fila 2: " << fila2.front() << endl;
            registro.push(fila2.front());
            fila2.pop();
        }
    }

    // ==============================
    // 3. Mostrar historial en orden inverso (último atendido primero)
    // ==============================
    cout << "\n===== HISTORIAL (ÚLTIMO ATENDIDO PRIMERO) =====" << endl;
    while (!registro.empty()) {
        historialInverso.push(registro.front());
        registro.pop();
    }

    while (!historialInverso.empty()) {
        cout << "📌 " << historialInverso.top() << endl;
        historialInverso.pop();
    }

    return 0;
}