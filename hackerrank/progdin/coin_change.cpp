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

long getWays(int n, vector<long> c) {
    long ways[n+1];
    ways[0] = 1L;
    for(int i = 1; i <= n; i++){
        ways[i] = 0L;
        for(auto coins: c){
            if(i - coins >= 0){
                ways[i] += ways[i - coins];
            }
        }
    }
    return ways[n];
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O, borrar al subir
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, c_size, tmp;
    vector<long> c;
    cin >> n;
    cin >> c_size;
    for (int i = 0; i < c_size; i++)
    {
        cin >> tmp;
        c.PB(tmp);
    }

    cout << getWays(n, c) << endl;
}

