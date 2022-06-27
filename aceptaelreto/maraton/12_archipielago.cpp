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
    int I = 0, P = 0, tmp1, tmp2, tmp3;
    cin >> I >> P;
    if (!I)
        return false;
    vector<vector<pair<int, int>>> adj; // No dirigido, con pesos
    adj.resize(I);                      // I nodos
    for (int i = 0; i < P; i++)         // P aristas
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1 - 1].PB(MP(tmp2 - 1, tmp3));
        adj[tmp2 - 1].PB(MP(tmp1 - 1, tmp3));
    }
    int visitadosTotal = 0;
    vector<bool> visitados(I, false);                                                  // Nodos visitados
    vector<int> conexiones(I, -1);                                                     // Conexiones finales
    vector<int> value(I, INT_MAX);                                                     // Peso minimo para un nodo
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // Para extraer pesos minimos, formato (PESO, NODO)

    q.push(MP(0, 0)); // Meter el nodo fuente 0 y su peso 0
    value[0] = 0;     // El peso minimo para el nodo 0 es 0

    while (!q.empty())
    {
        int a = q.top().S; // Coger el primer nodo de la lista
        q.pop();
        if (!visitados[a])
        {
            visitados[a] = true; // Marcarlo como visitado
            visitadosTotal++;
        }
        for (auto b : adj[a]) // Todos los vecinos w de a
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
    // Si no todos los nodos fueron visitados, era imposible
    if (visitadosTotal < I)
    {
        cout << "No hay puentes suficientes\n";
    }
    else
    { // Si fueron visitados, devolver la suma de las conexiones finales

        int total = 0;
        for (int i = 0; i < I; i++)
            total += value[i];
        cout << total << "\n";
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

