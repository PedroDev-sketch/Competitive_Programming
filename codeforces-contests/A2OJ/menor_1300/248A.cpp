#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    
    ll n;
    cin >> n;

    ll l = 0, r = 0;
    for(int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        l+=x;
        r+=y;
    }

    cout << min(l, n-l) + min(r, n-r) << '\n';

    return 0;
}