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
const int INF = 1e9 + 5;

vector<vector<pair<int, pair<int, int>>>> adj;
int max_t;

void dijkstra(int s, vector<int>& d, vector<int>& time) {
    int n = adj.size();
    d.assign(n, INF);
    time.assign(n, INF);
    time[0] = 0;
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.F;
            int len = edge.S.F, d_time = edge.S.S;

            if (d_time + time[v] <= max_t && d[v] + len < d[to]) {
                d[to] = d[v] + len;
                time[to] = d_time + time[v];
                q.push({d[to], to});
            }
        }
    }
}

inline bool solve() {
    int n;
    cin >> n;
    if(!n) return false;
    vi I(n), F(n), T(n);
    F0R(i, n) {
        cin >> I[i] >> F[i] >> T[i];
    }
    int start, end;
    cin >> start >> end >> max_t;
    adj.clear();
    adj.resize(end+1);
    for(int i = 1; i<=end; i++) {
        adj[i].PB(MP(i-1, MP(1, 1))); // esquiar abajo
    }
    for(int i = 0; i<n; i++) {
        adj[I[i]].PB(MP(F[i], MP(0, T[i]))); // remontes
    }
    vi d, time;
    debug("test");
    dijkstra(start, d, time);
    debug("test");
    if(time[end] == INF) {
        cout << "IMPOSIBLE\n";
    } else {
        cout << d[end] << "\n";
    }
    return true;
}

int main() {
    fastio;
    while (solve());
}
