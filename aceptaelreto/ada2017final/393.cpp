#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " is " << x << endl
#define F0R(i, n) for (int i = 0; i < n; i++)


map<string, int> patternCount;
set<tuple<int, int, string>> seen_at;
vector<vector<char>> mat;
int n, m;

inline void fix_index(int &i, int &j, int line_size) {
    if(i>=n) i-=line_size;
    else if(i < 0) i+= line_size;
    if(j>=m) j-=line_size;
    else if(j< 0) j+= line_size;
}

inline int get_line_size(int i, int j, int dir) {
    // vertical
    if(dir == 1 || dir == 6) {
        return  n;
    }
    // hor
    else if(dir == 3 || dir == 4) {
        return m;
    }
    else if (dir == 0 || dir == 7) {
        int up_left = min(i, j);
        int down_right = min(n - 1 - i, m - 1 - j);
        return up_left + down_right + 1;
    }
    else {
        int up_right = min(i, m - 1 - j);
        int down_left = min(n - 1 - i, j);
        return up_right + down_left + 1;
    }
}
map<pair<pair<int, bool>, pair<int, int>>, int> seen_start_end;
inline void precompute(int i, int j, int dir) {
    constexpr int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    constexpr int max_pattern_len = 300;
    int start_x = i, start_y = j;
    int line_size = get_line_size(i, j, dir);
    for(int offset = 0; offset < line_size; offset++){
        string pattern;
        int x = start_x, y = start_y;
        for (int len = 0; len < std::min(max_pattern_len, line_size); len++) {
            pattern += mat[x][y];
            if(seen_at.find(make_tuple(x, y, pattern)) == seen_at.end()) {
                seen_at.insert(make_tuple(x, y, pattern));   
                patternCount[pattern]++;
            }
            if(seen_at.find(make_tuple(start_x, start_y, pattern)) == seen_at.end()) {
                seen_at.insert(make_tuple(start_x, start_y, pattern));   
                patternCount[pattern]++;
            }
            x+=dx[dir];
            y+=dy[dir];
            fix_index(x, y, line_size);
            if(x < 0 || y < 0)
                break;
        }
        start_x+=dx[dir];
        start_y+=dy[dir];
        fix_index(start_x, start_y, line_size);
    }
}

inline bool solve() {
    cin >> m;
    if(!cin) return false;
    cin >> n;
    mat.assign(n, vector<char>(m));
    patternCount.clear();
    F0R(i, n) {
        string s; cin >> s;
        F0R(j, m) {
            mat[i][j] = s[j];
        }
    }

    F0R(i, n) {
        precompute(i, 0, 4); // hor
        precompute(i, 0, 7); // diag "\"
        precompute(i, 0, 2); // diag "/"
    }
    // first col
    precompute(0, 0, 6);
    for(int j = 1; j<m; j++) {
        precompute(0, j, 6); // hor
        precompute(0, j, 7); // diag "\"
        precompute(0, j, 2); // diag "/"
    }

    int nq; cin >> nq;
    vector<string> q(nq);
    F0R(i, nq) {
        cin >> q[i]; 
    }
    sort(q.begin(), q.end());
    F0R(i, nq) {
        if(patternCount[q[i]] > 0)
            std::cout << q[i] << " " << patternCount[q[i]] << "\n";
    }
    std::cout << "---\n";
    return true;
}

int main() {
    while (solve());
}