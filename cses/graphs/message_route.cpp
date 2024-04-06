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
    vector<vector<int>> g(n+1);
    F0R(i, m) {
        int a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    // Dijkstra with pred array
    vi pred(n+1);
    vi d(n+1, 1e9);
    priority_queue<pi, vector<pi>, greater<pi>> q; // dist,s
    d[1] = 0;
    pred[1] = -1;
    q.push({0, 1});
    while(!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        if(v == n) {
            int a = n;
            vi path;
            while(pred[a] != -1) {
                path.PB(a);
                a = pred[a];
            }
            path.PB(1);
            reverse(all(path));
            cout << path.size() << "\n";
            for(auto x: path) {
                cout << x << " ";
            }
            cout << "\n";
            return;
        }
        
        for (auto to : g[v]) {
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                pred[to] = v;
                q.push({d[to], to});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
