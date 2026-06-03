#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

void solve()
{
    ll n; cin >> n;
    vll a(n + 1);
    
    ll x, y, z;
    cout << "? 1 2" << endl; cin >> x;
    cout << "? 2 3" << endl; cin >> y;
    cout << "? 1 3" << endl; cin >> z;
    ll tri = (x + y + z) / 2;
    a[1] = tri - y;
    a[2] = tri - z;
    a[3] = tri - x;
    
    for(ll i = 4; i <= n; ++i)
    {
        cout << "? 1 " << i << endl;
        ll sum; cin >> sum;
        a[i] = sum - a[1];
    }
    
    cout << "! ";
    for(ll i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

signed main()
{
    //fio;
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
}