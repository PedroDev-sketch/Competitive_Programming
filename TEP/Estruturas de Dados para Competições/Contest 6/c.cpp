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
    ll n, m; cin >> n >> m;

    map<ll, ll> hs;
    ll num = 1;

    for(ll i = 0; i < n; i++)
        hs[i] = -1;

    vvll xs(n);
    for(ll i = 0; i < m; i++)
    {
        ll x, y; cin >> x >> y;
        xs[x-1].eb(y-1);
        xs[y-1].eb(x-1);
    }

    //ll idx = 0;
    vector<bool> vis(n, false);
    for(auto x : xs)
    {
        //if(hs.count(idx)) continue;
        stack<ll> zs;
        for(auto y : x) zs.push(y);
        while(!zs.empty())
        {
            ll src = zs.top();
            
            if(hs[src]==-1)
                hs[src] = num;

            vis[src] = true;
            zs.pop();

            for(auto y : xs[src]) 
                if(!vis[y])
                    zs.push(y);
        }
        num++; //idx++;
    }

    ll addon = 0;
    set<ll> ans; 
    for(auto [k, v] : hs) 
    {
        if(v!=-1) ans.insert(v);
        if(v==-1) addon++;
    }
    cout << ans.size() + addon << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
