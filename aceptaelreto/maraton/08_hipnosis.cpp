#include <bits/stdc++.h>
using namespace std;

// Es bueno desactivarlas para debuggear
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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

// Contar cuantos números contamos por no tener el dígito D
long countNumbersWithoutD(long N, int D)
{
    if (N < 10)
    {
        if (N < D || D == 0)
            return N;
        return N - 1;
    }

    int d = -1; // Número de dígitos - 1
    long tmp = N;
    while (tmp > 0)
    {
        tmp = tmp / 10;
        d++;
    }

    // count(10^d) =   9 * count(10^d - 1) + 10^d - 1
    long d10 = 1;
    int count = 1;
    for (int i = 2; i <= d; i++)
    {
        d10 *= 10;
        count = count * 9 + d10;
    }

    long p = d10 * 10;
    int msd = N / p;
    assert(N % p < N);
    if (msd == D)
        return (N - N % p) - msd * count - 1;
    else if (msd > D)
        return (N - N % p) - (msd - 1) * count - p + countNumbersWithoutD(N % p, D);
    else
        return (N - N % p) - msd * count + countNumbersWithoutD(N % p, D);
}

bool solve()
{
    // WA / TLE
    long N = 0;
    int D = 0;
    cin >> N >> D;
    if (!N)
        return false;
    long contados = countNumbersWithoutD(N, D);
    long faltan = N - contados;
    long lim = N + faltan;
    // buscamos en los que nos faltan a ver cuántos podemos sumar
    int lastlim = -1;
    int i = 0;
    while (faltan > 0)
    {
        long tmp = contados;
        contados = countNumbersWithoutD(lim, D);
        faltan -= contados - tmp;
        lastlim = lim;
        lim += faltan;
        i++;
    }
    cout << lim << "\n";
    return true;
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

    while (solve())
        ;

}
