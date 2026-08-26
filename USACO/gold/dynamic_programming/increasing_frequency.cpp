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

const ll MAXN = 5e5+5;
vll dp(MAXN), last_c(MAXN);

void solve()
{
    ll n, c; cin >> n >> c;
    vll xs(n); 

    ll total_c = 0, max_gain = 0;
    
    for(auto& x : xs) 
    {
        cin >> x;

        if(x==c)
        {
            ++total_c;
            continue;
        }

        ll cnt = total_c - last_c[x];
        dp[x] = max(0LL, dp[x] - cnt) + 1;
        last_c[x] = total_c;
        max_gain = max(max_gain, dp[x]);
    }

    cout << total_c + max_gain << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
