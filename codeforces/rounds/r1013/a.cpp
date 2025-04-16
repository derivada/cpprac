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
    int n; cin >> n; vi v(n);
    F0R(i, n)
        cin >> v[i];
    // 01 03 2025
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt5 = 0;
    F0R(i, n){
        if(v[i] == 0)
            cnt0++;
        if(v[i] == 1)
            cnt1++;
        if(v[i] == 2)
            cnt2++;
        if(v[i] == 3)
            cnt3++;
        if(v[i] == 5)
            cnt5++;
        if(cnt0 >= 3 && cnt1 >= 1 && cnt2 >= 2 && cnt3 >= 1 && cnt5 >= 1){
            std::cout << (i+1) << "\n";
            return;
        }
    }
    std::cout << "0\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
