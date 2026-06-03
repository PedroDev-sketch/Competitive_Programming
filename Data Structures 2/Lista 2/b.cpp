#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n; cin >> n;
    string en, fr; cin >> en >> fr;

    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        if(fr[i]!='1')
            continue;

        if(en[i]=='0')
            ans++;
        else if(i > 0 && en[i-1]=='1')
        {
            ans++;
            en[i-1]='2';
        }
        else if(i < n-1 && en[i+1]=='1')
        {
            ans++;
            en[i+1]='2';
        }
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
}