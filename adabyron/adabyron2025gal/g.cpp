#include <bits/stdc++.h>
using namespace std;
#define fastio cin.sync_with_stdio(0); cin.tie(0);

#define F first
#define S second
#define F0R(i,n) for(int i = 0; i<n; i++)
#define PB push_back
#define all(a) (a).begin(), (a).end()
using pi = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;


void solve() {
    int n; cin >> n;
    vi v(n);
    F0R(i, n) cin >> v[i];
    ll res = 0;
    int m; cin >> m;
    set<int> s;
    F0R(i, m) {
        int x; cin >> x; s.insert(x);
    }
    F0R(i, n) {
        if(s.find(v[i]) == s.end()){
            res += v[i];
        }
    }
    cout << res << "\n";
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) solve();
}