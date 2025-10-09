#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define MODN 1073741824

ll d(ll x)
{
    vll ds;
    for(ll i = 1; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            ds.eb(i);
            if(i * i != x) ds.eb(x/i);
        }
    }
    return ((ll) ds.size());
}

signed main()
{
    fio;
    
    ll a, b, c;
    cin >> a >> b >> c;

    vll xs(a*b*c + 1, -1);

    ll ans = 0;
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            for(int k = 1; k <= c; k++)
            {
                if(xs[i*j*k] == -1)
                    xs[i*j*k] = d(i*j*k)%MODN;
                
                ans += xs[i*j*k];
            }

    cout << ans%MODN << '\n';
    return 0;
}