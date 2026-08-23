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

vll spf(ll num)
{
    vll xs;
    for(ll i = 2; i*i <= num; ++i)
        while(num%i==0)
        {
            xs.eb(i);
            num /= i;
        }
    if(num > 1) xs.eb(num);
    return xs;
}

void solve()
{
    ll n; cin >> n;
    vll xs = spf(n);

    map<ll,ll> hs;
    for(auto x : xs)
        ++hs[x];

    ll cnt = 0;
    for(auto& [x, y] : hs)
        cnt += (-1 + sqrt(8*y+1))/2; 
    cout << cnt << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
