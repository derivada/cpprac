#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#define ll long long 
#define ld long double 
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> grunw;
typedef vector<vector<pair<int, int>>> grw;
#define umap unordered_map
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

bool solve()
{
    int N = 0;
    cin >> N;
    if(!N)
    return false;
    vector<vi> mat;
    mat.resize(N);
    int tmp, in_range = 1;
    for(int i = 0; i<N*N; i++){
        cin >> tmp;
        mat[i / N].PB(tmp);
        if(tmp <= 0 || tmp > N*N)
            in_range = 0;
    }
    // checkear diabolico
    int cm = 0, diag_1 = 0, diag_2 = 0;
    vi col_sums(N, 0);
    // primera fila para sacar constante
    for(int j = 0; j<N; j++){
        cm += mat[0][j];
        col_sums[j] += mat[0][j];
    }
    diag_1 += mat[0][0];
    diag_2 += mat[N-1][0];
    for(int i = 1; i<N; i++){
        int row_sum = 0;
        for(int j = 0; j<N; j++){
            row_sum += mat[i][j];
            col_sums[j] += mat[i][j]; // better efficiency because direct column sums are terrible for the hardware
        }
        diag_1 += mat[i][i];
        diag_2 += mat[N-1-i][i];
        // filas
        if(cm != row_sum){
            cout << "NO" << "\n";
            return true;
        }
    }
    // columnas
    for(int j = 0; j<N; j++){
        if(cm != col_sums[j]){
            cout << "NO" << "\n";
            return true;
        }
    }
    // diagonales
    if(cm != diag_1 || cm != diag_2){
        cout << "NO" << "\n";
        return true;
    }

    // esoterico
    int cm2 = 4 * cm / N;
    // cifras
    vi cifras(N*N + 1, 0);
    int count = N*N;
    if(in_range){
        for(int i = 0; i<N;i++){
            for(int j = 0; j<N; j++){
                if(cifras[mat[i][j]] == 0){
                    cifras[mat[i][j]] = 1;
                    count--;
                }
            }
        }
    }

    if(!in_range || count){
        cout << "DIABOLICO" << "\n";
        return true;
    }
    // suma esquinas
    if(mat[0][0] + mat[0][N-1] + mat[N-1][0] + mat[N-1][N-1] != cm2){
        cout << "DIABOLICO" << "\n";
        return true;
    }
    // impares
    if(N % 2 == 1){
        // centro lados
        int centro = (N-1)/2;
        if(mat[0][centro] + mat[centro][0] + mat[centro][N-1] + mat[N-1][centro] != cm2){
            cout << "DIABOLICO" << "\n";
            return true;
        }
        // centro
        if(mat[centro][centro] * 4 != cm2){
            cout << "DIABOLICO" << "\n";
            return true;
        }
    }else{
        // centro lados
        int centro = N / 2;
        if(mat[0][centro - 1] + mat[0][centro] +
            mat[centro - 1][0] + mat[centro][0] +
            mat[centro - 1][N-1] + mat[centro][N-1] +
            mat[N-1][centro - 1] + mat[N-1][centro] != 2 * cm2){
            cout << "DIABOLICO" << "\n";
            return true;
        }
        // centro
        if(mat[centro - 1][centro - 1] + mat[centro - 1][centro] + mat[centro][centro - 1] + mat[centro][centro]!= cm2){
            cout << "DIABOLICO" << "\n";
            return true;
        }
    }
    cout << "ESOTERICO" << "\n";
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = MAX_N;
    //cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        //cout << "Case #" << i << ": ";
        if(!solve())
            break;
    }
}
