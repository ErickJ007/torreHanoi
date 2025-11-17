#include <iostream>
#include <string>
using namespace std;

int a = -1;
string nombres[5];

void push() {
    if (a == 4) {
        cout << "Pila llena, no puedes agregar más nombres.\n";
        return;
    }
    a++;
    cout << "Ingrese un nombre: ";
    cin >> nombres[a];
}

void pop() {
    if (a == -1) {
        cout << "Pila vacía, no hay nada para quitar.\n";
        return;
    }
    cout << "Eliminando: " << nombres[a] << endl;
    a--;
}

void listar() {
    if (a == -1) {
        cout << "No hay nombres cargados.\n";
        return;
    }
    cout << "Nombres actuales:\n";
    for (int i = 0; i <= a; i++) {
        cout << i << ") " << nombres[i] << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1) Agregar nombre\n";
        cout << "2) Quitar nombre\n";
        cout << "3) Listar nombres\n";
        cout << "0) Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: listar(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}
