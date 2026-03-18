#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = n*(n-1); ans /= 2;
    ans -= m;
    while(m--)
    {
        ll x, y; cin >> x >> y;
    }
    cout << ans << '\n';
}