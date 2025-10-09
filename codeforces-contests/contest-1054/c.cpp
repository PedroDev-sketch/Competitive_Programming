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
    ll n, k; cin >> n >> k;
    vll xs(n); map<ll, ll> hs;
    for(auto& x : xs)
    {
        cin >> x;
        hs[x]++;
    }
    ll ans = 0;
    for(ll i = 0; i < k; i++)
    {
        if(hs[i] == 0) ans++;
    }
    
    if(hs[k] > ans)
        ans += (hs[k]-ans);
    
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}