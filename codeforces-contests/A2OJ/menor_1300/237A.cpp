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
    
    ll n; cin >> n;
    vpll xs(n); 
    map<pll,ll> hs;
    for(auto& [x, y] : xs)
    {
        cin >> x >> y;
        hs[{x, y}]++;
    }
    ll ans = 0;
    for(auto h : hs)
    {
        ans = max(ans, h.second);
    }

    cout << ans << '\n';
    return 0;
}