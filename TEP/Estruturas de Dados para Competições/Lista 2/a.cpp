#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> xs(n);
    for(auto& x : xs) cin >> x;

    sort(all(xs));

    int c = xs[n - k];
    cout << c << '\n';

    return 0;
}