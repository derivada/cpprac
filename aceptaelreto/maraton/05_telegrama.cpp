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

unordered_map<int, char> traduccion = {
    {'A', 5},
    {'B', 9},
    {'C', 11},
    {'D', 7},
    {'E', 1},
    {'F', 9},
    {'G', 9},
    {'H', 7},
    {'I', 3},
    {'J', 13},
    {'K', 9},
    {'L', 9},
    {'M', 7},
    {'!', 19},
    {'N', 5},
    {'O', 11},
    {'P', 11},
    {'Q', 13},
    {'R', 7},
    {'S', 5},
    {'T', 3},
    {'U', 7},
    {'V', 9},
    {'W', 9},
    {'X', 11},
    {'Y', 13},
    {'Z', 11},
    {'?', 15},
    {' ', -1}}; // 3 (separación entre letra anterior) + 3 (separación de esta letra) - 1 = 5

void solve()
{
    string line;
    int points = -3; // Para quitar separación de la última letra 
    getline(cin, line);
    for (int i = 0; i < line.size(); i++)
        points += traduccion.find(line[i])->second + 3;
    cout << points << "\n";
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // Número de casos
    int tc = 0;
    cin >> tc;
    string s;
    getline(cin, s);
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
