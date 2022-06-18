#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ar array
#define ll long long   // 64 bits
#define ld long double // 80 bits
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() // Todo el array, e.g. sort(all(a))

#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 1e9 + 7;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;        // Infinito
const ld EPS = 1e-9;       // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

// Vectores y pares de enteros
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

// Bucles
#define FOR(i, a, b) for (int i = a; i <= b; i++)

void generate()
{
    srand(time(NULL));
    int N = 1000;
    cout << N << "\n";
    int max = rand() % 900 + 100;
    int prev = rand() % max;
    cout << prev;
    for (int i = 0; i < N-1; i++)
    {
        int next = (prev + rand() % max);
        cout << " " << next;
        prev = next;
    }
    cout << "\n"
         << (rand() % 90 + 10);
    for (int i = 0; i < N - 2; i++)
    {
        cout << " " << (rand() % 90 + 10);
    }
    cout << " " << 0 << "\n";
    cout << max;
}

int main()
{
    // Optimizacion I/O{...}
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O
    freopen("input.txt", "w", stdout);
    generate();
}
