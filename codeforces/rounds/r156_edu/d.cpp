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
const ll MOD = 998244353;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

inline void solve() {
    int n, m;
    string s; // len n-1
    cin >> n >> m >> s;
    vi qn(m, 0); vector<char> qc(m, 0);
    F0R(i, m) {
        int a;
        cin >> a;
        a--;
        qn[i] = a;
        cin >> qc[i];
    }

    ll ans = 1;
    for(int i = n-2; i>1; i--) {
        if(s[i] == '?')
            ans = (ans * i) % MOD;
    }

    if(s[0] != '?')
        cout << ans << "\n";
    else 
        cout << "0\n";

    F0R(i, m) {
        if(qn[i] > 0) {
            if(qc[i] != '?' && s[qn[i]] == '?') {
                ll div = binpow(qn[i], MOD-2, MOD); // modular inverse
                ans = (ans * div) % MOD;
            } else if(qc[i] == '?' && s[qn[i]] != '?') {
                ans = (ans * qn[i]) % MOD;
            }
        }
        s[qn[i]] = qc[i];
        if(s[0] != '?')
            cout << ans << "\n";
        else 
            cout << "0\n";
    }
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    solve();
}