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

const ll MOD = 1e9+7;

ll fast_pow(ll base, ll exp, ll mod)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp&1)
        {
            res *= base;
            res %= mod;
        }

        base *= base;
        base %= mod;
        exp >>= 1;
    }
    return res%mod;
}

void solve()
{
    ll n, x=1, y=1, z=1, f=0; cin >> n;
    vpll xs;

    ll D_mod = 1;
    while(n--)
    {
        ll a, b; cin >> a >> b;
        xs.eb(a, b);

        f += b;

        x*=(b+1);
        x%=MOD;

        D_mod*=(b+1);
        D_mod%= 2*(MOD-1);
    }

    for(auto [a, b] : xs)
    {
        y *= ((fast_pow(a, b+1, MOD) - 1) * fast_pow(a-1, MOD-2, MOD))%MOD;
        y %= MOD;

        ll exp = ((b*D_mod)/2);
        z *= fast_pow(a, exp, MOD);
        z %= MOD;
    }

    cout << x%MOD << " " << y%MOD << " " << z%MOD << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
