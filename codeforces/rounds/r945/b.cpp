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
    ll target = 0, curr = 0;
    int max_bit = 0;
    vi v(n);
    vector<vector<int>> last_entry(n, vector<int>(21, -1));
    F0R(i, n) {
        cin >> v[i];
        target |= v[i];
        F0R(j, 21) {
            if((v[i] >> j) & 1) {
                last_entry[i][j] = i;
                max_bit = max(max_bit, j);
            } else if(i >= 1) {
                last_entry[i][j] = last_entry[i-1][j];
            }
        }
    }
/*     F0R(i, n) {
        F0R(j, 4) {
            cout << last_entry[i][j] << " "; 
        }
        cout << "\n";
    } */
    int r = -1;
    while(curr != target) {
        r++; 
        curr |= v[r];
    }
    int ans = 0;
    while(r < n) {
        int l = 1e9;
        F0R(j, max_bit) {
            l = min(l, last_entry[r][j]);
        }
        debug(r);
        debug(l);
        ans = max(ans, r-l+1);
        r++;
    }
    cout << ans << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
