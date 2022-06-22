#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;

int main()
{
    // acepta el reto 572
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 1;
    cin >> tc;
    float min = 10.0, max = 0.0, tmp;

    for (int i = 0; i < tc; i++)
    {
        min = 10.0, max = 0.0;
        for (int i = 0; i < 5; i++)
        {
            cin >> tmp;
            if (tmp < min)
                min = tmp;
            if (tmp > max)
                max = tmp;
        }
        if (min > 0.0f || max >= 9.0f)
            cout << "MEDIA"
                 << "\n";
        else
            cout << "SUSPENSO DIRECTO"
                 << "\n";
    }
}
