#include <bits/stdc++.h>
using namespace std;
#define fastio cin.sync_with_stdio(0); cin.tie(0);

#define F first
#define S second
#define F0R(i,n) for(int i = 0; i<n; i++)
#define PB push_back
#define all(a) (a).begin(), (a).end()
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

constexpr ll INF = 1e18 * 8;

vector<vector<pll>> adj;
vector<bool> waypoints_used;

void dijkstra(int s, vector<ll> &d) {
    int n = adj.size(); d.assign(n, INF);
    d[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});

    while(!q.empty()) {
        ll v = q.top().S;
        ll d_v = q.top().F;
        q.pop();
        if(d_v != d[v]) continue;
        for(auto edge: adj[v]) {
            ll to = edge.F, len = edge.S;
            if(waypoints_used[to]) {
                continue;
            }
            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
    fastio;
    ll n, c; cin >> n >> c;
    adj.resize(n);
    F0R(i, c) {
        ll from, to, w; cin >> from >> to >> w;
        from--, to--;
        adj[from].push_back(make_pair(to, w));
    }
    ll start, end, w;
    cin >> start >> end >> w;
    start--, end--;
    ll res = 0;
    vector<ll> d, p;
    ll current_source = start;
    waypoints_used.assign(n, false);
    F0R(i, w) {
        ll waypoint; cin >> waypoint; waypoint--;
        dijkstra(current_source, d);
        waypoints_used[current_source] = true;
        res += d[waypoint];
        current_source = waypoint;
    }
    dijkstra(current_source, d);
    res += d[end];
    cout << res << "\n";
}