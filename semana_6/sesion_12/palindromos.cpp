#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string texto;
    char continuar;

    do {
        // Solicitar entrada
        cout << "Escribe una palabra o frase para verificar: ";
        cin.ignore(); // Limpiar buffer
        getline(cin, texto);

        // Normalizar: convertir a minúsculas y quitar espacios
        stack<char> pilaCaracteres;
        string textoLimpio;
        for (char c : texto) {
            if (!isspace(c)) { // Ignorar espacios
                textoLimpio += tolower(c); // Todo a minúsculas
            }
        }

        // Cargar la pila con el texto limpio
        for (char c : textoLimpio) {
            pilaCaracteres.push(c);
        }

        // Construir la versión invertida
        string textoInvertido;
        while (!pilaCaracteres.empty()) {
            textoInvertido += pilaCaracteres.top();
            pilaCaracteres.pop();
        }

        // Verificar y mostrar resultado
        cout << "\n--- RESULTADO ---" << endl;
        cout << "Texto analizado: " << textoLimpio << endl;
        cout << "Texto invertido: " << textoInvertido << endl;
        if (textoLimpio == textoInvertido) {
            cout << "✅ ¡SÍ es un palíndromo!\n" << endl;
        } else {
            cout << "❌ NO es un palíndromo.\n" << endl;
        }

        // Preguntar por otra prueba
        cout << "¿Quieres verificar otro texto? (s/n): ";
        cin >> continuar;
        cout << "\n-----------------------------\n" << endl;

    } while (continuar == 's' || continuar == 'S');

    cout << "Programa finalizado. ¡Hasta luego!" << endl;
    return 0;
}