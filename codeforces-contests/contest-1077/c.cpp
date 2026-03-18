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
    map<ll, set<ll>> hs;
    vll xs(n); 
    for(auto& x : xs) 
    {
        cin >> x;
        hs[x].insert(idx);
        ++idx;
    }
    vll ys = xs; sort(all(ys));

    if(xs==ys)
    {
        cout << "-1\n";
        return;
    }

    ll ans = -1; 
    for(ll i = 0; i < n; ++i)
    {
        if(xs[i] == ys[i])
        {
            hs[xs[i]].erase(i);
            continue;
        }

        ll idx = *hs[xs[i]].begin();
        ans = max(abs(xs[i] - xs[idx]), ans);
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
