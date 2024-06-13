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

#define debug(x) cout << #x << " is " << x << endl

// Bucles
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = b-1; i>=0; i--)

void solve() {
    int n;

    cin >> n;

    int phase = 0;

    int curr, prev;

    cin >> prev;

    int flip, a=0, b=0;

    bool good = true;

    FOR (i,1,n) {
        cin >> curr;

        switch (phase) {
            case 0:
                if (prev > curr) {
                    phase = 1;
                    flip = prev;
                    a = i-1;
                }
                break;
            case 1:
                b = i;
                if (prev < curr) {
                    if (flip > curr)
                        phase = 4;
                    else {
                        phase = 2;
                        prev = flip;
                        b--;
                    }
                }
                break;
            case 2:
                if (prev > curr)
                    phase = 4;

        }
        prev = curr;
    }

    if (phase != 4)
        cout << "yes\n" << a+1 << ' ' << b+1 << '\n';
    else
        cout << "no\n";

}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    solve();
}