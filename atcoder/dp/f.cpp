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

inline void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<pair<int, pair<int,int>>>> dp(n + 1, vector<pair<int, pair<int,int>>> (m + 1, {0, {0,0}}));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i] == t[j]) {
                dp[i+1][j+1] = max(dp[i+1][j+1], make_pair(dp[i][j].F + 1, make_pair(i, j)));
            }
            dp[i][j+1] = max(dp[i][j+1], make_pair(dp[i][j].F, make_pair(i, j)));
            dp[i+1][j] = max(dp[i+1][j], make_pair(dp[i][j].F, make_pair(i, j)));
        }
    }
    pair<int, int> best;
    int best_n = -1;
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=m; j++) {
            if(dp[i][j].F > best_n) {
                best_n = dp[i][j].F;
                best = make_pair(i, j);
            }
        }
    }
    string ans = "";
    while(best.F * best.S > 0) { // not 1st row or col
        pair<int, int> prev = dp[best.F][best.S].S;
        if(prev.F == best.F - 1 && prev.S == best.S - 1) {
            ans += s[prev.F];
        }
        best = prev;
    }
    reverse(all(ans));
    cout << ans << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
