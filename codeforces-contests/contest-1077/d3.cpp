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
    ll x, y, low=1e12; cin >> x >> y;

    ll p, q;
    auto check = [&](ll a, ll b) -> void
    {
        if((a&b)==0 && abs(a-x)+abs(b-y) < low)
        {
            low = abs(a-x)+abs(b-y);
            p = a; q = b;
        }
    };

    check(x, y);
    for(ll i = 30; i >= 0; --i)
    {
        if((x&y) >> i & 1)
        {
            check((x>>i<<i)+(1LL<<i), y);
            check(x, (y>>i<<i)+(1LL<<i));
            check(x>>i<<i,(y>>i<<i)-1);
            check((x>>i<<i)-1, y>>i<<i);
        }
    }
    cout << p << " " << q << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
