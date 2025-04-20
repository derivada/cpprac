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


vector<ll> make_pre(const vector<ll> &v) {
    int n = v.size();
    vector<ll> pre(n);
    pre[0] = v[0];
    for(int i =1; i<n;i++) 
        pre[i] = pre[i-1] + v[i];
    return pre;
}
vector<ll> make_suff_exclusive(const vector<ll> &v) {
    int n = v.size();
    vector<ll> pre(n);
    pre[n-1] = 0;
    for(int i =n-2; i>=0;i--) 
        pre[i] = pre[i+1] + v[i+1];
    return pre;
}

void print_v(const vector<ll> &v, const string& name) {
    std::cout << name << ": ";
    int n = v.size();
    F0R(i, n) {
        cout << v[i];
        if(i<n-1) cout << ",";
    }
    std::cout << std::endl;
}

vector<ll> numbers(10), presum_1_10(10);

void solve() {
    // int n; cin >> n;
    // vector<ll> digits;
    // while(n > 0) {
    //     digits.push_back(n % 10);
    //     n /= 10;
    // }
    // int m = digits.size();
    // // presum of digits
    // vector<ll> suff_digits = make_suff_exclusive(digits);

    // ll pow = 1;
    // ll add = suff_digits[0] + digits[0];
    // debug(add);
    // ll res = add % 3; // sum of all digits mod 3, first step
    // for(int d = 0; d<m; d++) {
    //     int curr_digit = digits[d];
    //     if(digits[d] == 0){
    //         pow *= 10;
    //         continue;
    //     } 
    //     ll add = (presum_1_10[curr_digit-1] + suff_digits[d]*curr_digit) * pow;
    //     debug(add);
    //     res = (res + add) % 3;
    //     pow *= 10;
    // }

    // if(res % 3 == 0) {
    //     std::cout << "SI\n";
    // } else {
    //     std::cout << "NO\n";
    // }
    int n; cin >> n;
    if(n % 3 == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "SI\n";
    }
}

int main() {
    iota(numbers.begin(), numbers.end(), 0);
    presum_1_10 = make_pre(numbers);
    fastio;
    int tc; cin >> tc;
    while (tc--) solve();
}
