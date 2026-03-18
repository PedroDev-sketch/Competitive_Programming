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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void func(ll src, ll& ans, vector<bool>& vis, const vvll& xs)
{
    if(ans==1e6)
        return;
    
    vis[src] = true;
    ans++;

    for(auto x : xs[src])
        if(!vis[x])
            func(x, ans, vis, xs);

    vis[src] = false;
}

void solve()
{
    ll n, m; cin >> n >> m;

    vvll xs(n);
    for(ll i = 0; i < m; i++)
    {
        ll x, y; cin >> x >> y;
        xs[x-1].eb(y-1);
        xs[y-1].eb(x-1);
    }

    vector<bool> vis(n, false);
    ll ans = 0;
    func(0, ans, vis, xs);

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
