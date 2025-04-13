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
    unsigned long long k;
    cin >> k;
    char cod[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    vector<unsigned long long> freq(10, 1);
    unsigned long long total = 1;
    int j = 0;
    while(total < k) {
        freq[j]++; total = 1;
        for(int i = 0; i<10; i++) {
            total *= freq[i];
        }
        j++;
        if(j == 10) j = 0;
    }
    for(int i = 0; i<10; i++) {
        for(unsigned long long j = 0; j<freq[i]; j++){
            cout << cod[i];
        }
    }
    cout << "\n";
}

int main() {
    fastio;
        solve();
}
