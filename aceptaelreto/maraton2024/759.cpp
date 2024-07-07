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

vector<set<int>> adj, adj2; // grafo representado como una lista de adyacencia

void dfs(int v, vector<bool> &seen) {
    seen[v] = true;
    for (int u : adj[v])
        if (!seen[u])
            dfs(u, seen);
} 

vi color;
int cycle_start;
bool dfs2(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            if (dfs2(u))
                return true;
        } else if (color[u] == 1) {
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool find_cycle(int n) {
    color.assign(n+1, 0);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs2(v))
            break;
    }
    if(cycle_start == -1) {
        return false;
    } else {
        return true;
    }
}

inline bool solve() {
    int n;
    cin >> n;
    if(!cin) return false;
    int k; cin >> k;
    vi comps(n+1, -1);
    int comp_n = 0;
    bool flag = false; // true si tramposo
    // adj2 tiene los bordes al revés
    adj.clear(), adj.resize(n+1); 
    adj2.clear(), adj2.resize(n+1); // de momento ponemos n+1 aunque solo será igual que grande que comps_n tras leer input
    F0R(i, k) {
        int x, y; char c;
        cin >> x >> c >> y;
        if(flag) continue;
        if(c == '=') {
            if(comps[x] == -1 && comps[y] == -1) {
                // no se ha visto ninguno
                comps[x] = comp_n, comps[y] = comp_n;
                comp_n++;
            } else if(comps[x] != -1 && comps[y] == -1) {
                // se ha visto x, pero no y
                comps[y] = comps[x];
            } else if(comps[x] == -1 && comps[y] != -1) {
                // se ha visto y, pero no x
                comps[x] = comps[y];
            } else if(comps[x] != comps[y]) {
                // se han visto los 2 y no están en el mismo grupo, 
                // para poder mergear hay que comprobar que no estén en la misma componente conexa
                vector<bool> seen(n+1,0), seen2(n+1, 0);
                dfs(comps[x], seen);
                dfs(comps[y], seen2);
                // se puede llegar del uno al otro, hay relacion de desigualdad (bad)
                if(seen[comps[y]] || seen2[comps[x]]) {
                    flag = true;
                } else {
                    // se pueden mergear ponemos y = x, primero mandamos todos los outgoing de y a los outgoing de x
                    for(int u: adj[comps[y]]) {
                        adj[comps[x]].insert(u);
                        adj2[u].erase(comps[y]);
                        adj2[u].insert(comps[x]);
                    }
                    // ahora hay que mandar los incoming de y a x
                    for(int u: adj2[comps[y]]) {
                        adj2[comps[x]].insert(u);
                        adj[u].erase(comps[y]);
                        adj[u].insert(comps[x]);
                    }
                    adj[comps[y]].clear();
                    adj2[comps[y]].clear();
                    // finalmente cambiamos la componente de y
                    comps[y] = comps[x];
                }
            }
        } else {
            // add the edge
            if(comps[x] == -1){
                comps[x] = comp_n;
                comp_n++;
            }
            if(comps[y] == -1) {
                comps[y] = comp_n;
                comp_n++;
            }
            if(x == y || comps[x] == comps[y]) {
                flag = true;
                continue;
            } 
            if(c == '<') {
                adj[comps[x]].insert(comps[y]);
                adj2[comps[y]].insert(comps[x]);
            } else {
                adj[comps[y]].insert(comps[x]);
                adj2[comps[x]].insert(comps[y]);
            }
            if(find_cycle(comp_n))
                flag = true;
        }
    }
    F0R(i, n+1) {
        cout << comps[i] << " ";
    }
    cout << endl;
    debug(flag);
    F0R(i, comp_n) {
        cout << i << " -> ";
        for(int x: adj[i])
            cout << x << " ";
        cout << endl;
    }
    if(flag || find_cycle(comp_n)) {
        cout << "TRAMPAS\n";
    } else {
        cout << "DESCONFIADO\n";
    }
    return true;
}

int main() {
    fastio;
    while (solve());
}
