#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()
#define int long long

signed main()
{
    int n, t;
    cin >> n >> t;

    vector<int> xs, ys;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;

        if (i < n / 2)
            xs.push_back(in);
        else
            ys.push_back(in);
    }

    set<int> sumx, sumy;
    for (int bit = 0; bit < (1 << xs.size()); bit++)
    {
        int sum = 0;
        for (int i = 0; i < xs.size(); i++)
        {
            if (bit & (1 << i))
            {
                sum += xs[i];
            }
        }
        sumx.insert(sum);
    }

    for (int bit = 0; bit < (1 << ys.size()); bit++)
    {
        int sum = 0;
        for (int i = 0; i < ys.size(); i++)
        {
            if (bit & (1 << i))
            {
                sum += ys[i];
            }
        }
        sumy.insert(sum);
    }

    int ans = 0;

    for (auto x : sumx) {  
        int obj = t - x;   
        if (obj >= 0) {    
            auto it = sumy.upper_bound(obj);
            if (it != sumy.begin()) {
                it--;
                if (x + *it <= t) {
                    ans = max(ans, x + *it);
                }
            }
        }
    }

    cout << ans << '\n';
}