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
    ll n, ans = 0; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    sort(all(xs));
    for(ll i = 0, j = n - 1; i!=j && i < j && i < n && j >= 0; ++i, --j)
    {
        ll num = xs[i]+xs[j];
        ans += num*num;
    }
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
