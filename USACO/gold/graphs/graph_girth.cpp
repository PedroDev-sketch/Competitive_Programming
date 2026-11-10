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
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;

void solve()
{
    ll n, m; cin >> n >> m;
    vvll adj(n+1);

    rep(i, 0, m)
    {
        ll a, b; cin >> a >> b;
        adj[a].eb(b); adj[b].eb(a);
    }

    ll ans = LLONG_MAX;

    auto bfs = [&](ll src)
    {
        vll dist(n+1, -1); dist[src] = 0;
        queue<ll> q; q.push(src);
        
        while(!q.empty())
        {
            ll node = q.front();
            q.pop();

            if(adj[node].empty())
                continue;
            
            for(auto x : adj[node])
            {
                if(dist[x]==-1)
                {
                    dist[x] = dist[node] + 1;
                    q.push(x);
                }
                else if(dist[x] >= dist[node])
                    ans = min(ans, dist[node]+dist[x]+1);
            }
        }
    };

    rep(i, 1, n+1)
        bfs(i);

    cout << ((ans==LLONG_MAX) ? -1LL : ans) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
