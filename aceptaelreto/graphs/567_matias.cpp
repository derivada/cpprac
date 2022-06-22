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

void dfs_notas(vector<vector<pair<int, int>>> adj, int s, vector<bool> &nota_alumno, vi &visitados)
{
    if (visitados[s])
        return;
    visitados[s] = true;
    for (auto e : adj[s])
    {
        int b = e.F, w = e.S;
        dfs_notas(adj, b, nota_alumno, visitados);
        // Nueva nota detectada
        if (nota_alumno[b] != -1)
            nota_alumno[s] = nota_alumno[b] + w;
    }
}

bool solve()
{
    int V = 0, N = 0, M = 0;
    cin >> V >> N >> M;
    if (!V)
        return false;

    vector<vector<pair<int, int>>> adj; // grafo no dirigido con pesos (pesos aristas = peso de los 2 alumnos juntos)
    adj.resize(V);
    vi nota_alumno(V, -1);
    vector<bool> visitados(V, false); // pesos de los nodos (notas alumnos), visitados para el search

    // Leer exámenes previos y procesar
    for (int i = 0; i < N; i++)
    {
        int per = 0;
        cin >> per;
        if (per == 1)
        { // invididual
            int e1, nota;
            cin >> e1 >> nota;
            nota_alumno[e1 - 1] = nota;
        }
        else
        { // por parejas
            int e1, e2, nota;
            cin >> e1 >> e2 >> nota;
            adj[e1 - 1].PB({e2 - 1, nota});
            adj[e2 - 1].PB({e1 - 1, nota});
        }
    }

    // DFS para hallar todas las notas posibles
    for (int i = 0; i < V; i++)
    {
        if (!visitados[i])
            dfs_notas(adj, i, visitados, nota_alumno);
    }

    // Leer nuevos exámenes y responder
    for (int i = 0; i < N; i++)
    {
        int per = 0;
        cin >> per;
        if (per == 1)
        { // invididual
            int e1;
            cin >> e1;
            if (nota_alumno[e1] != -1)
                cout << nota_alumno[e1] << "\n";
            else
                cout << "CUIDADO\n";
        }
        else
        { // por parejas
            int e1, e2;
            cin >> e1 >> e2;
            if (nota_alumno[e1] != -1 && nota_alumno[e2] != -1)
                cout << (nota_alumno[e1] + nota_alumno[e2]) << "\n";
            else
                cout << "CUIDADO\n";
        }
    }
    cout << "---\n";
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
