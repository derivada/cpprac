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
    int q;
    cin >> q;
    vector<unsigned int> multiset(32, 0);
    unsigned int type, query;
    F0R(i, q) {
        cin >> type >> query;
        if(type == 1) {
            multiset[query]++;
        } else {
            vector<unsigned int> multiset_cp(32, 0);
            copy(all(multiset), multiset_cp.begin());
            bool possible = true;
            for(int b = 31; b>=0; b--) {
                if((query >> b) & 0x1) {
                    unsigned int amount = 0x1 << b;
                    for(int j = b; j >= 0; j--) {
                        unsigned int multiset_total = multiset_cp[j] << j;
                        if(amount < multiset_total) {
                            multiset_cp[j] = (multiset_total - amount) >> j;
                            //cout << " new multiset amount at bit " << b << " = " << multiset_cp[j] << endl;
                            amount = 0;
                            break;
                        } else {
                            amount -= multiset_total;
                            multiset_cp[j] = 0;
                        }
                    }
                    if(amount) {
                        cout << "NO\n";
                        possible = false;
                        break;
                    }
                }
            }
            if(possible)
                cout << "YES\n";
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
