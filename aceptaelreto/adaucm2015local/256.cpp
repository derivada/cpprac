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

vi get_digits(int a) {
    vi v(10);
    F0R(i, 10) {
        v[i] = (a%10);
        a = a / 10;
    }
    return v;
}

void print_v(const vi &v, const string &name)  {
    cout << name;
    F0R(i, v.size()) {
        cout << v[i]; if(i < v.size()-1) cout <<",";
    }
    cout << "\n";
}

inline bool solve() {
    int a, b, c; cin >> a; 
    if(!cin) return false; 
    cin>> b >> c;
    vi ad = get_digits(a), bd = get_digits(b), cd = get_digits(c);
    int n = 0, pow = 1;
    //print_v(ad, "a digits:"); print_v(bd, "b digits:"); print_v(cd, "c digits:");
    F0R(i, 10) {
        if(ad[i] != bd[i] && ad[i] != cd[i] && bd[i] != cd[i]) {
            cout << "RUIDO COSMICO\n"; return true;
        } else if(ad[i] == bd[i] || ad[i] == cd[i]) {
            n += pow*ad[i];
        } else {
            n+= pow*bd[i];
        }
        pow *= 10;
    }
    cout << n << endl; return true;
}

int main() {
    fastio;
    while(solve());
}
