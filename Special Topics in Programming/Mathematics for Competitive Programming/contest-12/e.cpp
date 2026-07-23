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
    ll x, y, z; cin >> x >> y >> z;

    ll ans = 0;
    auto binfind = [&](auto& self, ll l, ll r)
    {
        ll m = (l+r)/2, cost = 0;
        if(l>=r || abs(l-r) <= 1)
            return l;

        bool flag = true;

        if(x < m || y < m)
            flag = false;
        ll left = z + (x-m) + (y-m);
        if(left < m)
            flag = false;

        if(!flag)
            return self(self, l, m);
        else
        {
            ans = max(ans, m);
            return self(self, m, r);
        }
    };

    binfind(binfind, 0, 1e12+7);
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
