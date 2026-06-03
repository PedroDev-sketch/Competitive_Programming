#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

void solve(map<ll, vll>& hs, ll& ans, ll src, ll depth)
{
    ans = max(ans, depth);
    if(hs.count(src))
    {
        for(auto s : hs[src])
            solve(hs, ans, s, depth+1);
    }
}

signed main()
{
    fio;

    ll n; cin >> n;
    map<ll, vll> hs;
    for(ll i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        hs[x].eb(i);
    }

    ll ans = 0;
    for(auto h : hs[-1])
    {
        solve(hs, ans, h, 1);
    }

    cout << ans << '\n';
}
