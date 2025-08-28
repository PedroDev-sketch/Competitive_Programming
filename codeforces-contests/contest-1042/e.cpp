#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define int ll

#define all(xs) xs.begin(), xs.end()

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
        
        bool ans = true;
        for(int i = 0; i < n; i++)
        {
            if((a[i] != b[i] && i < n - 1 && (a[i] xor a[i+1]) != b[i]) || (a[i] != b[i] && i == n - 1)) 
            {
                ans = false;
            }
        }

        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}