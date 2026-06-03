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

vll divs(ll num)
{
    vll ds;
    for(ll i = 2; i * i <= num; ++i)
    {
        if(num%i==0)
        {
            ds.eb(i);
            if(num/i!=i)
                ds.eb(num/i);
        }
    }
    return ds;
}

void solve()
{
    ll l, r; cin >> l >> r;
    if(l==r)
        cout << l;
    else cout << 2;
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
