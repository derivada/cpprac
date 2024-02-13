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
struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        // Hash combination algorithm
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);

        // A simple hash combining algorithm
        // You can use a more sophisticated one if needed
        return hash1 ^ hash2;
    }
};

inline void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    graph g(n);
    set<int> pol;
    map<pi, int> roads;
    F0R(i, k) {
        int a;
        cin >> a;
        pol.insert(a-1);
    }
    F0R(i, n-1) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
        pi road = {min(b-1, a-1), max(a-1, b-1)};
        roads[road] = i;
    }

    vector<bool> visited(n, false);
    vi p(n, -1);
    queue<int> q;
    for(int x: pol) {
        q.push(x);
        visited[x] = true;
    }
    set<pi> roads_shut;
    unordered_set<pi, PairHash> roads_seen;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int u: g[v]) {
            pi road = {min(u, v), max(v, u)};
            if(visited[u]) {
                // shut down road
                if(roads_seen.count(road)==0)
                    roads_shut.insert(road);
            } else {
                roads_seen.insert(road);
                visited[u] = true;
                q.push(u);
                p[u] = v;
            }
        }
    }
    cout << roads_shut.size() << "\n";
    for(pi road: roads_shut) {
        cout << roads[road]+1 << " ";
    }
    cout << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
