#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string s;
    cin >> s;

    int l, r;
    bool looking = true;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] =='A' && looking)
        {
            l = i;
            looking = false;
        }

        if(s[i] == 'Z' && !looking)
        {
            r = i;
        }
    }

    cout << r - l + 1<< '\n';
}