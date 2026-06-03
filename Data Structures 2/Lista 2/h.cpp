#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define eb emplace_back
#define ff first 
#define ss second 
#define fio cin.tie(0)->ios::sync_with_stdio(0)

vpll moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(set<ll>& ans, const vvll& xs, vvll& visited, pll st, ll n, ll m)
{
    ll buff = 0;
    queue<pll> qs;
    qs.push(st);

    while(!qs.empty())
    {
        pll cd = qs.front(); qs.pop();
        visited[cd.ff][cd.ss] = 1;
        buff += xs[cd.ff][cd.ss];

        for(auto [x, y] : moves)
        {
            ll nx = cd.ff+x, ny = cd.ss+y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && xs[nx][ny])
            {
                qs.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }

    ans.insert(buff);
}

void solve()
{
    ll n, m; cin >> n >> m;
    set<ll> ans;

    vvll xs(n, vll(m)), visited(n, vll(m, 0));
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            cin >> xs[i][j];

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            if(!visited[i][j] && xs[i][j])
                bfs(ans, xs, visited, make_pair(i, j), n, m);

    if(ans.empty()) cout << 0;
    else cout << *ans.rbegin();
    cout << '\n';
}

signed main()
{
    fio;
    ll t=1; cin >> t;
    while(t--) solve();
}
