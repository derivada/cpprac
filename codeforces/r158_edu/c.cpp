#include <bits/stdc++.h>
using namespace std;   // Tipos
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
typedef vector<vector<int>> graph;
typedef vector<vector<pair<int, int>>> wgraph; 
#define umap unordered_map
#define uset unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())  
#define all(a) (a).begin(), (a).end() // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = b-1; i>=0; i--)

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    ll max_a = 0, min_a = 10e12;
    FOR(i, 0, n){
        cin >> v[i];
        min_a = min(v[i], min_a);
        max_a = max(v[i], max_a);
    } 

    ll diff = max_a - min_a;
    if(diff == 0){
        cout << "0\n";
        return;
    }
    int ops = floor(log(diff) / log(2)) + 1;

    cout << ops << endl;
    if(ops > n) 
        return;
    ll new_min = 1e12;
    // wrong answer test 3
    for(int j = 0; j < ops; j++) {
        // use x = last_min
        for(int i = 0; i < n; i++) {
            v[i] = (v[i] + min_a) / 2;
            new_min = min(v[i], new_min);
        }
        if(j < ops-1)
            cout << min_a << " ";
        else
            cout << min_a << endl;
        min_a = new_min;
    }
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
