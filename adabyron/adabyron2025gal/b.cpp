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
    int n; cin >> n;
    string ign; int start, end;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    F0R(i, n) {
        cin >> ign >> start >> end;
        q.push(make_pair(end, start));
    }
    int tiempo = -1, ans = 0;
    while(!q.empty()){
        int inicio = q.top().S, final = q.top().F;
        q.pop();
        if(inicio < tiempo) {
            continue;
        }
        ans++;
        tiempo = final;
    }
    cout << ans << "\n";
}