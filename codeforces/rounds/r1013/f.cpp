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
const ll MOD = 998244353;
ll dp[2001][2001][2];

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<string> v(n);
    F0R(i, n) {
        cin >> v[i];
    }
    memset(dp, 0, sizeof(dp));
    vector<ll> prefix_curr_1(m, 0), prefix_curr_0(m, 0);

    F0R(i, n) {
        // going up
        F0R(f, 2) {
            F0R(j, m) {
                if(v[i][j] == 'X') {
                    if(i == 0) {
                        dp[0][j][f] = 1;
                    } else {
                        int l = std::max(0, j-(d-1));
                        int r = std::min(m-1, j+(d-1));
                        ll pre = prefix_curr_0[r];
                        if(l > 0)
                            pre = (pre - prefix_curr_0[l-1] + MOD) % MOD;
                        dp[i][j][f] = (dp[i][j][f] + pre) % MOD;
                    }
                }
                // 1s are ready
                if(j > 0){
                    prefix_curr_1[j] = (prefix_curr_1[j-1] + dp[i][j][1]) % MOD;
                } else {
                    prefix_curr_1[0] = dp[i][0][1];
                }
            }
        }

        // going to second hold 
        F0R(j, m) {
            if(v[i][j] == 'X') {
                int l = std::max(0, j-d);
                int r = std::min(m-1, j+d);
                ll pre = (prefix_curr_1[r] - dp[i][j][1] + MOD) % MOD;
                if(l > 0)
                    pre = (pre - prefix_curr_1[l-1] + MOD) % MOD;
                dp[i][j][0] = (dp[i][j][0] + pre) % MOD;
            }
            // 0s are ready
            if(j > 0){
                prefix_curr_0[j] = (prefix_curr_0[j-1] + dp[i][j][0]) % MOD;
            } else {
                prefix_curr_0[0] = dp[i][0][0];
            }
        }
    }
    ll res = 0;
    F0R(j, m) {
        res = (res + dp[n-1][j][0]) % MOD;
    }
    cout << res << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
