#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Indica un número del 1 al 7 para conocer el día: ";
    cin >> numero;

    switch (numero) {
        case 1:
            cout << "📅 Lunes → Día laborable" << endl;
            break;
        case 2:
            cout << "📅 Martes → Día laborable" << endl;
            break;
        case 3:
            cout << "📅 Miércoles → Día laborable" << endl;
            break;
        case 4:
            cout << "📅 Jueves → Día laborable" << endl;
            break;
        case 5:
            cout << "📅 Viernes → Día laborable" << endl;
            break;
        case 6:
            cout << "📅 Sábado → Fin de semana" << endl;
            break;
        case 7:
            cout << "📅 Domingo → Fin de semana" << endl;
            break;
        default:
            cout << "❌ Valor no válido: debes escribir un número entre 1 y 7" << endl;
    }

    return 0;
}