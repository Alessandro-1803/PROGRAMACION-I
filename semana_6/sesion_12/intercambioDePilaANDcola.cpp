#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    // ==============================
    // 1. Operaciones con PILA (LIFO: último en entrar, primero en salir)
    // ==============================
    cout << "===== OPERACIONES CON PILA =====" << endl;
    stack<int> pilaNumeros;

    // Agregar elementos
    pilaNumeros.push(10);
    pilaNumeros.push(20);
    pilaNumeros.push(30);
    cout << "Elementos agregados: 10, 20, 30" << endl;

    // Consultar el tope y tamaño
    cout << "Tope actual: " << pilaNumeros.top() << endl;
    cout << "Cantidad de elementos: " << pilaNumeros.size() << endl;

    // Eliminar el tope
    pilaNumeros.pop();
    cout << "Después de eliminar el tope → Tope: " << pilaNumeros.top() << endl;

    // Vaciar la pila
    while (!pilaNumeros.empty()) {
        pilaNumeros.pop();
    }
    cout << "Pila vacía: " << (pilaNumeros.empty() ? "SÍ" : "NO") << "\n" << endl;

    // ==============================
    // 2. Operaciones con COLA (FIFO: primero en entrar, primero en salir)
    // ==============================
    cout << "===== OPERACIONES CON COLA =====" << endl;
    queue<int> colaNumeros;

    // Agregar elementos
    colaNumeros.push(5);
    colaNumeros.push(15);
    colaNumeros.push(25);
    cout << "Elementos agregados: 5, 15, 25" << endl;

    // Consultar frente, final y tamaño
    cout << "Frente actual: " << colaNumeros.front() << endl;
    cout << "Último actual: " << colaNumeros.back() << endl;
    cout << "Cantidad de elementos: " << colaNumeros.size() << endl;

    // Eliminar el frente
    colaNumeros.pop();
    cout << "Después de eliminar el frente → Frente: " << colaNumeros.front() << endl;

    // Vaciar la cola
    while (!colaNumeros.empty()) {
        colaNumeros.pop();
    }
    cout << "Cola vacía: " << (colaNumeros.empty() ? "SÍ" : "NO") << "\n" << endl;

    // ==============================
    // 3. Convertir PILA → COLA (orden invertido)
    // ==============================
    cout << "===== CONVERTIR PILA A COLA =====" << endl;
    stack<int> pilaOrigen;
    queue<int> colaDestino;

    pilaOrigen.push(1);
    pilaOrigen.push(2);
    pilaOrigen.push(3);
    cout << "Pila original (desde tope): 3, 2, 1" << endl;

    while (!pilaOrigen.empty()) {
        colaDestino.push(pilaOrigen.top());
        pilaOrigen.pop();
    }

    cout << "Cola resultante (desde frente): ";
    while (!colaDestino.empty()) {
        cout << colaDestino.front() << " ";
        colaDestino.pop();
    }
    cout << "\n" << endl;

    // ==============================
    // 4. Convertir COLA → PILA (orden invertido)
    // ==============================
    cout << "===== CONVERTIR COLA A PILA =====" << endl;
    queue<int> colaOrigen;
    stack<int> pilaDestino;

    colaOrigen.push(4);
    colaOrigen.push(5);
    colaOrigen.push(6);
    cout << "Cola original (desde frente): 4, 5, 6" << endl;

    while (!colaOrigen.empty()) {
        pilaDestino.push(colaOrigen.front());
        colaOrigen.pop();
    }

    cout << "Pila resultante (desde tope): ";
    while (!pilaDestino.empty()) {
        cout << pilaDestino.top() << " ";
        pilaDestino.pop();
    }
    cout << endl;

    return 0;
}