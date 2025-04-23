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

void dijkstra(ll s, vector<ll>& d, vector<ll>& p) {
    int n = adj.size();
    d[s] = 0;
    using pll = pair<ll, ll>;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    // cout << "starting dijks from " << s << endl;
    while (!q.empty()) {
        ll from = q.top().second;
        ll d_from = q.top().first;
        q.pop();
        if (d_from != d[from])
            continue;

        for (auto edge : adj[from]) {
            ll to = edge.first;
            ll len = edge.second;
            // cout << from << "->" << to << " current parent of " << to << ": " << p[to] << endl;

            if (d[from] + len < d[to] || (d[from] + len == d[to] && from < to))  {
                d[to] = d[from] + len;
                p[to] = from;
                q.push({d[to], to});
            }
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
    vector<bool> starts(n, true), ends(n, true);
    F0R(i, m) {
        ll from, to, w; cin >> from >> to >> w;
        from--, to--;
        w = -w;
        adj[from].PB(MP(to, w));
        ends[from] = false;
        starts[to] = false;
    }

    vector<ll> d, p;
    d.assign(n, INF);
    p.assign(n, -1);
    F0R(i, n) {
        //cout << "DIJKSTRA: " << i << " " << starts[i] << " " << ends[i] << endl;;
        if(starts[i])
            dijkstra(i, d, p);
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
        if(ends[i]) {
            ll dist = -d[i];
            if(highest_dist < dist) {
                highest_dist = dist;
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
