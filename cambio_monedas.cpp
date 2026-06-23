#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cant;
    cout << "Ingrese la cantidad de denominaciones de monedas: ";
    if (!(cin >> cant)) return 0;

    // crear un vector para almacenar las denominaciones de monedas
    vector<int> monedas(cant);
    cout << "Ingrese las denominaciones de las monedas: ";
    for (int i = 0; i < cant; ++i) {
        cin >> monedas[i];
    }

    return 0;
}