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

// WA
inline void solve() {
    int n; cin >> n;
    // distance matrix
    vector<vi> dist(n+1, vi(n+1, 0));
    vector<pi> points(n+1);
    points[0] = {0,0};
    F0R(i, n) {
        int x, y; cin >> x >> y;
        points[i+1] = {x,y};
    }
    F0R(i, n+1) {
        F0R(j, n+1) {
            dist[i][j] += std::max(points[i].F, points[j].F) - std::min(points[i].F, points[j].F);
            dist[i][j] += std::max(points[i].S, points[j].S) - std::min(points[i].S, points[j].S);
        }
    }
    int pos1 = 0, pos2 = 0;
    ll res = 0;
    F0R(i, n+1) {
        if(dist[pos1][i] < dist[pos2][i]) {
            res += dist[pos1][i];
            pos1 = i;
        } else if(dist[pos1][i] > dist[pos2][i]) {
            res += dist[pos2][i];
            pos2 = i;
        } else {
            // equal -> choose min sum of remaining dist
            int sum_dist1 = 0, sum_dist2 = 0;
            for(int j = i; j<=n; j++) {
                sum_dist1 += dist[pos1][j], sum_dist2 += dist[pos2][j];
            }
            if(sum_dist1 < sum_dist2) {
                res += dist[pos1][i];
                pos1 = i;
            } else {
            res += dist[pos2][i];
            pos2 = i;
            }
        }
    }

    std::cout << res << "\n";
    return;
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) solve();
}
