#include <iostream>
using namespace std;

// Funciones independientes para cada operación
int sumar(int val1, int val2) {
    return val1 + val2;
}

int restar(int val1, int val2) {
    return val1 - val2;
}

int multiplicar(int val1, int val2) {
    return val1 * val2;
}

float dividir(int val1, int val2) {
    return static_cast<float>(val1) / val2;
}

int main() {
    int opcion;
    int numero1, numero2;
    char repetir;

    do {
        // Entrada de datos
        cout << "Ingresa el primer valor entero: ";
        cin >> numero1;
        cout << "Ingresa el segundo valor entero: ";
        cin >> numero2;

        // Menú de operaciones
        cout << "\n===== OPERACIONES DISPONIBLES =====" << endl;
        cout << "1 → Sumar los dos valores" << endl;
        cout << "2 → Restar los dos valores" << endl;
        cout << "3 → Multiplicar los dos valores" << endl;
        cout << "4 → Dividir los dos valores" << endl;
        cout << "Elige una opción (1-4): ";
        cin >> opcion;

        // Ejecución según la elección
        switch (opcion) {
            case 1:
                cout << "\n✅ Resultado: " << numero1 << " + " << numero2 << " = " << sumar(numero1, numero2) << endl;
                cout << "Escribe 's' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> repetir;
                break;

            case 2:
                cout << "\n✅ Resultado: " << numero1 << " - " << numero2 << " = " << restar(numero1, numero2) << endl;
                cout << "Escribe 's' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> repetir;
                break;

            case 3:
                cout << "\n✅ Resultado: " << numero1 << " × " << numero2 << " = " << multiplicar(numero1, numero2) << endl;
                cout << "Escribe 's' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> repetir;
                break;

            case 4:
                if (numero2 == 0) {
                    cout << "\n❌ ERROR: No se puede dividir entre cero" << endl;
                } else {
                    cout << "\n✅ Resultado: " << numero1 << " ÷ " << numero2 << " = " << dividir(numero1, numero2) << endl;
                }
                cout << "Escribe 's' para volver a calcular o cualquier tecla para cerrar: ";
                cin >> repetir;
                break;

            default:
                cout << "\n⚠️ OPCIÓN INVÁLIDA: Solo puedes elegir entre 1 y 4" << endl;
                repetir = 'n'; // No repite si la opción es errónea
        }
        cout << "------------------------------------\n";

    } while (repetir == 's' || repetir == 'S'); // Admite mayúscula y minúscula

    cout << "👋 Programa finalizado. ¡Hasta luego!" << endl;
    return 0;
}