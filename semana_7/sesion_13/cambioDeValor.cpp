#include <iostream>
using namespace std;

int main() {
    // Valores iniciales
    int valorX = 20;
    int valorY = 30;

    // Punteros que apuntan a cada variable
    int* ptrX = &valorX;
    int* ptrY = &valorY;

    // Mostrar estado inicial
    cout << "===== ANTES DEL INTERCAMBIO =====" << endl;
    cout << "valorX = " << valorX << endl;
    cout << "valorY = " << valorY << "\n" << endl;

    // Guardar valor original de X usando su puntero
    int auxiliar = *ptrX;

    // Copiar valor de Y en X
    *ptrX = *ptrY;

    // Recuperar valor original de X y guardarlo en Y
    *ptrY = auxiliar;

    // Mostrar resultado final
    cout << "===== DESPUÉS DEL INTERCAMBIO =====" << endl;
    cout << "valorX = " << valorX << endl;
    cout << "valorY = " << valorY << endl;

    return 0;
}