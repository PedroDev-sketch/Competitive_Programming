#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;

void solve()
{
    ll n, idx = 0; cin >> n;
    vll xs(n), ys(n); 
    map<ll,ll> conv;
    for(auto& x : xs) {cin >> x; conv[x] = idx; ++idx;}
    for(auto& x : ys) {cin >> x; x = conv[x];}
    
    vll dp;
    for(auto x : ys)
    {
        if(dp.empty() || x > dp.back())
            dp.eb(x);
        else
        {
            auto it = upper_bound(all(dp), x);
            if(it==dp.end())
                continue;
            *it = x;
        }
    }
    cout << dp.size() << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
