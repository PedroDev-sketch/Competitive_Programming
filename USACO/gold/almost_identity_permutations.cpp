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

ll f(ll start, ll end)
{
    ll res = 1;
    for(ll i = start; i <= end; ++i)
        res *= i;
    return res;
}

void solve()
{
    ll n, k; cin >> n >> k;

    ll ans = 0;
    vll Dn(5); Dn[1] = 0, Dn[2] = 1;

    for(ll i = 3; i <= 4; ++i)
        Dn[i] = (i-1)*(Dn[i-1]+Dn[i-2]);

    for(ll i = 1; i <= k; ++i)
    {
        ll num = f(n-i+1, n), denum = f(1, i);
        ll c = num/denum;
        ans += c * Dn[i];
    }

    cout << ans+1 << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
