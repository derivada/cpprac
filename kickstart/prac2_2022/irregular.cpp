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

void solve()
{
    string s;
    cin >> s;
    for (int k = 0; k < s.length() - 4; k++)
    {
        // WIP https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b55464
        int i = k, voc = 0;
        while (i <= s.length() - 4 && voc < 2)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                voc++;
            i++;
        }
        if (voc < 2)
            break;
        int len = i - k;
        i--;
        for (; (i + k) < s.length() - 4; i++)
        {
            for (int j = s.length() - 1; i < (j - len - 1); j--)
            {
                bool flag = true;
                for (int b = 0; b < len; b++)
                {
                    if (s[b] != s[j - len + 1 + b])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    cout << "Spell!\n";
                    return;
                }
            }
        }
        if (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u')
        {
            break;
        }
    }
    cout << "Nothing.\n";
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
    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
    }
}
