#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
#define debug(x) cout << #x << " is " << x << endl
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

vector<vector<short>> dp;

inline bool solve() {
    string s;
    cin >> s; if(!cin) return false;
    int n = s.length();
    dp.assign(n, vector<short>(n, -1));
    F0R(i, n)
        dp[i][i] = 1;
    for(int len = 2; len<=n; len++) {
        for(int l = 0; l+len-1<n; l++) {
            int r = l+len-1;
            if (s[l] == s[r]) {
                if (len == 2) dp[l][r] = 2;
                else dp[l][r] = dp[l+1][r-1] + 2;
            } else {
                dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
    }
    // reconstruct 0..n
    string left = "", right = "";
    int l = 0, r = n-1;
    while (l <= r) {
        if (l == r) {
            left += s[l];
            break;
        }
        if (s[l] == s[r]) {
            left += s[l];
            right = s[r] + right;
            l++, r--;
        } else {
            if (dp[l+1][r] >= dp[l][r-1])
                l++;
            else
                r--;
        }
    }
    cout << (left+right) << endl;
    return true;
}

int main() {
    fastio;
    while(solve());
}
