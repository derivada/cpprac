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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value
#define INF 1e9+5


inline bool solve() {
    int n;
    cin >> n;
    if(!cin) return false;
    int k;
    cin >> k;
    vector<vector<pi>> adj((n+1) * 60);
    FOR(i, 1, n+1)
        F0R(j, 60)
                adj[i*60+j].PB(MP(i*60 + ((j+1) % 60), 1)); // esperar 1 min

    string t;
    getline(cin, t); // el input format es estupido y hay que leer esto e ignorarlo para que funcione
    F0R(i, k) {
        int curr_time = 0;
        string s;
        getline(cin, s);
        istringstream iss(s);
        vector<int> numbers;
        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }
        if(numbers.size() > 1) {
            // Añadimos bordes con 0 de distancia ya que ir en bus no suma tiempo de espera
            for(int i = 0; i<numbers.size()-1; i+=2) {
                int u = numbers[i], delta = numbers[i+1], v = numbers[i+2], next_time = curr_time + delta;
                adj[u*60 + curr_time].PB(MP(v*60 + next_time, 0));
                curr_time = next_time;
            }
            adj[(numbers[numbers.size()-1])*60 + curr_time].PB(MP(numbers[0]*60, 0));
        }
    }

    // 0-1 BFS (epic algorithm)
    vector<int> d((n+1)*60, INF);
    deque<int> q;
    int s = 60;
    d[s] = 0;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
    
    // Coger entre los 60 minutos de la estacion final cual es el mejor
    int ans = INF;
    F0R(i, 60)
        ans = min(ans, d[n*60 + i]);
    
    if(ans == INF) {
        cout << "Hoy no vuelvo\n";
    } else {
        cout << ans << "\n";
    }
    return true;
}

int main() {
    fastio;
    while(solve());
}
