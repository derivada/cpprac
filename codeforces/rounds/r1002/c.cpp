#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> graph;
typedef vector<vector<pair<int, int>>> wgraph;
// set with also order_of_key(k) and find_by_order(k)
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define umap unordered_map
#define uset unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define debug(x) cout << #x << " is " << x << endl
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value

inline void solve() {
    int n;
    cin >> n;
    // suffix sum on each row
    // go backwards in time
    // for each time, try to get the minimum??
    vector<vector<ll>> m(n, vector<ll>(n, 0)), suff(n, vector<ll>(n+1, 0));
    F0R(i, n) {
        F0R(j, n) {
            ll x;
            cin >> m[i][j];
        }
    }
    F0R(i, n) {
        for(int j = n-1; j>=0; j--) {
            suff[i][j] = m[i][j] + suff[i][j+1];
        }
    }
    // F0R(i, n) {
    //     F0R(j, n+1) {
    //         cout << suff[i][j] << " ";
    //     }
    //     cout << std::endl;
    // }
    int count = 0;
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    // start on the last time
    for(int time = n; time >= 1; time--) {
        int good_row = 0;
        int target = n-time;
        for(int row = 0; row<n; row++) {
            if(dp[row][time] == target) {
                good_row ++;
            }
        }
        for(int row = 0; row < n; row++ ){
            if(good_row > 0 && dp[row][time+1] == count-1 ){
                dp[row][time] = count;
            }
        }
    }
    cout << count << "\n";
    // dp[i][j] = máximo MEX habiendo elegido la fila i en el tiempo j
    // tiempo n:
    // todas se pueden elegir para tomar MEX = 0, así que dp[i][N] = 0 (MEX-1)
    // tiempo n-1:
    // ahora hace falta que suff[i][n-1] = 1
    // si eso ocurre, ponemos dp[i][n-1] = 1
    // tiempo n-2:
    // probablemente hubo varias opciones para las que tenemos MEX = 2 ya, para cada una de ellas
    // ver si podemos seguir construyendo
    // para la fila i, tenemos dos opciones:
    // cambiar el corte que habiamos hecho antes -> cuando hay otro dp[i][n-1] = 1 y tenemos un 2 en esta fila
    // dejar el corte que habiamos hecho antes -> cuando no tenemos un 2 en esta fila
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
