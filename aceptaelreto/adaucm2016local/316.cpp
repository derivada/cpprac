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
    int n; cin >> n;
    ll big = -1e12, sum = 0;
    int start_s = -1, end_s = -1;
    int start = -1, end = -1;
    F0R(i, n) {
        int x; cin >> x;
        if(x >= sum + x) {
            sum = x;
            start = i;
        } else {
            sum += x;
        }
        if(sum >= big) {
            end = i;
            if(sum > big || end - start < end_s - start_s || end_s == -1) {
                end_s = end; start_s = start;
            }
            big = sum;
        }
    }
    cout << (start_s+1) << " " << (end_s + 1) << "\n"; 
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}