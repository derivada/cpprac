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

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> orig(n);
    F0R(i, n) {
        cin >> orig[i];
    }
    vector<bool> seen(n, false);
    int max_seen = 0;
    F0R(i, m) {
        int curr = 0;
        F0R(j, n) {
            string s; cin >> s;
            if(s == orig[j]) {
                curr++;
                seen[j] = true;
            }
            max_seen = std::max(curr, max_seen);
        }
    }
    int total_seen = 0;
    F0R(i, n) {
        if(seen[i]) total_seen++;
    }
    if(total_seen < n) {
        std::cout << "-1\n";
        return;
    }
    // spamming all in the best row, then deleting the n-max_seen that are not present in there
    // and using other rows one by one to end
    int total = n + (n-max_seen)*2;
    std::cout << total << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
