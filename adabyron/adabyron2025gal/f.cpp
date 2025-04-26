#include <bits/stdc++.h>
using namespace std;
#define fastio cin.sync_with_stdio(0); cin.tie(0);

#define F first
#define S second
#define F0R(i,n) for(int i = 0; i<n; i++)
#define PB push_back
#define all(a) (a).begin(), (a).end()
using pi = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, T; cin >> n >> T;
    vi time(n), value(n);
    vector<pair<double, int>> frac(n);
    F0R(i, n) {
        cin >> time[i];
    }
    F0R(i, n) {
        cin >> value[i];
        frac[i] = make_pair((double) value[i] / (double) time[i], 
            i); // ordenar por valor/tiempo, mantener tiempo
    }
    sort(all(frac));
    reverse(all(frac));
    double ans = 0.0;
    F0R(i, n) {
        int index = frac[i].second;
        double value_per_time_unit = frac[i].first;
        if(T < time[index]) {
            // fraccionar y acabar
            ans += value_per_time_unit * T;
            // cout << "FRACCIONANDO " << index << " CON TIEMPO " << 
            //    T << " Y VALOR FINAL " << value_per_time_unit * T << endl;
            break;
        } else {
            // meter entero
            ans += value[index];
            T -= time[index];
            // cout << "METIENDO ENTERO " << value[index] << " " << time[index] << endl;
        }
    }
    cout << ans << endl;
}


int main() {
    fastio;
    int tc; cin >> tc; while(tc--) solve();
}