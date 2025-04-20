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

vector<vector<pi>> g;
vector<int> d;
vector<bool> seen;

inline void bfs01(int s) {
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : g[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
    
}

inline bool solve() {
    int n, k, s, e; cin >> n >> k >> s >> e;
    if(!n) return false;
    g.clear();
    g.resize(n*n);
    // p.resize(n*n);
    seen.assign(n*n, false);
    d.assign(n*n, 1e7);
    F0R(i, n*n) {
        for(int j = 1; j<=k; j++) {
            if(i+j <n*n)
                g[i].push_back({i+j, 1});
        }
    }
    
    F0R(i, s+e) {
        int from, to; cin >> from >> to; from--, to--;
        g[from].clear();
        g[from].push_back({to, 0});
    }

    bfs01(0);
    // int par = n*n-1;
    // while(par > -1) {
    //     std::cout << par;
    //     par = p[par];
    //     if(par > -1)
    //         cout << "->";
    // }
    // cout << endl;
    cout << d[n*n-1] << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
