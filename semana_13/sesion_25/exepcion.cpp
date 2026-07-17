#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    try {
        // Crear objeto para leer el archivo
        ifstream archivo("datos.txt");

        // Verificar si se abrió correctamente
        if (!archivo.is_open()) {
            throw "No se pudo abrir el archivo.";
        }

        cout << "Contenido del archivo:\n" << endl;
        string linea;

        // Leer línea por línea hasta el final
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        // Cerrar el archivo
        archivo.close();
    }
    catch (const char* mensaje) {
        cout << "Error: " << mensaje << endl;
    }

    return 0;
}