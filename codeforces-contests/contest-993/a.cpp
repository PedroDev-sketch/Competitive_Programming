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
        int n;
        cin >> n;


        /* int b = 1;

        while(n>0)
        {
            if(n - b > 0)
            {
                ans++;
                n--;
            }
        } */

        cout << n-1 << '\n';
    }

    return 0;
}