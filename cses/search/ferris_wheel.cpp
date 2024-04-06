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
    int n, x; cin >> n >> x;
    multiset<int> v;
    F0R(i, n){
        int x; cin >> x; v.insert(x);
    }
    int ans = 0;
    while(!v.empty()) {
        auto it = v.lower_bound(x);
        if (it != v.begin() && *it != x)
            it--;
        v.erase(it); // remove biggest
        if(!v.empty()) {
            int rem = x - *it;
            auto it2 = v.lower_bound(rem);
            if (it != v.begin() && *it2 != rem)
                it2--;
            if(it2 != v.begin()){
                v.erase(it2);
            }
        }
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    fastio;
    solve();
}
