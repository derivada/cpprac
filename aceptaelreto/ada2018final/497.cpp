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
const int INF = 1e9 + 5;

vector<set<int>> adj;

inline void bfs(int s, vector<int> &d) {
    int n = adj.size();
    queue<int> q;
    vector<bool> used(n);

    q.push(s);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
}

inline bool solve() {
    int n, l; cin >> n >> l;
    if(!n && !l) return false;
    adj.clear(); adj.resize(n+1);
    set<int> seen;
    set<int> seen_twice;
    F0R(i, l) {
        vi v;
        int x; cin >> x;
        while(x != 0){
            if(seen.count(x)) seen_twice.insert(x);
            seen.insert(x);
            v.PB(x);
            cin >> x;
        }
        for(int i = 0; i<v.size()-1; i++){
            adj[v[i]].insert(v[i+1]);
        }
        for(int i = 1; i<v.size(); i++){
            adj[v[i]].insert(v[i-1]);
        }
    }
    int ans = -1, best = 1e9 + 5;
    for(int s: seen_twice) {
        int sum = 0;
        vector<int> d(n+1);
        bfs(s, d);
        for(int s2: seen_twice) {
            sum += d[s2];
        }
        if(sum < best) {
            best = sum, ans = s;
        }
    }
    cout << ans << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
