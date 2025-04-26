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

int main() {
    fastio;
    int n, k; cin >> n >> k;
    vi v(n);
    F0R(i, n) {
        cin >> v[i];
    }
    vector<int> res;
    F0R(i, n) {
        int curr_power = k;
        res.clear();
        int up = i+1, down = i-1;
        if(v[i] > curr_power)
            continue;
        curr_power++;
        res.push_back(i);    
        //cout << "EXEC WITH I = " << i << endl;
        while(down >= 0 || up <= n-1) {
            //cout << "curr power = " << curr_power << "  bounds=" 
            // << down << "," << up << "   ";
            if(down >= 0 && v[down] <= curr_power) {
                res.push_back(down);
                //cout << "chose down";
                down--;
            } else if(up <= n-1 && v[up] <= curr_power) {
                res.push_back(up);
                //cout << "chose up";
                up++;
            } else {
                break;
            }
            //cout << endl;
            curr_power++;
        }
        if(res.size() == n) break;
    }

    if(res.size() == n) {
        F0R(i, res.size()) {
            cout << res[i]+1; if(i < n-1) cout << " ";
        }
        cout << "\n";
    } else {
        cout << "FALLIDA\n";
    }
}