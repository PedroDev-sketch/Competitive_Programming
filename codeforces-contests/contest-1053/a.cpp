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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll n, m; cin >> n >> m;
    vll xs(m); for(auto& x : xs) cin >> x;

    ll ans = 0;
    for(ll i = 1; i < m; i++)
    {
        if(xs[i] <= xs[i-1])
            ans = 1;
    }

    if(!ans)
    {
        ans = n - xs[m-1] + 1;
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
