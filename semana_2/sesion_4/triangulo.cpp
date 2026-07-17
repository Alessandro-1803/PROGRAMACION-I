#include <iostream>
using namespace std;

int main() {
    double lado1, lado2, lado3;

    // Bucle para pedir valores correctos
    do {
        cout << "Escribe la longitud del primer lado: ";
        cin >> lado1;
        cout << "Escribe la longitud del segundo lado: ";
        cin >> lado2;
        cout << "Escribe la longitud del tercer lado: ";
        cin >> lado3;

        if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
            cout << "⚠️ ERROR: Todos los lados deben ser mayores a cero. Intenta nuevamente.\n\n";
        }
    } while (lado1 <= 0 || lado2 <= 0 || lado3 <= 0);

    // Validación extra: desigualdad triangular (condición geométrica obligatoria)
    if (lado1 + lado2 <= lado3 || lado1 + lado3 <= lado2 || lado2 + lado3 <= lado1) {
        cout << "\n❌ Estos valores NO forman un triángulo válido geométricamente." << endl;
        return 0;
    }

    // Clasificación por longitud de lados
    cout << "\n✅ El triángulo es: ";
    if (lado1 == lado2 && lado2 == lado3) {
        cout << "EQUILÁTERO → Todos sus lados son iguales." << endl;
    }
    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        cout << "ISÓSCELES → Tiene exactamente dos lados iguales." << endl;
    }
    else {
        cout << "ESCALENO → Ninguno de sus lados es igual." << endl;
    }

    return 0;
}