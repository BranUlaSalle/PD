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

    // dp[i] representa el numero minimo de monedas necesarias para formar la cantidad i
    for (int i = 1; i <= cant_llegar; ++i) {
        for (int c : monedas) {
            if (i - c >= 0) {
                //relacion de recurrencia: dp[i] = min(dp[i], dp[i - c] + 1) para cada moneda c
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    //salir de la funcion si no es posible formar la cantidad deseada
    if (dp[cant_llegar] >= actual) return;
    

    cout << "Cantidad minima de monedas: " << dp[cant_llegar] << endl;

    // Reconstruccion de la combinacion de monedas utilizada
    vector<int> combinacion;
    int totalAhora = cant_llegar;
    while (totalAhora > 0) {
        // Iterar sobre las monedas para encontrar una que haya sido utilizada en la solucion optima
        for (int c : monedas) {
            // Verificar si la moneda c fue utilizada en la solucion optima
            if (totalAhora - c >= 0 && dp[totalAhora] == dp[totalAhora - c] + 1) {
                combinacion.push_back(c);
                totalAhora -= c;
                break;
            }
        }
    }

    // Ordenar la combinacion de mayor a menor
    sort(combinacion.rbegin(), combinacion.rend());

    cout << "Combinacion: ";
    for (size_t i = 0; i < combinacion.size(); ++i) {
        cout << combinacion[i];
        if (i < combinacion.size() - 1) {
            cout << " + ";
        }
    }
    
    // Imprimir la tabla de DP
    cout << "\nTabla DP:" << endl;
    for (int i = 0; i <= cant_llegar; ++i) {
        int val = (dp[i] >= actual) ? -1 : dp[i];
        cout << val;
        if (i < cant_llegar) cout << ", ";
    }
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