using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define ld long double
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i< b; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)

short dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
short dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline int count_bombs(int x, int y, vector<vector<short>> &adj, int n, int m) {
    int count = 0;
    F0R(i, 8) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if(adj[nx][ny] == 10) count++;
    }
    if(count == 0) return -1;
    return count;
}

inline bool solve() {
    int n, m; cin >> n;
    if(!cin) return false;
    cin >> m;
    vector<vector<short>> adj(n, vector<short>(m, 0));
    F0R(i, n) {
        string s; cin >> s;
        F0R(j, m) {
            if(s[j] == '*')
                adj[i][j] = 10;
        }
    }
    int k;
    cin >> k;
    queue<pi> q;

    F0R(i, k) {
        int x, y; cin >> x >> y;
        x--, y--;
        if(adj[x][y] == 10) {
            cout << "GAME OVER\n";
            while(i < k) {
                i++;
                cin >> x >> y;
            }
            return true;
        }
        if(adj[x][y] == -1) // ya revelado
            continue; 

        adj[x][y] = 0; // revelar
        q.push(MP(x, y));
        while(!q.empty()) {
            x = q.front().F, y = q.front().S; q.pop();
            adj[x][y] = count_bombs(x, y, adj, n, m);
            if(adj[x][y] == -1) {
                F0R(j, 8) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || adj[nx][ny] != 0)
                        continue;
                    q.push(MP(nx, ny));
                }
            }
        }
    }
    F0R(i, n) {
        F0R(j, m) {
            switch(adj[i][j]) {
                case -1: cout << '-'; break;
                case 0: cout << "X"; break;
                case 10: cout << "X"; break;
                default: cout << adj[i][j];
            }
        }
        cout << "\n";
    } 
    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    while(solve());
}