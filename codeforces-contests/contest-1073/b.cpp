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

// 0 0 1 1 5 6
void solve()
{
    ll n, i = 0; cin >> n;
    ll zero = 0, one = 0;
    vll xs(n); for(auto& x : xs){cin >> x;(x==0?++zero:(x==1?++one:one));}
    if(zero==0) cout << "NO\n";
    else if(one > 0) cout << "YES\n";
    else if(zero==1) cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
