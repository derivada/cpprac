#include <bits/stdc++.h>
using namespace std;

// Es bueno desactivarlas para debuggear
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

// Tipos>
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
#define FOR(i, a, b) for (int i = a; i < b; i++)

int maxdiff(int first, int second, int third)
{
    int diff21 = abs(second - first);
    int diff32 = abs(third - second);
    int diff31 = abs(third - first);
    return max(max(diff32, diff21), diff31);
}

bool solve()
{
    // WA
    int N = 0;
    cin >> N;
    if (!N)
        return false;
    vi por;
    por.resize(N);

    int tmp = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        por[i] = tmp;
        sum += tmp;
    }

    
    int i = 0, j = N - 1, limit = N;
    ll first = por[i], third = por[j];
    ll second = sum - first - third;
    ll max = maxdiff(first, second, third), newDiffR = 0, newDiffL = 0;
    while (i < j - 1 && limit >= 0)
    {
        limit--;
        // Probar mover i a la derecha
        newDiffR = maxdiff(first + por[i + 1], second - por[i + 1], third);
        // Probar mover j a la izquierda
        newDiffL = maxdiff(first, second - por[j - 1], third + por[j - 1]);

        if (newDiffR <= max && newDiffR <= newDiffL)
        {
            max = newDiffR;
            i++;
            first += por[i];
            second -= por[i];
            continue;
        }

        if (newDiffL <= max && newDiffL <= newDiffR)
        {
            max = newDiffL;
            j--;
            second -= por[j];
            third += por[j];
            continue;
        }
    }
    cout << max << "\n";
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

    // Número de casos
    while (solve())
        ;
}
