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

inline void solve() {
    int n; ll k;
    cin >> n >> k;
    vi v(n+1); vi ans(n+1);
    if(k%2 == 1) {
        cout << "No\n"; return;
    }
    for(int i = 1; i<=n; i++){
        v[i] = i;
        ans[i] = i;
    }
    
    int l = 1, r = n;
    while(l < r) {
        int diff = r-l;
        //debug(l); debug(r); debug(k);
        if(2*diff <= k) {
            // swap
            ans[r] = v[l];
            ans[l] = v[r];
            k -= 2*diff;
            l++, r--;
        } else {
            // not swap
            l++;
        }
    }
    if(k == 0) {
        cout << "Yes\n";
        for(int i = 1; i<=n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    } else {
        cout << "No\n";
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
