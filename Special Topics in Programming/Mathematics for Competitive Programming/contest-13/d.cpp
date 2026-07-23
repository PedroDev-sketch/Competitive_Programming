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

ll val(ll a, ll b, ll x, ll y, ll n)
{
    ll da = min(n, a - x);
    a -= da;
    n -= da;

    ll db = min(n, b - y);
    b -= db;
    return a*b;
}

void solve()
{
    ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;

    cout << min(val(a, b, x, y, n), val(b, a, y, x, n)) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
