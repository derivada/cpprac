#include <iostream>
#include <vector>
using namespace std;

inline bool solve() {
    int n;
    cin >> n;
    if(!cin) 
        return false;
    bool flag = false;
    int x;
    cin >> x;
    vector<pair<int,int>> ranges;
    ranges.push_back(make_pair(x, x));
    for(int i = 1; i < n; i++) {
        cin >> x;
        for(int j = ranges.size() - 1; j >= 0; j--) {
            int left = ranges[j].first, right = ranges[j].second;
            if(left < x) {
                if(right > x)
                    flag = true;
                break;
            }
        }
        if(flag) {
            for(; i < n; i++) // read the rest of the input
                cin >> x;
            break;
        }
        int rn = ranges.size() - 1;
        if (ranges[rn].first < x) { // increase right limit of this range
            ranges[rn].second = x;
        } else if (ranges[rn] == ranges[rn]) { // update this (equal) range
            ranges[rn] = make_pair(x, x);
        } else { // add new range because new minimum
            ranges.push_back(make_pair(x, x));
        }

    }
    if (flag) 
        cout << "ELEGIR OTRA\n";
    else 
        cout << "SIEMPRE PREMIO\n";
    return true;
}

int main() {
    while(solve());
}
