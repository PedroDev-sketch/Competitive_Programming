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
    
    ll n;
    cin >> n;
    vll xs(n);
    for(auto& x : xs) cin >> x;

    auto tall = max_element(all(xs));
    ll idxt = tall - xs.begin();

    reverse(all(xs));
    auto nottall = min_element(xs.begin(), xs.end());
    ll idxn = nottall - xs.begin();

    ll total = (idxt + idxn);

    if((n - idxn - 1) < idxt) total--;

    cout << total << '\n';
    //cout << idxt << " " << idxn << '\n';

    return 0;
}