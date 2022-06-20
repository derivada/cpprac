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

bool solve()
{
    int s = 0, sum = 0;
    scanf("%d", &s);
    if (!s)
        return false;
    int tmp = 0;
    while (1)
    {
        scanf("%d", &tmp);
        if (tmp == 0)
            break;
        sum += tmp;
    }
    sum *= s;
    int seg = sum % 60;
    sum /= 60;
    int min = sum % 60;
    sum /= 60;
    printf("%02d:%02d:%02d\n", sum, min, seg);
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
