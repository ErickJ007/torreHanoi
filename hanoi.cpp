#include <iostream>
#include <vector>
using namespace std;

// Torres globales
vector<int> A, B, C;

// Función para imprimir el estado actual de las torres
void imprimirTorres() {
    cout << "\nEstado actual de las torres:\n";

    cout << "A: ";
    for (int i = A.size() - 1; i >= 0; i--) {
        cout << A[i] << " ";
    }

    cout << "\nB: ";
    for (int i = B.size() - 1; i >= 0; i--) {
        cout << B[i] << " ";
    }

    cout << "\nC: ";
    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i] << " ";
    }

    cout << "\n---------------------------\n";
}

// Devuelve una referencia a la torre según la letra
vector<int>& torrePorNombre(char nombre) {
    if (nombre == 'A') return A;
    if (nombre == 'B') return B;
    return C; // si no es A ni B, asumimos C
}

// Mueve un disco de una torre a otra
void moverDisco(char desde, char hacia) {
    vector<int>& origen = torrePorNombre(desde);
    vector<int>& destino = torrePorNombre(hacia);

    int disco = origen.back();     // tomar el disco superior
    origen.pop_back();             // quitarlo de la torre origen
    destino.push_back(disco);      // ponerlo en la torre destino

    cout << "Mover disco " << disco << " de " << desde << " a " << hacia << endl;
    imprimirTorres();
}

// Algoritmo recursivo de Hanoi
void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        moverDisco(origen, destino);
        return;
    }

    hanoi(n - 1, origen, destino, auxiliar);
    moverDisco(origen, destino);
    hanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int n;
    cout << "Ingrese cantidad de discos: ";
    cin >> n;

    // Inicializar la torre A con n discos (el mayor abajo)
    // Usamos números: 1 = disco más pequeño, n = disco más grande
    for (int i = n; i >= 1; i--) {
        A.push_back(i);
    }

    cout << "\nEstado inicial:";
    imprimirTorres();

    cout << "\nSecuencia de movimientos:\n";
    hanoi(n, 'A', 'B', 'C');

    cout << "\n¡Juego completado!\n";
    return 0;
}