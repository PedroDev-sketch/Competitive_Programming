#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair

signed main()
{
    fio;
    
    ll n, m, d; cin >> n >> m >> d;

    vvll xs(n, vll(m));
    vll ys;

    for(auto& x : xs)
        for(auto& y : x)
        {
            cin >> y;
            ys.eb(y);
        }
    
    sort(all(ys));
    ll median = ys[(n*m - 1)/2];
    ll ans = 0;
    for(auto y : ys)
    {
        ll diff = abs(median - y);
        if(diff%d)
        {
            cout << "-1\n";
            return 0;
        }
        ans += diff/d;
    }

    cout << ans << '\n';
    
    return 0;
}

/* 
Corner case:
    2 2 1000
    1000 0
    1000 1000

*/