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

    for(int i = n-1; i > 0; i--)
    {
        vll ys(i, 0);
        for(int j = 1; j < i+1; j++)
        {
            if(xs[j] == xs[j-1]) ys[j-1] = 1;
            else ys[j-1] = -1;
        }
        xs = ys;
    }

    cout << (xs[0] == 1 ? "preta" : "branca") << '\n';

    return 0;
}