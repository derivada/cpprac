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

inline bool solve() {
    string sa; cin >> sa; if(!cin) return false; string sb; cin >> sb;
    ll na = 0, nb = 0;
    ll pow = 1;
    for(int i = sa.length()-1; i>=0; i--) {
        if(sa[i] > '5') sa[i]--;
        na += ((int) (sa[i] - '0')) * pow;
        pow *= 9;
    }
    pow = 1;
    for(int i = sb.length()-1; i>=0; i--) {
        if(sb[i] > '5') sb[i]--;
        nb += ((int) (sb[i] - '0')) * pow;
        pow *= 9;
    }
    // std::cout << "NA = " << na << " | NB = " << nb << endl;

    ll ans_base_10 = na*nb;
    // debug(ans_base_10);
    // convert to base 9
    // 16 = 10 + 6 = 9 + 7
    vector<ll> digits_ans;
    while(ans_base_10 > 0) {
        digits_ans.push_back(ans_base_10 % 9);
        ans_base_10 /= 9;
    }
    reverse(all(digits_ans));
    // F0R(i, digits_ans.size()) {
    //     cout << digits_ans[i] << ",";
    // }
    // cout << endl;
    if(digits_ans.size() == 0) {
        cout << "0\n"; return true;
    }
    string ans = "";
    F0R(i, digits_ans.size()) {
        if(digits_ans[i] >= 5) {
            digits_ans[i]++;
        }
        ans = ans + (char)(digits_ans[i] + '0');
    }
    cout << ans << endl;
    return true;
}

int main() {
    fastio;
    while (solve());
}
