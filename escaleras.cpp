#include <iostream>
#include <vector>
using namespace std;

//Funcion para calcular las formas de subir N escalones
void escalera(int n) {
    //si n es negativo sale de la funcion
    if (n < 0) return;

    //crea un vector dp de tamaño n+1 para almacenar el número de formas de llegar a cada escalón
    vector<long long> dp(n + 1, 0);

    //dp[0] = 1 para que 1 este en el inicio y dp[1] = 1 para que 1 este en el primer escalon
    dp[0] = 1;
    if (n >= 1) {
        dp[1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << "Formas posibles: " << dp[n] << endl;

    cout << "Tabla dp: ";
    for (int i = 0; i <= n; ++i) {
        cout << dp[i];
        if (i < n) cout << " ";
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de escalones N: ";
    cin >> n;
    escalera(n);
    return 0;
}
