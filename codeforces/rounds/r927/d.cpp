#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> graph;
typedef vector<vector<pair<int, int>>> wgraph;
// set with also order_of_key(k) and find_by_order(k)
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value


inline void solve() {
    int n, trump_n; char trump_c;
    cin >> n >> trump_c;
    string s;
    switch(trump_c) {
        case 'C':
            s = "CDHS"; break;
        case 'D':
            s = "DHSC"; break;        
        case 'H':
            s = "HSCD"; break;        
        case 'S':
            s = "SCDH"; break;
    }
    vector<char> f, sec, t, trump; // first, second, third, trump_c (alphabetical order after trump)
    F0R(i, 2*n) {
        string card;
        cin >> card;
        if(card[1] == s[0])
            trump.push_back((int) card[0]);
        else if(card[1] == s[1])
            f.push_back(card[0]);
        else if(card[1] == s[2])
            sec.push_back(card[0]);
        else
            t.push_back(card[0]);
    }
    sort(all(f));
    sort(all(sec));
    sort(all(t));
    sort(all(trump));
    if(f.size() % 2 + sec.size() % 2 + t.size() % 2 > trump.size()){
        cout << "IMPOSSIBLE\n";
        return;
    }
    int i = 0, trump_given = 0;
    for(; i+1 < f.size(); i+=2){
        cout << f[i] << s[1] << " ";
        cout << f[i+1] << s[1] << "\n";
    }
    if(i < f.size()) {
        cout << f[i] << s[1] << " ";
        cout << trump[trump_given] << s[0] << "\n";
        trump_given++;
    }
    i = 0;
    for(; i+1 < sec.size(); i+=2){
        cout << sec[i] << s[2] << " ";
        cout << sec[i+1] << s[2] << "\n";
    }
    if(i < sec.size()) {
        cout << sec[i] << s[2] << " ";
        cout << trump[trump_given] << s[0] << "\n";
        trump_given++;
    }
    i = 0;
    for(; i+1 < t.size(); i+=2){
        cout << t[i] << s[3] << " ";
        cout << t[i+1] << s[3] << "\n";
    }
    if(i < t.size()) {
        cout << t[i] << s[3] << " ";
        cout << trump[trump_given] << s[0] << "\n";
        trump_given++;
    }
    for(; trump_given < trump.size(); trump_given+=2){
        cout << trump[trump_given] << s[0] << " ";
        cout << trump[trump_given+1] << s[0] << "\n";
    }
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
