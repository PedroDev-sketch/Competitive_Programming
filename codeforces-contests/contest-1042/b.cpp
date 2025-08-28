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

        vll ans(n);

        for(ll i = 0; i < n; i++)
        {
            if(i % 2 && i+2 >= n && n%2)
            {
                ans[i] = n;
            }
            else if(i % 2)
            {
                ans[i] = i + 1;
            }
            else
            {
                ans[i] = -1;
            }
        }

        for(auto i : ans) cout << i << " ";
        cout << '\n';
    }
}