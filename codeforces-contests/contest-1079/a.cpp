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

ll d(ll num)
{
    string s = to_string(num);
    ll add = 0;
    for(auto x : s)
        add += (x-'0');
    return add;
}

void solve()
{
    ll x; cin >> x;
    ll gap = 81, ans = 0;

    for(ll i = 0; i <= gap; ++i)
    {
        ll y = x+i;
        if(y - d(y) == x)
            ++ans;
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
