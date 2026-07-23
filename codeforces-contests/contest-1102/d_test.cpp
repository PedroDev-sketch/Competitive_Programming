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

void fillup(ll l, ll r, vll& xs)
{
    ll m = (l+r)/2;
    if(xs[m]!=-1)
        return;
    xs[m] = xs[l]^xs[r];
    fillup(l, m, xs);
    fillup(m, r, xs);
}

void solve() 
{
    ll n; cin >> n;
    vll xs(n, -1);
    xs[0] = 101;
    xs.back() = 110;

    fillup(0, xs.size()-1, xs);
    for(auto x : xs) cout << x << ' ';
    cout << '\n';
}

signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}