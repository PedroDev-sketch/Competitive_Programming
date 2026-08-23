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

ll fast_pow(ll base, ll exp)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp&1)
        {
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return res%MOD;
}

void solve()
{
    ll a, b; cin >> a >> b;
    cout << fast_pow(a, b) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
