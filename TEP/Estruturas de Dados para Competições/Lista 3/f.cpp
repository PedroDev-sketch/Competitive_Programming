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
    
    vll xs(n);
    stack<pll> ys;
    ll total = 0;
    for(auto& x : xs)
    {
        cin >> x;
        total++;
        
        if(!ys.empty() && x == ys.top().first)
        {
            if(x == ys.top().first) ys.top().second++;
            if(ys.top().second == ys.top().first)
            {
                total -= ys.top().second;
                ys.pop();
            }
        }

        else
        {
            pll zs{x, 1};
            ys.push(zs);
        }

        cout << total << '\n';
    }
    
    return 0;
}