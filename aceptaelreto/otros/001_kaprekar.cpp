#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> grunw;
typedef vector<vector<pair<int, int>>> grw;
#define umap unordered_map
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void solve()
{
    int N = 0;
    cin >> N;
    int vueltas = 0;
    while (1)
    {
        if (N == 6174)
        {
            cout << vueltas << "\n";
            return;
        }
        if(N % 1111 == 0){
            cout << '8' << "\n";
            return;
        }
        int digits[4];
        int tmp = N;
        for (int i = 0; i < 4; i++)
        {
            digits[i] = (tmp % 10);
            tmp /= 10;
        }

        sort(begin(digits), end(digits)); // asc
        // desc - asc
        N = (digits[3] - digits[0]) * 1000 + (digits[2] - digits[1]) * 100 + (digits[1] - digits[2]) * 10 + (digits[0] - digits[3]);
        vueltas++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = MAX_N;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
