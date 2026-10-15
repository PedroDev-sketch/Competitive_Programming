#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;

void solve()
{
    ll n, m; cin >> n >> m;

    vvll xs(n);
    rep(i, 0, m)
    {
        ll a, b; cin >> a >> b;
        --a, --b;
        xs[b].eb(a);
    }

    vvll dp((1<<n), vll(n));
    dp[1][0] = 1;
    rep(i, 2, 1<<n)
    {
        if(!(i&1))
            continue;

        if(i&(1<<(n-1)) && i != (1<<n)-1)
            continue;

        rep(j, 0, n)
        {
            if(!(i&(1<<j))) 
                continue;
            
            ll prev = i^(1<<j);
            for(auto x : xs[j])
            {
                if(prev&(1<<x))
                    dp[i][j] = (dp[i][j] + dp[prev][x]) % MOD;
            }
        }
    }

    cout << dp[(1<<n)-1][n-1] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
