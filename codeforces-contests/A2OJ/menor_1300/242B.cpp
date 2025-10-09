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

    vpll xs(n);
    ll h = -1, l = 1e9+7;
    for(auto& [x, y] : xs) {cin >> x >> y; l = min(l, x); h = max(h, y);}

    ll i = 0;
    bool flag = false;
    for(auto [x, y] : xs)
    {
        i++;
        //cout << x << " " << y << " <-\n";
        if(x <= l && y >= h) {flag = true; break;}
    }
    if(!flag) i = -1;

    cout << i << '\n';

    return 0;
}