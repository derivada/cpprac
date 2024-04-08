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

int dirx[4] = {1, 0, -1, 0}; int diry[4] = {0, 1, 0, -1};

inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (m, 1e9));
    pi start;
    queue<pair<pi, int>> q;
    F0R(i, n) {
        string s; cin >> s;
        F0R(j, m) {
            if(s[j] == '#') {
                g[i][j] = 0;
            } else if(s[j] == 'M') {
                g[i][j] = 0;
                q.push(MP(MP(i, j), 0));
            } else if(s[j] == 'A') {
                start = MP(i, j);
            }
        }
    }
    // bfs in all monters to fill graph with numbers on what turn max you can go there
    while(!q.empty()) {
        pi u = q.front().F; int turn = q.front().S; q.pop();
        for(int i = 0; i<4; i++) {
            int x = u.F+dirx[i], y = u.S + diry[i];
            if(x >= 0 && y >= 0 && x < n && y < m && g[x][y] > turn + 1) {
                g[x][y] = turn + 1;
                q.push(MP(MP(x, y), turn + 1));
            }
        }
    }
    /*
    F0R(i, n){
        F0R(j, m){
            if(g[i][j] == 1e9)
                cout << ".";
            else 
                cout << g[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    */
    // human pathfinding, escape through tiles where currdepth < tile_value 
    q.push(MP(start, 0));
    vector<vector<int>> pred(n, vector<int>(m, -1));
    while(!q.empty()) {
        // check if win
        int x = q.front().F.F, y = q.front().F.S, depth = q.front().S; q.pop();
        if(x == 0 || x == n-1 || y == 0 || y == m-1) {
            cout << "YES\n";
            // print path
            vector<char> path;
            char letter_dir[4] = {'D', 'R', 'U', 'L'};
            while(pred[x][y] != -1) {
                int nx = x - dirx[pred[x][y]], ny = y - diry[pred[x][y]];
                path.PB(letter_dir[pred[x][y]]);
                x = nx, y = ny;
            }
            reverse(all(path));
            cout << path.size() << "\n" << string(all(path)) << "\n";
            return;
        }
        for(int i = 0; i<4; i++) {
            int dx = x + dirx[i], dy = y + diry[i];
            if(dx >= 0 && dy >= 0 && dx < n && dy < m && g[dx][dy] > depth + 1) {
                pred[dx][dy] = i;
                q.push(MP(MP(dx, dy), depth + 1));
            }
            // dont go back
            g[x][y] = 0;
        }
    }
    cout << "NO\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
