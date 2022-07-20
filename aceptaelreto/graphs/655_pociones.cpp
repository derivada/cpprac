#include <bits/stdc++.h>
using namespace std;

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

void topSort(int v, vector<vector<pair<int, int>>> &adj, vector<bool> &visitados, stack<int> &s)
{
    visitados[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int node = adj[v][i].F;
        if (!visitados[node])
            topSort(node, adj, visitados, s);
    }
    s.push(v);
}

bool solve()
{
    // wa :(
    int N = 0, E = 0, tmp1, tmp2, tmp3;
    cin >> N >> E;
    if (!N && !E)
        return false;
    vector<vector<pair<int, int>>> adj;
    adj.resize(N + 1);
    for (int i = 0; i < E; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].PB({tmp2, tmp3});
    }

    vector<bool> visitados(N + 1, false);
    stack<int> s;
    vi path(N + 1, 0);
    vi dist(N + 1, 0);
    int a = 1, bestDist = 0, bestEnd = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visitados[i])
            topSort(i, adj, visitados, s);

        while (!s.empty())
        {
            int from = s.top();
            s.pop();
            for (auto e : adj[from])
            {
                int to = e.F, w = e.S;
                int newDist = dist[from] + w;
                if (dist[to] < newDist || (dist[to] == newDist && from < path[to]))
                {
                    path[to] = from;
                    dist[to] = newDist;
                    if (bestDist < dist[to] || (bestDist == dist[to] && to < bestEnd))
                    {
                        bestEnd = to;
                        bestDist = dist[to];
                    }
                }
            }
        }
    }
    cout << bestDist << "\n";
    stack<int> finalPath;
    while (bestEnd)
    {
        finalPath.push(bestEnd);
        bestEnd = path[bestEnd];
    }
    int ps = finalPath.size();
    for (int i = 0; i < ps - 1; i++)
    {
        cout << finalPath.top() << " ";
        finalPath.pop();
    }
    cout << finalPath.top() << "\n";
    finalPath.pop();
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
    while (solve())
        ;
}
