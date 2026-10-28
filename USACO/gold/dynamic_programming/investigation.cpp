#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define vll  vector<ll>
#define vvll  vector<vll>
#define pll  pair<ll, ll>
#define vpll  vector<pll>
#define vvpll vector<vector<pair<ll, ll>>>

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;
ll dp[12][94][94][2];
ll k, cnt = 1;

ll dp_solve(ll idx, ll num, ll sum, bool tight, string& str)
{
    if(idx==str.size())
        return (sum == 0 && num == 0);

    if(dp[idx][num][sum][tight]!=-1)
        return dp[idx][num][sum][tight];
    
    ll ans = 0, limit = (tight ? (str[idx] - '0') : 9);
    rep(i, 0, limit+1)
    {
        ll nxt_idx = idx+1;
        ll nxt_num = (10*num+i)%k;
        ll nxt_sum = (sum+i)%k;
        bool nxt_tight = tight && (i==limit);

        ans += dp_solve(nxt_idx, nxt_num, nxt_sum, nxt_tight, str);
    }

    if(dp[idx][num][sum][tight]==-1)
        dp[idx][num][sum][tight] = ans;

    return ans;
}

void solve()
{
    ll a, b; cin >> a >> b >> k;

    cout << "Case " << cnt++ << ": ";

    if(k > 90)
        cout << 0 << '\n';
    else
    {
        string str = to_string(b);
        string str2 = to_string(a-1);
        memset(dp, -1, sizeof(dp));
        ll ans = dp_solve(0, 0, 0, true, str);
        memset(dp, -1, sizeof(dp));
        ll sub = dp_solve(0, 0, 0, true, str2);
        cout << ans - sub << '\n';
    }

}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
