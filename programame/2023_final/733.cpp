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

unordered_map<char, int> vals = {
    {'B', 0},
    {'C', 1},
    {'D', 2},
    {'F', 3},
    {'G', 4},
    {'H', 5},
    {'J', 6},
    {'K', 7},
    {'L', 8},
    {'M', 9},
    {'N', 10},
    {'P', 11},
    {'R', 12},
    {'S', 13},
    {'T', 14},
    {'V', 15},
    {'W', 16},
    {'X', 17},
    {'Y', 18},
    {'Z', 19}
};

inline void solve() {
    ll n1, n2; string s1, s2, ign;
    cin >> n1 >> s1 >> ign >> n2 >> s2;
    ll diff = 0, pow = 1, res = 0;
    for(int i = 2; i>=0; i--) {
        diff += (vals[s2[i]] - vals[s1[i]]) * pow;
        pow *= 20;
    }
    if(diff < 0 || (diff == 0 && n1 > n2)){
        swap(n1, n2);
        swap(s1, s2);
        diff = -diff;
    }

    diff--;
    res += (10000-n1 + n2);
    res += 10000*diff;
    std::cout << (res+1)<< "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
