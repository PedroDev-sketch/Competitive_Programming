#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define eb emplace_back
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n; cin >> n;
    vll xs(n);
    for(auto& x : xs) cin >> x;
    ll ans = 0;

    vll ys(n, 0);
    for(ll i = n-1; i >= 0; i--)
    {
        ys[i] += xs[i];
        if(i + xs[i] < n)
            ys[i] += ys[i + xs[i]];
        ans = max(ans, ys[i]);
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t=1; cin >> t;
    while(t--) solve();
}
