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

vll sieve(ll num = 1e7)
{
    vll xs, ys(num, (ll)0);
    for(ll i = 2; i < num; i++)
    {
        if(!ys[i]) 
        {
            xs.eb(i);
            for(ll j = i; j < num; j+=i)
            {
                ys[j] = 1;
            }
        }
    }
    return xs;
}

signed main()
{
    fio;
    
    ll n;
    cin >> n;

    vll xs = sieve();
    for(ll i = 0; i < n; i++) cout << xs[i] << " ";
    cout << '\n';

    return 0;
}