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
        map<int, int> hist;
        for(auto& x : xs) 
        {
            cin >> x;
            hist[x]++;
        }

        sort(all(xs));

        vll mex(n+1, 0);
        vll ks(n+1, 0);

        for(int i = 0; i < n+1; i++)
        {
            mex[i] += hist[i];
        }
    }

    return 0;
}