#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3;
    int maximo, minimo;

    // Pedimos los tres valores
    cout << "Escribe el primer número: ";
    cin >> n1;
    cout << "Escribe el segundo número: ";
    cin >> n2;
    cout << "Escribe el tercer número: ";
    cin >> n3;

    // Empezamos suponiendo que el primero es el mayor y el menor
    maximo = n1;
    minimo = n1;

    // Actualizamos el mayor si el segundo es más grande
    if (n2 > maximo) {
        maximo = n2;
    }
    // Actualizamos el mayor si el tercero es más grande
    if (n3 > maximo) {
        maximo = n3;
    }

    // Actualizamos el menor si el segundo es más pequeño
    if (n2 < minimo) {
        minimo = n2;
    }
    // Actualizamos el menor si el tercero es más pequeño
    if (n3 < minimo) {
        minimo = n3;
    }

    // Verificamos si todos son iguales
    if (n1 == n2 && n2 == n3) {
        cout << "✅ Todos los números son iguales" << endl;
    } else {
        cout << "🔹 El número mayor es: " << maximo << endl;
        cout << "🔹 El número menor es: " << minimo << endl;
    }

    return 0;
}