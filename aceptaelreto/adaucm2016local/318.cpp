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


int INF = 1e9 + 5;
vector<vector<pi>> adj;

void dijkstra(int s, vi &d) {
    int n = adj.size();
    d.assign(n, INF);

    d[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push(MP(0, s));

    while(!q.empty()) {
        int v = q.top().S; int d_v = q.top().F;

        q.pop();

        if(d_v != d[v]) continue;

        for(auto edge: adj[v]) {
            int to = edge.F, len = edge.S;
            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push(MP(d[to], to));
            }
        } 
    }
}

inline bool solve() {
    int n; cin >> n;
    if(!cin) return false;
    adj.clear();
    adj.resize(n+1);
    
    vi pesos(n);
    F0R(i, n)
        cin >> pesos[i];

    int m;
    cin >> m;
    F0R(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB(MP(v, w + pesos[v-1]));
    }

    vi d;
    dijkstra(1, d);
    if(d[n] != INF) {
        cout << d[n]+pesos[0] << "\n";
    } else {
        cout << "IMPOSIBLE\n";
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    while(solve());
}