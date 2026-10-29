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

/*
    The dp's dimensions will be:
    -> index in the forming string
    -> current number (long long) modulo m
    -> if the current number (string) is already smaller than b
*/

ll dp[2003][2003][2];
ll m, d;

ll solve_dp(ll idx, ll num, bool tight, string& str)
{
    if(idx==str.size())
        return (num==0);
    
    if(dp[idx][num][tight] != -1)
        return dp[idx][num][tight];

    ll limit = (tight ? str[idx]-'0' : 9);
    ll ans = 0;
    rep(i, 0, limit+1)
    {
        if((idx+1)&1 && i == d)
            continue;
        if(idx&1 && i != d)
            continue;
        
        ll nxt_idx = idx+1;
        ll nxt_num = (num*10+i)%m;
        bool nxt_tight = tight && i==limit;

        ll buff = solve_dp(nxt_idx, nxt_num, nxt_tight, str); 
        /*  if(buff)
        {
            cout << "added: " << buff << " - last digit: " << i << " - num%m: " << nxt_num << '\n';
        } */

        ans += buff;
        ans %= MOD;
    }

    if(dp[idx][num][tight] == -1)
        dp[idx][num][tight] = ans;

    return ans;
}

void solve()
{
    cin >> m >> d;
    string a, b; cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    ll fwd = solve_dp(0, 0, true, b);

    memset(dp, -1, sizeof(dp));
    ll back = solve_dp(0, 0, true, a);

    ll ans = (fwd - back + MOD) % MOD;

    bool a_valid = true;
    ll rem = 0;
    rep(i, 0, a.size()) 
    {
        if(!a_valid)
            break;

        ll digit = a[i] - '0';
        if(i % 2 == 0 && digit == d) a_valid = false;
        if(i % 2 == 1 && digit != d) a_valid = false;
        rem = (rem * 10 + digit) % m;
    }
    
    if(a_valid && rem == 0)
        ans = (ans + 1) % MOD;

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
