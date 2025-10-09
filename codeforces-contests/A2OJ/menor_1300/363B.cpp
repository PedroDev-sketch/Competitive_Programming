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

signed main()
{
    fio;
   
    ll n, k;
    cin >> n >> k;

    vll xs(n); for(auto& x : xs) cin >> x;
    vpll ys;

    ll total = 0, idx = 0;
    for(int i = 0; i <= k - 1; i++)
    {
        total += xs[i];
    }

    ys.eb(total, idx);

    for(int i = k; i < n; i++)
    {
        total -= xs[idx];
        total += xs[i];
        idx++;
        ys.eb(total, idx);
    }

    sort(all(ys));
    //for(auto [x, y] : ys) cout << x << " " << y << '\n';
    cout << ys[0].second+1 << '\n';

    return 0;
}