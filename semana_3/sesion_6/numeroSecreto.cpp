#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Número secreto aleatorio entre 1 y 10 (en lugar de valor fijo)
    srand(time(0));
    int numeroObjetivo = rand() % 10 + 1;
    int intentoUsuario;
    bool acertado = false;
    const int MAX_INTENTOS = 4;

    cout << "🎮 JUEGO: ADIVINA EL NÚMERO 🎮" << endl;
    cout << "El número está entre 1 y 10" << endl;
    cout << "Tienes " << MAX_INTENTOS << " oportunidades para acertar\n" << endl;

    // Bucle de intentos
    for (int turno = 1; turno <= MAX_INTENTOS; turno++) {
        cout << "Intento " << turno << " → Escribe tu número: ";
        cin >> intentoUsuario;

        if (intentoUsuario == numeroObjetivo) {
            acertado = true;
            break; // Sale del bucle inmediatamente al acertar
        } else {
            // Pista extra para ayudar al jugador
            if (intentoUsuario < numeroObjetivo) {
                cout << "❌ Incorrecto: el número es MAYOR\n" << endl;
            } else {
                cout << "❌ Incorrecto: el número es MENOR\n" << endl;
            }
        }
    }

    // Resultado final
    cout << "\n========================================" << endl;
    if (acertado) {
        cout << "🎉 ¡MUY BIEN! Adivinaste el número secreto" << endl;
    } else {
        cout << "😔 Se agotaron los intentos" << endl;
        cout << "El número correcto era: " << numeroObjetivo << endl;
    }
    cout << "========================================" << endl;

    return 0;
}