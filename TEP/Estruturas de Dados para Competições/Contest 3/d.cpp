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

ll find3s(ll num)
{
    ll n = 0, ret=1;
    while(num%ret == 0 && ret<num)
    {
        ret = pow(3LL, n);
        n++;
    }
    return n-1;
}

ll find2s(ll num)
{
    ll n = 0, ret=1;
    while(num%ret == 0 && ret < num)
    {
        ret = (1LL<<n);
        n++;
    }
    return n-1;
}

void solve()
{
    ll n; cin >> n;
    vll xs(n);

    bool flag = true;
    ll ans = 0, target = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> xs[i];
        if(!i) target = xs[i];
        target = gcd(target, xs[i]);
    }

    for(auto x : xs)
    {
        ll rdct = x/target;
        if(rdct%2 && rdct%3 && rdct!=target)
        {
            flag = false;
            break;
        }

        if(rdct%2==0)
            ans += find2s(rdct);
        if(rdct%3==0)
            ans += find3s(rdct);
    }

    cout << (flag ? ans : -1) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
