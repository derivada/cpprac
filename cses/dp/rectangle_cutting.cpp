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

vector<vector<int>> dp(501, vector<int>(501, -1));

inline int solve_rect(int a, int b) {
    if(dp[a][b] != -1)
        return dp[a][b];
    if(a == b) {
        dp[a][b] = 0;
        return 0;
    }
    int cuts = 1e9;
    // cut horizontally
    // a = 1 -> no cuts
    // a = 2 -> 1 cut
    // a = 3 -> 1 cut
    // a = 4 -> 2 cuts
    for(int i = 1; i<=a/2 && a-i>0; i++) {
        cuts = min(cuts, solve_rect(i, b) + solve_rect(a-i, b) + 1);
    }
    // cut vertically
    for(int i = 1; i<=b/2 && b-i>0; i++) {
        cuts = min(cuts, solve_rect(a, i) + solve_rect(a, b-i) + 1);
    }
    dp[a][b] = cuts;
    return dp[a][b];
}

inline void solve() {
    int a, b;
    cin >> a >> b;
    cout << solve_rect(a, b) << "\n";

    // cout << " debug \n";
    // F0R(i, a){
    //     F0R(j, b) {
    //         cout << dp[i+1][j+1] << " ";
    //     }
    //     cout << "\n";
    // }
}

int main() {
    fastio;
    solve();
}
