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
    vpll xs(n);
    ll l=0, r=0;
    ll chg = 0;
    for(auto& [x, y] : xs)
    {
        cin >> x >> y;
        if(x%2)l++;
        if(y%2)r++;

        if((x%2 && y%2==0) || (x%2==0 && y%2)) chg++;
    }

    l = l%2;
    r = r%2;

    if((l+r)%2 || ((l || r) && !chg))
    {
        cout << "-1\n";
        return 0;
    }

    cout << max(l, r) << '\n';

    return 0;
}