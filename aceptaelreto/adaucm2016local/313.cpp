using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define ld long double
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i< b; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)

inline void solve() {
    ll x, y;
    cin >> x >> y;
    if(x+y >= 0) {
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}