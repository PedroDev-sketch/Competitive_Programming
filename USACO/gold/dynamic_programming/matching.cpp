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
    ll n; cin >> n;
    vvll xs(n, vll(n));
    rep(i, 0, n)
        rep(j, 0, n)
            cin >> xs[i][j];

    ll size = 1<<n;
    vll dp(size); dp[0] = 1;

    rep(i, 0, size)
    {
        if(dp[i]==0)
            continue;
        
        ll x = __builtin_popcount(i);
        rep(j, 0, n)
        {
            if(!(i&(1<<j)) && xs[x][j])
            {
                ll nxt = i | (1<<j);
                dp[nxt] += dp[i];
                dp[nxt] %= MOD;
            }
        }
    }

    cout << dp[size-1] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
