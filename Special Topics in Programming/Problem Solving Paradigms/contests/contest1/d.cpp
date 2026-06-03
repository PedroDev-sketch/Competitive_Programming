#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    vector<int> bad(n);
    for(auto& p : bad)
    {
        cin >> p;
    }

    for(int i = 0; i < q; i++)
    {
        int num;
        cin >> num;

        int l = 1, r = 1e18+7;
        while(r-l > 1)
        {
            int mid = (l+r)/2;

            auto it = lower_bound(all(bad), mid);
            int pos = it - bad.begin();
            if(mid - pos > num)
            {
                r = mid;
            }
            else l = mid;
        }
        cout << l << '\n';
    }
}