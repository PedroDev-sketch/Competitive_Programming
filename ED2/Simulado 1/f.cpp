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

vll topsort(ll n, const vpll& ys)
{
    vvll xs(n+1);
    vll dgr(n+1, 0);

    for(auto [x, y] : ys)
    {
        xs[x].eb(y);
        dgr[y]++;
    }

    priority_queue<ll,vll,greater<ll>> pq;

    for(ll i = 1; i <= n; i++)
        if(dgr[i]==0)
            pq.ep(i);

    vll res;
    while(!pq.empty())
    {
        ll x = pq.top();
        pq.pop();

        res.eb(x);
        for(ll y : xs[x])
        {
            dgr[y]--;
            if(dgr[y]==0)
                pq.push(y);
        }
    }

    if(res.size() < n)
        return {};

    return res;
}

signed main()
{
    ll n;
    cin >> n;

    vpll ys, zs;
    
    ll l; cin >> l;
    while(l--)
    {
        ll x, y; cin >> x >> y;
        ys.eb(x, y);
    }

    ll c; cin >> c;
    while(c--)
    {
        ll x, y; cin >> x >> y;
        zs.eb(x, y);
    }

    vll row = topsort(n, ys);
    vll col = topsort(n, zs);

    if(col.empty() || row.empty())
    {
        cout << "IMPOSSIVEL\n";
        return 0;
    }

    vvll ans(n, vll(n, 0));
    vpll islands(n+1);

    for(ll i = 0; i < n; i++)
    {
        ll island = row[i];
        islands[island].ff = i;

        island = col[i];
        islands[island].ss = i;
    }

    for(ll i = 1; i <= n; i++)
    {
        ll x = islands[i].ff, y = islands[i].ss;
        ans[x][y] = i;
    }

    for(auto x : ans)
    {
        for(auto y : x)
            cout << y << " ";
        cout << '\n';
    }
}