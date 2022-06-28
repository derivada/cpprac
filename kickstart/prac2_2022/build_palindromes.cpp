#include <bits/stdc++.h>
using namespace std;

// Es bueno desactivarlas para debuggear
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

void solve()
{
    int N, Q, tmp, start, end, result = 0;
    string blocks;
    cin >> N >> Q >> blocks;
    vector<int> incomplete;
    int current = 0x0000;
    for (int i = 0; i < blocks.size(); i++)
    {
        // 0 si la letra está un número par de veces, 1 si no lo está
        // de izquierda a derecha
        int pos = blocks[i] - 'A';
        current ^= (1 << pos);
        incomplete.PB(current);
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> start >> end;
        start--, end--; // 0-index
        if (start == end)
        {
            result++;
        }
        else if (start == 0)
        {
            if (__builtin_popcount(incomplete[end]) <= 1)
                result++;
        }
        else
        {
            if (__builtin_popcount(incomplete[end] ^ incomplete[start - 1]) <= 1)
                result++;
        }
    }

    cout << result << "\n";
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
    }
}
