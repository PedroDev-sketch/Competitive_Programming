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

ll pwdist(ll a, ll b, ll c)
{
    return abs(a-b)+abs(b-c)+abs(c-a);
}

void solve()
{
    ll a, b, c; cin >> a >> b >> c;
    vll mvs{0, 1, -1};
    ll ans = LLONG_MAX;
    for(ll i = 0; i < 3; ++i)
        for(ll j = 0; j < 3; ++j)
            for(ll k = 0; k < 3; ++k)
                ans = min(ans, pwdist(a+mvs[i], b+mvs[j], c+mvs[k]));
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
