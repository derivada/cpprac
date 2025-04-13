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

inline void solve(unsigned int n, unsigned int k) {
    // unsigned int n, k;
    // cin >> n >> k;
    if(n == k+1) {
        //cout << -1 << endl;
        return;
    }
    unordered_set<unsigned int> seen;
    vector<int> digits;
    for(int d = 0; d<=16; d++) {
        if((k >> d) & 1) {
            digits.push_back(d);
        }
    }
    // cyclic shift
    unsigned int total = 0;
    if(digits.size() > 1) {
        for(int i = 0; i<digits.size(); i++) {
            int j = digits[(i+1) != digits.size() ? i+1 : 0];
            unsigned int a = (1 << digits[i]);
            unsigned int b = ((1 << j) ^ (n-1));
            seen.insert(a); seen.insert(b);
            //cout << a << " " << b << endl;
            total += a & b;
        }
    } else if(digits.size() == 1) {
        // and with 1111111...
        unsigned int a = (1 << digits[0]);
        //cout << a << " " << n-1 << endl;
        //cout << (a ^ (n-1)) << " " << 0 << endl;
        seen.insert(a); seen.insert(0); seen.insert(n-1); seen.insert(a ^(n-1));
        total += a;
    }

    for(int i = 0; i<n; i++) {
        unsigned int a = i;
        unsigned int b = (i ^(n-1));
        if(seen.find(a) == seen.end() && seen.find(b) == seen.end()) {
            //cout << a << " " << b << endl;
            seen.insert(a); seen.insert(b);
            total += a & b;
        }
    }
    if(total != k) {
        cout << "Wrong answer at " << n << ", " << k << endl;
    }
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    // int tc;
    // cin >> tc;
    // while (tc--) 
    //     solve();
    for(int d = 16; d <= 16; d++) {
        unsigned int n = (1 << d);
        cout << d << endl;
        for(int k = 0; k < n; k++) {
            solve(n, k);
        }
    }
}
