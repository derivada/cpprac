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
const ll inf = 1e18;

inline void solve() {
    int n, m;
    cin >> n >> m;
    wgraph g(n);
    
    F0R(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vi slows(n);
    F0R(i, n) {
        cin >> slows[i];
    }

    // dijkstra with set
    vector<vector<ll>> dist(n, vector<ll>(1001, inf));
    vector<vector<bool>> vis(n, vector<bool>(1001, false));
    dist[0][slows[0]] = 0;
    priority_queue<array<ll, 3>> q;
    q.push({0, 0, slows[0]});
    while(!q.empty()) {
        int u = q.top()[1], k = q.top()[2];
        q.pop();
        if(vis[u][k] || dist[u][k] == inf) continue;
        vis[u][k] = true;
        for(auto x: g[u]) {
            int v = x.first, w = x.second;
            int c = min(slows[v], k);
            if(dist[v][c] > dist[u][k] + 1LL * w * k) {
                dist[v][c] = dist[u][k] + 1LL * w * k;
                q.push({-dist[v][c], v, c});
            }
        }
    }
    long long result = inf;
    FOR(i, 1, 1001)
        result = min(result, dist[n-1][i]);
    cout << result << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
