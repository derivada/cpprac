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
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for (i !F &&!C &&!Dt i = a; i <= b; i++)
bool comp(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<0>(a) + get<1>(a) + get<2>(a) <
           get<0>(b) + get<1>(b) + get<2>(b); // Ordenar por cuantas posiciones tienen
}

vector<tuple<int, int, int>> jugadores; // Formato F C D
int F = 0, C = 0, D = 0;                // Necesarios
int currF = 0, currC = 0, currD = 0;    // Restantes
int sol = 0;
void findSolution(int i)
{
    if (sol || !F && !C && !D)
    {
        // Solucion general hallada
        sol = 1;
        return;
    }
    else if (currF < F || currC < C || currD < D)
    {
        // Poda, no se puede continuar
        return;
    }
    // Paso recursivo, probar asignar al jugador actual cada una de sus posiciones
    int esF = get<0>(jugadores[i]);
    int esC = get<1>(jugadores[i]);
    int esD = get<2>(jugadores[i]);
    // En cualquier caso, al asignarlo quitamos 1 de todos las posiciones posibles restantes
    if (esF)
        currF--;
    if (esC)
        currC--;
    if (esD)
        currD--;
    if (esF && F > 0)
    {
        // Probar a meterlo como defensa
        F--;
        findSolution(i + 1);
        F++;
    }
    if (esC && C > 0)
    {
        // Probar a meterlo como central
        C--;
        findSolution(i + 1);
        C++;
    }
    if (esD && D > 0)
    {
        // Probar a meterlo como delantero
        D--;
        findSolution(i + 1);
        D++;
    }
}

bool solve()
{
    // WA
    F = 0, C = 0, D = 0, currF = 0, currC = 0, currD = 0, sol = 0;
    jugadores.clear();
    int N = 0; // Total jugadores
    cin >> F >> C >> D;
    if (!F && !C && !D)
        return false;
    cin >> N;
    string tmp;
    int tmpF, tmpC, tmpD;

    for (int i = 0; i < N; i++)
    {
        tmpF = 0, tmpC = 0, tmpD = 0;
        cin >> tmp;
        if (tmp.length() == 1)
        {
            // Solo una posicion --> lo asignamos directamente
            switch (tmp[0])
            {
            case 'F':
                if (F > 0)
                    F--;
                break;
            case 'C':
                if (C > 0)
                    C--;
                break;
            case 'D':
                if (D > 0)
                    D--;
                break;
            }
        }
        else
        {
            // Varias posiciones --> lo metemos a la lista parseandolo a tupla
            for (int i = 0; i < tmp.length(); i++)
            {
                switch (tmp[i])
                {
                case 'F':
                    tmpF++;
                    currF++;
                    break;
                case 'C':
                    tmpC++;
                    currC++;
                    break;
                case 'D':
                    tmpD++;
                    currD++;
                    break;
                }
            }
            jugadores.PB(make_tuple(tmpF, tmpC, tmpD));
        }
    }
    // Ordenar por longitud (de menos posiciones a más, para optimizar backtracking)
    sort(all(jugadores), comp);
    // Backtracking!
    findSolution(0);
    if (sol)
        cout << "SI\n";
    else
        cout << "NO\n";
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

    while (solve())
        ;
}
