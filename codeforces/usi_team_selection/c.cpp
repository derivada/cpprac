#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const ld EPS = 1e-9;
#define ar array        
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
#define all(a) (a).begin(), (a).end()
#define FOR(i, a, b) for(int i = a; i < b; i++)
const ll MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vi a(n,0), d(n,0), diff(n, 0);
    int max_index, max = 0, min_index, min = 2000000, second_min = 1000000;
    vi b(n,0);
    FOR(i, 0, n) {
        cin >> a[i];
        b[i] = a[i];
        if(a[i] > max){ max = a[i]; max_index = i; }
        if(a[i] < min) { min = a[i]; min_index = i; }
    }
    sort(all(b));
    int max_diff_index, max_diff = -100;
    FOR(i, 0, n) {
        cin >> d[i];
        if(d[i] <= max && d[i] >= b[1])
            diff[i] = d[i] - a[i];
        else 
            diff[i] = -1;
        if(diff[i] > max_diff) { max_diff_index = i; max_diff = diff[i]; }
    }
    if(max_diff > 0)
        a[max_diff_index] = d[max_diff_index];
    sort(all(a));
    int sum = 0;
    FOR(i, 1, n-1)
        sum += a[i];
    
    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        solve();
}
