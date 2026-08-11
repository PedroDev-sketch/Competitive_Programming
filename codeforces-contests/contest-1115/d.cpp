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

void solve()
{
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    vll ds(n-1); rep(i, 1, n) ds[i-1] = xs[i] - xs[i-1];

    ll l = 0, r = 0;
    while(l < n-1)
    {
        r = l;
        while(r < n-1 && (ds[l]&1)==(ds[r]&1))
            ++r;
        sort(ds.begin()+l, ds.begin()+r);
        l = r;
    }

    vll ans(n); ans[0] = xs[0];
    rep(i, 1, n)
        ans[i] = ans[i-1] + ds[i-1];

    for(auto x : ans)
        cout << x << ' ';
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
