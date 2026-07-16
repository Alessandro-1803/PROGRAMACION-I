#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    int eleccion;
    char continuar;

    do {
        // Solicitud de números
        cout << "Escribe el primer valor: ";
        cin >> num1;
        cout << "Escribe el segundo valor: ";
        cin >> num2;

        // Menú de operaciones
        cout << "\n===== OPERACIONES DISPONIBLES =====" << endl;
        cout << "1 → Sumar los valores" << endl;
        cout << "2 → Restar los valores" << endl;
        cout << "3 → Multiplicar los valores" << endl;
        cout << "4 → Dividir los valores" << endl;
        cout << "Elige una opción (1-4): ";
        cin >> eleccion;

        switch (eleccion) {
            case 1:
                cout << "\n✅ Suma: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                cout << "Escribe 'c' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> continuar;
                break;

            case 2:
                cout << "\n✅ Resta: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                cout << "Escribe 'c' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> continuar;
                break;

            case 3:
                cout << "\n✅ Multiplicación: " << num1 << " × " << num2 << " = " << num1 * num2 << endl;
                cout << "Escribe 'c' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> continuar;
                break;

            case 4:
                if (num2 == 0) {
                    cout << "\n❌ ERROR: No se puede dividir entre cero" << endl;
                } else {
                    cout << "\n✅ División: " << num1 << " ÷ " << num2 << " = " << (float)num1 / num2 << endl;
                }
                cout << "Escribe 'c' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> continuar;
                break;

            default:
                cout << "\n⚠️ OPCIÓN NO VÁLIDA: Solo puedes elegir entre 1 y 4" << endl;
                continuar = 'n'; // No repite si la opción es incorrecta
        }
        cout << "------------------------------------\n";

    } while (continuar == 'c' || continuar == 'C');

    cout << "Programa finalizado ✨" << endl;
    return 0;
}