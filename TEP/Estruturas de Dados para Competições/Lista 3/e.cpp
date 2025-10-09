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

signed main()
{
    fio;

    ll n;
    cin >> n;
    
    vll xs(n);
    for(auto& x : xs) cin >> x;

    vll ys = xs;
    sort(all(ys));

    ll ans = 0;
    for(auto y : ys)
    {
        ll temp = 0;
        for(int i = 0; i < n; i++)
        {
            if(xs[i] < y) temp = 0;
            if(xs[i] >= y) temp += y;
            ans = max(ans, temp);
        }
    }

    cout << ans << '\n';

    return 0;
}