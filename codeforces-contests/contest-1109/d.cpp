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
    ll n, m; cin >> n >> m;
    vll as(n), bs(m);
    for(auto& a : as) cin >> a; for(auto& b : bs) cin >> b;

    vll psum(n+1, 0), nsum(n+1, 0);
    for(ll i = 1; i <= n; ++i)
    {
        psum[i] += psum[i-1];
        nsum[i] += nsum[i-1];
        if(as[i-1] < 0) nsum[i] += as[i-1];
        else psum[i] += as[i-1];
    }

    ll ans = 0, last = 0;
    sort(all(bs));
    for(ll i = 0; i < m; ++i)
    {
        ll b = bs[i];
        ll pos = psum[b] - psum[last];
        ll neg = nsum[b] - nsum[last];
        ans += max(pos + neg, (-1)*pos + (-1)*neg);
        last = b;
    }

    ll lastpos = bs.back();
    for(ll i = lastpos; i < n; ++i)
        ans += as[i];

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
