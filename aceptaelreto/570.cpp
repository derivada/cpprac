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

const char val[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 
                'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 
                'C', 'K', 'E'};
const int mults[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};


inline void solve() {
    string s; cin >> s;
    int sum = 0;
    vi interr;
    int total = 1;
    F0R(i, 8) {
        if(s[i] == '?') {
            interr.PB(i);
            total *= 10;
        } else {
            sum += (s[i] - '0') * mults[i];
        }
    }
    int ans = 0;
    for(int i = 0; i<total; i++) {
        int sum_interr = 0;
        int tmp = i, j = 0;
        while(tmp > 0) {
            sum_interr += (tmp % 10) * mults[interr[j]];
            tmp /= 10;
            j++;
        }
        if(val[(sum + sum_interr) % 23] == s[8])
            ans++;
    }
    cout << ans << "\n";
}

int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
