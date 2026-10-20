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
    ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    complex<ll> p1 = {x1, y1}, p2 = {x2, y2}, p3 = {x3, y3};
    ll cross_prod = (conj(p3 - p1) * (p3 - p2)).imag();
    if(cross_prod > 0)
        cout << "LEFT";
    else if(cross_prod < 0)
        cout << "RIGHT";
    else cout << "TOUCH";
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
