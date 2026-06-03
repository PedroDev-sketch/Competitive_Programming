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
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    vll diff, idxs;
    for(ll i = 1; i < n; ++i)
        if(xs[i] < xs[i-1])
        {
            diff.eb(xs[i-1]-xs[i]);
            idxs.eb(i);
        }
    ll num = 0;
    if(!diff.empty()) num = *max_element(all(diff));
    for(ll i = 1; i < n; ++i)
        if(xs[i] < xs[i-1])
            xs[i] += num;

    vll ys = xs; sort(all(ys));
    cout << (xs==ys ? "YES" : "NO") << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
