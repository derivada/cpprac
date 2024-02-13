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
    int n, k;
    cin >> n >> k;
    vi v(n,0);
    int min_rem = 1000;
    if(k != 4) {
        F0R(i, n){
            int a;
            cin >> a;
            int rem = abs(k - a%k);
            if(rem == k) rem = 0;
            if(rem < min_rem)
                min_rem = rem;
        }
    } else {
        int counter_mod_3 = 0, counter_mod_2 = 0;
        F0R(i, n){
            int a;
            cin >> a;
            int rem = abs(k - a%k);
            if(rem == k) rem = 0;
            if(rem == 3)
                counter_mod_3++;
            if(rem == 2)
                counter_mod_2++;
            if(rem < min_rem)
                min_rem = rem;
        }
        if(counter_mod_3 >= 2)
            min_rem = min(min_rem,2);
        if(counter_mod_2 == 1)
            min_rem = min(min_rem,1);
        if(counter_mod_2 >= 2)
            min_rem = 0;

    }
    cout << min_rem << "\n";
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
