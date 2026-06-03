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
    vll xs(n), pos(n + 1);

    for(ll i = 0; i < n; i++)
    {
        cin >> xs[i];
        pos[xs[i]] = i;
    }

    ll l = n, r = -1;
    string ans = "";

    for(ll m = 1; m <= n; ++m)
    {
        l = min(l, pos[m]);
        r = max(r, pos[m]);

        if (r-l+1==m)
            ans += '1';
        else
            ans += '0';
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
