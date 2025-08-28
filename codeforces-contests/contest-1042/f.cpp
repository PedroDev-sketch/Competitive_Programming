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

        string a, b;
        cin >> a >> b;

        vvll xs(n, vector<ll> (n));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                xs[i][j] = (a[i] - '0') xor (b[j] - '0');
            }
        }

        
    }

    return 0;
}