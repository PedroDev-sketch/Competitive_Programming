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

const ll MOD = 998244353;

ll count_zero(ll num)
{
    return ((num+1)/4)+1;
}

ll count_one(ll num)
{
    return (num+3)/4;
}

void solve()
{
    ll n, x; cin >> n >> x;

    ll pre1 = count_zero(x-1)%MOD, pre2 = count_one(x-1)%MOD;
    ll ans1 = (pre1 * ((count_zero(n)-pre1)%MOD))%MOD, ans2 = (pre2 * ((count_one(n)-pre2)%MOD))%MOD;
    cout << (ans1+ans2)%MOD << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
