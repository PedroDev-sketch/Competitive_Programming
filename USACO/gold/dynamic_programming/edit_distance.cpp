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
    string s, t; cin >> s >> t;
    ll n = s.size(), m = t.size();

    vvll dp(n+1, vll(m+1));

    rep(i, 0, n+1)
        dp[i][0] = i;

    rep(i, 0, m+1)
        dp[0][i] = i;

    rep(i, 1, n+1)
        rep(j, 1, m+1)
        {
            if(s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
        }

    /* for(auto x : dp)
    {
        for(auto y : x)
            cout << y << ' ';
        cout << '\n';
    } */
    cout << dp[n][m] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
