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
    The dp's dimensions will be: (size)
    -> index in the forming string (max is 18-ish)
    -> if the current number (string) is already smaller than b (2)
    -> if the current number is already greater than a (2)
    -> if we've already had a non leading zero or not (2)
*/

pair<ll, string> dp[20][2][2][2];

pair<ll, string> solve_dp(ll idx, bool lower_tight, bool upper_tight, bool has_started, string& a, string& b)
{
    if(idx==b.size())
    {
        if(has_started)
            return {1, ""};
        else return {0, ""};
    }

    if(dp[idx][lower_tight][upper_tight][has_started].ff != -1)
        return dp[idx][lower_tight][upper_tight][has_started];

    ll lower_limit = (lower_tight ? a[idx] - '0' : 0);
    ll upper_limit = (upper_tight ? b[idx] - '0' : 9);

    pair<ll, string> ans = {-1, ""};
    rep(i, lower_limit, upper_limit+1)
    {
        ll nxt_idx = idx+1;
        bool nxt_low_tight = lower_tight && i==lower_limit;
        bool nxt_up_tight = upper_tight && i==upper_limit;
        bool nxt_started = has_started || i;

        auto [suffix_product, suffix_str] = solve_dp(nxt_idx, nxt_low_tight, nxt_up_tight, nxt_started, a, b);

        ll curr_product;
        string curr_str;

        if(!has_started && !i)
        {
            curr_product = suffix_product;
            curr_str = suffix_str;
        }
        else
        {
            curr_product = i * suffix_product;
            curr_str = to_string(i) + suffix_str;
        }

        if(curr_product > ans.ff)
            ans = {curr_product, curr_str};
    }

    dp[idx][lower_tight][upper_tight][has_started] = ans;
    return ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;

    string stra = to_string(a), strb = to_string(b);
    ll diff = strb.size() - stra.size();
    rep(i, 0, diff)
        stra = '0' + stra;
    rep(i, 0, 20) rep(j, 0, 2) rep(k, 0, 2) rep(l, 0, 2) dp[i][j][k][l] = {-1, ""};
    cout << solve_dp(0, true, true, false, stra, strb).ss << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
