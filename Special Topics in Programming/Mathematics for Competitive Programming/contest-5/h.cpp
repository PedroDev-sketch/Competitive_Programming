#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n; cin >> n;
    multiset<ll> ys;
    vll xs(n); for(auto& x : xs) {cin >> x; ys.insert(x);}

    ll ans=0, x=0, y=0, num=0;
    while(!ys.empty())
    {
        auto it = prev(ys.end());
        if(!x)
        {
            if(*it==num)
            {
                x=num;
                num = 0;
            }
            else if(*it==num-1)
            {
                x=num-1;
                num = 0;
            }
            else
            {
                num = *it;
            }
            ys.erase(it);
        }

        else if(!y)
        {
            if(*it==num)
            {
                y=num;
                num = 0;
            }
            else if(*it==num-1)
            {
                y=num-1;
                num = 0;
            }
            else
            {
                num = *it;
            }
            ys.erase(it);
        }
        ans += x*y;
        if(x*y)
            x = y = 0;
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
