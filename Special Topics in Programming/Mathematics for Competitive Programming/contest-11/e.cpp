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

    if(!(n&1))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    ll num = (n)*(2*n + 1);

    vll xs, ys; ll x = 0, y = 0;
    for(ll i = 2*n; i > 0; --i)
    {
        if(x <= y)
        {
            x += i;
            xs.eb(i);
        }
        else
        {
            y += i;
            ys.eb(i);
        }
    }

    reverse(all(xs));
    reverse(all(ys));
    for(auto x : ys) cout << x << ' ';
    for(auto x : xs) cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
