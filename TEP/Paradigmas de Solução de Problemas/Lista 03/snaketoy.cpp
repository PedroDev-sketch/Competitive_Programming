#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> xs(n);
    for(auto& x : xs) cin >> x;

    sort(all(xs), greater<>());

    int total = 0;
    for(int i = 0; i < k; i++) total += xs[i];

    cout << total << '\n';
}