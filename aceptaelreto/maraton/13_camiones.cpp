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
vector<vector<pair<int, int>>> adj; // no dirigido, con pesos

int path_with_lowest(int N, int from, int to)
{
    // modified Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vi mayorAncho(N, INT_MIN);
    q.push({0, from});
    mayorAncho[from] = INT_MAX;
    vector<bool> visitados(N, false);
    while (!q.empty())
    {
        auto temp = q.top();
        int a = temp.S;
        q.pop();
        if (visitados[a])
            continue;
        visitados[a] = true;
        for (auto u : adj[a])
        {
            int b = u.F, w = u.S;
            // Relajamos el camino a b más ancho cogiendo el máximo de:
            // Mantener el actual (con ancho mayorAncho[b])
            // Actualizar el actual mirando si el nuevo borde hace el camino hasta b pasando por a de menor ancho mínimo
            int dist = max(mayorAncho[b], min(mayorAncho[a], w));
            if (dist > mayorAncho[b]) // Modificamos, solo queremos el w más pequeño para llegar a b
            {
                mayorAncho[b] = dist;
                q.push({dist, b});
            }
        }
    }
    return mayorAncho[to];
}

bool solve()
{
    // WA, bad approach (this is for directed graphs)
    int V = 0, E = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0;
    cin >> V >> E;
    if (!V)
        return false;
    adj.clear();
    adj.resize(V);
    for (int i = 0; i < E; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1 - 1].PB(MP(tmp2 - 1, tmp3));
        adj[tmp2 - 1].PB(MP(tmp1 - 1, tmp3));
    }
    int K = 0;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        if (tmp3 > path_with_lowest(V, tmp1 - 1, tmp2 - 1)) // El camion es demasiado grande
            cout << "NO\n";
        else
            cout << "SI\n";
    }
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
