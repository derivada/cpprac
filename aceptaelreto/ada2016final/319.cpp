#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
#define debug(x) cout << #x << " is " << x << endl
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

vector<vi> adj(10000);

inline void construct_adj() {
    F0R(i, 10000) {
        int sum = (i+1) % 10000;
        int prod = (i * 2) % 10000;
        int div = (i / 3) % 10000;

        adj[i].push_back(sum);
        adj[i].push_back(prod);
        adj[i].push_back(div);
    }
}

inline bool solve() {
    int from, to; cin >> from; if(!cin) return false; cin >> to;
    // bfs
    if(from == to) {
        cout << "0\n";
        return true;
    }
    vector<bool> used(10000, false);
    vi d(10000, 0);
    queue<int> q;
    q.push(from);
    used[from] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                if(u == to) {
                    cout << d[to] << endl;
                    return true;
                }
            }
        }
    }
    return true;
}

int main() {
    fastio;
    construct_adj();
    while (solve());
}
