#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        int ans = 0;

        for(int i = 0; i < 32; i++)
        {
            int pk = pow(k, i);
            if(pk > r2/l1) break;

            int rr2 = r2/pk, ll2 = l2/pk;
            if(l2%pk)ll2++;

            if(min(r1, r2/pk) >= max(l1, l2/pk))
                ans += min(r1, rr2) - max(l1, ll2) + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}