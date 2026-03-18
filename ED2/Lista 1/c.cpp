#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)

void solve(map<ll,ll>& hs, vll& ys)
{
    for(auto y : ys)
    {
        cout << hs[y] << ' ';

        ll idx = hs[y];
        for(auto& [k, v] : hs)
            if(v<idx)
                v++;

        hs[y] = 1;
    }  
    cout << '\n';
}

signed main()
{
    fio;
    ll n, q; cin >> n >> q;
    map<ll, ll> hs;
    for(ll i = 0; i < n; i++) 
    {
        ll x; cin >> x;
        if(!hs.count(x))
            hs[x] = i+1;
    }

    vll ys(q); for(auto& y : ys) cin >> y;
    solve(hs, ys);
}
