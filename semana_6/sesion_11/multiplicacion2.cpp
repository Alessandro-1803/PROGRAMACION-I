#include <iostream>
using namespace std;

// Multiplica dos números usando solo sumas y recursividad
int multiplicarPorSumas(int valor1, int valor2) {
    // Caso base: si el segundo factor es cero, el resultado es 0
    if (valor2 == 0) {
        return 0;
    }

    // Si valor2 es positivo: sumamos valor1 y reducimos valor2 en 1
    if (valor2 > 0) {
        return valor1 + multiplicarPorSumas(valor1, valor2 - 1);
    }

    // Si valor2 es negativo: cambiamos el signo y ajustamos la operación
    return -valor1 + multiplicarPorSumas(valor1, valor2 + 1);
}

int main() {
    int num1, num2;

    cout << "===== MULTIPLICACIÓN SIN USAR EL OPERADOR * =====" << endl;
    cout << "Ingresa el primer número: ";
    cin >> num1;
    cout << "Ingresa el segundo número: ";
    cin >> num2;

    int resultado = multiplicarPorSumas(num1, num2);
    cout << "\n✅ El resultado de la multiplicación es: " << resultado << endl;

    return 0;
}