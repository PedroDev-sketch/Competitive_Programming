#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string s;
    cin >> s;

    int x = 0;
    for(auto e : s)
    {
        if(e == '7' || e == '4') x++;
    }

    cout << ((x == 4 || x == 7) ? "YES" : "NO") << '\n';
}