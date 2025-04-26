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
    int n; cin >> n; vector<ll> a(n), b(n);
    F0R(i, n){
        cin >> a[i];
    }
    F0R(i, n) {
        cin >> b[i];
    }
    vector<ll> c(n+1);
    int i = 0, j = 0;
    int last_seen = 0;
    while(i+j < n+1) {
        ll val_a, val_b;
        if(i == n) {
            val_a = 1e17 + 7;
        } else {
            val_a = a[i];
        }
        if(j == n) {
            val_b = 1e17 +7;
        } else {
            val_b = b[j];
        }

        if(val_a <= val_b) {
            c[i+j] = val_a;
            i++;
        } else {
            c[i+j] = val_b;
            j++;
        }
    }
    double ans = ((double) c[n-1] + c[n]) / (double) 2;
    cout << ans << "\n";
}

int main() {
    fastio;
    solve();
}