#include <iostream>
using namespace std;

int main() {
    int anios;

    cout << "Escribe tu edad en años: ";
    cin >> anios;

    // Validación de entrada
    if (anios < 0) {
        cout << "⚠️ Error: No puedes tener una edad negativa." << endl;
        return 1;
    }

    // Clasificación según el rango de edad
    cout << "\n✅ Categoría: ";
    if (anios <= 12) {
        cout << "Eres un niño o niña." << endl;
    }
    else if (anios <= 17) {
        cout << "Eres adolescente." << endl;
    }
    else if (anios <= 59) {
        cout << "Eres adulto/a." << endl;
    }
    else {
        cout << "Eres persona mayor." << endl;
    }

    return 0;
}