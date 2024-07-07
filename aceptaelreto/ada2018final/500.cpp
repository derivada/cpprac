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
const int INF = 1e9 + 5;

inline bool solve() {
    int n, q; cin >> n >> q;
    if(!n && !q) return false;
    int ans = 0;
    unordered_set<int> s;
    for(int i = 0; i <= n; i++) {
        vi cifras;
        int tmp = i;
        while(tmp > 0) {
            cifras.PB(tmp % 10);
            tmp /= 10;
        }
        reverse(all(cifras));
        while(cifras.size() < 4)
            cifras.PB(0);
        int mult = 1, j = 0;
        for(int d = 0; d<cifras.size();d++) {
            j += cifras[d] * mult;
            mult*=10;
        }
        if(i+j<=n && i+j >= q && !s.count(i) && !s.count(j)) {
            ans++;
            if(i != j)
                ans++;
            s.insert(i), s.insert(j);
        }
    }
    cout << ans << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}