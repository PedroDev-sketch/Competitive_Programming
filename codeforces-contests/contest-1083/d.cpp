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
    ll n, idx = 0; cin >> n;
    map<ll,ll> hs; map<ll, pll> pos; priority_queue<ll> ys;
    vll xs(n); 
    for(auto& x : xs)
    {
        ++idx;
        cin >> x;
        ys.push(x);
        pos[x] = idx;
    }
    
    set<ll> maxs;
    while(!ys.empty())
    {
        ll num = ys.top(); ys.pop();
        maxs.emplace(pos[num]);

        auto it = maxs.find(pos[num]);
        if(it!=maxs.begin())
            hs[xs[*maxs.begin() - 1]].ss = num;
        else if(next(it) != maxs.end())
            hs[xs[*next(it) - 1]].ff = num;
    }

    for(auto h : hs)
    {
        cout << h.ff << ": {" << h.ss.ff << ", " << hs.ss.ss << "}\n";
    }
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
