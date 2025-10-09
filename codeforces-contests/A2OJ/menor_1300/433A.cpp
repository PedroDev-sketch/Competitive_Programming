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
    ll n; vll ys(2, 0);
    cin >> n;
    vll xs(n); for(auto& x : xs) {cin >> x; ys[(x/100 - 1)]++;}
    bool ans = false;
    if((ys[0] % 2 == 0 && ys[1] % 2 == 0)) ans = true;
    else if(ys[1]%2 && ys[0] >= 2 && (ys[0] - 2) % 2 == 0) ans = true;
    cout << (ans ? "YES" : "NO")<< '\n';
    return 0;
}