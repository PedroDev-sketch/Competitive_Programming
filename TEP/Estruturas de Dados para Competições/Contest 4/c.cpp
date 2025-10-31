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

void solve()
{
    ll st = 1;
    map<ll, vll> xs;

    ll n; cin >> n;
    ll buff = n;
    while(buff--)
    {
        ll a, b;
        cin >> a >> b;
        xs[a].eb(b);
        xs[b].eb(a);
    }

    queue<ll> qs;
    set<ll> vis;
    qs.push(st);
    vis.insert(st);
    while(!qs.empty())
    {
        ll num = qs.front();
        qs.pop();

        for(auto x : xs[num])
        {
            if(!vis.count(x))
            {
                qs.push(x);
                vis.insert(x);
            }
        }
    }

    ll ans = *vis.rbegin();
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
