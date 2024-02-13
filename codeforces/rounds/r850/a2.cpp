#include <bits/stdc++.h>
using namespace std;

// // Es bueno desactivarlas para debuggear
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
#define FOR(i, a, b) for(int i = a; i<= b; i++)

void solve()
{
    int n = 0, aw = 0, ab = 0, bw = 0, bb = 0, count = 1, sum = 0;
    cin >> n;
    while(n - count >= 0){
        n -= count;
        if(count % 4 <= 1){
            // alice
            aw += count / 2;
            ab += count / 2;
            if(count % 2 == 1 && sum % 2 == 0)
                aw++;
            else if(count % 2 == 1&& sum % 2 == 1) 
                ab++;
        }else{
            // bob
            bw += count / 2;
            bb += count / 2;
            if(count % 2 == 1 && sum % 2 == 0)
                bw++;
            else if(count % 2 == 1&& sum % 2 == 1) 
                bb++;
        }
        sum+=count;
        count++;
    }
    if(count % 4 <= 1){
        aw += n / 2;
        ab += n / 2;
        if(n % 2 == 1 && sum % 2 == 0)
            aw++;
        else if(n % 2 == 1&& sum % 2 == 1) 
            ab = 1;
    }else{
        bw += n / 2;
        bb += n / 2;
        if(n % 2 == 1 && sum % 2 == 0)// first black
            bw++;
        else if(n % 2 == 1&& sum % 2 == 1) // first white
            bb++;
    }
    cout << aw << " " << ab << " " << bw << " " << bb << "\n";
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
