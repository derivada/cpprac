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
// WRONG ANSWER
void solve()
{
    int N = 0, Q = 0, tmp1, tmp2;
    cin >> N >> Q;
    vector<vi> adj;
    adj.resize(N + 1);
    for (int i = 0; i < N-1; i++)
    {
        cin >> tmp1 >> tmp2;
        if(tmp1 < tmp2)
            adj[tmp1].PB(tmp2);
        else
            adj[tmp2].PB(tmp1);
    }
    vector<bool> visitados(N + 1, false);
    vector<int> distancias(N + 1, 0); // También guarda la distancia
    queue<int> q;
    visitados[1] = true;
    q.push(1);
    vi niveles;
    niveles.resize(N+1);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (auto u : adj[s])
        {                     // Vecinos del nodo actual
            visitados[u] = true;
            distancias[u] = distancias[s] + 1;
            niveles[distancias[u]]++;
            q.push(u);
        }
    }
    for(int i = 0; i<Q;i++){
        cin >> tmp1;
    }
    int lvl = 0, result = 0;
    niveles[0] = 1;
    while(Q>0 && lvl < niveles.size()){
        if(Q-niveles[lvl] >= 0){
            result += niveles[lvl];
        }   
        Q-= niveles[lvl];
        lvl++;
    }
    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
        // Archivos I/O, BORRAR AL SUBIR
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    
    for (int t = 1; t <= tc; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
    }
}
