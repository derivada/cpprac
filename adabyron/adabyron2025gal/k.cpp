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
    int n; cin >> n; int base; cin >> base;
    vi digits;
    while(n > 0) {
        digits.push_back(n % base);
        n /= base;
    }
    if(digits.size() == 0) {
        cout << "0\n"; return;
    }
    reverse(all(digits));
    F0R(i, digits.size()) {
        cout << digits[i];
    }
    cout << "\n";
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) solve();
}