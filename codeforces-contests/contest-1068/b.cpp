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
    ll n; cin >> n;
    vll xs(n), ys(n);
    for(auto& x : xs) cin >> x;
    for(auto& y : ys) cin >> y;

    ll lscore = 0, hscore = 0;
    for(ll i = 0; i < n; ++i)
    {
        ll newhigh = max(hscore - xs[i], ys[i] - lscore);
        ll newlow = min(lscore - xs[i], ys[i] - hscore);
        hscore = newhigh;
        lscore = newlow;
    }
    cout << hscore << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
