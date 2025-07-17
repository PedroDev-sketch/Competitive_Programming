#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9+7;
#define int uint64_t

signed main()
{
    int n;
    cin >> n;

    vector<string> xs(n);
    vector<vector<int>> ys(n, vector<int> (n, 0));

    for(auto& x : xs) cin >> x;

    if(xs[0][0] == '*')
    {
        cout << 0 << '\n';
        return 0;
    } else ys[0][0] = 1;

    bool flag1 = false, flag2 = false;
    for(int i = 1; i < n; i++)
    {
        if(xs[0][i] == '*') flag1 = true;
        if(xs[i][0] == '*') flag2 = true;

        if(!flag1)ys[0][i] = 1;
        if(!flag2)ys[i][0] = 1;
    }

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            if(xs[i][j] != '*')
            {
                if(xs[i-1][j] != '*') ys[i][j] += ys[i-1][j];
                if(xs[i][j-1] != '*') ys[i][j] += ys[i][j-1];
                ys[i][j] %= INF;
            }else continue; 

    /* for(auto e : ys)
    {
        for(auto p : e) cout << p << ' ';
        cout << '\n';
    }  */

    cout << (ys[n-1][n-1]) % INF << '\n';
    return 0;
}