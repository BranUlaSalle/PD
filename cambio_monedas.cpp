#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// funcion para resolver el problema del cambio minimo de monedas
void CambioMoneda(const vector<int>& monedas, int cant_llegar) {
    const int actual = cant_llegar + 2;
    vector<int> dp(cant_llegar + 1, actual);
    //dp[0] =0 0 monedas para hacer cantidad 0
    dp[0] = 0;
    
    //salir de la funcion si no es posible formar la cantidad deseada
    if (dp[cant_llegar] >= actual) return;
}

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

    int cant_llegar;
    cout << "Ingrese la cantidad a la que se desea llegar: ";
    cin >> cant_llegar;
    CambioMoneda(monedas, cant_llegar);

    return 0;
}