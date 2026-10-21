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

const ll MOD = 1e9+7;

ll cross_product(complex<ll> a, complex<ll> b)
{
    return (conj(a)*b).imag();
}

void solve()
{
    ll n; cin >> n;
    vpll xs(n); for(auto& [x, y] : xs) cin >> x >> y;

    ll ans = 0;
    rep(i, 0, n)
    {
        complex<ll> a{xs[i].ff, xs[i].ss}, b{xs[(i+1)%n].ff, xs[(i+1)%n].ss};
        ans += cross_product(a, b);
    }
    cout << abs(ans) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
