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
    ll a, b; cin >> a >> b;
    ll cnt = 0, ans = 0;

    bool flag = true;
    ll sa = a, sb = b;
    for(ll i = 1; i <= 1e8; i*=2)
    {
        if(flag && i <= a)
            a-=i;
        else if(!flag && i <= b)
            b-=i;
        else
            break;

        ++cnt;
        flag = !flag;
    }

    ans = cnt;
    cnt = 0;
    flag = false;
    a = sa, b = sb;

    for(ll i = 1; i <= 1e8; i*=2)
    {
        if(flag && i <= a)
            a-=i;
        else if(!flag && i <= b)
            b-=i;
        else
            break;

        ++cnt;
        flag = !flag;
    }

    ans = max(ans, cnt);
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
