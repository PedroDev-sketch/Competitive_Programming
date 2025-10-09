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

    vll xs(n);
    for(auto& x : xs) cin >> x;

    ll num = xs[k-1];

    ll ans = 0;
    for(int i = n-1; i>=0 && !ans; i--)
        if(xs[i] != num) ans = i+1;

    cout << (ans<k ? ans : -1) << '\n';

    return 0;
}