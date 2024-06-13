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
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> matched, to_match, extra;
    vi a(n);
    F0R(i, n) {
        cin >> a[i];
    }
    F0R(i, m) {
        int x; cin >> x; to_match.insert(x);
    }
    F0R(i, m) {
        auto it = to_match.find(a[i]);
        if(it != to_match.end()) {
            matched.insert(*it);
            to_match.erase(it);
        } else {
            extra.insert(a[i]);
        }
    }
    int ans = (matched.size() >= k);
    for(int i = m; i<n; i++) {
        auto it = matched.find(a[i-m]);
        auto it2 = extra.find(a[i-m]);

        if(it != matched.end()){
            matched.erase(it);
            if(it2 != extra.end()) {
                matched.insert(*it2);
                extra.erase(it2);
            } else {
                to_match.insert(*it);
            }
        }
        it = to_match.find(a[i]);
        if(it != to_match.end()) {
            matched.insert(*it);
            to_match.erase(it);
        } else {
            extra.insert(a[i]);
        }
        ans += (matched.size() >= k);
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
