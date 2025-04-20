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


inline bool solve() {
    int x; cin >> x;
    if(!x) return false;
    map<int, int> m;
    m[x]++;
    while(x > 0) {
        cin >> x;
        if(x > 0)
        m[x]++;
    }
    int sz = m.size();
    vector<pi> v(sz);
    int i = 0;
    int total = 0;
    for(auto x: m) {
        v[sz-i-1] = x;
        i++;
        total += x.second;
    }
    sort(all(v), [&](const pi &p1, const pi &p2) {
        return p1.first < p2.first;
    });
    int l =0, r = total-1;
    vi print(total);
    F0R(i, sz) {
        pi elem = v[i];
        if(i == sz-1) {
            // biggest
            if(elem.S % 2 != 1) {
                cout << "NO\n"; return true;
            }
            print[l] = elem.F;
        } else {
            if(elem.S % 2 == 1) {
                cout << "NO\n"; return true;
            } else {
                F0R(j, elem.S/2) {
                    print[l] = elem.F, print[r] = elem.F;
                    l++, r--;
                }
            }
        }
    }
    F0R(i, total){
        cout << print[i]; 
        if(i<total-1) cout << " ";
    }
    cout << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
