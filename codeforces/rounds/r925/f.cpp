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

int n;
vector<char> color;
vi parent;
int cycle_start, cycle_end;
vector<vector<int>> adj;
bool dfs(int v) {
    color[v] = 1;
    for(int u : adj[v]) {
        if(color[u] == 0) {
            parent[u] = v;
            if(dfs(u))
                return true;
        } else if(color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    adj.clear(); adj.resize(n+1);
    color.assign(n+1, 0); parent.assign(n+1, -1);
    F0R(i, k) {
        vi row(n);
        F0R(j, n)
            cin >> row[j];
        for(int j = 1; j < n-1; j++) {
            adj[row[j]].PB(row[j+1]);
        }
    }
    
    // now we find the cycle in the directed graph
    cycle_start = -1;
    for(int v = 1; v<=n; v++) {
        if(color[v] == 0 && dfs(v)) 
            break;
    }
    if(cycle_start == -1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
