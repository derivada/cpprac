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
    vi l(n,0), r(n,0);
    int min = 0, max = 200000;
    FOR(i, 0, n) {
        cin >> l[i] >> r[i];
        if(l[i] > min)
            min = l[i];
        if(r[i] < max)
            max = r[i];
    }
    if(min <= max)
        cout <<"YES\n";
    else
        cout <<"NO\n";
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
