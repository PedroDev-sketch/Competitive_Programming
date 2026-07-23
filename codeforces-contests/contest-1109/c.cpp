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
    ll n, x, y; cin >> n >> x >> y;
    vll xs(n); for(auto& x : xs) cin >> x;
    vector<bool> vis(n, false);
    vvll graph(n);

    for(ll i = 0; i < n; ++i)
    {
        if(i+x < n)
        {
            graph[i].push_back(i+x);
            graph[i+x].push_back(i);
        }
        if(i+y < n)
        {
            graph[i].push_back(i+y);
            graph[i+y].push_back(i);
        }
    }

    set<ll> zs;
    auto search = [&](auto& self, ll src)
    {
        if(vis[src])
            return 0;

        zs.insert(src);
        vis[src] = true;

        if(graph[src].empty())
            return 0;

        for(ll i = 0; i < graph[src].size(); ++i)
            self(self, graph[src][i]);

        return 0;
    };

    for(ll i = 0; i < n; ++i)
    {
        if(vis[i])
            continue;
        zs.clear();
        search(search, i);

        priority_queue<ll, vll, greater<>> pq;
        for(auto it : zs)
            pq.push(xs[it]);

        for(auto it : zs)
        {
            xs[it] = pq.top();
            pq.pop();
        }
    }

    vll ys = xs; sort(all(ys));
    if(xs==ys)
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
