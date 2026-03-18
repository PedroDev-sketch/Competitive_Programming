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

vll d(ll n)
{
    vll d;
    for(ll i = 1; i*i <= n; ++i)
    {
        if(n%i == 0)
        {
            d.eb(i);
            if(n/i != i) d.eb(n/i);
        }
    }
    sort(all(d));
    return d;
}

void solve()
{
    ll n; cin >> n;
    vll ans = d(n);
    vll check;

    for(ll i = 0; i < ans.size(); ++i)
    {
        bool flag = true;
        for(ll j = 0; j < i && flag; ++j)
            if(ans[j]!=1 && ans[j]!= -1 && ans[i] % ans[j] == 0)
                flag = false;
        if(flag) check.eb(ans[i]);
    }

    ll flag = false;
    for(ll i = 0; i < ans.size() && !flag; ++i)
    {
        flag = true;
        for(ll j = 0; j < check.size() && flag; ++j)
            if(ans[i]%check[j]!=0)
                flag = false;
        if(flag)
            cout << ans[i] << '\n';
    }
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
