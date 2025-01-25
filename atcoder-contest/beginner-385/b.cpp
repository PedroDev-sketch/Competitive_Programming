#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;


signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int h, w, x, y, houses = 0;
    cin >> h >> w >> x >> y;
    x--;y--;
    vector<vector<char>> field(h, vector<char>(w));

    for(int i = 0; i < h; i++)
    {
        for(int j= 0 ; j < w; j++)
        {
            cin >> field[i][j];
        }
    }

    string moves;
    cin >> moves;

    for(auto p : moves)
    {
        if(field[x][y] == '@')
        {
            houses++;
            field[x][y] = '.';
        }

        if(p == 'U' && field[x-1][y] != '#') x--;
        else if(p == 'D' && field[x+1][y] != '#') x++;
        else if(p == 'R' && field[x][y+1] != '#') y++;
        else if(p == 'L' && field[x][y-1] != '#') y--;
    }

    if(field[x][y] == '@')
        {
            houses++;
            field[x][y] = '.';
        }

    cout << x+1 << " " << y+1 << " " << houses << '\n';

    return 0;
}