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

vi subset;
int n;
vi nums;
set<int> ans;
void search(int k) {
    if (k == nums.size()-1) {
        // process subset
        // cout << " curr subset: ";
        // F0R(i, subset.size()) {
        //     cout << subset[i] << " ";
        // }
        // cout << endl;
        if(subset.size() == 0) {
            //cout << "tot = " << n << endl;
            ans.insert(n);
        } else {
            int tmp = n, j = subset.size()-1, tot = 0, mult = 1, curr = 0;
            for(int i = nums.size()-1; i >= 0; i--) {
                if(j >= 0 && subset[j] == i) {
                    j--;
                    tot += curr;
                    curr = nums[i];
                    mult = 10; 
                    //cout << " we cut on " << j << " now tot = " << tot << " and curr = " << curr << endl;
                } else {
                    curr += nums[i] * mult;
                    mult *= 10;
                }
            }
            tot += curr;
            //cout << "tot = " << tot << endl;
            ans.insert(tot);
        }
    } else {
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }
}

void solve() {
    ans.clear(); subset.clear(); nums.clear();
    cin >> n;
    int tmp = n;
    while(tmp > 0) {
        nums.PB(tmp % 10);
        tmp/=10;
    }
    reverse(all(nums));
    // cout << "nums: ";
    // F0R(i, nums.size()) {
    //     cout << nums[i] << " "; 
    // }
    // cout << endl;
    search(0);
    for(int x: ans) {
        cout << x;
        if(x != *ans.rbegin())
            cout << " "; 
    }
    cout << "\n";
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}
