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

void solve() {
    int n;
    cin >> n;
    vi v(n);
    F0R(i, n)
        cin >> v[i];

    int start = 0, end = 1;
    bool reversed = false, equality = false;
    for(int i = 1; i<n; i++) {
        if(v[i-1] == v[i] && !reversed) {
            start = i-1; equality = true;
        }
        if(v[i] < v[i-1]) {
            if(reversed) {
                cout << "no\n"; return;
            }
            reversed = true;
            if(!equality)
                start = i-1;
            while(i < n && v[i] <= v[i-1]) {
                i++;
            }  
            end = i;
            reverse(v.begin()+start, v.begin()+end);
            i--; // xd
        }
    }
    cout << "yes\n" << start+1 << " " << end << "\n";
}

int main() {
    fastio;
    solve();
}
