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

vector<vi> adj;
int N;
bool ciclo = false;
void topologicalSortUtil(int v, vector<bool> &visitados, vector<bool> &onStack, stack<int> &s)
{
    // DFS pero se mete al stack de resultados después de visitar cada vecino
    visitados[v] = true;
    onStack[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int node = adj[v][i];
        if (!visitados[node])
            topologicalSortUtil(node, visitados, onStack, s);
        else if (onStack[node])
            ciclo = true; // Deteccion de ciclos, nodo ya visitado y en el stack de llamadas
    }
    s.push(v);
    onStack[v] = false;
}

void topologicalSort()
{
    stack<int> s;                     // Resultados
    vector<bool> visitados(N, false); // Visitados
    vector<bool> onStack(N, false);
    // Llamamos al DFS
    for (int i = 1; i < N; i++)
    {
        if (!visitados[i])
            topologicalSortUtil(i, visitados, onStack, s);
        if (ciclo)
        {
            cout << "Ciclo detectado\n";
            return;
        }
    }
    // Damos la vuelta al stack para obtener el sort topologico
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

bool solve()
{
    N = 0, ciclo = false;
    int E = 0, tmp1, tmp2;
    cin >> N;
    if (!N)
        return false;
    cin >> E;
    adj.clear();
    adj.resize(N + 1);
    for (int i = 0; i < E; i++)
    {
        cin >> tmp1 >> tmp2;
        adj[tmp1].PB(tmp2);
    }
    topologicalSort();

    // Caminos del nodo 1 hasta el nodo i
    // Prog dinamica!
    // paths(x) = paths(a1) + ... + paths(an) a1,...,an nodos con arista hasta x
    vi paths(N, 0);
    // Empezamos desde el principio de la lista de top. sort y vamos hasta adelante
    paths[1] = 1; // 1 camino hasta el origen
    for(int i = 2; i<N;i++){
        for(int j = 0; j<N; j++){ // momento lista de adyacencia
            if(adj[j][i]){
                paths[i]+=paths[j];
            }
        }
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
