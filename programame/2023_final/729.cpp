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
#define debug(x) cout << #x << " is " << x << endl
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value

inline bool check_subset(const vi &v1, const vi &v2) {
    int i = 0, j = 0;
    int n1 = v1.size(), n2 = v2.size();
    
    // check if v1 is subset of v2 (both are ordered)
    while(i < n1 && j < n2) {
      if(v1[i] == v2[j]) {
        i++, j++;
      } else if(v1[i] > v2[j]) {
        j++;
      } else { // v1[i] < v2[j]
        return false;
      }
    }
    
    return i == n1;
}

inline bool solve() {
    int n; cin >> n;
    if(!cin) return false;
    vector<string> names(n);
    vector<vi> cartones(n, vi());
    F0R(i, n) {
        cin >> names[i];
        int x;
        cin >> x;
        while(x) {
            cartones[i].push_back(x);
            cin >> x;
        }
        sort(all(cartones[i]));
    }
    int q;
    cin >> q;
    vi nums(q);
    F0R(i, q) {
        cin >> nums[i];
    }

    int l = -1, r = q;
    std::vector<string> winners;
    while (r - l > 1) {
        int m = (l + r) / 2;
        std::vector<string> current_winners;

        std::vector<int> nums_sorted(m+1);
        F0R(i, m+1)
            nums_sorted[i] = nums[i];
        sort(all(nums_sorted));
        F0R(i, n) {
            if(check_subset(cartones[i], nums_sorted)) {
                current_winners.push_back(names[i]);
            }
        }
        if (current_winners.size() > 0) {
            r = m; // 0 = f(l) < f(m) = 1
            winners = std::move(current_winners);
        } else {
            l = m; // 0 = f(m) < f(r) = 1
        }
    }
    sort(all(winners));
    F0R(i, winners.size()) {
        cout << winners[i];
        if(i < winners.size()-1)
            cout << " " ;
    }
    cout << "\n";
   
    return true;
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    while (solve());
}