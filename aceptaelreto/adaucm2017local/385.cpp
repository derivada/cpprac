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

inline void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> g(n, vi(m, 0)); // 1 = no se puede pasar
    pi start, end;
    vector<pair<pi, int>> sensors;
    F0R(i, n) {
        string s; cin >> s;
        F0R(j, m) {
            if(s[j] == 'E') {
                start = MP(i, j);
            } else if(s[j] == 'P') {
                end = MP(i, j);
            } else if('0' <= s[j] && s[j] <= '9') {
                g[i][j] = 1;
                sensors.PB(MP(MP(i, j), s[j] - '0'));
            } else if(s[j] == '#') {
                g[i][j] = 2;
            }
        }
    }
    int dx[4] = {1, 0, -1, 0}; int dy[4] = {0, 1, 0, -1};
    F0R(i, sensors.size()) {
        pi coords = sensors[i].F; int span = sensors[i].S;
        for(int j = 0; j < 4; j++) {
            for(int k = 1; k<=span;  k++) {
                int nx = coords.F + k*dx[j];
                int ny = coords.S + k*dy[j];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == 2)
                    break;
                else
                    g[nx][ny] = 1;
            }
        }
    }
    F0R(i, n) {
         F0R(j, m) {
             cout << g[i][j];
         } 
         cout << "\n";
    }
    if(g[start.F][start.S] || g[end.F][end.S]) {
        cout << "NO\n";
        return;
    }
    queue<pi> q;
    vector<vi> d(n, vi(m, -1));
    q.push(start);
    d[start.F][start.S] = 0;
    
    while(!q.empty()) {
        pi u = q.front(); q.pop();
        if(u == end) {
            cout << d[u.F][u.S] << "\n";
            return;
        }
        F0R(j, 4) {
            int nx = u.F + dx[j], ny = u.S + dy[j];
            if(nx < 0 || nx >= n || ny  < 0 || ny >= m) {
                continue;
            }
            if(d[nx][ny] == -1 && !g[nx][ny]) {
                d[nx][ny] = d[u.F][u.S] + 1;
                q.push(MP(nx, ny));
            } 
        }
    }
    cout << "NO\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
