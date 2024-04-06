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

int n, m;
vi pre(1e5 + 5, -1);
vector<vector<int>> g(1e5 + 5);

void print_cycle(int start, int end) {
    vi cycle;
    cycle.PB(start);
    for(int v = end; v != start; v = pre[v]) {
        cycle.PB(v);
    }
    cycle.PB(start);
    cout << cycle.size() << "\n";
    F0R(i, cycle.size())
        cout << cycle[i] << " ";
    cout << "\n";
}

inline void solve() {
    cin >> n >> m;
    F0R(i, m) {
        int a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    // Finding a cycle through the starting city
    // Need to to DFS until visited found (since graph is undirected)
    vector<bool> visited(n+1, false);
    stack<pi> st;
    for(int i = 1; i<=n; i++){
        if(!visited[i]) {
            st.push({i, -1});
            while(!st.empty()) {
                int u = st.top().F, parent = st.top().S; st.pop();
                visited[u] = true;
                //cout << "visiting " << u << " with parent " << parent << endl;
                for(int v: g[u]) {
                    //out << "checking edge (" << u << ", " << v << ")" << endl;
                    if(v == parent) // evitar 2-loops mirando si el padre del padre es el mismo
                        continue;
                    pre[v] = u;
                    if(visited[v]) {
                        //cout << "loop found " << u << " --> " << v << endl;
                        print_cycle(v, u);
                        return;
                    }
                    st.push(MP(v, u));
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
