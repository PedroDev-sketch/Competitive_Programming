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
    ll n, ans = 0; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    
    vvll dp(n+1, vll(2, 1e9));
    dp[0][0] = 0;
    for(ll i = 0; i < n; ++i)
    {
        dp[i+1][1] = min(dp[i+1][1], dp[i][0] + xs[i]);
        if(i+2 <= n)
            dp[i+2][1] = min(dp[i+2][1], dp[i][0]+xs[i]+xs[i+1]);

        dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
        if(i + 2 <= n)
            dp[i+2][0] = min(dp[i+2][0], dp[i][1]);
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
