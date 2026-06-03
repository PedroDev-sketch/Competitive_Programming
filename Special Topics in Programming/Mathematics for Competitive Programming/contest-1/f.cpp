#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

ll addup(ll num)
{
    return (1LL<<num)-1;
}

void solve()
{
    ll n, m; cin >> n >> m;
    vvll xs(n, vll(m));
    for(auto& x : xs)
        for(auto& y : x)
            cin >> y;

    ll ans = 0;
    vpll ys, zs;

    for(ll i = 0; i < n; ++i)
    {
        ll one = 0, zero = 0;
        for(ll j = 0; j < m; ++j)
        {
            if(xs[i][j]==0) ++zero;
            else ++one;
        }
        ys.eb(zero, one);
    }

    for(ll i = 0; i < m; ++i)
    {
        ll one = 0, zero = 0;
        for(ll j = 0; j < n; ++j)
        {
            if(xs[j][i]==0) ++zero;
            else ++one;
        }

        zs.eb(zero, one);
    }

    for(auto [xy, yy] : ys)
    {
        //cout << "{" << xy << ", " << yy << "}\n";
        ans += addup(xy);
        //cout << "-> " << addup(xy) << '\n';
        ans += addup(yy);
    }
    for(auto [xy, yy] : zs)
    {
        //cout << "{" << xy << ", " << yy << "}\n";
        ans += addup(xy);
        //cout << "-> " << max(0LL, addup(xy-1)-1) << '\n';
        ans += addup(yy);
    }
    
    cout << ans - n*m << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
