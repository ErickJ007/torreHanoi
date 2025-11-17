#include <iostream>
using namespace std;
//espero se actualice

void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }

    // Mover n-1 discos de origen a auxiliar
    hanoi(n - 1, origen, destino, auxiliar);

    // Mover el disco mayor a destino
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;

    // Mover los n-1 discos desde auxiliar a destino
    hanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int n;
    cout << "Ingrese cantidad de discos: ";
    cin >> n;

    cout << "\nSecuencia de movimientos:\n";
    hanoi(n, 'A', 'B', 'C');  // A = origen, B = auxiliar, C = destino

    return 0;
}