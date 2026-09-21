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
    vector<string> grid(n); for(auto& x : grid) cin >> x;
    vvll dp(n, vll(n, 0)); if(grid[0][0] != '*') dp[0][0] = 1;
    rep(i, 0, n)
        rep(j, 0, n)
        {
            if(grid[i][j]=='*')
                continue;
            if(i)
            {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            }
            if(j)
            {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    cout << dp[n-1][n-1] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
