#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n, k; cin >> n >> k;
    --k;
    ll ans = n/k+(n%k!=0);
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while(t--)
        solve();
}