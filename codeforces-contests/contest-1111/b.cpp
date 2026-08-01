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
    ll n, k, m; cin >> n >> k >> m;
    if(k > m)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vll xs;
    for(ll i = 0; i < k-1; ++i)
        xs.eb(1);
    xs.eb(m - k + 1);

    for(ll i = k; i < n; ++i)
        xs.eb(1);

    for(auto x : xs)
        cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
