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
    ll n, x; cin >> n >> x;
    vll price(n), pages(n);
    for(auto& x : price) cin >> x; for(auto& x : pages) cin >> x;
    vll dp(x+1);
    rep(i, 0, n)
        per(j, x, 0)
        {
            if(j - price[i] < 0)
                continue;
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }

    cout << dp[x] << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
