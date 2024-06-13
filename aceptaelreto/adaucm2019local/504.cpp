#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <limits>
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
#define INF LLONG_MAX

bool add_n = false;
inline bool solve() {
    int n;
    cin >> n;
    if(!cin) return false;
    if(!add_n) {
        add_n = true;
    } else {
        cout << "\n";
    }
    vector<vector<pi>> adj(n+1);
    int m; cin >> m;
    F0R(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB(MP(v,w));
        adj[v].PB(MP(u,w));
    }
    int k;
    cin >> k;
    F0R(i, k) {
        int s, end;  // source - to
        cin >> s >> end;
        if(s == end){
            cout << "0 SI\n";
            continue;
        }
        // dijkstra (fastes path)
        vector<ll> d(n+1, INF);
        vi p(n+1, -1);
        d[s] = 0;
        using pill = pair<int, ll>;
        priority_queue<pill, vector<pill>, greater<pill>> q;
        q.push({0, s});
        while (!q.empty()) {
            ll v = q.top().second;
            ll d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;

            for (auto edge : adj[v]) {
                ll to = edge.first;
                ll len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
        if(p[end] == -1) {
            cout << "SIN CAMINO\n";
            continue;
        }
        cout << d[end];
        // find depth of path
        int depth = 0, curr = end;
        while(p[curr] != -1) {
            depth++;
            curr = p[curr];
        }
        // run BFS until finding node and check if depth is the same (BFS gives path with min depth)

        queue<int> q2;
        vector<bool> used(n+1);
        vector<int> d2(n+1);

        q2.push(s);
        used[s] = true;
        while (!q2.empty()) {
            int v = q2.front();
            q2.pop();
            for (pi p : adj[v]) {
                int u = p.F;
                if (!used[u]) {
                    used[u] = true;
                    q2.push(u);
                    d2[u] = d2[v] + 1;
                }
            }
        }
        cout << ((d2[end] == depth) ? " SI\n" : " NO\n");
    }
    cout << "----";
    return true;
}
int main() {
    fastio;
    while(solve());
}
