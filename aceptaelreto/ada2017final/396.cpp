#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
#define debug(x) cout << #x << " is " << x << endl
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


inline void print_pq(std::priority_queue<int> &pq) {
    priority_queue<int> temp = pq;

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}
inline bool solve() {
    int p, n; cin >> p; 
    if(!cin) return false;
    cin >> n;
    priority_queue<int> pq;
    F0R(i, n) {
        int x; cin >> x; pq.push(x);
    }
    p -= n; // una para cada grupo
    pq.push(1); // baseline
    // print_pq(pq); 
    while(p > 0) {
        p++; // recuperamos la perdida por el grupo ya que vamos a dividirlo
        // debug(p);
        int first = pq.top();
        int first2 = pq.top();
        if(first > 1) {
            while(pq.top() == first2) {
                p++;
                first += pq.top();
                pq.pop();
            }
        }
        pq.pop();
        int second = pq.top();
        // debug(first); debug(second);
        int div_fs = first/second + (first % second > 0 );
        // debug(div_fs);
        int div = std::max(2, std::min(p, div_fs));
        p-=div;
        int floor_div = first/div;
        int resto = first % div;
        for(int i = 0; i<div; i++){
            if(i < resto) {
                pq.push(floor_div+1);
            } else {
                pq.push(floor_div);
            }
        }
        // print_pq(pq);
    }
    // debug(p);

    cout << pq.top() << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
