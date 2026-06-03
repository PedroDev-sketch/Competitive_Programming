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
    sort(all(xs));

    xs.insert(xs.begin(), 0);

    bool ans = true;
    for(int i = 1; i < n+1 && ans; i++)
    {
        if(xs[i] - xs[i-1] > 8) ans = false;
    }
    

    cout << (ans ? "S" : "N") << '\n';

    return 0;
}