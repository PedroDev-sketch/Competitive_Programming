#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define all(xs) xs.begin(), xs.end()
#define int long long

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vll xs(n);
        vll counter(n+1, 0);
        for(auto& x : xs) 
        {
            cin >> x;
            counter[x]++;
        }

        int mex_initial = 0;
        for(int i = 0; i < n+1; i++)
        {
            if(!counter[i]){mex_initial = i; break;}
        }

        vll ys(n+2, 0);

        for(int m = 0; m <= mex_initial; m++)
        {
            ll k_min, k_max;
            if(m != mex_initial)
            {
                k_min = counter[m];
                k_max = n-m;
            }
            else
            {
                k_min = 0;
                k_max = n-m;
            }

            if(k_min <= k_max)
            {
                ys[k_min]++;
                ys[k_max+1]--;
            }
        }

        ll curr = 0;
        for(int k = 0; k <= n; k++)
        {
            curr += ys[k];
            cout << curr << ' ';
        }
        cout << '\n';
    }

    return 0;
}