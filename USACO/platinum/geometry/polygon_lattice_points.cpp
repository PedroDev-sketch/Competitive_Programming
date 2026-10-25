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

void solve()
{
    ll n; cin >> n;
    vpll xs(n); for(auto& [x, y] : xs) cin >> x >> y;
    ll b = 0, area = 0;
    rep(i, 0, n)
    {
        ll j = (i+1)%n;
        complex<ll> p1{xs[i].ff, xs[i].ss}, p2{xs[j].ff, xs[j].ss};

        b += gcd(abs(p2.imag() - p1.imag()), abs(p2.real() - p1.real()));
        area += (conj(p1)*p2).imag();
    }    

    ll a = abs(area) - b + 2;
    cout << a/2 << " " << b << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
