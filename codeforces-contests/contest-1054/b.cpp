#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n; cin >> n;

    vll xs(n); for(auto& x : xs) cin >> x;
    sort(all(xs));
    ll diff = 0;
    for(ll i = 1; i < n; i+=2)
    {
        diff = max(diff, abs(xs[i]-xs[i-1]));
    }
    cout << diff << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}