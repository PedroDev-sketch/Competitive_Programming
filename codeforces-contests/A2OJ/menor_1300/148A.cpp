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
    
    ll k, l, m, n;
    ll d;
    cin >> k >> l >> m >> n >> d;

    ll ans = 0;
    rep(i, 1, d+1)
    {
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) ans++;
    }

    cout << ans << '\n';

    return 0;
}