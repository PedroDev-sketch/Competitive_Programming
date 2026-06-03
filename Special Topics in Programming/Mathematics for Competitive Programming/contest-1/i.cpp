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
    ll cnt1, cnt2, x, y; cin >> cnt1 >> cnt2 >> x >> y;
    auto binfind = [&] (auto self, ll a, ll b) -> ll
    {
        if(a==b) return a;
        ll m = a + (b-a)/2;
        ll mx = m/x, my = m/y;
        ll mxy = mx/y;

        ll cnt1m = m - mx, cnt2m = m - my, cntboth = m - mxy;
        if(cnt1m >= cnt1 && cnt2m >= cnt2 && cntboth >= cnt1+cnt2)
            return self(self, a, m);
        return self(self, m+1, b);
    };

    ll ans = binfind(binfind, 1, 1e12);
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
