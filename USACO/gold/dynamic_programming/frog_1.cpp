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
    ll n; cin >> n;
    vll xs(n), dp(n, 0); for(auto& x : xs) cin >> x;
    dp[1] = abs(xs[0] - xs[1]);

    for(ll i = 2; i < n; ++i)
        dp[i] = min( dp[i-1] + abs(xs[i-1] - xs[i]),  dp[i-2] + abs(xs[i-2] - xs[i]) );

    cout << dp[n-1] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
