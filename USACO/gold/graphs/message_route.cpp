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

const ll MOD = 1e9+7;

void solve()
{
    ll n, m; cin >> n >> m;
    vvll adj(n+1);
    rep(i, 0, m)
    {
        ll a, b; cin >> a >> b;
        adj[a].eb(b);
        adj[b].eb(a); 
    }

    vll distance(n+1, LLONG_MAX), parent(n+1);
    distance[1] = 1;

    auto bfs = [&](ll src)
    {
        queue<ll> xs;
        xs.push(src);

        while(!xs.empty())
        {
            ll curr_node = xs.front(); xs.pop();
            for(auto node : adj[curr_node])
            {
                if(distance[node]==LLONG_MAX)
                {
                    distance[node] = distance[curr_node]+1;
                    parent[node] = curr_node;
                    xs.push(node);
                }
            }
        }
    };

    bfs(1);

    stack<ll> ys; ll num = n;
    while(num)
    {
        ys.push(num);
        num = parent[num];
    }

    if(distance[n]==LLONG_MAX)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << distance[n] << '\n';
        while(!ys.empty())
        {
            cout << ys.top() << ' ';
            ys.pop();
        }
        cout << '\n';
    }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
