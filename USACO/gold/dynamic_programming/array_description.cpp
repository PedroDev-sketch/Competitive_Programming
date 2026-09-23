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
    vll xs(n); for(auto& x : xs) cin >> x;
    
    vll dp(m+2);
    if(xs[0]==0)
        rep(i, 1, m+1)
            dp[i] = 1;
    else dp[xs[0]] = 1;

    rep(i, 1, n)
    {
        vll nxt_dp(m+2);

        if(xs[i]==0)
        {
            rep(j, 1, m+1)
            {
                ll w = dp[j-1] + dp[j] + dp[j+1];
                nxt_dp[j] = w % MOD;
            }
        }
        else
        {
            ll j = xs[i];
            ll w = dp[j-1] + dp[j] + dp[j+1];
            nxt_dp[j] = w % MOD;
        }

        dp = move(nxt_dp);
    }

    ll ans = 0;
    rep(i, 1, m+1)
    {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
