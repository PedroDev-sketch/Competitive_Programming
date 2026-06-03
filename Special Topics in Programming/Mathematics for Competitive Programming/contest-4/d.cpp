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

// x/k * x%k = n
// r = x%k
// x/k = n/r ou x*r = n*k
void solve()
{
    ll n, k; cin >> n >> k;
    ll num = n*k;
    for(ll i = k-1; i >= 1; --i)
    {
        if(num%i==0)
        {
            ll q = n/i;
            ll x = q*k + i;
            cout << x << '\n';
            return;
        }
    }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
