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

inline bool solve() {
    int f, c, n; cin >> f >> c >> n;
    if(!f && !c && !n) {
        return false;
    }
    vector<vector<pi>> ins(c, vector<pi>(0));    
    vector<vector<pi>> outs(c, vector<pi>(0));    

    F0R(i, n) {
        int col, a, b, m; cin >> col >> a >> b >> m;
        ins[col].PB(MP(a, m));
        outs[col].PB(MP(b, m));
    }
    F0R(i, c) {
        sort(all(ins[i]));
        sort(all(outs[i]));
    }
    vector<vector<int>> ans(c, vector<int>(f, 0));
    F0R(i, c) {
        // update matrix
        int sum = 0, l = 0, r = 0, m = ins[i].size();
        F0R(j, f) {
            while(r < m && ins[i][r].F <= j) {
                sum += ins[i][r].S;
                r++;
            }
            while(l < m && outs[i][l].F < j) {
                sum -= outs[i][l].S;
                l++;
            }
            ans[i][j] = sum;
        }
    }
    F0R(j, f) {
        F0R(i, c) {
            cout << ans[i][j] << " ";
        }
        if(j < f-1)
            cout << "\n";
    }
    return true;
}

int main() {
    fastio;
    while (solve());
}
