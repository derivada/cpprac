#include <bits/stdc++.h>

using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define ar array
#define ll long long   // 64 bits
#define ld long double // 80 bits
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 1e9 + 7;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;        // Infinito
const ld EPS = 1e-9;       // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

// Vectores y pares de enteros
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

// Bucles
#define FOR(i, a, b) for (int i = a; i <= b; i++)

inline bool solve()
{
    int num = 0, denom = 0, cociente = 0, resto = 0;
    map<int, int> restos; // resto y posicion
    vi cocientes;
    cin >> num;
    if (!num)
        return 0;
    cin >> denom;

    // Parte entera
    cociente = num / denom;
    resto = num % denom;
    int i = 0;
    restos.insert({resto, i});
    cout << cociente;
    if (resto % denom == 0)
    {
        cout << "\n";
        return true;
    }

    // Parte decimal
    cout << ".";
    int inicioPeriodo, finPeriodo;
    while (true) // Mientras no llegemos al 0 (o no se cumpla lo de abajo)
    {
        resto = (resto * 10);        // Mult 10
        cocientes.PB(resto / denom); // Nueva cifra
        resto = resto % denom;       // Nuevo resto
        // Si el nuevo resto es 0 acabamos, no habia periodo
        if (resto == 0)
        {
            // Imprimimos todos los cocientes
            for (int i = 0; i < cocientes.size(); i++)
                cout << cocientes[i];
            break;
        }
        auto anterior = restos.find(resto);
        if (anterior != restos.end())
        {
            // Si el nuevo resto ya lo habíamos encontrado, hay periodo
            int comienzoPeriodo = anterior->second;
            int i = 0;
            for (; i < comienzoPeriodo; i++)
                cout << cocientes[i];
            cout << "|";
            for (; i < cocientes.size(); i++)
                cout << cocientes[i];
            cout << "|";
            break;
        }
        i++;
        restos.insert({resto, i});    

    }

    cout << "\n";
    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // Número de casos
    while (solve())
        ;
}
