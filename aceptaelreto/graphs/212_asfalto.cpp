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

void dfs(vector<vector<int>> graph, int start, vector<bool> &visited, int *visitedCount)
{
    if (visited[start])
        return;
    visited[start] = true;
    (*visitedCount)++;
    for (auto edge : graph[start])
    {
        dfs(graph, edge, visited, visitedCount);
    }
}

bool solve()
{
    // TLE
    int N, E;
    cin >> E;
    if (E == 0)
        return false;
    cin >> N;
    vector<vector<int>> adj; // adj list, no dirigido, sin pesos
    /*
     1. Comprobamos que el grafo sea conexo (con DFS)
     2. Vemos que se cumpla la cond. de camino Euleriano en grafos dirigidos: el grado es par para todos (ciclo euleriano) o es par para todos excepto 2 impares
        (camino euleriano)
     */

    adj.resize(N);
    for (int i = 0; i < E; i++)
    {
        int in, out;
        cin >> in >> out;
        // 0-indexed
        adj[in - 1].PB(out - 1);
        adj[out - 1].PB(in - 1);
    }

    // DFS para conexidad
    int visitedCount = 0;
    vector<bool> visited(N, false);
    dfs(adj, 0, visited, &visitedCount);
    if (visitedCount != N)
    {
        cout << "NO" << "\n"; // no conexo
        return true;
    }

    int odd = 0;
    for (int i = 0; i < N; i++)
    {
        // El grado es el tamaño de su lista de adyacencia (no dirigido)
        if (adj[i].size() % 2 != 0)
        {
            odd++;
            if (odd > 2)
            {
                cout << "NO" << "\n";
                return true;
            }
        }
    }

    if (odd == 1)
    {
        cout << "NO" << "\n";
        return true;
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
