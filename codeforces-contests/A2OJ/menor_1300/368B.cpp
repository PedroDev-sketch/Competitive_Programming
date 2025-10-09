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
    
    ll n, m; cin >> n >> m;
    vll xs(n), ys(n);
    map<ll, ll> hs;
    for(auto& x : xs) {cin >> x; hs[x]++;}
    for(ll i = 0; i < n; i++)
    {
        ys[i] = hs.size();
        hs[xs[i]]--;
        if(hs[xs[i]] <= 0) hs.erase(xs[i]);
    }

    while(m--)
    {
        ll q;
        cin >> q;
        cout << ys[q-1] << '\n';
    }
    
    return 0;
}