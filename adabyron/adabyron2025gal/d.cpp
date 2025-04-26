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
vi d;
vector<vector<pi>> adj;

void bfs_01(int s) {
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(auto edge: adj[v]) {
            int u = edge.first, w = edge.second;
            if(d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if(w == 1) {
                    q.push_back(u);
                } else {
                    q.push_front(u);
                }
            }
        }
    }
}

int main() {
    fastio;
    int m, n; cin >> m >> n;
    d.clear(); d.assign(n, 1e7 + 7);
    adj.clear(); adj.resize(n);
    F0R(i, n-1) {
        adj[i].push_back({i+1, 1});
    }
    F0R(i, m) {
        int from, to; cin >> from >> to; from--, to--;
        adj[from].push_back({to, 0});
    }

    bfs_01(0);
    cout << d[n-1] << "\n";
}