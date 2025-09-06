#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    
    ll n, total = 0;
    cin >> n;
    vll xs(n);
    for(auto& x : xs) {cin >> x; total += x;}

    double ans = (double)total/n;

    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}