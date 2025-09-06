#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    vector<int> xs(3);
    cin >> xs[0] >> xs[1] >> xs[2];

    sort(all(xs));
    cout << xs[1] << '\n';
    return 0;
}