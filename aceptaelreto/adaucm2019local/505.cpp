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

inline bool solve() {
    int n, na, nb;
    cin >> n;
    if(!cin) return false;
    cin >> na >> nb;
    map<int, int> pa, pb;
    F0R(i, na){
        int x; 
        cin >> x; 
        if(pa.find(x) != pa.end()) 
            pa[x] += 1;
        else
            pa[x] = 1;
    }
    F0R(i, nb){
        int x; 
        cin >> x; 
        if(pb.find(x) != pb.end()) 
            pb[x] += 1;
        else
            pb[x] = 1;
    }
    int max_per_day = min(n, min(na, nb)); vector<ll> ans; bool end = false;
    while(pa[0] < na && pb[0] < nb) {
        int i = 0; ll val = 0;
        while(i < max_per_day) {
            pi lasta = *pa.rbegin();
            pi lastb = *pb.rbegin();
            if(lasta.F == 0 || lastb.F == 0){
                end = true;
                break;
            }
            //cout << "choosing pair (" << lasta.F << ", " << lasta.S << ") and (" << lastb.F << ", " << lastb.S << ")\n";
            int hours = min(lasta.F, lastb.F);
            int flied = min(max_per_day - i, min(lasta.S, lastb.S));
            //cout << "flying " << flied << " drones for " << hours << " hours\n";
            if(lasta.S-flied == 0) 
                pa.erase(lasta.F);
            else
                pa[lasta.F] = lasta.S - flied;
            if(lastb.S-flied == 0)
                pb.erase(lastb.F);
            else 
                pb[lastb.F] = lastb.S - flied;
            
            pa[lasta.F - hours] += flied;
            pb[lastb.F - hours] += flied;
            val += hours * flied;
            i += flied;
        }
        ans.PB(val);
        if(end) break;
    }
    F0R(i, ans.size()) {
        cout << ans[i];
        if(i < ans.size()-1)
            cout << " ";
        else
            cout << "\n";
    }
    return true;
}

int main() {
    while(solve());
}
