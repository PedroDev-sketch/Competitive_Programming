#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    ll total = 0;

    ll n;
    cin >> n;
    vll xs(n);

    for(auto& x : xs) cin >> x;

    ll p;
    cin >> p;
    vll ys(p);
    for(auto& y : ys) 
    {
        cin >> y;

        if(y > 0 && y <= n && xs[y-1])
        {
            xs[y-1]--;
            total++;
        }        
    }

    cout << total << '\n';

    return 0;
}