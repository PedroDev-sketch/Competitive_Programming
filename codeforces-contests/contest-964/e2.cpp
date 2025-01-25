#include <bits\stdc++.h>
using namespace std;
const int MAXN = 200002;

int main()
{
    int t, l, r, log[MAXN+1];
    cin >> t;

    log[0] = 0;
    log[1] = 0;
    log[2] = 0;
    for(int i = 3; i <= MAXN; i++)
    {
        log[i] = log[i/3] + 1;
    }

    int dp[MAXN+1];
    dp[0] = 0;
    for(int i = 1; i <= MAXN; i++)
    {
        dp[i] = (dp[i-1] + log[i] + 1);
    }

    while(t--)
    {
        cin >> l >> r;

        cout << log[l] + 1 + (dp[r] - dp[l-1]) << endl;
    }

    return 0;
}