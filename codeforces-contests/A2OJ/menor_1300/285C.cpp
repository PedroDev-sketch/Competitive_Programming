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
    vll xs(n); for(auto& x : xs) cin >> x;

    sort(all(xs));

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += abs(xs[i] - (i+1));
    }

    /* for(auto& x : xs)
    {
        if(x < 1)
        {
            ans += -(x) + 1;
            x=1;
        }
    }

    for(int i = 1; i < n; i++)
    {
        ll diff = xs[i] - xs[i-1];

        if(!diff)
        {
            xs[i]++;
            ans++;
        }

        if(diff < 0)
        {
            xs[i] += -(diff)+1;
            ans += -(diff)+1;
        }

        else
        {
            
        }
    } */

    cout << ans << '\n';
    
    return 0;
}