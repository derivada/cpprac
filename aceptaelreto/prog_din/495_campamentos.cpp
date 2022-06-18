#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ar array
#define ll long long   // 64 bits
#define ld long double // 80 bits
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() // Todo el array, e.g. sort(all(a))

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

bool solve()
{
    int N = 0, max = 0, tmp = 0;
    cin >> N;
    if (!N)
    { // fin de la entrada
        return false;
    }

    vi camp, costes, costesMinimos;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        camp.PB(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        costes.PB(tmp);
        costesMinimos.PB(0);
    }

    cin >> max;
    // Calculamos los costes mínimos de los campamentos en los que se puede comenzar
    int i = 0;
    while (camp[i] <= max)
    {
        costesMinimos[i] = costes[i];
        i++;
    }

    for (; i < N; i++)
    {
        // costeMinimo[i] es el coste para llegar al campamento i, el costeMinimo[N] es el resultado
        // costeMinimo[i] = min_k (de los k que cucmplen camp[i] - camp[k] < max) (costeMinimo[i-k] + coste[i])
        int minAnterior = 1000000, k = i - 1;
        while (k >= 0 && camp[i] - camp[k] <= max)
        {
            if (costesMinimos[k] < minAnterior)
                minAnterior = costesMinimos[k];
            k--;
        }
        costesMinimos[i] = minAnterior + costes[i];
    }
    cout << costesMinimos[N - 1] << "\n";
    return true;
}

int main()
{
    // Optimizacion I/O{...}
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
