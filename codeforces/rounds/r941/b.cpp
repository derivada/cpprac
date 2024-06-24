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
    int n, m;
    cin >> n >> m;
    int bi_min = 1000, bi_max = -1, bj_min = 1000, bj_max = -1;
    int wi_min = 1000, wi_max = -1, wj_min = 1000, wj_max = -1;
    F0R(i, n) {
        string s; cin >> s;
        F0R(j, m) {
            if(s[j] == 'B') {
                bi_min = min(i, bi_min), bi_max = max(i, bi_max);
                bj_min = min(j, bj_min), bj_max = max(j, bj_max);
            } else {
                wi_min = min(i, wi_min), wi_max = max(i, wi_max);
                wj_min = min(j, wj_min), wj_max = max(j, wj_max);
            }
        }
    }
    if(bi_min == 0 && bi_max == n-1 && bj_min == 0 && bj_max == m-1) {
        cout << "YES\n";
    } else if(wi_min == 0 && wi_max == n-1 && wj_min == 0 && wj_max == m-1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
