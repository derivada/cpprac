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
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    vector<pi> attack_k{
        {xk-a, yk-b},
        {xk+a, yk-b},
        {xk-a, yk+b},
        {xk+a, yk+b},
        {xk-b, yk-a},
        {xk+b, yk-a},
        {xk-b, yk+a},
        {xk+b, yk+a},
    };
    vector<pi> attack_q{
        {xq-a, yq-b},
        {xq+a, yq-b},
        {xq-a, yq+b},
        {xq+a, yq+b},
        {xq-b, yq-a},
        {xq+b, yq-a},
        {xq-b, yq+a},
        {xq+b, yq+a},
    };
    set<pi> common;
    F0R(i, 8) {
        F0R(j, 8) {
            if(attack_k[i] == attack_q[j])
                common.insert(attack_k[i]);
        }
    }
    cout << common.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // DEBUG I/O, COMMENT BEFORE SUBMIT
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
	solve();
}
