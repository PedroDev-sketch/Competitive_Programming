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
    ll n, f = 0, s = 0; cin >> n;
    vll xs(n); for(auto& x : xs) {cin >> x; f += x;}
    sort(all(xs)); ll sum = 0;
    for(ll i = 0; i < n; ++i)
    {
        s += (i*xs[i]) - sum;
        sum += xs[i];
    }
    s*=2;

    ll num = f + s;
    ll cmd = gcd(num, n);
    cout << num/cmd << ' ' << n/cmd << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
