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
#define M 24
#define N 5
bool solve()
{
    int A = 0;
    cin >> A;
    if (!A)
        return false;
    int a, b, c, d, e;
    a = A % 19;
    b = A % 4;
    c = A % 7;
    d = (19 * a + M) % 30;
    e = (2 * b + 4 * c + 6 * d + N) % 7;
    if (d + e < 10)
    {
        cout << (d + e + 22) << " de marzo\n";
    }
    else
    {
        int fecha = d + e - 9;
        if (fecha == 26)
            cout << "19 de abril\n";
        else if (fecha == 25 && d == 28)
            cout << "18 de abril\n";
        else
            cout << fecha << " de abril\n";
    }
    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (solve())
        ;
}