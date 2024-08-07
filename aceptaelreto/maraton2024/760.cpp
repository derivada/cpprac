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

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int power(int x, unsigned int y, int p) {
    int res = 1; 
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
int modInverse(int a, int p) {
    return power(a, p - 2, p);
}
 
int modFact(int n, int p) {
    if (p <= n)
        return 0;
    int res = (p - 1);
    for (int i = n + 1; i < p; i++)
        res = (res * modInverse(i, p)) % p;
    return res;
}

inline void solve() {
    int t, a, b;
    cin >> t >> a >> b;
    ll n = t*t;
    debug("test");
    ll num = (modFact(n-a, MOD) * modFact(a, MOD)) % MOD;
    debug(num);
    ll denum = (modFact(n-b, MOD) * modFact(b, MOD)) % MOD;
    debug(denum);
    ll denum_inv = binpow(denum, MOD-2, MOD);
    debug(denum_inv);
    ll ans = (num * denum_inv) % MOD;
    cout << ans << "\n";
}

int main() {
    fastio;
    int tc; cin >> tc;
    while (tc--){
        solve();
    }
}
