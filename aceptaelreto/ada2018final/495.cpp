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

inline bool solve() {
    int n, m;
    cin >> n;
    if(!cin) return false;
    vi v(n+1), cost(n+1);
    v[0] = 0, cost[0] = 0;
    F0R(i, n)
        cin >> v[i+1];
    F0R(i, n)
        cin >> cost[i+1];
    cin >> m;
    
    // dp[i] := minimum cost to reach camp i (camp 0 is base)
    vi dp(n+1, 1e9 + 5);
    dp[0] = 0;
    for(int i = 1; i<=n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(v[i] - v[j] > m)
                break;
            dp[i] = min(dp[i], dp[j] + cost[i]);
        }
    }
    cout << dp[n] << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
