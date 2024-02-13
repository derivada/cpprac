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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int index = 0, total = 0; //index until sorted, total n of ops
    // find first index
    for(index; index < n-1; index++) {
        if(s[index] > s[index+1]) break;
    }
    if(index == n-1) {
        cout << "0" << "\n"; return;
    }
    while(index < n-1) {
        vector<pi> st;
        // find lex biggest subseq
        for(int i = index; i<n; i++) {
            while(!st.empty() && st[st.size()-1].S < s[i])
                st.pop_back();
            st.push_back(MP(i, s[i]));
        }
        if(st.size() > 1) {
            // shift
            F0R(i, st.size()) {
                if(i != st.size()-1)
                    s[st[i+1].F] = st[i].S;
                else
                    s[st[0].F] = st[i].S;
            }
            total++;
            // check sorted until second place
            for(int i = index; i < st[1].F - 1; i++) {
                if(s[i] > s[i+1]) {
                    cout << "-1" << "\n";
                    return; // impossible because the maximum is at right of an unsorted array
                }
            }
            index = st[1].F;
        } else {
            // check entire array sorted
            for(int i = index; i < n - 1; i++) {
                if(s[i] > s[i+1]) {
                    cout << "-1" << "\n";
                    return; // impossible because maximum is at end and the rest of the string is not sorted
                }
            }
            index = n - 1;
        }
    }
    cout << total << "\n";
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
