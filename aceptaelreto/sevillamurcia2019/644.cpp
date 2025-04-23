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

inline bool solve() {
    int A; int M = 24, N = 5;
    cin >> A; if(!A) return false;
    int a = A % 19, b = A % 4, c = A % 7;
    int d = (19*a+M) % 30;
    int e = (2*b + 4*c + 6*d + N) % 7;
    int day; string month = "";
    bool abril = false;
    if (d+e < 10) {
        day = d+e+22;
    } else {
        day = d+e-9;
        abril = true;
    }
    if(abril && day == 26)
        day = 19;
    else if(abril && day == 25 && d == 28)
        day = 18;
    
    cout << day << " de " << (abril ? "abril" : "marzo") << "\n"; 

    // Si la fecha obtenida es el 26 de abril, debe cambiarse por el 19 de abril.
    // Si el resultado final conseguido es el 25 de abril con d=28, entonces la fecha correcta es el 18 de  abril.

    // Sea a el resto de la división A/19.
    // Sea b el resto de la división A/4.
    // Sea c el resto de la división A/7.
    // Sea d el resto de la división (19a + M)/30.
    // Sea e el resto de la división (2b + 4c + 6d + N)/7.
    // Si d + e es menor que 10, entonces el Domingo de Pascua es el (d + e + 22) de marzo.
    // En caso contrario, el Domingo de Pascua es el (d + e - 9) de abril.
    return true;
}

int main() {
    fastio;
    while(
        solve());
}
