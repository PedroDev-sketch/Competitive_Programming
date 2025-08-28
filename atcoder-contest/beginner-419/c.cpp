#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<pair<ll,ll>> xs(n);

    ll maxx=0, minx=1e9+7;
    ll maxy=0, miny=1e9+7;
    for(auto& [x, y] : xs) 
    {
        cin >> x >> y;
        maxx = max(maxx, x);
        minx = min(minx, x);

        maxy = max(maxy, y);
        miny = min(miny, y);
    }

    ll x = maxx - minx;
    ll y = maxy - miny;

    cout << (max(x, y) + 1)/2 << '\n';

    return 0;
}