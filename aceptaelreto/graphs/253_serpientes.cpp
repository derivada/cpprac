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
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for (int i = a; i <= b; i++)

bool solve()
{
    // WA, tiempo alto
    int N, K, S, E;
    scanf("%d %d %d %d", &N, &K, &S, &E);
    if (!N)
        return false;
    int size = N * N;
    vector<vector<pair<int,int>>> adj; // peso 1 para dados, peso 0 para S/E
    adj.resize(size);

    for (int i = 0; i < size; i++)
    {
        // añadir a cada casilla del grafo las alcanzables por dado
        for (int j = i + 1; j < min(i + K + 1, size); j++)
        {
            adj[i].PB(MP(j, 1));
        }
    }

    for (int i = 0; i < (S + E); i++)
    {
        // añadir escaleras / serpientes
        int from, to;
        scanf(" %d %d", &from, &to);
        adj[from - 1].PB(MP(to - 1, 0));
    }

    // dijkstra camino minimo desde 0 hasta el final
    vi dist(size, INT_MAX);
    vi parent(size, -1);
    vector<bool> procesados(size, false);
    priority_queue<pair<int, int>> q;

    dist[0] = 0;
    q.push({0, 0}); // dist 0 al nodo 0
    while (!q.empty())
    {
        int a = q.top().second; // nodo con dist actual minima
        q.pop();
        if (procesados[a])
            continue;
        procesados[a] = true;
        for (auto e : adj[a])
        { // nodos salientes
            int b = e.first, w = e.second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                parent[b] = a;
                q.push({-dist[b], b});
            }
        }
    }
    
    int tmp = size - 1;
    stack<int> camino;
    cout << "DEBUG, CAMINO 0 hasta 100 (al revés): ";
    camino.push(tmp + 1);
    while (parent[tmp] != -1)
    {
        camino.push(parent[tmp] + 1);
        tmp = parent[tmp];
    }

    while (!camino.empty())
    {
        cout << camino.top() << " ";
        camino.pop();
    }

    cout << endl;
    
    cout << dist[size - 1] << "\n";
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
