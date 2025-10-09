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
    ll n, k, l, r; cin >> n >> k >> l >> r;
    vll xs(n); for(auto& x : xs) cin >> x;

    ll e = 0, d= 0, ans = 0;
    map<ll,ll> hs;
    while(d < n)
    {
        hs[d]++;
        while(hs.size()>k)
        {
            hs[xs[l]]--;
            if(hs[xs[l]] <= 0) hs.erase(xs[l]);
            e++;
        }

        while(d-e+1 > r)
        {
            hs[xs[l]]--;
            if(hs[xs[l]] <=0 ) hs.erase(xs[l]);
            l++;
        }

        ans += (d-e+1);
        d++;
    }
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}