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
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    vector<string> ys(n); for(auto& y : ys) cin >> y;
    
    map<ll,vll> graph;
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < n; ++j)
            if(ys[i][j]=='1')
                graph[i].eb(j);

    vector<set<ll>> changes;
    for(auto& [k, v] : graph)
    {
        if(v.empty())
            continue;

        set<ll> buff;
        queue<ll> zs;
        zs.push(k);
        while(!zs.empty())
        {
            ll num = zs.front(); zs.pop();
            buff.insert(num);

            if(!graph.count(num))
                continue;
                
            for(auto x : graph[num])
                zs.push(x);
            graph[num].clear();
        }

        if(!buff.empty())
            changes.eb(buff);
    }

    for(auto x : changes)
    {
        priority_queue<ll, vll, greater<>> lst;
        for(auto y : x)
        {
            lst.push(xs[y]);
            xs[y]=-1;
        }

        for(auto y : x)
        {
            if(xs[y]==-1)
            {
                xs[y] = lst.top();
                lst.pop();
            }
        }  
    }

    for(auto x : xs)
        cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
