#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

signed main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, INF);

    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        int num = i;
        while(num)
        {
            int digit = num % 10;

            dp[i] = min(dp[i], dp[i - digit]);

            num /= 10;
        }
        dp[i]++;
    }

    cout << dp[n] << '\n';
    return 0;
}