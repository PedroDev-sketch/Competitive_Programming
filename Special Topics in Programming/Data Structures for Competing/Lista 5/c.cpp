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
    vll a(n), b(n), c(n);
    for(auto& h : a) {cin >> h; h--;}
    for(auto& h : b) {cin >> h; h--;}
    for(auto& h : c) {cin >> h; h--;}

    vll match(n,0);

    ll ans = 0;
    for(ll i = 0; i < n; i++)
        match[b[c[i]]]++;
    for(ll i = 0; i < n; i++)
        ans += match[a[i]];
    cout << ans << '\n';
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}