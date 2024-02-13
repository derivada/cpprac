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
    int n, a;
    cin >> n;
    vi cnt(n+1,0);
    F0R(i, n){
        cin >> a;
        if (a <= n) {
            cnt[a]++;
        }
    }
    vi catched(n+1,0);
    // harmonic series is O(nlogn)
    for(int i = 1; i<n+1; i++)
        for(int j = i; j<=n; j+=i)
            catched[j] += cnt[i];
    int max = 0;
    for(int i = 1; i<n+1; i++){
        if(catched[i] > max)
            max = catched[i];
    }
    cout << max << "\n";
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
