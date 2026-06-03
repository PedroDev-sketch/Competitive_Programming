#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int k, s;
    cin >> k >> s;

    int ans = 0;

    for(int x = 0; x <= k; x++)
    {
        for(int y = 0; y <= k; y++)
        {
            if((x+y == s || s-x-y <= k) && x+y <= s)
            {
                ans++;
            }
        }
    }



    cout << ans << '\n';

    return 0;
}