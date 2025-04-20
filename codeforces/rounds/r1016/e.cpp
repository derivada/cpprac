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

inline bool check_possible(int MEX, int k, const vi &v) {
    int n = v.size();
    // debug(MEX); debug(k);
    // check if we can do min mex of k subpartitions
    int i=0, j = 0;
    while(j < n){
        unordered_set<int> found;
        while(found.size() <= MEX && j < n) {
            if(v[j] <= MEX) {
                found.insert(v[j]);
            }
            // debug(found.size());
            j++;
        }
        if(found.size() == (MEX+1))
            i++;
    }
    // if(i == k) 
    // {
    //     std::cout << "m = " << MEX << " is possible\n";
    // } else {
    //     std::cout << "m = " << MEX << " is not possible\n";

    // }
    return (i >= k);
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    F0R(i, n) {
        cin >> v[i];
    }
    int l = -1, r = n, MEX;
    while (r - l > 1) {
        MEX = (l + r) / 2;
        if (!check_possible(MEX, k, v)) {
            r = MEX;
        } else {
            l = MEX;
        }
    }
    
    cout << l+1 << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
