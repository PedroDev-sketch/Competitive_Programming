#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

const ll MAXN = 1e6+10;

void solve()
{
    ll v, j, m; cin >> v >> j >> m;
    double i = j/100.0;

    vector<double> xs(MAXN);
    double x = 0; xs[0] = 0;

    double curr_pow = 1.0;
    for(ll k = 1; k < MAXN; ++k)
    {
        curr_pow *= (1.0+i);
        x += 1.0/curr_pow;
        xs[k] = x;
    }

    ll ans = LLONG_MAX;
    auto binfind = [&](auto& self, ll l, ll r)
    {
        if(l > r)
            return 0;
        ll n = (l+r)/2;

        double p = (double)v/xs[n]; 
        if(p <= m)
        {
            ans = min(ans, n);
            self(self, l, n-1);
        }
        else self(self, n+1, r);
        return 0;
    };

    binfind(binfind, 1, MAXN-1);
    if(ans > 1e6)
        ans = -1;

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while(t--)
        solve();
}