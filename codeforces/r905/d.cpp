#include <bits/stdc++.h>
using namespace std;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> graph;
typedef vector<vector<pair<int, int>>> wgraph;
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

const ll MOD = 1e9 + 7; // change MOD value

void solve() {
    int n;
    cin >> n;
    multiset<pi> lr, rl;
    F0R(i, n) {
        char c; 
        int l, r;
        cin >> c >> l >> r;
        if(c == '+') {
            lr.insert({l, r});
            rl.insert({r, l});
        } else {
            lr.erase(lr.find({l, r}));
            rl.erase(rl.find({r, l}));
        }

        if(lr.size() <= 1) {
            cout << "NO\n";
            continue;
        }
        auto a = *(rl.begin());
        int first_r = a.F;
        auto b = *(--lr.end());
        int last_l = b.F;
        if(first_r < last_l) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // DEBUG I/O, COMMENT BEFORE SUBMIT
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	solve();
}
