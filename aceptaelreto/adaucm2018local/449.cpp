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

int INF = 1e9 + 5;
vector<vi> dp;
string t;

inline void trim(int i, int j) {
    if(j-i <= 1) { // caso i = j y i+1 = j, tener en cuenta que t[i] != t[i+1] por construcción
        dp[i][j] = j - i + 1;
        return;
    }
    if(t[i] == t[j]) { // letras coinciden
        if(dp[i+1][j-1] == INF) trim(i+1, j-1);
        dp[i][j] = dp[i+1][j-1] + 1;
    } else { // letras no coinciden
        if(dp[i+1][j] == INF) trim(i+1, j);
        if(dp[i][j-1] == INF) trim(i, j-1);
        dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1);
    }
}

inline bool solve() {
    string s; cin >> s;
    if(!cin) return false;
    dp.clear();
    t.clear();
    t = s[0];
    FOR(i, 1, s.length()) {
        if(s[i] != s[i-1]) t+=s[i];
    }
    int n = t.length();
    dp.assign(n, vi(n, INF));
    trim(0, n-1);
    cout << dp[0][n-1] << endl;
    return true;
}

int main() {
    fastio;
    while(solve());
}
