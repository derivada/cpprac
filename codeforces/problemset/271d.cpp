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
const ll MOD = 1e9 + 9;
const int p = 31;

inline void solve() {
    string s, bad;
    int k;
    cin >> s >> bad >> k;
    int n = s.length();
    unordered_set<char> b;
    F0R(i, 26) {
        if((bad[i] - '0') == 0)
            b.insert(i + 'a');
    }

    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % MOD;

    vector<long long> h(n + 1, 0);
    vector<int> bad_prefix(n+1, 0);
    for (int i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
        bad_prefix[i+1] = bad_prefix[i] + (b.find(s[i]) != b.end());
    }
    ll cnt = 0;
    for (int l = 1; l <= n; l++) {
        unordered_set<long long> hs;
        int c = bad_prefix[l];
        for (int i = 0; i <= n - l; i++) {
            if(c <= k) {
                long long cur_h = (h[i + l] + MOD - h[i]) % MOD;
                cur_h = (cur_h * p_pow[n-i-1]) % MOD;
                hs.insert(cur_h);
            }
            if(b.find(s[i]) != b.end()) {
                c--;
            }
            if((b.find(s[i+l]) != b.end())) {
                c++;
            }
        }
        cnt += hs.size();
    }
    cout << cnt << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}
