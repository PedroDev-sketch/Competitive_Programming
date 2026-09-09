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

const ll MOD = 998244353;

void solve()
{
    ll q, k; cin >> q >> k;
    vll dp(k+1, 0); dp[0] = 1;
    while(q--)
    {
        char t; ll num;
        cin >> t >> num;
        if(t=='+')
        {
            per(i, k, 1)
            {
                if(i-num < 0)
                    continue;
                dp[i] += dp[i-num];
                if(dp[i] > MOD) dp[i] -= MOD;
            }
            cout << dp[k] << '\n';
        }
        else
        {
            rep(i, 1, k+1)
            {
                if(i-num < 0)
                    continue;
                dp[i] -= dp[i-num];
                if(dp[i] < 0) dp[i] += MOD;
            }
            cout << dp[k] << '\n';
        }
    }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
