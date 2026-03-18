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

void func(ll src, vll& vis, const vvll& xs)
{
    vis[src] = 1; 
    for(auto y : xs[src])
        if(!vis[y])
            func(y, vis, xs);
}

void solve()
{
    ll n, m; cin >> n >> m;

    vvll xs(n); vll vis(n, 0);
    while(m--)
    {
        ll x, y; cin >> x >> y;
        x--; y--;
        xs[x].eb(y);
        xs[y].eb(x);
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            ans++;
            func(i, vis, xs);
        }
    }

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
