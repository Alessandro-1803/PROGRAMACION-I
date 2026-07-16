#include <iostream>
using namespace std;

// Funciones de operaciones matemáticas
int sumar(int num1, int num2) {
    return num1 + num2;
}

int restar(int num1, int num2) {
    return num1 - num2;
}

int multiplicar(int num1, int num2) {
    return num1 * num2;
}

float dividir(int num1, int num2) {
    return (float)num1 / num2;
}

// Función nueva: cálculo del cuadrado de un número
int cuadrado(int num) {
    return num * num;
}

int main() {
    int opcion;
    int n1, n2;

    cout << "=== CALCULADORA BÁSICA ===" << endl;
    cout << "Elige una operación:" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicación" << endl;
    cout << "4. División" << endl;
    cout << "5. Cuadrado de un número" << endl;
    cout << "Ingresa tu opción: ";
    cin >> opcion;

    switch(opcion) {
        case 1:
            cout << "Resultado de 12 + 28 = " << sumar(12, 28) << endl;
            break;
        case 2:
            cout << "Resultado de 50 - 17 = " << restar(50, 17) << endl;
            break;
        case 3:
            cout << "Resultado de 9 * 7 = " << multiplicar(9, 7) << endl;
            break;
        case 4:
            cout << "Ingresa el primer número: ";
            cin >> n1;
            cout << "Ingresa el segundo número: ";
            cin >> n2;
            if(n2 == 0) {
                cout << "ERROR: No se puede dividir entre cero" << endl;
            } else {
                cout << "Resultado: " << dividir(n1, n2) << endl;
            }
            break;
        case 5:
            cout << "Ingresa un número: ";
            cin >> n1;
            cout << "El cuadrado es: " << cuadrado(n1) << endl;
            break;
        default:
            cout << "ERROR: Opción no válida, intenta nuevamente" << endl;
    }

    return 0;
}