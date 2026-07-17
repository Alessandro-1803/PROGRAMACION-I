#include <iostream>
using namespace std;

class Calculadora {
public:
    // Suma de dos enteros
    int Sumar(int a, int b) {
        cout << "Sumando enteros: " << a << " + " << b << endl;
        return a + b;
    }

    // Suma de dos decimales (sobrecarga por tipo de parámetros)
    double Sumar(double a, double b) {
        cout << "Sumando decimales: " << a << " + " << b << endl;
        return a + b;
    }

    // Suma de tres enteros (sobrecarga por cantidad de parámetros)
    int Sumar(int a, int b, int c) {
        cout << "Sumando tres enteros: " << a << " + " << b << " + " << c << endl;
        return a + b + c;
    }
};

int main() {
    Calculadora c;

    // Llama a la versión de 2 enteros
    cout << "Resultado: " << c.Sumar(2, 3) << endl << endl;

    // Llama a la versión de 2 decimales
    cout << "Resultado: " << c.Sumar(2.5, 3.5) << endl << endl;

    // Llama a la versión de 3 enteros
    cout << "Resultado: " << c.Sumar(1, 2, 3) << endl;

    return 0;
}