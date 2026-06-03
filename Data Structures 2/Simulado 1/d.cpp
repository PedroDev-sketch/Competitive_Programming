#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define eb emplace_back

void dfs(vvll& xs, vll& visited, ll i)
{
    visited[i] = 1;
    for(auto x : xs[i])
        if(!visited[x])
            dfs(xs, visited, x);
}

signed main()
{
    ll n, m;
    cin >> n >> m;

    vvll xs(n);
    vll visited(n, 0);
    while(m--)
    {
        ll x, y; cin >> x >> y;
        x--; y--;
        xs[x].eb(y); xs[y].eb(x);
    }

    ll ans = 0, idx = 0;
    for(auto v : visited)
    {
        if(v==0)
        {
            ans++;
            dfs(xs, visited, idx);
        }
        idx++;
    }

    cout << ans << '\n';
}