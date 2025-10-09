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
#define MAXN (1e9 + 7)

signed main()
{
    fio;
    
    ll n; cin >> n;
    vpll xs(n); 
    vll ys(n+1, -1);
    
    ll idx = 0;
    for(auto& [x, y] : xs)
    {
        cin >> x >> y;
        ys[idx] = x;
        idx++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        ll key = xs[i].second;
        for(ll j = 0; j <= n; j++)
            if(j!=i && key==ys[j])
                ys[j] = 0;
    }
    for(auto y : ys)
        if(y>0) 
            ans++;
    cout << ans << '\n';


    return 0;
}
