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

vector<vector<int>> mat; // 0 -> nada, 1 -> start, 2 -> objetivo
vector<vi> d;
int min_seen = 1e7;
int n, m;

inline void bfs01(int i, int j) {
    d.resize(n);
    F0R(i, n)
        d[i].assign(m, INF);
    d[i][j] = 0;
    deque<pi> q;
    constexpr int dx[4]  = {1, 0, -1, 0};
    constexpr int dy[4] = {0, 1, 0, -1};
    q.push_front(make_pair(i, j));
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop_front();
        F0R(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            // si no es 1 (start), la distancia es 1
            int w = (mat[nx][ny] != 1);
            if(d[x][y] + w < d[nx][ny]) {
                d[nx][ny] = d[x][y] + w;
                if(mat[nx][ny] == 2) {
                    min_seen = min(d[nx][ny], min_seen);
                }
                if(w == 1) {
                    q.push_back(make_pair(nx, ny));
                } else {
                    q.push_front(make_pair(nx, ny));
                }
            }
        }
    }
}


int main() {
    fastio;
    min_seen = 1e7;
    cin >> n >> m;
    mat.clear();
    mat.resize(n);
    int size_comp = 0;
    int first_x = -1, first_y = -1;
    F0R(i, n) {
        mat[i].resize(m);
        F0R(j, m) {
            int x; cin >> x;
            if(x && first_x == -1) {
                first_x = i, first_y = j;
            }
            mat[i][j] = x;
            if(x == 1) {
                size_comp++;
            }
        }
    }
    int overlap = 0;
    F0R(i, n) {
        F0R(j, m) {
            int x; cin >> x;
            if(x == 1) {
                if(mat[i][j] == 1)
                    overlap++;
                mat[i][j] = 2;
            }
        }
    }
    // cout << "OVERLAP =" << overlap << endl;
    if(overlap > 0) {
        cout << (size_comp-overlap) << "\n"; return 0;
    }
    d.clear();
    bfs01(first_x, first_y);
    // cout << "MATRIZ DISTANCIAS = \n";
    // F0R(i, n) {
    //     F0R(j, m){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (min_seen + (size_comp - 1)) << "\n"; return 0;
}