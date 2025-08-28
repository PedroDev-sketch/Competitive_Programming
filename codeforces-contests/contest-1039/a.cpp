#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()
#define int ll

const ll INF = 1e12+7;

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    ll t;
    cin >> t;

    while(t--)
    {
        ll coins = 0;
        ll n, c;
        cin >> n >> c;

        vll xs(n);
        for(auto& x : xs) cin >> x;

        sort(all(xs));
        while(true)
        {
            auto it = lower_bound(all(xs), c);
            ll eq = *it;
            ll idx = it - xs.begin();

            if(eq == c)
            {
                xs[idx] = INF;
            }
            else if(idx)
            {
                idx--;
                eq = xs[idx];
                xs[idx] = INF;                
            }
            else break;

            int index = 0;
            while(xs[index] != INF)
            {
                xs[index] *= 2;
                index++;
            }

            sort(all(xs));
        }

        int i;
        for(i = 0; i < n; i++)
        {
            if(xs[i] == INF) break;
        }

        cout << i << '\n';
    }
}