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
    vll pos(n+1, 0); vpll hs(n+1, {0,0}); priority_queue<ll> ys;
    vll xs(n); 
    for(auto& x : xs)
    {
        ++idx;
        cin >> x;
        ys.push(x);
        pos[x] = idx;
    }

    ll start = ys.top();
    
    set<ll> maxs;
    while(!ys.empty())
    {
        ll num = ys.top(); ys.pop();
        maxs.emplace(pos[num]);

        auto it = maxs.find(pos[num]);
        if(it!=maxs.begin() && !hs[xs[*prev(it) - 1]].ss)
            hs[xs[*prev(it) - 1]].ss = num;
        else if(next(it) != maxs.end() && !hs[xs[*next(it) - 1]].ff)
            hs[xs[*next(it) - 1]].ff = num;
    }

    ll cnt = 0;
    auto ds = [&](auto& self, ll depth, ll num) -> void
    {
        cnt = max(cnt, depth);

        if(hs[num].ff)
            self(self, depth+1, hs[num].ff);
        if(hs[num].ss)
            self(self, depth+1, hs[num].ss);
    };

    ds(ds, 1, start);
    cout << n - cnt << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
