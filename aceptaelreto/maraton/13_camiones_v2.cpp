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

// Devuelve el ancho mínimo del camino más ancho de a hasta b
int widest_path(int N, int from, int to)
{
    // En primer lugar, hallar MAXIMUM spanning tree, ayer hicimos MINIMUM
    // Para hallarlo, solo multiplicar bordes por -1 (los leemos así)

    vector<bool> visitados(N, false);                                                  // Nodos visitados
    vector<int> conexiones(N, -1);                                                     // Conexiones finales
    vector<int> value(N, INT_MAX);                                                     // Peso minimo para un nodo
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // Para extraer pesos minimos, formato (PESO, NODO)

    q.push(MP(0, from)); // Meter el nodo fuente 0 y su peso 0
    value[from] = 0;     // El peso minimo para el nodo 0 es 0

    while (!q.empty())
    {
        int a = q.top().S; // Coger el primer nodo de la lista
        q.pop();
        if (!visitados[a])
            visitados[a] = true; // Marcarlo como visitado
        for (auto b : adj[a])    // Todos los vecinos w de a
        {
            int w = b.S;     // Peso de la conexión a->b
            int v = b.first; // Número de nodo
            if (!visitados[v] && value[v] > w)
            {
                value[v] = w;
                conexiones[v] = a;
                q.push(make_pair(value[v], v)); // Actualizamos la cola
            }
        }
    }

    // El camino con mayor ancho es aquel marcado por el MST, hallar el ancho máximo
    if (value[to] == INT_MAX)
        return INT_MIN; // No hay camino

    int anchoMax = INT_MAX;
    while (to != from)
    {
        int peso = 0;
        vector<pair<int, int>> edges = adj[conexiones[to]];
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i].F == to)
            {
                anchoMax = min(anchoMax, -edges[i].S);
                break;
            }
        }
        to = conexiones[to];
    }
    return anchoMax;
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
        adj[tmp1 - 1].PB(MP(tmp2 - 1, -tmp3));
        adj[tmp2 - 1].PB(MP(tmp1 - 1, -tmp3));
    }
    int K = 0;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        if (tmp1 == tmp2) // Caso trivial a-->a
            cout << "SI\n";
        else if (tmp3 > widest_path(V, tmp1 - 1, tmp2 - 1)) // El camion es demasiado grande
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
