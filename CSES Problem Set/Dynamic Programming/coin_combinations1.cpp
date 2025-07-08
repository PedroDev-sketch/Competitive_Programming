#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
const int m = 1e9 + 7;

void solve(vll& coins, vll& count, ll x)
{
    count[0] = 1;
    for(ll i = 1; i <= x; i++)
    {
        for(auto c : coins) if(i-c >= 0) {count[i] += count[i-c]; count[i] %= m;}
    }
}

signed main()
{
    ll n, x;
    cin >> n >> x;

    vll coins(n), count(x+1, 0);
    for(auto& c : coins) cin >> c;

    solve(coins, count, x);

    cout << count[x] << '\n';
    return 0;
}