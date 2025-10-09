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
    ll n; cin >> n;
    map<ll,ll> hs;
    vll xs(n); for(auto& x : xs) {cin >> x; hs[x]++;}
    ll ans = true;
    for(auto [k, v] : hs)if((n%2&&v>n/2+1)||(n%2==0&&v>n/2)){ ans=false;break;}
    cout << (ans?"YES":"NO") << '\n';
    return 0;
}