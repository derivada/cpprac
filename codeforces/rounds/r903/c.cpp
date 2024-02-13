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
int n;
inline void solve() {
    cin >> n;
    vector<vector<char>> biggest(n/2, vector<char>(n/2, 0));
    vector<string> strings(n);
    F0R(i, n) {
        string s;
        cin >> s;
        // (i, j) -> (n-j, n-i) -> (n-i, n-j) -> (n-j , i)
        F0R(j, n) {
            biggest[j < n/2 ? i : n-1-j][i < n/2 ? j : n-1-i] = 
                max(biggest[j < n/2 ? i : n-1-j][i < n/2 ? j : n-1-i], s[j]);
        }
        strings[i] = s;
    }
    ll total = 0;
    F0R(i, n/2) {
        F0R(j, n/2)
            cout << biggest[i][j] << " ";
        cout << "\n";
    }
    F0R(i, n) {
        F0R(j, n) {
            total += biggest[j < n/2 ? i : n-1-j][i < n/2 ? j : n-1-i] - strings[i][j];
        }
    }
    cout << total << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
