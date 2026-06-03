#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, x;
    cin >> n >> x;

    vector<int> xs(n);
    for(auto& p : xs) cin >> p;

    int count = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(i%2==0 && xs[i] > x) {count += xs[i] - x; xs[i] = x;}
        if(xs[i] + xs[i+1] > x)
        {
            count += xs[i] + xs[i+1] - x;
            xs[i+1] -= xs[i] + xs[i+1] - x;
        }
    }

    cout << count << '\n';
}