#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n; cin >> n;
    vll xs(n+1); 
    for(ll i = 1; i <= n; ++i) 
        cin >> xs[i];

    ll tgt = sqrt(n), ans = 0;
    for(ll x = 1; x <= tgt; ++x)
    {
        for(ll j = 1; j <= n; ++j)
        {
            ll i = j - x*xs[j];

            if(i >= 1 && xs[i]==x)
                ++ans;
        }
    }
    for(ll y = 1; y <= tgt; ++y)
    {
        for(ll i = 1; i <= n; ++i)
        {
            if(xs[i] > tgt)
            {
                ll j = i + xs[i]*y;
                if(j <= n && xs[j] == y)
                    ++ans;
            }
        }
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
