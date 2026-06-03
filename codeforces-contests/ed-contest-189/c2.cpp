#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    vll dp(n+1, LLONG_MAX);
    dp[0] = 0;

    for(ll i = 0; i < n; ++i)
    {
        dp[i+1] = min(dp[i+1], dp[i] + (s[i]!=t[i]));
        if(i + 1 < n)
            dp[i+2] = min(dp[i+2], dp[i]+(s[i]!=s[i+1])+(t[i]!=t[i+1]));
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
