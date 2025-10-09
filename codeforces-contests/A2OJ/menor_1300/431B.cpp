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
    vvll xs(5, vll(5));

    for(auto& x : xs)
        for(auto& y : x) 
            cin >> y;
    
    ll ans = 0;
    vll ys{0, 1, 2, 3, 4};
    do
    {
        ll buffer = (xs[ys[0]][ys[1]] + xs[ys[1]][ys[0]]) + (xs[ys[1]][ys[2]] + xs[ys[2]][ys[1]]) + 2*(xs[ys[2]][ys[3]] + xs[ys[3]][ys[2]]) + 2*(xs[ys[3]][ys[4]] + xs[ys[4]][ys[3]]);
        ans = max(ans, buffer);
    }while(next_permutation(all(ys)));

    cout << ans << '\n';

    return 0;
}