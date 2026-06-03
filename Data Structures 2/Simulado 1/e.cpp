#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define eb emplace_back
#define ep emplace
#define mp make_pair
#define ff first 
#define ss second 

const ll inf = 1'000'000'000;

vpll moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void bfs(vvll& xs, vector<string>& ys, set<ll>& ans, pll ps, ll dist, ll n, ll m)
{
    ll x = ps.ff, y = ps.ss;
    if(ys[x][y]=='+') return;
    xs[x][y] = dist;

    if((x==0 || y==0 || x==n-1 || y==m-1) && dist != 0)
    {
        ans.insert(dist);
        return;
    }

    for(auto [mx, my] : moves)
    {
        ll newx = x + mx, newy = y + my;
        pll newps = mp(newx, newy);
        if(newx>=0 && newx < n && newy >= 0 && 
            newy < m && xs[newx][newy] > dist+1 && ys[newx][newy]=='.')
                bfs(xs, ys, ans, newps, dist+1, n, m);
    }
}

signed main()
{
    ll n, m;
    cin >> n >> m;

    vvll xs(n, vll(m, inf));
    vector<string> ys;
    ll buffn = n;
    while(buffn--)
    {
        string s; cin >> s;
        ys.eb(s);
    }

    ll x, y; cin >> x >> y;
    set<ll> ans; pll ps{x, y};
    bfs(xs, ys, ans, ps, 0, n, m);

    if(ans.empty())
        cout << -1;
    else
        cout << *ans.begin();
    cout << '\n';
}