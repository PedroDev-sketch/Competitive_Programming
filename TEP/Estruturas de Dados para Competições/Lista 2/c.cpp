#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    ll n;
    cin >> n;

    vll xs(n);
    for(auto& x : xs) cin >> x;

    ll diff = xs[0] + xs[n-1];
    bool ans = true;
    for(int i = 0; i < n && ans; i++)
    {
        if(xs[i] + xs[n-i-1] != diff) ans = false;
    }

    cout << (ans ? "S" : "N") << '\n';

    return 0;
}