#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define pb push_back
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
    vll ys = xs; sort(all(ys));
    map<ll,ll> hs;

    ll idx = 0;
    for(auto y : ys)
    {
        hs[y] = idx;
        ++idx;
    }

    vvll ans;
    for(ll i = 0; i < n; ++i)
    {
        if(!hs.count(xs[i]))
            continue;

        vll buff;
        idx = i;

        while(hs.count(xs[idx]))
        {
            buff.eb(idx+1);
            ll nxt = hs[xs[idx]];

            hs.erase(xs[idx]);
            idx = nxt;
        }
        ans.eb(buff);
        
    }

    vll buff;
    for(auto [k, v] : hs)
        buff.eb(v+1);
    if(!buff.empty()) ans.eb(buff);

    cout << ans.size() << '\n';
    for(auto a : ans)
    {
        cout << a.size() << ' ';
        for(auto x : a)
            cout << x << ' ';
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
