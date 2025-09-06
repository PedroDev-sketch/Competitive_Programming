#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    ll n;
    cin >> n;

    vll xs(n), ys(n);
    for(auto& x : xs) cin >> x;

    for(int i = 0; i < n; i++)
    {
        ys[xs[i]-1] = i+1; 
    }

    for(auto y : ys) cout << y << '\n';

    return 0;
}