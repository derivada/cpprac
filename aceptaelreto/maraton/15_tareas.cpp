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

bool solve()
{
    int N = 0, M = 0, T = 0, tmp1, tmp2, tmp3;
    cin >> N >> M >> T;
    if (!N && !M && !T)
        return false;
    // vector<pair<int, int>> noPeriod;     // start end
    vector<pair<int, pair<int, int>>> events, checkedEvents; // period start end, si son no periodicos period = INF
    for (int i = 0; i < N; i++)
    {
        cin >> tmp1 >> tmp2;
        events.PB(MP(INT_MAX, MP(tmp1, tmp2)));
    }
    for (int i = 0; i < M; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        events.PB(MP(tmp3, MP(tmp1, tmp2)));
    }
    sort(all(events));
    reverse(all(events));
    for (int i = 0; i < (N + M); i++)
    {
        int p1 = events[i].F;
        int s1 = events[i].S.F;
        int e1 = events[i].S.S;
        
        // Check for conflicts
        bool flag = false;
        for (int i = 0; i < checkedEvents.size(); i++)
        {
            int p2 = checkedEvents[i].F;
            int s2 = checkedEvents[i].S.F;
            int e2 = checkedEvents[i].S.S;
            // Checkear conflicto 
            
            (s2 - s1) % p1 >= e1
            (e2 - s1) % p1 >= e1
            
        }
        if(flag){
            cout << "SI\n";
            return true;
        }

    }
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
