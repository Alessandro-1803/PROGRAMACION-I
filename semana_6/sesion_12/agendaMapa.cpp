#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Diccionario: clave = apellido, valor = nombre
    map<string, string> agenda;

    // Agregamos los contactos
    agenda["García"] = "Juan";
    agenda["López"] = "María";
    agenda["Álvarez"] = "Pedro";
    agenda["Sajami"] = "Yago";

    // Encabezado ordenado
    cout << "========================================" << endl;
    cout << "         AGENDA DE CONTACTOS             " << endl;
    cout << "========================================" << endl;

    // Recorremos y mostramos los datos
    for (const auto& contacto : agenda) {
        cout << "🔹 Apellido: " << contacto.first << endl;
        cout << "   Nombre:   " << contacto.second << "\n" << endl;
    }

    return 0;
}