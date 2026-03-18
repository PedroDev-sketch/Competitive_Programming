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
    ll n, idx = 0; cin >> n;
    vll xs(n); 
    for(auto& x : xs) cin >> x;
    vll ys = xs; sort(all(ys));

    if(xs==ys)
    {
        cout << "-1\n";
        return;
    }

    ll ans = 1e10; 
    vll unxs;
    for(ll i = 0; i < n; ++i)
        if(xs[i] != ys[i]) 
            unxs.eb(xs[i]);

    ll mn = ys[0];
    ll mx = ys.back();
    for(auto it = unxs.begin(); it != unxs.end(); ++it)
        ans = min(ans, max(*it - mn, mx - *it));
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
