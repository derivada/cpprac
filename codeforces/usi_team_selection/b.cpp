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
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2){
        double a = x1;
        x1 = x2;
        x2 = a;
        a = y1;
        y1 = y2;
        y2 = a;
    } else if(x1 == x2) {
        cout << y1 + y2 << "\n";
        return;
    }

    double x = (x2*y1 + x1*y2) / (y1+y2);
    double a = x - x1;
    double b = x2 - x;
    double c = sqrt(a*a + y1*y1);
    double d = sqrt(b*b + y2*y2);
    printf("%lf\n", (c+d));
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
