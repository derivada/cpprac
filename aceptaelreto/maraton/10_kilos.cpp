#include <bits/stdc++.h>
using namespace std;

// Es bueno desactivarlas para debuggear
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
    // WA, no pude resolverlo :(
    int K = 0, N = 0, tam, result;
    int max_r = 0, max_e = 0, rep_max_r = 0, rep_max_e = 0;
    char cubo;
    cin >> K >> N;
    if (!K)
        return false;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        cin >> tam >> cubo;

        if (cubo == 'R')
        {
            v.PB(MP(tam, 0));

            if (tam > max_r)
            {
                max_r = tam;
                rep_max_r = 0;
            }
            else if (tam == max_r)
            {
                rep_max_r++;
            }
        }
        else
        {
            v.PB(MP(0, tam));

            if (tam > max_e)
            {
                max_e = tam;
                rep_max_e = 0;
            }
            else if (tam == max_r)
            {
                rep_max_e++;
            }
        }
    }

    result = max(max_r, (int)ceil(max_e / 2.0));

    // float conrep = max_r * rep_max_r;
    // float tienequecaber = conrep / K;
    // result = max(result, max_r * (int)ceil(tienequecaber / max_r));

    // conrep = ceil(max_e / 2.0) * rep_max_e;
    // tienequecaber = conrep / K;
    // result = max(result, (int)ceil(max_e / 2.0) * (int)ceil(tienequecaber / ceil(max_e / 2.0)));

    while (1)
    {
        // Tratar de resolver
        int actualE = 0, actualR = 0, tirados = 1; // Se empieza a 1 por el final que siempre hay que tirarlo
        for (int i = 0; i < N; i++)
        {
            int R = v[i].F, E = v[i].S;
            if (actualR + R > result || actualE + E > 2 * result)
            {
                // Tirar por residuos
                tirados++;
                if (tirados > K) // Ya se tiro más de K veces --> probaremos el siguiente limite de peso
                {
                    result++;
                    break;
                }
                actualE = E, actualR = R;
                continue;
            }
            else if (actualR + R == result || actualE + E == 2 * result)
            {
                // tirar pero esta justo y queda a 0 para la siguiente
                tirados++;
                if (tirados > K)
                {
                    result++;
                    break;
                }
                actualE = actualR = 0;
                continue;
            }
            actualR += R;
            actualE += E;
        }

        if (tirados <= K)
        {
            cout << result << "\n";
            break;
        }
    }
    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Número de casos
    while (solve())
        ;
}