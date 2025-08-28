#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define int ll

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

        vll xs(n, 0);

        for(ll i = 0; i < n-1; i++)
        {
            ll x, y;
            cin >> x >> y;
            xs[x-1]++;
            xs[y-1]++;
        }

        ll counter = 0;
        for(auto x : xs)
        {
            if(x > 1) counter++;
        }

        cout << (!counter ? 0 : counter - 1) << '\n';
    }

    return 0;
}