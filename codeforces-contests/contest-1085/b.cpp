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
    ll n, m, l; cin >> n >> m >> l;
    vll xs(n); for(auto& x : xs) cin >> x;

    m = min(m, n+1);
    vll ys(m, 0); ll xidx = 0, rem = n;
    for(ll i = 0; i < xs.back(); ++i)
    {
        if(m>rem+1)
        {
            sort(all(ys), greater<>());
            m = rem+1;
            ys.resize(m);
        }
        auto it_min = min_element(all(ys));
        ++(*it_min);
        if(xidx < n && xs[xidx]==i+1)
        {
            auto it_max = max_element(all(ys));
            *it_max = 0;
            xidx++;
            --rem;
        }
    }

    /* cout << "-> ";
    for(auto y : ys) cout << y << ' ';
    cout << '\n'; */

    auto it = max_element(all(ys));
    cout << *it + (l - xs.back()) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
