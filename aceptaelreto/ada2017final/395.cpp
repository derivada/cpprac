#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
#define debug(x) cout << #x << " is " << x << endl
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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value

// x1 y1 x2 y2
int dp[25][25][25][25];
vector<string> mat;

void compute(int x1, int y1, int x2, int y2) {
    //std::cout << x1 << "," << y1 << " -> " << x2 << "," << y2 << endl; 
    int min = 1e7;
    if(abs(x1-x2) + abs(y1-y2) == 1) {
        dp[x1][y1][x2][y2] = mat[x1][y1] != mat[x2][y2];
        return;
    }
    if(x1 == x2 && y1 == y2){
        dp[x1][y1][x2][y2] = 0;
        return;
    }
    bool flag = false;
    // horizontal cuts
    for(int i = 0; i < (x2-x1); i++) {
        // left
        if(dp[x1][y1][x1+i][y2] == -1) {
            compute(x1, y1, x1+i, y2);
        } 
        if(dp[x1+i+1][y1][x2][y2] == -1) {
            compute(x1+i+1, y1, x2, y2);
        }
        int left = dp[x1][y1][x1+i][y2], right = dp[x1+i+1][y1][x2][y2];
        if(left == 0 && right == 0 && (mat[x1][y1] == mat[x2][y2])) {
            dp[x1][y1][x2][y2] = 0;
            return;
        }
        if(left + right + 1 < min)
            min = left+right+1;
    }
    if(flag)
        return;
    // vertical cuts
    for(int j = 0; j < (y2-y1); j++) {
        // left
        if(dp[x1][y1][x2][y1+j] == -1) {
            compute(x1, y1, x2, y1+j);
        } 
        if(dp[x1][y1+j+1][x2][y2] == -1) {
            compute(x1, y1+j+1, x2, y2);
        }
        int top = dp[x1][y1][x2][y1+j], bottom = dp[x1][y1+j+1][x2][y2];
        int vert = top+bottom+1;
        if(top == 0 && bottom == 0 && (mat[x1][y1] == mat[x2][y2])) {
            dp[x1][y1][x2][y2] = 0;
            return;
        }
        if(vert < min)
            min = vert;
    }
    dp[x1][y1][x2][y2] = min;
}

inline bool solve() {
    memset(dp, -1, sizeof(dp));
    int n, m; cin >> n; 
    if(!cin) return false;
    mat.resize(n);
    cin >> m;
    
    F0R(i, n) {
        cin >> mat[i];
    }
    compute(0,0,n-1,m-1);

    cout << dp[0][0][n-1][m-1] << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
