#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)

ll mod(ll x, ll y = MAXN)
{
    ll res = x%y;
    return (res < 0 ? res+y : res);
}

signed main()
{
    fio;
    
    ll x, y, n; cin >> x >> y >> n;

    ll ans = 0;
    if(n%6 == 0)
        ans = x - y;
    else if(n%6 == 1)
        ans = x;
    else if(n%6 == 2)
        ans = y;
    else if(n%6 == 3)
        ans = y-x;
    else if(n%6 == 4)
        ans = -x;
    else if(n%6 == 5)
        ans = -y;
    else
        ans = x-y;
    
    cout << mod(ans) << '\n';
    
    return 0;
}
