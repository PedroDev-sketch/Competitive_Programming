#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n, k; cin >> n >> k;
    ll ans = n;

    if(k >= n-1) ans = 1;

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
}