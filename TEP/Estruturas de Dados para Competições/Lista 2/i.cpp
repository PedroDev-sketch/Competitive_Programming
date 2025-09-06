#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    ll n = 5;
    ll t = 0, p = 0;

    vll xs(n);
    map<ll, ll> hist;
    for(auto& x : xs){ cin >> x; hist[x]++;}
    sort(all(xs));

    auto it = *max_element(all(xs));
    t=hist[it];

    ll big = -1;
    for(auto x : xs)
    {
        if (x > big && x < it) big = x;
    }

    if(big == -1) big = 0;
    p = hist[big];

    cout << t << " " << p << '\n';

    return 0;
}