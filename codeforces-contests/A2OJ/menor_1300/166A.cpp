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
    
    ll n, k;
    cin >> n >> k;

    map<pll,ll> hs;
    vpll xs(n); for(auto& [x, y] : xs) {cin >> x >> y; x*=-1; hs[{x,y}]++;}
    sort(all(xs));
    cout<<hs[xs[k-1]]<<'\n';
    return 0;
}