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
bool cmp1(tuple<int, int, int> a, tuple<int, int, int> b){
    // ordenar por dinero ascendente y luego por dias descendente
    if( get<1>(a) == get<1>(b)){
        return  get<0>(a) < get<0>(b);
    }
    return get<1>(a) > get<1>(b);
}
// ACCEPTED 1/3, TLE 2/3
void solve()
{
    int D, N, X;
    cin >> D >> N >> X;
    vector<tuple<int, int, int>> seeds;
    int tmp1, tmp2, tmp3;
    for(int i = 0; i<N; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        seeds.PB(make_tuple(tmp2, tmp3, tmp1)); // format days, money, seeds
    }
    sort(all(seeds), cmp1);
    int profit = 0;
    for(int d = D; d > 0; d--){
        int energy = X;
        int remaining = D - d;
        for(int i = 0; i<N; i++){
            if(get<0>(seeds[i]) > remaining)
                continue;
            // la mejor semilla
            int semillas = get<2>(seeds[i]);
            // plantamos todas las que podamos
            int plantadas = 0;
            if(energy > semillas){
                // sobra energia
                energy -= semillas;
                plantadas = semillas;
                get<2>(seeds[i]) = 0;
            }else{
                // falta energia
                plantadas = energy;
                get<2>(seeds[i]) -= energy;
                energy = 0;
            }
            profit += plantadas * get<1>(seeds[i]);
            if(energy == 0) break; // no plantamos más no hay energía
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
