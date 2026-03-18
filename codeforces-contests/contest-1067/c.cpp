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
    ll n, k; cin >> n >> k;
    vll as(n), bs(n);
    for(auto& x : as) cin >> x;
    for(auto& x : bs) cin >> x;

    if(k&1)
        for(ll i = 0; i < n; ++i)
            as[i]+=bs[i];

    ll ans = as[0], curr = as[0];
    pll xs{0, 0}, ys{0, 0};
    for(ll i = 1; i < n; ++i)
    {
        if(as[i] > curr+as[i])
        {
            curr = as[i];
            ys = {i, i};
        }
        else
        {
            curr += as[i];
            ++ys.ss;
        }

        if(curr > ans)
        {
            ans = curr;
            xs = ys;
        }
    }

    ll num = 0;
    for(ll i = xs.ff; i <= xs.ss; ++i)
    {
        if(k&1)
            ans -= bs[i];
        num = max(num, bs[i]);
    }

    if(k&1)
    {
        cout << ans + num << '\n';
    }
    else
    {
        cout << ans << '\n';
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
