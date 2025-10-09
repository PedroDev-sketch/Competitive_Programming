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
    ll a, b, c; cin >> a >> b >> c;
    set<ll> xs;
    xs.insert(a); xs.insert(b); xs.insert(c);
    cout << xs.size() << '\n';
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}