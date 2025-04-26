#include <bits/stdc++.h>
using namespace std;
#define fastio cin.sync_with_stdio(0); cin.tie(0);

#define F first
#define S second
#define F0R(i,n) for(int i = 0; i<n; i++)
#define PB push_back
#define all(a) (a).begin(), (a).end()
using pi = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;
const int INF = 1e7 + 7;

vector<vector<bool>> mat;
vector<vector<bool>> seen;
int n, m;
inline void bfs(int i, int j) {
    constexpr int dx[8] = {-1, 0, 1, -1,  1, -1, 0, 1};
    constexpr int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    queue<pi> q;
    q.push(make_pair(i, j));
    while(!q.empty()) {
        pi coords = q.front(); q.pop();
        int x = coords.F, y = coords.S;
        if(seen[x][y])
            continue;
        seen[x][y] = true;
        F0R(j, 8) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
                !seen[nx][ny] && mat[nx][ny]) {
                q.push(make_pair(nx, ny));
            }          
        }
    }
}

void solve() {
    cin >> n >> m;
    mat.clear(), seen.clear();
    mat.resize(n);
    seen.resize(n);
    F0R(i, n) {
        mat[i].resize(m);
        seen[i].assign(m, false);
        F0R(j, m) {
            int x; cin >> x;
            mat[i][j] = x;
        }
    }
    ll total = 0;
    F0R(i, n) {
        F0R(j, m) {
            if(!seen[i][j] && mat[i][j]) {
                total++;
                bfs(i, j);
            }
        }
    }
    cout << total << "\n";
}


int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) solve();
}