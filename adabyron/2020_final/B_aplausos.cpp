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
#define FOR(a, b) for (int i = a; i < b; i++)
#define ROF(a, b) for (int i = n; i > a; i--)
#define EACH(n) for (int i = 0; i < n; i++)

bool solve()
{
    int N = 0, tmp1, tmp2, total = 0;
    priority_queue<pair<int, int>> v;
    cin >> N;
    if (!N)
        return false;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp1 >> tmp2;
        // Se pone el - para cambiar el orden de la prio_queue, que siempre quita el máximo
        v.push({-tmp1, tmp2});
    }
    while (!v.empty())
    {
        auto a = v.top();
        v.pop();
        a.first += total;
        if (a.first <= 0 && N >= a.second) // no para de aplaudir por falta de ruido, sumar tiempo
            total -= a.first; // Invertir el signo
        N--;
    }
    cout << total << "\n";
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
