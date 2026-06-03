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

bool divs(ll num)
{
    vll ds;
    for(ll i = 1; i * i <= num; ++i)
    {
        if(num%i==0 && num/i == i)
        {
            return true;
        }
    }  
    return false;
}

void solve()
{
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    sort(all(xs), greater<>());
    for(auto x : xs)
    {
        ll rx = sqrt(x);
        if(rx*rx!=x) {cout << x << '\n'; return;}
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
