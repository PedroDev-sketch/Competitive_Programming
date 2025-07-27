#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define all(xs) xs.begin(), xs.end()
#define int long long

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vll xs(n);
        for(auto& x : xs) cin >> x;

        vector<bool> ys(n, false);

        ys[0] = true, ys[n-1] = true;

        int small = xs[0];
        for(int i = 1; i < n - 1; i++)
        {
            if(xs[i] < small) 
            {
                small = xs[i];
                ys[i] = true;
            }
        }

        int big = xs[n-1];
        for(int i = n - 2; i >= 0; i--)
        {
            if(xs[i] > big)
            {
                big = xs[i];
                ys[i] = true;
            }
        }

        string s = "";

        for(auto y : ys)
        {
            if(y) s+="1";
            else s+="0";
        }

        cout << s << '\n';
    }

    return 0;
}