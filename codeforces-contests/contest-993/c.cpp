#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        int ans = 0, max = 2*m;

        if(m >= a) ans += a;
        else ans += m;

        if(m>= b) ans += b;
        else ans += m;

        if(ans < max)
        {
            if(ans + c >= max)
            {
                ans = max;
            }
            else
            {
                ans += c;
            }
        }

        cout << ans << '\n';
    }
    

    return 0;
}