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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value

const int K = 26;

// my_trie vertex structure
struct Vertex {
    int next[K];
    bool output = false;

    bool bad = false;
    bool good = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> my_trie(1);

// Añadir una string al my_trie
void add_string() {
    string s;
    int v = 0;

    cin >> s;

    bool good = s[0] == '+';
    FOR(i,1,s.length()) {
        char ch = s[i];
        int c = ch - 'a';
        if (my_trie[v].next[c] == -1) {
            my_trie[v].next[c] = my_trie.size();
            my_trie.emplace_back();
        }
        if (good)
            my_trie[v].good = true;
        else
            my_trie[v].bad = true;

        v = my_trie[v].next[c];
    }
    if (!good) {
        my_trie[v].output = true;
        my_trie[v].bad = true;
    } else
        my_trie[v].good = true;
}

inline void solve() {
    int n;

    cin >> n;

    FOR(i,0,n)
        add_string();
    
    stack<pair<int, string>> st;

    st.push(MP(0, ""));

    bool bad = false;

    vector<string> ans;

    while (!st.empty()) {
        int v = st.top().F;
        string s = st.top().S;
        st.pop();

        if (!my_trie[v].bad)
            continue;
        if (!my_trie[v].good) {
            ans.PB(s);
            continue;
        }
        if (my_trie[v].output) {
            bad = true;
            break;
        }

        FOR(i,0,K) {
            if (my_trie[v].next[i] == -1)
                continue;
            char ch = i+'a';
            st.push(MP(my_trie[v].next[i], s+ch));
        }

    }

    if (bad)
        cout << "-1\n";
    else {
        cout << ans.size() << '\n';
        FOR(i,0,ans.size()) {
            cout << ans[i] << '\n';
        }
    }

}

int main() {
    fastio;
    solve();
}