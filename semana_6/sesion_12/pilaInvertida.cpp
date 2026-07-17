#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Declaramos las pilas necesarias
    stack<int> pilaOriginal;
    stack<int> pilaCopia;
    stack<int> pilaInvertida;

    // Cargamos la pila original
    pilaOriginal.push(1);
    pilaOriginal.push(2);
    pilaOriginal.push(3);

    // Mostramos la pila original
    cout << "===== PILA ORIGINAL (desde el tope) =====" << endl;
    pilaCopia = pilaOriginal; // Copiamos para no vaciar la original
    while (!pilaCopia.empty()) {
        cout << "• " << pilaCopia.top() << endl;
        pilaCopia.pop();
    }

    // Proceso de inversión: pasamos de la original a la pila invertida
    pilaCopia = pilaOriginal; // Restauramos la copia
    while (!pilaCopia.empty()) {
        pilaInvertida.push(pilaCopia.top());
        pilaCopia.pop();
    }

    // Mostramos el resultado invertido
    cout << "\n===== PILA INVERTIDA (desde el tope) =====" << endl;
    while (!pilaInvertida.empty()) {
        cout << "• " << pilaInvertida.top() << endl;
        pilaInvertida.pop();
    }

    return 0;
}