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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value

inline bool solve() {
    int m, n;
    cin >> m;
    if(!cin) return false;
    cin >> n;
    vector<vi> grid(n, vi(m, 0));
    F0R(i, n) {
        F0R(j, m) {
            int x; cin >> x;
            grid[i][j] = x;
        }
    }
    // dp[i][j] = LOWEST charge I need to get to (i,j)
    vector<vector<ll>> dp(n, vector<ll>(m, LLONG_MAX));
    vector<vector<pi>> pre(n, vector<pi>(m));
    dp[0][0] = 2; // at the beginning I need 2, it can never drop from 2 aswell
    FOR(i, 1, n) {
        dp[i][0] = dp[i-1][0] - grid[i][0];
        if(grid[i][0] > 0 && dp[i-1][0] > 2)
            dp[i][0] += grid[i][0];
    }
    FOR(j, 1, m) {
        dp[0][j] = dp[0][j-1] - grid[0][j];
        if(grid[0][j] > 0 && dp[0][j-1] > 2)
            dp[0][j] += grid[0][j];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) - grid[i][j];
            if(grid[i][j] > 0 && min(dp[i-1][j], dp[i][j-1]) > 2)
                dp[i][j] += grid[i][j];
        }
    }
    
    cout << "DP : \n";
    F0R(i, n) {
        F0R(j , m) {
            cout << dp[i][j] << " "; 
        }
        cout << "\n";
    }
    
    // TODO fix case where we reach a lower value in the path but then it is increased
    //cout << max(2LL, dp[n-1][m-1]) << "\n";
    cout << dp[n-1][m-1] << "\n";
    return true;
}

int main() {
    fastio;
    while(solve());
}
