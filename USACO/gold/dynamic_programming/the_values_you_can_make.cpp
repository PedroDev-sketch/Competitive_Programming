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
    vll xs(n); for(auto& x : xs) cin >> x;

    vector<bitset<507>> dp(k+1);
    dp[0][0] = 1;
    
    for(auto x : xs)
        per(i, k, x)
            dp[i] |= dp[i-x] | (dp[i-x] << x);

    vll ans;
    rep(i, 0, k+1)
        if(dp[k][i])
            ans.eb(i);

    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
