#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>

constexpr ll MAXN = 1e5+10;

signed main()
{
    ll n, x;
    cin >> n >> x;

    vll price(n), pages(n);
    for(auto& p : price) cin >> p;
    for(auto& p : pages) cin >> p;

    vll dp(x+1);

    for(ll i = 0; i < n; ++i)
        for(ll j = x; j >= price[i]; --j)
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);

    cout << dp[x] << '\n';
}