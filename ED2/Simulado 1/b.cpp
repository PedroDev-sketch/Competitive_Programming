#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>

signed main()
{
    ll n, m;
    cin >> n >> m;
    vvll xs(n, vll(n, 0));
    set<pll> ans;
    while(m--)
    {
        ll x, y; cin >> x >> y;
        xs[x-1][y-1]=1;
        xs[y-1][x-1]=1;
    }

    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            if(i!=j && xs[i][j] == 0)
            {
                ans.insert(make_pair(i+1, j+1));
                xs[j][i]=2;
            }
        }
    }

    for(auto [x, y] : ans) cout << x << " " << y << '\n';
}