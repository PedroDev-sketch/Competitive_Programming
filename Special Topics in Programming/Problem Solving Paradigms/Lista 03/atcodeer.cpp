#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int lasta = 1, lastb = 1;
    int ans = 0;

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        int i = max((lasta+a-1)/a, (lastb+b-1)/b);

        lasta = a * i;
        lastb = b * i;

        ans = lasta + lastb;
    }

    cout << ans << '\n';

    return 0;
}