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

inline void solve() {
    int n;
    cin >> n;
    vi v(n,0);
    F0R(i, n){ 
        cin >> v[i];
    }
    vi right(n,0), left(n,0); // distances from city 0 to i and from city n to i
    if(n> 2) {
        right[1] = 1, left[n-2] = 1;
        for(int i = 2; i<n; i++) {
            int prev = abs(v[i-1] - v[i-2]), curr = abs(v[i] - v[i-1]);
            if(curr > prev) right[i] = right[i-1] + curr;
            else right[i] = right[i-1] + 1;
        }
        for(int i = n-3; i>=0; i--) {
            int prev = abs(v[i+1] - v[i+2]), curr = abs(v[i] - v[i+1]);
            if(curr > prev) left[i] = left[i+1] + curr;
            else left[i] = left[i+1] + 1;
        }
    } else {
        right[1] = 1, left[0] = 1;
    }
    /*
        F0R(i, n) cout << left[i] << " ";
        cout << endl;
        F0R(i, n) cout << right[i] << " ";
        cout << endl;
    */
    int m;
    cin >> m;
    F0R(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(x < y) {
            cout << (right[y] - right[x]) << "\n";
        } else {
            cout << -(left[x] - left[y]) << "\n";
        }
    }
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
