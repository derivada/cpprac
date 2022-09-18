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
// RUNTIME ERROR
void solve()
{
    int D, N, X;
    cin >> D >> N >> X;
    int cantidad, dias, valor;
    priority_queue<tuple<int, int, int>> semillas;
    for (int i = 0; i < N; i++)
    {
        cin >> cantidad >> dias >> valor;
        semillas.push(make_tuple(valor, cantidad, dias));
    }
    vi energias(N + 1, X);
    long profit = 0;
    for (int i = 0; i < N; i++)
    {
        tuple<int, int, int> a = semillas.top();
        semillas.pop();
        // encontrar el ultimo dia en que podamos plantarla y aun tengamos energia
        for (int d = D - get<2>(a); d > 0; d--)
        {
            int plantadas = 0;
            if (energias[d] == 0)
            {
                continue;
            }
            else if (energias[d] > get<1>(a))
            { // sobra energia
                energias[d] -= get<1>(a);
                profit += get<0>(a) * get<1>(a);
                break; // siguiente semilla
            }
            else
            { // falta energia
                profit += get<0>(a) * energias[d];
                get<1>(a) -= energias[d];
                energias[d] = 0;
            }
        }
    }
    cout << profit << endl;
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
