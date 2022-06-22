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
    // WA
    int N = 0, M = 0, tmp;
    long total = 0;
    cin >> N >> M;
    if (!N)
        return false;
    vi v;
    if (N == 1)
        return 0;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.PB(tmp);
    }
    sort(all(v));
    for (int i = 0; i < N - 2; i++)
    {
        // Busqueda binaria en el slice del array v[i+1..N] al elemento y0 tal que M - v[i] = y0
        // Si no existe, y0 > M -v[i] más cercano
        if (v[i] * 2 > M)
            break;
        int low = min(i + 1, N - 1), high = N - 1, k = (low + high) / 2;
        while (low < high)
        {
            if (v[k] == M - v[i])
            {
                break;
            }
            else if (v[k] > M - v[i])
            {
                high = k - 1;
            }
            else
            {
                low = k + 1;
            }
            k = (low + high) / 2;
        }
        // fine tune
        while (k > i && v[k] + v[i] > M)
        {
            k--;
        }
        if (k - i > 0)
            total += k - i;
    }
    if (v[N - 2] + v[N - 1] <= M)
        total++;
    cout << total << "\n";

    return true;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O, BORRAR AL SUBIR
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve())
        ;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << duration.count() << " ms" << endl;
}
