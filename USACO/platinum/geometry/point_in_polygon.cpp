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

complex<ll> cross_prod(complex<ll> a, complex<ll> b, complex<ll> pt)
{
    return (conj(pt-a)*(pt-b));
}

ll inside(vpll& xs, ll n, complex<ll> pt)
{
    ll ans = 0;
    rep(i, 0, n)
    {
        ll j = (i+1)%n;
        complex<ll> a{xs[i].ff, xs[i].ss}, b{xs[j].ff, xs[j].ss};
        ll ret = cross_prod(a, b, pt).imag(), dot = cross_prod(a, b, pt).real();
        if(ret == 0 && dot <= 0)
            return 2;

        if(a.imag() <= pt.imag() && b.imag() > pt.imag())
        {
            if(ret > 0)
                ans = !ans;
        }
        else if(a.imag() > pt.imag() && b.imag() <= pt.imag())
        {
            if(ret < 0)
                ans = !ans;
        }
    }

    return ans;
}

void solve()
{
    ll n, m; cin >> n >> m;
    vpll xs(n); for(auto& [x, y] : xs) cin >> x >> y;

    while(m--)
    {
        ll a, b; cin >> a >> b;
        complex<ll> x{a, b};
        ll ret = inside(xs, n, x);
        if(!ret)
            cout << "OUTSIDE";
        else if(ret==1)
            cout << "INSIDE";
        else cout << "BOUNDARY";
        cout << '\n';
    }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
