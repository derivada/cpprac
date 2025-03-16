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


unordered_map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int subtract(const string &s, int i) {
    // check if pos-1 is subtracting
    if(i-1 < 0) {
        return 0;
    } 
    if((s[i] == 'V' || s[i] == 'X') && s[i-1] == 'I')
        return 2*1;
    if((s[i] == 'L' || s[i] == 'C') && s[i-1] == 'X')
        return 2*10;
    if((s[i] == 'D' || s[i] == 'M') && s[i-1] == 'C')
        return 2*100;
    return 0;
}

inline void construct(std::string &res, int& target, int threeshold, std::string append) {
    while(target >= threeshold) {
        target-=threeshold;
        res+=append;
    }
}

inline bool solve() {
    string s;
    cin >> s;
    if(!cin) return false;
    int n = s.length();
    int number = 0;
    F0R(i, n) {
        number += values[s[i]];
        number -= subtract(s, i);
    }
    int target = number + 1;
    // std::cout << s << ": " << number << " --> " << target << ": ";
    std::string res = "";
    construct(res, target, 1000, "M");
    construct(res, target, 900, "CM");
    construct(res, target, 500, "D");
    construct(res, target, 400, "CD");
    construct(res, target, 100, "C");
    construct(res, target, 90, "XC");
    construct(res, target, 50, "L");
    construct(res, target, 40, "XL");
    construct(res, target, 10, "X");
    construct(res, target, 9, "IX");
    construct(res, target, 5, "V");
    construct(res, target, 4, "IV");
    construct(res, target, 1, "I");
    std::cout << res << "\n";
    return true;
}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    while (solve());
}