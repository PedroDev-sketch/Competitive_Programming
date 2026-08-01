#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

ll power(ll num)
{
    ll exp = 0;
    while(num && num%2==0)
    {
        num /= 2;
        ++exp;
    }

    return pow(2LL, exp);
}

void solve()
{
    ll n, q; cin >> n >> q;
    vll xs(n); for(auto& x : xs) cin >> x;

    vll prefix(n), suffix(n);
    prefix[0] = xs[0];
    rep(i, 1, n)
        prefix[i] = max(xs[i], prefix[i-1]);
    suffix[n-1] = xs[n-1];
    per(i, n-2, 0)
        suffix[i] = min(xs[i], suffix[i+1]);

    ll ans = 0;
    rep(i, 0, n-1)
        if(prefix[i] > suffix[i+1])
            ans = max(ans, power(i+1));

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
