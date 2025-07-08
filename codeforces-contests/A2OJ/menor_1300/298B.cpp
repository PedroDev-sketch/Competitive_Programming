#include <bits/stdc++.h>
using namespace std;

//Problem name: Sail

signed main()
{
    int t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;
    string s;
    cin >> s;

    int count = 0;

    for(int i = 0; i < t; i++)
    {
        count++;
        if(s[i] == 'S')
        {
            if(abs((sy - 1) - ey) < abs(sy - ey))
            {
                sy--;
            }
        }
        else if(s[i] == 'N')
        {
            if(abs((sy + 1) - ey) < abs(sy - ey))
            {
                sy++;
            }
        }
        else if(s[i] == 'E')
        {
            if(abs((sx + 1) - ex) < abs(sx - ex))
            {
                sx++;
            }
        }
        else
        {
            if(abs((sx - 1) - ex) < abs(sx - ex))
            {
                sx--;
            }
        }

        if(sx == ex && sy == ey) break;
    }

    if(sx==ex && sy==ey) cout << count << '\n';
    else cout << -1 << '\n';

    return 0;
}