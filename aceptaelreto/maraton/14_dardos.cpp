#include <bits/stdc++.h>
using namespace std;

// Es bueno desactivarlas para debuggear
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

// Tipos
#define ll long long   // 64 bits INT
#define ld long double // 80 bits FP

// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 1e9 + 7;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;        // Infinito
const ld EPS = 1e-9;       // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

// Estructuras de datos
#define ar array
typedef vector<int> vi;
typedef pair<int, int> pi;
#define umap unordered_map
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for (int i = a; i <= b; i++)

bool solve()
{
    int V = 0, S = 0, tmp;
    vi v;
    cin >> V >> S;
    if (!V)
        return false;
    for (int i = 0; i < S; i++)
    {
        cin >> tmp;
        v.PB(tmp);
    }

    // Prog dinamica problema cambio de monedas
    vector<pair<int, int>> solucion; // Número de monedas, última moneda
    solucion.PB(MP(1, 0));
    for (int i = 1; i <= V; i++)
    {
        // Hallar minimo
        int min = INT_MAX;
        int minCoin = -1;
        for (int j = S - 1; j >= 0; j--) // Empezamos desde la moneda más grande!
        {
            int pos = i - v[j];
            if (pos >= 0 && solucion[pos].F > 0 && solucion[pos].F < min)
            {
                min = solucion[pos].F;
                minCoin = v[j];
            }
        }
        if (minCoin == -1)
            solucion.PB(MP(0, 0));
        else
            solucion.PB(MP(1 + min, minCoin));
    }
    if (solucion[V].F == 0)
    {
        cout << "Imposible"
             << "\n";
        return true;
    }
    // Quitamos el 1 que teniamos de las monedas para llegar a 0 para obtener el número de monedas real
    cout << (solucion[V].F - 1) << ": ";
    vi coins;
    int last = V;

    while (V > 0)
    {
        coins.PB(solucion[V].S);
        V -= solucion[V].S;
    }
    sort(all(coins));
    for (int i = coins.size()-1; i > 0; i--)
    {
        cout << coins[i] << " ";
    }
    cout << coins[0] << "\n";
    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O, BORRAR AL SUBIR
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve())
        ;
}
