#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)

ll position(ll x, ll y, ll n, ll m)
{
    if((x==1 && y==1) || (x==n && y==m) || (x==1 && y==m) || (x==n && y==1))
        return 2;
    if(x==1 || y==1 || x==n || y==m)
        return 3;
    return 4;
}

void solve()
{
    ll n, m; cin >> n >> m;
    
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << min(position(x1, y1, n, m), position(x2, y2, n, m)) << '\n';
}

signed main()
{
    fio;
    ll t=1; cin >> t;
    while(t--) solve();
}
