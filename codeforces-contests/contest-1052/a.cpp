#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define all(xs) xs.begin(), xs.end()
#define rep(i, a, b) {for(ll i = (a); i <= (b); i++)}
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define eb emplace_back

signed main()
{
    fio;

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        map<ll,ll> hs;
        vll xs(n); for(auto& x : xs){ cin >> x; hs[x]++;}
        
        vll sizes;
        for(auto h : hs)
            sizes.eb(h.second);
        
        sort(all(sizes));
        ll ans = 1;
        for(ll i = 0; i < (ll)sizes.size(); i++)
        {
            ans = max(ans, (ll) sizes[i] * ((ll)sizes.size() - i));
        }
        
        cout << ans << '\n';
    }

    return 0;
}