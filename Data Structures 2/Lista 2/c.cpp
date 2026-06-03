#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n; cin >> n;
    
    if(n&1)
        cout << 9 << '\n';
    else if(n==2)
        cout << 4 << '\n';
    else
        cout << n-2 << '\n';
}

signed main()
{
    fio;
    ll t=1; //cin >> t;
    while(t--) solve();
}
