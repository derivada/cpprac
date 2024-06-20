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

inline bool solve() {
    int f, c;
    cin >> f >> c;
     if(!f && !c) 
        return false;
    vector<vector<bool>> m(f, vector<bool>(c, false));
    vector<vector<bool>> seen(f, vector<bool>(c, false));
    F0R(i, f) {
        string s; cin >> s;
        F0R(j, c) {
            m[i][j] = s[j] == '.';
        }
    }
    if(!m[0][0]) {
        cout << "NO\n"; return true;
    }
    queue<pi> q;
    q.push(MP(0, 0));
    int dx[4] = {1, 0, -1, 0}; int dy[4] = {0, 1, 0, -1};
    while(!q.empty()) {
        pi curr = q.front(); q.pop();
        if(!seen[curr.F][curr.S]) {
            seen[curr.F][curr.S] = true;
            F0R(i, 4) {
                int nx = min(f-1, max(0, dx[i] + curr.F));
                int ny = min(c-1, max(0, dy[i] + curr.S));
                if(!seen[nx][ny] && m[nx][ny])
                    q.push(MP(nx, ny));
            }
        }
    }
    if(seen[f-1][c-1]) {
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }
    return true;
}

int main() {
    fastio;
    while (solve());
}
