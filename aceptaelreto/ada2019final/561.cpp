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

int m;
inline vi sum(vi s, vi t) {
    vi res(m+1);
    int carry = 0;
    F0R(i, m+1) {
        res[i] = (carry + s[i] + t[i]) % 10;
        carry = (s[i] + t[i]) >= 10; 
    }
    reverse(all(res));
    return res;
}

inline vi sub(vi s, vi t) {
    vi res(m+1);
    int carry = 0;
    F0R(i, m+1) {
        int d = s[i] - carry;
        if(d >= t[i]) {
            res[i] = d - t[i];
            carry = 0;
        } else {
            d += 10;
            res[i] = d - t[i];
            carry = 1;
        }
    }
    reverse(all(res));
    return res;
}

inline vi inv(int d) {
    vi res(m+1);
    int D = 1;
    F0R(i, m+1) {
        D *= 10;
        res[i] = D / d;
        D %= d;
    }
    return res;
}

inline bool solve() {
    int n;
    cin >> n;
    if(!n) return false;
    cin >> m;
    
    vi ans(m+1, 0); // order is from LST to MST
    int sgn = 0;
    F0R(i, n) {
        if(sgn)
            ans = sum(ans, inv(1 + 2*i));
        else
            ans = sub(ans, inv(1 + 2*i));
        sgn ^= 1;
    }
    if(n == 1 || m == 0)
        cout << "1.";
    else
        cout << "0.";
    F0R(i, m)
        cout << ans[i];
    cout << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
