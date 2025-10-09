#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll ans = 0;
    for(ll i = 0; i <= n && i*a <= n; i++)
    {
        for(ll j = 0; j <= n && j * b <= n; j++)
        {
            ll buffn = n;
            buffn -= i*a + j*b;
            if(buffn >= 0 && buffn%c==0)
                ans = max(ans, i+j+(buffn/c));
        }
    }

    cout << ans << '\n';
    
    return 0;
}