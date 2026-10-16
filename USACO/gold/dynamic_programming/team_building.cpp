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

struct dt
{
    ll val;
    vll p_val;
};

void solve()
{
    ll n, p, k; cin >> n >> p >> k;
    
    vector<dt> xs(n);
    rep(i, 0, n)
    {
        ll x; cin >> x;
        xs[i].val = x;
    }

    rep(i, 0, n)
        rep(j, 0, p)
        {
            ll x; cin >> x;
            xs[i].p_val.eb(x);
        }

    sort(all(xs), [](const dt& a, const dt& b){ return a.val > b.val; });
    vvll dp(n+1, vll((1<<p), -1)); dp[0][0] = 0;

    rep(i, 0, n)
    {
        rep(mask, 0, 1<<p)
        {
            if(dp[i][mask]==-1)
                continue;

            rep(j, 0, p)
            {
                if((mask&(1<<j)))
                    continue;
                dp[i+1][mask|(1<<j)] = max(dp[i+1][mask|(1<<j)], dp[i][mask]+xs[i].p_val[j]);
            }

            ll c = __builtin_popcount(mask);
            if(i - c < k)
                dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask]+xs[i].val);

            else
                dp[i+1][mask] = max(dp[i+1][mask], dp[i][mask]);
        }
    }

    cout << dp[n][(1<<p)-1] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
