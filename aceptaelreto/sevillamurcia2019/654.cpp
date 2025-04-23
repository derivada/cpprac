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
struct Bounds {
    int left, right, up, down;
    Bounds() {
        left = 1e9, right = -1e9, down = -1e9, up = 1e9;
    }

    void update(int i, int j)  {
        left = min(left, j);
        right = max(right, j);
        down = max(down, i);
        up = min(up, i);
    }
};

int m, n; 
vector<vector<char>> mat;
map<char, Bounds> bounds;
vector<set<char>> adj;
vector<int> indeg;


inline void construct_graph(char c, Bounds &b) {
    // cout << "building " << c << " with (" << b.up 
    //     << ", " << b.down << ") x (" << b.left << ", " << b.right << ")" << endl;
    for(int i = b.up; i<=b.down; i++) {
        for(int j = b.left; j<=b.right; j++) {
            char c2 = mat[i][j];
            if(c2 == '.') continue;
            if(c != c2) {
                // c2 encima de c
                if(adj[c2].find(c) == adj[c2].end()){
                    adj[c2].insert(c);
                    indeg[c]++;
                }
            }
        }
    }
}

inline bool letter_exists(char c) {
    return bounds.find(c) != bounds.end();
}
// AC
inline void solve() {
    cin >> m >> n;
    mat.clear(); mat.resize(n);
    adj.clear(); adj.resize(256); // en ASCII
    bounds.clear(); 
    indeg.clear(); indeg.assign(256, 0); // en ASCII
    // read input and create bounds map
    F0R(i, n){
        mat[i].resize(m);
        string s; cin >> s;
        F0R(j, m) {
            char c = s[j];
            mat[i][j] = c;
            if(c != '.') {
                Bounds b;
                if(bounds.find(c) != bounds.end()) {
                    b = bounds[c];
                }
                b.update(i, j);
                bounds[c] = b;
            }
        }
    }
    for(auto elem: bounds) {
        construct_graph(elem.F, elem.S);
    }

    queue<char> q; // cola de elementos con in-deegree = 0
    for(int i = 0; i<256; i++) {
        if(letter_exists(i)){
            // cout << (char) i << " --> ";
            // for(char c2: adj[i]) {
            //     cout << c2 << ",";
            // }
            // cout << " and indeg = " << indeg[i];
            // cout << endl;
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
    }
    // lista de impresion
    vector<vector<char>> its;
    // total de post-its encontrados
    int total_found = 0;
    while(!q.empty()) {
        queue<char> temp_q;
        vector<char> it_line;
        while(!q.empty()) {
            char c = q.front(); q.pop();
            total_found++;
            it_line.push_back(c);
            for(char c2: adj[c]) {
                // como estamos "quitando" el c del grafo, restamos un indeg a todos los c->c2
                indeg[c2]--;
                if(indeg[c2] == 0) {
                    // para hacer por iteraciones, añadimos a una lista temporal
                    temp_q.push(c2);
                } 
            }    
        }
        sort(all(it_line));
        its.push_back(it_line);
        q = temp_q; // copiamos la lista temporal a la normal
    }
    // si no se encontraron todos, es imposible
    if(bounds.size() > 0  && total_found < bounds.size()) {
        // ciclo detectado
        cout << "IMPOSIBLE\n";
    } else {
        F0R(i, its.size()) {
            F0R(j, its[i].size()) {
                cout << its[i][j];
                if(j < its[i].size()-1) cout << " ";
            }
            cout << "\n";
        }
    }
    cout << "----\n";

    return;
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) solve();
}
