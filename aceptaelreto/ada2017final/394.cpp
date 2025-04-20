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

vector<vector<int>> adj;
vector<bool> seen;
int res;
int dfs(int x) {
    int min_of_child = 1e7;
    seen[x] = true;
    for(auto node: adj[x]) {
        if(seen[node] == false){
            min_of_child = std::min(min_of_child, dfs(node));
        }
    }
    if(adj[x].size() == 2) {
        int val = min_of_child + 1;
        res = std::max(res, val);
        return val;
    } else {
        return 0;
    }
}

inline void read_tree(int father) {
    // example: 1 2 1 0 1 0
    // add node
    int child_n = adj.size();
    adj.push_back({});
    // add backlink to father
    if(father >= 0){
        adj[father].push_back(child_n);
    }
    // read number of children
    int nchild; cin >> nchild;
    F0R(c, nchild) {
        read_tree(child_n);
    }
}

inline void solve() {
    adj.clear();
    read_tree(-1);

    int n = adj.size();
    // dfs, tree is rooted
    res = 0;
    seen.assign(n, false);
    dfs(0);
    
    std::cout << res << "\n";
}

int main() {
    fastio;
    int tc; cin >> tc;
    while (tc--)
        solve();
}
