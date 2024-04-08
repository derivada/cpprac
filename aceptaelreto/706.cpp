#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
typedef vector<int> vi;
typedef pair<int, long> pl;
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
#define INF 1e9 + 5
const ll MOD = 1e9 + 7; // change MOD value

void dijkstra(long s, vector<vector<pl>> & adj, vector<long> & d, vector<long> & p, vector<long> & ignore_less_eq) {
    long n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pll = pair<long, long>;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (!q.empty()) {
        long v = q.top().second;
        long d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            long to = edge.first;
            long len = edge.second;
            long new_len = d[v] + len;

            if (new_len < d[to] && new_len > ignore_less_eq[to]) {
                /*if(ignore_less_eq[to] != -1) {
                    cout << "going from " << v << " to " << to << " with new dist " << new_len << "\n";
                    cout << " d[to] = " << d[to] << " , ignore_less_eq[to] = " << ignore_less_eq[to] << "\n";
                }*/
                d[to] = new_len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

bool solve() {
    long n, m;
    cin >> n;
    if(!cin)
        return false;
    cin  >> m;
    //cout << n << " " << m << endl;
    vector<vector<pl>> adj(n+1);
    F0R(i, m) {
        long u, v, w;
        cin >> u >> v >> w;
        //cout << u << " " << v << " " << w << endl;
        adj[u].PB(MP(v, w));
        adj[v].PB(MP(u, w));
    }
    
    // find best path
    vector<long> d(n+1); vector<long> p(n+1); vector<long> ignorexd(n+1, -1);
    // el ultimo argumento dice en que punto no queremos seguir mirando ese camino (como de largo puede ser como máximo)
    dijkstra(1, adj, d, p, ignorexd);
    vector<long> d2(n+1); vector<long> p2(n+1);
    dijkstra(1, adj, d2, p2, d);
    if(d2[n] == INF) { // no hay ruta original hasta la guarida
        cout << "IMPOSIBLE\n";
    } else {
        cout << d2[n] << "\n";
    }
    return true;
}

int main() {
    while(solve());
}