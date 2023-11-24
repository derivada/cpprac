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
    int n;
    cin >> n;
    vi v(n, 0);
    FOR(i, 0, n) cin >> v[i];

    int result = v[0], lastSeq = 0;
    for(int i = 1; i <=n; i++) {
        // check until not alternating
        if(i == n || (v[i] % 2) == (v[i-1] % 2) || (v[i] % 2) == -(v[i-1] % 2)) {
            // check if all array is negative
            // analyze the subsequence
            int max_sum = -INF;           
            int curr_sum = 0;
            int max_elem = -INF;
            bool allNeg = true;
            for(int j = lastSeq; j<i; j++){
                curr_sum += v[j];
                if(v[j] >= max_elem)
                    max_elem = v[j];
                if(v[j] >= 0)
                    allNeg = false;
                if(max_sum < curr_sum) // replace
                    max_sum = curr_sum;
                if(curr_sum < 0){ // restart seq.
                    curr_sum = 0;
                }
            }

            if(allNeg && result < max_elem){
                result = max_elem;
            }
            else if(result < max_sum)
                result = max_sum;
            
            lastSeq = i;
        }
    }
    cout << result << endl;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
