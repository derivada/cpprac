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


inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(m, false));
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    vector<int> count_r(n, 0), count_c(m, 0);
    F0R(i, n) {
        string s; cin >> s;
        F0R(j, m) {
            if(s[j] == '#') {
                g[i][j] = true;
                count_r[i]++;
                count_c[j]++;
            }
        }
    }
    vector<pair<pi, int>> rows; // range x1-x2 of cc and size
    vector<pair<pi, int>> cols; // range y1-y2 of cc and size
    queue<pair<int,int>> q;
    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    F0R(i, n) {
        F0R(j, m) {
            if(g[i][j] && !seen[i][j]) {
                int w = 0;
                int min_x = i, min_y = j, max_x = i, max_y = j;
                q.push(MP(i, j));
                while(!q.empty()) {
                    pi curr = q.front(); q.pop();
                    seen[curr.F][curr.S] = true;
                    min_x = min(min_x, curr.F);
                    min_y = min(min_y, curr.S);
                    max_x = max(max_x, curr.F);
                    max_y = max(max_y, curr.S);
                    w++;
                    F0R(i, 4) {
                        int nx = min(n-1, max(0, curr.F+dx[i]));
                        int ny = min(m-1, max(0, curr.S+dy[i]));
                        if(g[nx][ny] && !seen[nx][ny]) {
                            q.push(MP(nx, ny));
                        }
                    }
                }
                rows.PB(MP(MP(min_x, max_x), w));
                cols.PB(MP(MP(min_y, max_y), w));
            }
        }
    }

    int ans = 0;
    sort(all(rows));
    sort(all(cols));
    int in = 0, out = 0, curr = 0;
    F0R(i, n) {
        while(in < rows.size() && rows[in].F.F <= i) {
            curr += rows[in].S;
            in++;
        }
        while(out < rows.size() && rows[out].F.S > i) {
            curr -= rows[out].S;
            out++;
        }
        if(i == 0)
            curr = curr + n - count_r[0];
        else
            curr = curr - count_r[i-1] + count_r[i];
        debug(i); debug(curr);
        ans = max(curr, ans);
    }
    in = 0, out = 0, curr = 0;
    F0R(j, m) {
        while(in < cols.size() && cols[in].F.F <= j) {
            curr += cols[in].S;
            in++;
        }
        while(out < cols.size() && cols[out].F.S > j) {
            curr -= cols[out].S;
            out++;
        }
        if(j == 0)
            curr = curr + n - count_c[0];
        else
            curr = curr - count_c[j-1] + count_c[j];
        debug(j); debug(curr);
        ans = max(curr, ans);
    }
    cout << ans << "\n";
}  

int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
