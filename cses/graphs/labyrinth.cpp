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

#define B_VAL 2
inline void solve() {
    // TLE
    int n, m;
    cin >> n >> m;
    // use adj matrix representation this time
    vector<vi> g(n, vi(m, 0));
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    pi start;
    F0R(i, n) {
        string s;
        cin >> s;
        F0R(j, m){
            if(s[j] == '.') {
                g[i][j] = 1;
            } else if(s[j] == 'A') {
                start = MP(i, j);
                g[i][j] = 1;
            } else if(s[j] == 'B') {
                g[i][j] = B_VAL;
            }
        }
    }
    // bfs starting in A
    queue<pi> q;
    q.push(start);
    int dx[4] = {-1, 0, 1, 0}; int dy[4] = {0, 1, 0, -1};
    char mpath[4] = {'U', 'R', 'D', 'L'};
    vector<char> path;
    while(!q.empty()) {
        pi curr = q.front(); q.pop();
        if(seen[curr.F][curr.S]) {
            path.pop_back();
            continue;
        }
        //cout << "checking out " << curr.F << " " << curr.S << "\n";
        if(g[curr.F][curr.S] == B_VAL) {
            cout << "YES\n" << path.size() << "\n" << string(all(path)) << "\n";
            return;
        }
        for(int i = 0; i<4; i++) {
            int nx = curr.F + dx[i]; int ny = curr.S + dy[i];
            if(nx >= 0 && nx < n && ny>=0 && ny<m & !seen[nx][ny]){
                q.push(MP(nx, ny));
                path.push_back(mpath[i]);
            }
        }
        seen[curr.F][curr.S] = true;
    }
    cout << "NO\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
