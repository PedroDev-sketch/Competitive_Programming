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

ll sgn(ll x)
{
    return (x > 0) - (x < 0);
}

ll cross_product(complex<ll> p, complex<ll> p1, complex<ll> p2)
{
    return (conj(p - p1) * (p - p2)).imag();
}

bool on_segment(complex<ll> p, complex<ll> p1, complex<ll> p2)
{
    if(cross_product(p, p1, p2))
        return false;
    bool c1 = p.imag() >= min(p1.imag(), p2.imag()) && p.imag() <= max(p1.imag(), p2.imag());
    bool c2 = p.real() >= min(p1.real(), p2.real()) && p.real() <= max(p1.real(), p2.real());
    return c1 && c2;
}

void solve()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    complex<ll> p1 = {x1, y1}, p2 = {x2, y2}, p3 = {x3, y3}, p4 = {x4, y4};

    ll side1 = cross_product(p1, p3, p4), 
    side2 = cross_product(p2, p3, p4),
    side3 = cross_product(p3, p1, p2), 
    side4 = cross_product(p4, p1, p2);

    bool check1 = sgn(side1) != sgn(side2) && sgn(side3) != sgn(side4);
    bool check2 = (p1==p3 || p1==p4 || p2==p3 || p2==p4);
    bool check3 = on_segment(p1, p3, p4) || on_segment(p2, p3, p4) || on_segment(p3, p1, p2) || on_segment(p4, p1, p2);

    if(check1 || check2 || check3)
        cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
