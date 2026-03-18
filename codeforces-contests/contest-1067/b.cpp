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
    map<ll,ll> hs;
    for(ll i = 0; i < 2*n; i++)
    {
        ll x; cin >> x;
        hs[x]++;
    }

    ll a = 0, b = 0, c = 0;
    for(auto [k, v] : hs)
    {
        if(v&1)
            ++a;
        else if(v%4)
            ++c;
        else
            ++b;
    }
    ll ans = a + 2*b + 2*c;
    if(!a && b&1)
        ans -= 2;
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
