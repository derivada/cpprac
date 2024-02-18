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
    int n, m;
    cin >> n >> m;
    vi v(n);
    F0R(i, n) cin >> v[i];
    ll total = 1;
    int gap_len = 0, gap_start = -1;
    bool possible = true;
    for(int i = 0; i<=n; i++) {
        if(i+1 < n && v[i]*v[i+1] != 0 && abs(v[i] - v[i+1]) > 1){
            possible = false;
            break;
        }
        if(i < n && v[i] == 0) {
            // gap
            if(gap_len == 0)
                gap_start = i-1;
            gap_len++;
        } else if(gap_len != 0) {
            // end of gap
            //cout << "new gap starting at " << gap_start << " with length " << gap_len << "\n";
            vector<vi> dp(gap_len, vi(m+1, 0));
            if(gap_start == -1) {
                // initialize for all
                for(int i = 1; i<=m; i++) {
                    dp[0][i] = 1;
                }
            } else {
                // initialize for adjacent to start
                dp[0][v[gap_start]] = 
                    dp[0][min(m, v[gap_start]+1)] = 
                    dp[0][max(1, v[gap_start]-1)] = 1;
            }
            for(int pos = 1; pos<gap_len; pos++) {
                dp[pos][1] = (dp[pos-1][1] + dp[pos-1][2]) % MOD;
                for(int j = 2; j<=m-1; j++) {
                    dp[pos][j] = ((dp[pos-1][j] + dp[pos-1][j-1] % MOD) + dp[pos-1][j+1]) % MOD;
                }
                dp[pos][m] = (dp[pos-1][m] + dp[pos-1][m-1]) % MOD;
            }
            /*cout << "DP = \n";
            for(int k = 0; k<=m; k++) {
                for(int j = 0; j< gap_len; j++) {
                    cout << dp[j][k] << " ";
                }
                cout << "\n";
            }
            cout << "\n";*/
            // collect total
            int gap_total = 0;
            if(i == n) {
                // from all
                for(int j = 1; j<=m; j++) {
                    gap_total = (gap_total + dp[gap_len-1][j]) % MOD; 
                }
            } else {
                // from adjacent to next
                int last = v[i];
                if(last == 1) {
                    gap_total = (dp[gap_len-1][1] + dp[gap_len-1][2]) % MOD;
                } else if(last == m) {
                    gap_total = (dp[gap_len-1][m] + dp[gap_len-1][m-1]) % MOD;
                } else {
                    gap_total = (((dp[gap_len-1][last] + dp[gap_len-1][last-1]) % MOD ) 
                                    + dp[gap_len-1][last+1]) % MOD;
                }
            }
            // add to main total
            //cout << "GAP TOTAL = " << gap_total << "\n";
            total = (total * gap_total) % MOD;
            gap_len = 0, gap_start = -1;
        }
    }
    if(possible)
        cout << total << "\n";  
    else
        cout << "0\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
