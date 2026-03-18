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

bool check(vll& xs, vll& ys, ll pos, ll n)
{
    bool ans = true;
    for(ll m = 0; m < n && ans; ++m)
        if(xs[m]>=ys[(m+pos)%n])
            ans = false;
    return ans;
}

void solve()
{
    ll n; cin >> n;
    vll as(n), bs(n), cs(n);
    
    for(auto& a : as) cin >> a;
    for(auto& b : bs) cin >> b;
    for(auto& c : cs) cin >> c;

    ll cntx = 0, cnty = 0;
    for(ll i = 0; i < n; i++)
    {
        if(check(as, bs, i, n))
            ++cntx;
        if(check(bs, cs, i, n))
            ++cnty;
    }
    cout << cntx*cnty*n << "\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
