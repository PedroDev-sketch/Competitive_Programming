#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string s;
    cin >> s;

    int l = 0, r = s.size()-1, ans = 0;
    char ltype, rtype;

    ltype = s[0];

    bool exchange = false;

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == ltype);
        else
        {
            ans++;
        }

        ltype = s[i];
    }

    cout << ans << '\n';
    return 0;
}