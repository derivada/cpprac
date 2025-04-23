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

#define L 0
#define T 1
#define R 2
#define B 3

char esquina_contenida(vector<int> &dim1, vector<int> &dim2, vector<vector<char>> &mat) {
    // esquina TL
    if (dim1[L] <= dim2[L] && dim2[L] <= dim1[R] && dim1[T] <= dim2[T] && dim2[T] <= dim1[B]) {
        //cout << "esquina tl" << endl;
        return mat[dim2[T]][dim2[L]];
    }
    // esquina TR
    if (dim1[L] <= dim2[R] && dim2[R] <= dim1[R] && dim1[T] <= dim2[T] && dim2[T] <= dim1[B]) {
        //cout << "esquina tr" << endl;
        return mat[dim2[T]][dim2[R]];
    }
    // esquina BL
    if (dim1[L] <= dim2[L] && dim2[L] <= dim1[R] && dim1[T] <= dim2[B] && dim2[B] <= dim1[B]) {
        //cout << "esquina bl" << endl;
        return mat[dim2[B]][dim2[L]];
    }
    // esquina BR
    if (dim1[L] <= dim2[R] && dim2[R] <= dim1[R] && dim1[T] <= dim2[B] && dim2[B] <= dim1[B]) {
        //cout << "esquina br" << endl;
        return mat[dim2[B]][dim2[R]];
    }
    return '.';
}

char caso_raro(vi &dim1, vi &dim2, vector<vector<char>> &mat) {
    // caso rectángulo 2 es más alto y 1 más ancho
    if (dim1[T] > dim2[T] && dim1[B] < dim2[B] && dim1[L] > dim2[L] && dim1[R] > dim2[R]) {
        //cout << "caso raro 1" << endl;
        return mat[dim1[T]][dim2[L]];   //devuelve la esquina superior izquierda del subcuadrado
    }
    // caso rectángulo 1 es más alto y 2 más ancho
    if (dim2[T] > dim1[T] && dim2[B] < dim1[B] && dim2[L] > dim1[L] && dim2[R] > dim1[R]) {
        //cout << "caso raro 2" << endl;
        return mat[dim2[T]][dim1[L]];
    }
    return '.';
}

bool intersection(const std::unordered_set<char>& set1, const std::unordered_set<char>& set2) {
    // Iterate through the smaller set for efficiency
    const std::unordered_set<char>& smallerSet = (set1.size() < set2.size()) ? set1 : set2;
    const std::unordered_set<char>& largerSet = (set1.size() < set2.size()) ? set2 : set1;

    for (const char& elem : smallerSet) {
        if (largerSet.find(elem) != largerSet.end()) {
            return true; // Found a common element
        }
    }
    return false; // No common elements
}

void solve() {
    int fil, col;
    cin >> col >> fil;
    vector<vector<char>> mat(fil, vector<char>(col));
    umap<char,bool> visited;
    umap<char,vector<int>> dims;

    unordered_set<char> chars;

    FOR(i,0,fil) {
        FOR(j,0,col) {
            char curr;
            cin >> curr;
            mat[i][j] = curr;
            if (curr == '.')
                continue;
            if (!visited[curr]) {
                visited[curr] = true;
                chars.insert(curr);
                // L T R B
                dims[curr] = vector<int>(4);
                dims[curr][L] = j;
                dims[curr][T] = i;
                dims[curr][R] = j;
                dims[curr][B] = i;
            } else {
                dims[curr][L] = min(j, dims[curr][0]);
                dims[curr][T] = min(i, dims[curr][1]);
                dims[curr][R] = max(j, dims[curr][2]);
                dims[curr][B] = max(i, dims[curr][3]);
            }
        }
    }

    // FOR(i,0,fil) {
    //     FOR(j,0,col) {
    //         cout<<mat[i][j];
    //     }
    //     cout << endl;
    // }

    umap<char, unordered_set<char>> encima;

    for(char curr1: chars) {
        // Esquina contenida
        for(char curr2: chars) {
            if (curr1 == curr2) continue;
            //cout << "comprobando " << curr1 << " con " << curr2 << endl;
            char esquina = esquina_contenida(dims[curr1], dims[curr2], mat);
            if (esquina != '.' && esquina != curr1) {
                encima[curr1].insert(curr2);
            }
            if (esquina == '.') { // este caso solo se puede dar cuando no se da el otro
                esquina = caso_raro(dims[curr1], dims[curr2], mat);
                if (esquina != '.' && esquina != curr1) {
                    encima[curr1].insert(curr2);
                }
            }
        }
    }

    // FOR(i,0,chars.size()) {
    //     cout << "char " << chars[i] << endl;
    //     cout << dims[chars[i]][L] << ' ' << dims[chars[i]][T] << ' ' << dims[chars[i]][R] << ' ' << dims[chars[i]][B] << endl;
    //     cout << "encima: ";
    //     FOR(j,0,encima[chars[i]].size()) {
    //         cout << encima[chars[i]][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int size = chars.size();

    while (chars.size() != 0) {
        vector<char> removal; // Las eliminamos todas al final para que no entren en conflicto
        for(char curr: chars) {
            if (chars.find(curr) == chars.end())
                continue;
            if (!intersection(encima[curr], chars))
                removal.PB(curr);
        }
        sort(all(removal));
        FOR(i,0,removal.size()) {
            char curr = removal[i];
            chars.erase(curr);
            cout << curr;
            if (i != removal.size()-1)
                cout << ' ';
            else
                cout << "\n";
        }
        // Si no se quita ningun posit es imposible
        if (removal.size()==0) {
            cout << "IMPOSIBLE\n";
            chars.clear();
        }
    }

    cout << "----\n";

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

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}