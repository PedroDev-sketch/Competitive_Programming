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
    ll num; cin >> num;
    ll ans = 0, ngt = 0;
    while(num--)
    {
        ll nt; cin >> nt;
        if(nt<0)ngt++;
        else if(nt==0)ans++;
    }
    if(ngt%2) ans += 2;
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}