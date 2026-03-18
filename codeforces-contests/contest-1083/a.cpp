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
    ll n, idx = 0, ch = 0; pll top{-1,-1}; cin >> n; vll xs(n); 
    for(auto& x : xs) {++idx; cin >> x; ll sv = top.ff; top.ff = max(top.ff, x); if(top.ff !=sv) top.ss = idx-1; if(idx==top.ff) ++ch;}
    if(ch){xs[top.ss] = xs[0]; xs[0] = top.ff;} for(auto x : xs) cout << x << " "; cout << '\n'; 
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
