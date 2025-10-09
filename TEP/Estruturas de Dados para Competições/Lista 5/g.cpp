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
    vll xs(n); map<ll,ll> hs;
    ll ans = 0;
    for(auto& x : xs)
    {
        cin >> x;
        ans += x;
        hs[x]++;
    }

    ll q; cin >> q;
    while(q--)
    {
        ll b, c;
        cin >> b >> c;
        ans -= b * hs[b];
        ans += c * hs[b];
        hs[c] += hs[b];
        hs.erase(b);
        cout << ans << '\n';
    }
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}