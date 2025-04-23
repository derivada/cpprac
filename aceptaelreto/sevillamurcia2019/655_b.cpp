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
vector<vector<pair<long, long>>> adj;
const ll INF = 1000000000;



void dfs(int v, vector<bool> &visited, vector<int> &top_sort) {
    visited[v] = true;
    for (auto edge : adj[v]) {
        int u = edge.F;
        if (!visited[u]) {
            dfs(u, visited, top_sort);
        }
    }
    top_sort.push_back(v);
}

void topological_sort(int n, vector<bool> &visited, vector<int> &top_sort) {
    visited.assign(n, false);
    top_sort.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, visited, top_sort);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
}


void cool_dfs(ll s, vector<ll>& d, vector<ll>& p, vector<bool>& visited) {
    visited[s] = true;
    d[s] = 0;
    // debug(s);
    for(auto edge: adj[s]) {
        int to = edge.F; ll w = edge.S;
        // cout << s << "->" << to << " w =" << w << endl;
        if(!visited[to])
            cool_dfs(to, d, p, visited);
        ll dist_son = w + d[to];
        if(d[s] < dist_son || (d[s] == dist_son && s > to)) {
            d[s] = dist_son;
            p[s] = to;
        }
    }
}

inline bool solve() {
    ll n, m;
    cin >> n >> m; if(!n && !m) return false;
    adj.clear(); adj.resize(n);
    // a node is an start unless it has incoming edges
    // a node is an end unless it has outgoing edges
    // from (outgoing) --> to (incoming)
    F0R(i, m) {
        ll from, to, w; cin >> from >> to >> w;
        from--, to--;
        // al reves
        adj[to].PB(MP(from, w));

    }
    vector<ll> d, p; vector<bool> visited(n, false);
    vector<int> top_sort;
    d.assign(n, INF);
    p.assign(n, -1);
    topological_sort(n, visited, top_sort);
    visited.assign(n, false);
    F0R(i, n) {
        //cout << "DIJKSTRA: " << i << " " << starts[i] << " " << ends[i] << endl;;
        cool_dfs(i, d, p, visited);
    }

    // F0R(i, n) {
    //     cout << "i = " << i;
    //     cout << "   d[i] = " << d[i];
    //     cout << "   p[i] = " << p[i] << endl;
    // }
    
    ll highest_dist = 0, end = -1;
    F0R(i, n) {
        // no outgoing edges
        //std::cout << "i = " << i << " || " << adj[i].size() << " outgoing edges and d = " << -d[i] << endl;
        if(adj[i].size() == 0) {
            if(highest_dist < d[i]) {
                highest_dist = d[i];
                end = i;
            }
        }
    }
    std::cout << highest_dist << "\n";
    vector<ll> path;
    while(end != -1) {
        path.push_back(end + 1);
        end = p[end];
    }
    reverse(all(path));
    F0R(i, path.size()) {
        cout << path[i];
        if(i<path.size()-1) cout << " ";
    }
    if(path.size() > 0)
        cout << "\n";
    // print path
    return true;
}

int main() {
    fastio;
    while(solve());
}
