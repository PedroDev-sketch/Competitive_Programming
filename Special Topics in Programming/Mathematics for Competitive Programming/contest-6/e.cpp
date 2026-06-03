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

ll sieve(ll num)
{
    for(ll i = 2; i*i <= num; ++i)
    {
        if(num%i==0)
            return i;
    }
    return num;
}

void solve()
{
    ll n, op=0; cin >> n;
    if(n&1)
    {
        ll num = sieve(n);
        ++op;
        n -= num;
    } 
    if(!(n&1)) op += n/2;
    cout << op << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
