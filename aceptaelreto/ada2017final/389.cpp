#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
#define debug(x) cout << #x << " is " << x << endl
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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value


// ada + byron = molar
int n1, n2, n3;
map<char, int> m;
vector<bool> is_assigned(10, false);
string op1, op2, res;

// 0: was assigned, 1: was not assigned, 2: is not present
inline int get_assignment_posibilities(vi &v, const string &s, int pos) {
    if(pos < s.size()) {
        if(m.find(s[pos]) != m.end()) {
            v.push_back(m[s[pos]]);
            return false;
        } else {
            F0R(i, 10) if(is_assigned[i] == false) v.push_back(i);
            return true;
        }
    } else {
        v.push_back(0);
        return false;
    }
}

inline void assign(const string &s, int pos, int ass) {
    if(pos < s.size()) {
        m[s[pos]] = ass;
        is_assigned[ass] = true;
    }
}
inline void unassign(string &s, int pos, int ass) {
    if(pos < s.size()) {
        char c = s[pos];
        m.erase(c);
        is_assigned[ass] = false;
    }
}


inline bool solve_add(int pos, int carry) {
    if(pos == n3) {
        // check sol is correct
        int final1 = 0, final2 = 0, final3 = 0;
        int mult = 1;
        F0R(i, n1) {
            final1 += m[op1[i]] * mult;
            mult *= 10;
        }
        mult = 1;
        F0R(i, n2) {
            final2 += m[op2[i]] * mult;
            mult *= 10;
        }
        mult = 1;        
        F0R(i, n3) {
            final3 += m[res[i]] * mult;
            mult *= 10;        
        }
        return (final1 + final2 == final3);
    }

    // extract the operands or assign them
    vi possible_d1, possible_d2, possible_dres;
    bool needs_ass1 = get_assignment_posibilities(possible_d1, op1, pos);
    bool needs_ass2 = get_assignment_posibilities(possible_d2, op2, pos);
    bool needs_ass3 = get_assignment_posibilities(possible_dres, res, pos);

    // check every possible assignment at this step
    F0R(i, possible_d1.size()) {
        F0R(j, possible_d2.size()) {
            F0R(k, possible_dres.size()) {
                int ass1 = possible_d1[i], ass2 = possible_d2[j], ass3 = possible_dres[k];

                // check all different if they werent assigned
                if((needs_ass1 && (ass1 == ass2 || ass1 == ass3))
                    || (needs_ass2 && (ass2 == ass1 || ass2 == ass3))
                    ||  (needs_ass3 && (ass3 == ass1 || ass3 == ass2))) {
                     // duplicates are fine if they are the same letter they are referring to
                        if(!(
                            (pos < n1 && pos < n2 && op1[pos] == op2[pos]) ||
                            (pos < n2 && pos < n3 && op2[pos] == res[pos]) ||
                            (pos < n1 && pos < n3 && op1[pos] == res[pos])
                        ))
                            continue;
                }
                // check if correct
                int sum = ass1 + ass2 + carry;
                if(sum % 10 == ass3) {
                    // all good, assign permanently and go into next digit
                    if(needs_ass1) assign(op1, pos, ass1);
                    if(needs_ass2) assign(op2, pos, ass2);
                    if(needs_ass3) assign(res, pos, ass3);

                    // check recursively
                    if(solve_add(pos+1, sum/10)) {
                        return true;
                    } else {
                        // DONT UNASSIGN WHEN A SECOND INSTANCE OF THAT LETTER WAS FOUND
                        if(needs_ass1) unassign(op1, pos, ass1);
                        if(needs_ass2) unassign(op2, pos, ass2);
                        if(needs_ass3) unassign(res, pos, ass3);
                    }
                } 
            }
        }
    }
    return false;
}

inline bool solve_mult(int pos, int carry) {
    return false;
}

inline bool solve() {
    char op_sign, ign2;
    cin >> op1;
    if(!cin)
        return false;
    cin >> op_sign >> op2 >> ign2 >> res;
    reverse(all(op1)), reverse(all(op2)), reverse(all(res));
    n1 = op1.size(), n2=op2.size(), n3=res.size();
    m.clear();
    is_assigned.assign(10, false);
    if(op_sign == '+') {
        solve_add(0, 0);
    } else {
        solve_mult(0, 0);
    }

    for(int i = n1-1; i>=0; i--) {
        cout << m[op1[i]];
    }
    cout << " " << op_sign << " ";
    for(int i = n2-1; i>=0; i--) {
        cout << m[op2[i]];
    }
    cout << " = ";
    for(int i = n3-1; i>=0; i--) {
        cout << m[res[i]];
    }
    cout << "\n";
    return true;
}

int main() {
    fastio;
    while (solve());
}
