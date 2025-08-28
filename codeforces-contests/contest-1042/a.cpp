#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
#define int ll

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        vll a(n), b(n);

        for(auto& x : a) cin >> x;
        for(auto& x : b) cin >> x;

        ll counter = 1;
        for(ll i = 0; i < n; i++)
        {
            ll diff = a[i] - b[i];

            if(diff > 0) counter += diff;
        }

        cout << counter << '\n';
    }
}