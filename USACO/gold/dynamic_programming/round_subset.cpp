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

void solve()
{
    ll n, k; cin >> n >> k;
    vpll xs(n);
    rep(i, 0, n)
    {
        ll x; cin >> x;
        while(x%2==0)
        {
            x /= 2;
            ++xs[i].ff;
        }
     
        while(x%5==0)
        {
            x /= 5;
            ++xs[i].ss;
        }
    }

    ll fives = 25*n+50;
    vvll dp(k+1, vll(fives+1, -1)); dp[0][0] = 0;
    for(auto x : xs)
    {
        ll cnt2 = x.ff, cnt5 = x.ss;
        per(i, k, 1)
            per(j, fives, cnt5)
                if(dp[i-1][j-cnt5] != -1)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-cnt5]+ cnt2);
    }

    ll ans = 0;
    rep(j, 0, fives+1)
        if(dp[k][j]!=-1)
            ans = max(ans, min(j, dp[k][j]));

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
