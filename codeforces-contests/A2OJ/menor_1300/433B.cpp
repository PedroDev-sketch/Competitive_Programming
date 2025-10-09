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

void solve(vll& xs, ll l, ll r)
{
    ll ans = 0;
    
    ans = xs[r-1];
    if(l-2 >= 0) ans -= xs[l-2]; 
    
    cout << ans << '\n';
}

signed main()
{
    fio;
    
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    vll ys = xs; sort(all(ys));

    for(ll i = 1; i < n; i++) {xs[i]+=xs[i-1]; ys[i]+=ys[i-1];}

    ll m; cin >> m;
    while(m--)
    {
        ll t, l, r; cin >> t >> l >> r;
        if(t==1) solve(xs, l, r);
        else solve(ys, l, r);
    }
    
    return 0;
}