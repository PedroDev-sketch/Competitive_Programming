#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        vll xs(n);
        for(auto& x : xs) cin >> x;

        ll e = 0;
        sort(all(xs));

        for(int i = n-1; i >= 0; i-=2)
        {
            e+=xs[i];
        }
        
        cout << e << '\n';
    }

    return 0;
}