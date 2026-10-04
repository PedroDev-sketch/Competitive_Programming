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
    ll n; cin >> n;
    vll xs(n), ys; 
    for(auto& x : xs) 
    {
        cin >> x;
        if(ys.empty())
            ys.eb(x);
        else if(ys.back() < x)
            ys.eb(x);
        else
        {
            auto it = lower_bound(all(ys), x);
            if(it==ys.end())
                continue;
            ll idx = it - ys.begin();
            ys[idx] = x;
        }
    }
    cout << ys.size() << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
