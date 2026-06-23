#include <iostream>
#include <vector>
using namespace std;

//Funcion para calcular las formas de subir N escalones
void escalera(int n) {
    //crea un vector dp de tamaño n+1 para almacenar el número de formas de llegar a cada escalón
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) {
        dp[1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de escalones N: ";
    cin >> n;
    escalera(n);
    return 0;
}
