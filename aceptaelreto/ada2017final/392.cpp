#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " is " << x << endl

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;
int comp_size;
bool dfs(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    comp_size++;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}


inline bool solve() {
    int n, p;
    cin >> n >> p;
    if(!n) return false;
    adj.assign(n, {});
    parent.assign(n, -1);
    visited.assign(n, false);
    cycle_start = -1;

    int start = 0;
    for(int i = 0; i<p; i++) {
        int from, to; cin >> from >> to; from--, to--;
        adj[from].push_back(to), adj[to].push_back(from);
        start = from;
    }
    // dfs
    stack<int> st;
    st.push(start);
    int total_in_cycles = 0;
    int biggest_comp = 0;
    for(int v = 0; v<n; v++) {
        if (!visited[v]) {
            comp_size = 0;
            bool has_cycle = dfs(v, parent[v]);
            if(has_cycle) {
                // extract cycle length and subtract it
                total_in_cycles += comp_size;
            } else {
                // no cycle
                biggest_comp = max(biggest_comp, comp_size);
            }
        }
    }

    if(biggest_comp >= n-total_in_cycles-1) {
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }
    return true;
}

int main() {
    while (solve());
}
