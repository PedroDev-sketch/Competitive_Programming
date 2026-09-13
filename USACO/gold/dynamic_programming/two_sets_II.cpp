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

ll fast_pow(ll base, ll exp)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp & 1)
        {
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return res;
}

ll mod_inv(ll num)
{
    return fast_pow(num, MOD-2);
}

void solve()
{
    ll n; cin >> n;
    ll num = (n*(n+1))/2;
    if(num&1)
    {
        cout << "0\n";
        return;
    }
    num >>= 1;

    vll xs(n); iota(all(xs), 1);
    vll dp(num+1); dp[0] = 1;
    for(auto x : xs)
    {
        per(i, num, 0)
        {
            if(i - x < 0)
                continue;
            dp[i] += dp[i-x];
            dp[i] %= MOD;
        }
    }

    cout << dp[num]*mod_inv(2) % MOD << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
