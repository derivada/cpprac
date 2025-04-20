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

vector<ll>  l, r;
vector<vector<int>> tr; // adj list
int res = 0;
inline ll dfs(int v) {
    int nchild = tr[v].size();
    if(nchild == 0) {
        // leaf
        res++;
        return r[v];
    }

    ll accum = 0;
    for(int i = 0; i<nchild; i++) {
        accum += dfs(tr[v][i]); 
    }

    if(accum < l[v]) {
        // not enough, new op
        res++;
        return r[v];
    } else {
        // enough, but dont overflow the node!
        return std::min(r[v], accum);
    }
}


inline void solve() {
    int n;
    cin >> n;
    res = 0;
    tr.assign(n, {});
    l.resize(n);
    r.resize(n);
    for(int i = 1; i<n; i++){
        int x;
        cin >> x;
        x--;
        tr[x].push_back(i);
    }
    
    for(int i = 0; i<n; i++) {
        cin >> l[i] >> r[i];
    }
    dfs(0);
    std::cout << res << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
