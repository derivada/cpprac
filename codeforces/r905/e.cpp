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
void fast(){cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const ll MOD = 1e9 + 7; // change MOD value

inline int leftmost_set_bit_position(unsigned int a) {
    if (a == 0) {
        return 0;
    }

    int bits = 0;

    #ifdef __GNUC__
        bits = 31 - __builtin_clzll(a);
    #else
        while (a >>= 1) {
            bits++;
        }
    #endif

    return bits;
}

void solve() {
    int n;
    cin >> n;
    unsigned int last = 0, total  = 0, last_bits = 0;
    cin >> last;
    last_bits = leftmost_set_bit_position(last);
    FOR(i, 1, n) {
        unsigned int a;
        cin >> a;
        int a_bits = leftmost_set_bit_position(a);
        int bits_diff = last_bits - a_bits;
        if(bits_diff > 0) {
            a = a << (bits_diff);
            a_bits = last_bits; 
            total += bits_diff;
        }
        while(a < last) {
            a = a << 1;
            total++;
            a_bits++;
        }
        last = a;
        last_bits = a_bits;
    }
    cout << total << "\n";
}

int main() {
    fast();
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
	solve();
}
