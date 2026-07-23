#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n; cin >> n;
    ll num5 = n/5, num3 = n/3, num15 = n/15;
    cout << n - num5 - num3 + num15 << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while(t--)
        solve();
}