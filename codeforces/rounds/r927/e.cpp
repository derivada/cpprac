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
    string s;
    cin >> s;
    vi pre(n);
    pre[0] = (int) (s[0] - 48);
    for(int i = 1; i<n; i++) {
        pre[i] = pre[i-1] + (int) (s[i] - 48);
    }
    vector<char> ans(n);
    int carry = 0;
    for(int i = n-1; i>=0; i--) {
        ans[i] = (pre[i]+carry) % 10;
        carry = (pre[i]+carry) / 10;
    }
    bool printed_carry = false;
    while(carry > 0) {
        printed_carry = true;
        int digit = carry % 10;
        cout << (char) (digit + 48);
        carry /= 10;
    }
    bool seen_diff_0 = false;
    for(int i = 0; i<n; i++) {
        if(ans[i] == 0 && !seen_diff_0 && !printed_carry){
            continue;
        }
        if(ans[i] != 0)
            seen_diff_0 = true;
        cout << (char) (ans[i] + 48);
    }
    cout << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
