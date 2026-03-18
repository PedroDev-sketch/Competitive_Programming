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
    ll n, l, r; cin >> n >> l >> r;
    vll xs(n+1, 0);

    for(ll i = 0; i <= n; i++)
        xs[i] = i;
    xs[r] = l-1;

    vll ans;
    for(ll i = 1; i <= n; i++)
        ans.eb((xs[i] xor xs[i-1]));
    

    for(auto x : ans)
        cout << x << " ";
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
