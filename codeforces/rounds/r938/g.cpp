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

int n, m;
vector<vector<bool>> dp;
inline bool check(vector<vi> &v, int a) {
    dp.resize(n);
    F0R(i, n) {
        dp[i].assign(m, false);
    }
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] % a > 0) {
                continue;
            }
            if (!dp[i][j] && i) {
                dp[i][j] = (dp[i - 1][j] == 1 ? 1 : 0);
            }
            if (!dp[i][j] && j) {
                dp[i][j] = (dp[i][j - 1] == 1 ? 1 : 0);
            }
        }
    }
    return dp[n-1][m-1];
}

inline void solve() {
    cin >> n >> m;
    vector<vi> v(n, vi(m));
    F0R(i, n) {
        F0R(j, m) {
            cin >> v[i][j];
        }
    }
    int g = gcd(v[0][0], v[n-1][m-1]);
    int ans = -1;
    vi to_check;
    for (int i = 1; i * i <= g; i++) {
        if(g % i == 0) {
            int a = g/i;
            if(check(v, a)) { 
                cout << a << "\n";
                return;
            }
            to_check.PB(i);
        }
    }
    reverse(all(to_check));
    for(int i: to_check) {
        if(check(v, i)) { 
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
