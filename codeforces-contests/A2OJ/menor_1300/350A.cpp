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
   
    ll n, m;
    cin >> n >> m;
    vll xs(n), ys(m);for(auto& x : xs) cin >> x; for(auto& y: ys) cin >> y;
    ll down = *min_element(all(xs)), up = *max_element(all(xs));
    ll ans = max(up, down*2);
    bool check = true;
    for(auto y : ys) if(y <= ans) check = false;
    cout << (check ? ans : -1) << '\n';

    return 0;
}