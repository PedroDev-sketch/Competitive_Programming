#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    ll n;
    cin >> n;

    vll xs(n);
    for(auto& x : xs) cin >> x;

    for(int i = 0; i < n; i++)
    {
        if(xs[i] == -1)
        {
            ll posfor = 1e9+7, posback = 1e9+7;
            for(int j = i; j < n; j++)
            {
                if(xs[j] == 0) {posfor = j - i; break;}
            }

            for(int j = i; j >= 0; j--)
            {
                if(xs[j] == 0) {posback = i - j; break;}
            }

            xs[i] = min(posfor, posback);
            if(xs[i] > 9) xs[i] = 9;
        }
    }

    for(auto x : xs) cout << x << " ";
    cout << '\n';

    return 0;
}