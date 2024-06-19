#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> cd;
   
    int x = 0, y = 0, t = 0, ans = 1e9;
    for(int i = 0; i < n; i++)
    {
        string dir;
        int val;

        cin >> dir >> val;
        for(int j = 0; j < val; j++)
        {
            t++;

            if(dir == "N") y++;
            else if(dir == "S") y--;
            else if(dir == "E") x++;
            else x--;

            if(cd.count({x, y}) == 1)
            {
                ans = min(ans, t - cd[{x, y}]);
            }

            cd[{x, y}] = t;
        }
    }

    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}