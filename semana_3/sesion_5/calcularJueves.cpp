#include <iostream>
using namespace std;

int main() {
    int seleccion;

    cout << "===== MENÚ DE HERRAMIENTAS =====" << endl;
    cout << "1 → Calcular suma de valores" << endl;
    cout << "2 → Calcular diferencia" << endl;
    cout << "3 → Calcular producto" << endl;
    cout << "4 → Calcular división" << endl;
    cout << "5 → Cerrar el programa" << endl;
    cout << "\nIngresa el número de tu elección: ";
    cin >> seleccion;

    switch (seleccion) {
        case 1:
            cout << "\n✅ Has seleccionado: SUMA" << endl;
            break;
        case 2:
            cout << "\n✅ Has seleccionado: RESTA" << endl;
            break;
        case 3:
            cout << "\n✅ Has seleccionado: MULTIPLICACIÓN" << endl;
            break;
        case 4:
            cout << "\n✅ Has seleccionado: DIVISIÓN" << endl;
            break;
        case 5:
            cout << "\n👋 Saliendo del menú... Hasta luego" << endl;
            break;
        default:
            cout << "\n⚠️ Esa opción no existe, elige entre 1 y 5" << endl;
    }

    return 0;
}