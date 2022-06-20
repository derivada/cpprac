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

bool bfs_bipart(vector<vector<int>> adj, int s, vi &colors, int initColor)
{
    // Hay 2 colores, 1 y -1. Actua también como visited[], ya que al principio no hemos coloreado y todos son 0 (no visitados)
    colors[s] = initColor;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (auto t : adj[f])
        {
            if (f == t)
                return false; // self loop

            if (colors[t] == 0)
            { // sin colorear
                colors[t] = -colors[f];
                q.push(t);
            }
            else if (colors[f] == colors[t])
            {
                return false;
            }
        }
    }
    return true;
}

bool solve()
{
    int V = 0, A = 0;
    cin >> V;
    if (!V)
        return false;
    cin >> A;
    vector<vector<int>> adj;
    adj.resize(V);

    for (int i = 0; i < A; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].PB(to);
                adj[to].PB(from);
    }

    // grafo bipartito -> se puede colorear con 2 colores sin aristas que conecten colores iguales
    vi colors(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (colors[i] == false) {
            if (!bfs_bipart(adj, i, colors, 1))
            {
                cout << "NO" << "\n";
                return true;
            }
        }
    }
    cout << "SI" << "\n";
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