#include <iostream>
using namespace std;

int main() {
    int fecha;

    cout << "Escribe el año que deseas comprobar: ";
    cin >> fecha;

    // Regla oficial: bisiesto si es múltiplo de 4, no múltiplo de 100, o sí lo es de 400
    if ((fecha % 4 == 0 && fecha % 100 != 0) || (fecha % 400 == 0)) {
        cout << "✅ El año " << fecha << " SÍ es bisiesto" << endl;
    } else {
        cout << "❌ El año " << fecha << " NO es bisiesto" << endl;
    }

    return 0;
}