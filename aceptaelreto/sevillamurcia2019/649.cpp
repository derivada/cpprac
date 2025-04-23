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

inline bool solve() {
    int n, m, t;
    cin >> n; if(!cin) return false; cin >> m >> t;

    // prio_queue sorted by start time: (2,3) (3,4) (3,5)
    // if current_end > next_start there is a conflict
    // add flag for periodics
    // .F start time .S.F end time, .S.S period (0 if aperiodic)
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> prio; 
    
    F0R(i, n) {
        int st, end; cin >> st >> end;
        prio.push(MP(st, MP(end, 0)));
    }
    F0R(i, m) {
        int st, end, period;
        cin >> st >> end >> period;
        prio.push(MP(st, MP(end, period)));
    }
    int curr_time = -1, total_tasks = 0;
    while(!prio.empty() && prio.top().F < t && total_tasks <= 100000) {
        auto elem = prio.top();
        prio.pop();
        int st = elem.F, end = elem.S.F, period = elem.S.S;
        // cout << "st = " << st;
        // cout << "  end = " << end;
        // cout << "  period = " << period << endl;
        if(curr_time > st) {
            cout << "SI\n"; return true;
        }
        if(period != 0) {
            prio.push(MP(st+period, MP(end+period, period)));
        }
        
        curr_time = end;
        // debug(curr_time);
        total_tasks++;
    }

    cout << "NO\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}