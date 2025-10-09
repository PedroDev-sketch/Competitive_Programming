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
   
    ll n, total = 0, ans = 1;
    cin >> n;
    vll xs(n); for(auto& x : xs) {cin >> x; total += x;}
    ll ml = total - (n-1);
    cout << (total%n == 0 ? n : n-1) << '\n';
    
    return 0;
}