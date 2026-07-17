#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    // Estructuras de datos
    queue<int> colaOriginal;
    stack<int> pilaAuxiliar;

    // Agregamos elementos a la cola
    colaOriginal.push(1);
    colaOriginal.push(2);
    colaOriginal.push(3);

    // Mostramos la cola en su orden original
    cout << "===== COLA ORIGINAL =====" << endl;
    queue<int> colaTemporal = colaOriginal; // Copia para no modificar la original
    while (!colaTemporal.empty()) {
        cout << "• " << colaTemporal.front() << endl;
        colaTemporal.pop();
    }

    // Pasamos todos los elementos de la cola a la pila
    while (!colaOriginal.empty()) {
        pilaAuxiliar.push(colaOriginal.front());
        colaOriginal.pop();
    }

    // Mostramos el resultado invertido desde la pila
    cout << "\n===== COLA INVERTIDA (usando pila) =====" << endl;
    while (!pilaAuxiliar.empty()) {
        cout << "• " << pilaAuxiliar.top() << endl;
        pilaAuxiliar.pop();
    }

    return 0;
}