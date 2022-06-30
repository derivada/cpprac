#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, E, i;
    unsigned int in, out;
    bitset<64> count;
    while (1)
    {
        i = 0, E = 0;
        bitset<64> count = 0;
        cin >> E >> N;
        if (E == 0)
            break;
        for (; i < E; i++)
        {
            cin >> in >> out;
            count.flip(in);
            count.flip(out);
        }
        if (count.count() <= 2)
            cout << "SI\n";
        else
            cout << "NO\n";
    }
}