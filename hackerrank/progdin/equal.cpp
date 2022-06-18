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

map<vector<int>, int> moves;

int equal(vector<int> arr)
{
    int check = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[0])
        {
            check = 0;
            break;
        }
    }
    if (check)
        return 0;
    else
    {
        if (moves.find(arr) != moves.end())
        {
            return moves.find(arr)->second;
        }
        else
        {
            int minMoves = 100000;
            for (int i = 0; i < arr.size(); i++)
            {
                if(arr[i] <= 0) continue;
                vector<int> nuevo;
                nuevo = arr;
                nuevo[i] -= 1;
                int m = equal(nuevo);
                if (m < minMoves)
                    minMoves = m;
                nuevo[i] -= 1;
                m = equal(nuevo);
                if (m < minMoves)
                    minMoves = m;
                nuevo[i] -= 3;
                m = equal(nuevo);
                if (m < minMoves)
                    minMoves = m;
            }
            moves[arr] = minMoves + 1;
        }
    }
}

int solve()
{
    int n = 0, tmp = 0;
    vector<int> c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        c.push_back(tmp);
    }
    cout << equal(c) << "\n";
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O, borrar al subir
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
