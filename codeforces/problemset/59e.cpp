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
const int inf = 1e9 * 2;


inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    graph g(n);
    set<array<int, 3>> forb;
    F0R(i, m) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    F0R(i, k) {
        int a, b, c;
        cin >> a >> b >> c;
        forb.insert({a-1, b-1, c-1});
    }

    vector<vector<int>> d(n, vector<int>(n, inf)), p(n, vector<int>(n, -1));
    vector<vector<bool>> used(n, vector<bool>(n, false));
    queue<pi> q;
    for(int u: g[0]) {
        d[0][u] = 1;
        used[0][u] = true;
        q.push({0, u});
    }
    // BFS on the graph of pairs (last, current), checking that (last, current, next) is not on the set
    // can also be done with dijkstra but is slower
    while (!q.empty()) {
        int a = q.front().F, b = q.front().S;
        q.pop();
        for (int to : g[b]) {
            if(!used[b][to] && forb.count({a, b, to}) == 0) {
                used[b][to] = true;
                d[b][to] = d[a][b] + 1;
                q.push({b, to});
                p[b][to] = a;
            }
        }
    }

    int len = inf, pt = 0;
    for(int u : g[n-1]) {
        if(d[u][n-1] < len) {
            len = d[u][n-1];
            pt = u;
        }
    }
    
    if(len == inf) {
        cout << "-1\n"; return;
    }

    stack<int> path;
    path.push(n-1);
    path.push(pt);
    int v = n-1;
    while(p[pt][v] != -1) {
        int a = p[pt][v];
        v = pt;
        pt = a;
        path.push(pt);
    }
    cout << path.size() - 1 << "\n";
    while(!path.empty()){
        cout << (path.top() + 1) << " ";
        path.pop();
    }
    cout << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}