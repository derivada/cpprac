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

bool get_bit(uint64_t n, int bit) {
    return n & (1ll<<bit);
}

inline void solve() {
    int64_t a, b, r, new_a = 0, new_b = 0;
    cin >> a >> b >> r;
    bool found_highest = false;
    uint64_t x = 0;
    if(a > b)
        swap(a, b);
    for(int i = 63; i>=0; i--) {
        bool bit_a = get_bit(a, i), bit_b = get_bit(b, i);
        if(bit_a == bit_b) continue;
        if(!bit_a && bit_b){
            if(!found_highest){
                found_highest = true;
            } else if(x + (1LL<<i) <= r){
                bit_a = !bit_a;
                bit_b = !bit_b;
                x += (1LL<<i);
            }
        }
        if(bit_a)
            new_a += (1LL<<i);
        if(bit_b)
            new_b += (1LL<<i);
    }
    cout << abs(new_a-new_b) << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
