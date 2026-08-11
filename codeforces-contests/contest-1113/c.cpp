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

ll fast_pow(ll base, ll exp)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp&1)
            res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

void solve()
{
    ll n; cin >> n;
    n <<= 1LL;
    vll xs(n+1, 0), vis(n+1, 0), dp(n+1, 0);

    for(ll i = 1; i <= n; ++i)
    {
        cin >> xs[i];

        dp[i] = dp[i-1]+1;
        if(vis[xs[i]])
        {
            ll dist = i - vis[xs[i]] + 1;
            dp[i] = max(dp[i], dp[vis[xs[i]] - 1] + dist*dist);
        }
        else vis[xs[i]] = i;
    }

    cout << dp[n] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
