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

vi max3index(vi v, int n) {
    vi max3{0, 0, 0};
    vi max3index{0, 0, 0};
    for (int i = 0; i < n; i++) {
        if (v[i] > max3[0]) {
            max3[2] = max3[1];
            max3index[2] = max3index[1];
            max3[1] = max3[0];
            max3index[1] = max3index[0];
            max3[0] = v[i];
            max3index[0] = i;
        } else if (v[i] > max3[1]) {
            max3[2] = max3[1];
            max3index[2] = max3index[1];
            max3[1] = v[i];
            max3index[1] = i;
        } else if (v[i] > max3[2]) {
            max3[2] = v[i];
            max3index[2] = i;
        }
    }
    return max3index;
}
void solve() {
    int n;
    cin >> n;
    vi a(n,0); vi b(n,0); vi c(n,0);
    F0R(i, n)
        cin >> a[i];
    F0R(i, n)
        cin >> b[i];
    F0R(i, n)
        cin >> c[i];
    
    vi max_a = max3index(a, n);
    vi max_b = max3index(b, n);
    vi max_c = max3index(c, n);
    int max = 0;
    F0R(i, 3) {
        F0R(j, 3) {
            F0R(k, 3){
                if( max_a[i] != max_b[j] && 
                    max_a[i] != max_c[k] && 
                    max_b[j] != max_c[k]) {
                    int result = a[max_a[i]] + b[max_b[j]] + c[max_c[k]];
                    if(result > max)
                        max = result;
                }
            }
        }
    }
    cout << max << endl;
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
