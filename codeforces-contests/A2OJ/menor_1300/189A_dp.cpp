#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vll xs{a, b, c};
    sort(all(xs));

    vll dp(n+1, 0);
    dp[0]=0;
    for(ll x = 1; x <= n; x++)
    {
        dp[x] = -LLONG_MAX;
        for(auto y : xs)
            if(x-y >= 0)
                dp[x] = max(dp[x], dp[x-y]+1);
    }

    cout << dp[n] << '\n';
    
    return 0;
}