#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    map<int, int> mp;

    int a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        mp[a]++;
    }
    string ans;

    if(mp[0] == 0) cout << -1 << '\n';
    else if(mp[5] < 9) cout << 0 << '\n';
    else
    {
        int rem = mp[5] % 9;
        int numfive = mp[5] - rem;
        while(numfive--) ans.push_back('5');
        int numzero = mp[0];
        while(numzero--) ans.push_back('0');
        cout << ans << '\n';
    }
}