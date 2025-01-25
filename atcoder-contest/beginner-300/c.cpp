#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second

int flood_fill(vector<string>& field, vector<vector<bool>>& visited, int i, int j, int h, int w)
{
    //debug
    //cout << "inside floodfill\n";

    int size = 0;
    vector<pair<int,int>> moves = {{1,1},{1,-1},{-1,1},{-1,-1}};
    queue<pair<int,int>> list;

    list.push(make_pair(i, j));
    while(!list.empty())
    {
        size++;
        pair<int,int> c = list.front();
        visited[c.x][c.y] = true;
        list.pop();

        for(int k = 0; k < 4; k++)
        {
            int posx = c.x + moves[k].x, posy = c.y + moves[k].y;

            if((posy >= 0 && posy < w) && (posx >= 0 && posx < h) && field[posx][posy] == '#' && !visited[posx][posy])
            {
                list.push(make_pair(posx, posy));
            }
        }
    }

    //debug
    //cout << "outside floodfill queue\n";

    for(int k = 0; k < h; k++)
    {
        for(int g = 0; g < w; g++)
        {
            if(visited[k][g])
            {
                field[k][g] = '.';
                visited[k][g] = false;
            }
        }
    }

    //debug
    //cout << "outside floodfill backtracking\n";

    size--;
    size/=4;
    return size;
} 

auto solve(vector<string>& field, map<int,int>& hist, int h, int w)
{
    //debug
    //cout << "inside solve\n";

    vector<vector<bool>> visited(h, vector<bool> (w, false));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(field[i][j] == '#')
            {
                int size = flood_fill(field, visited, i, j, h, w);
                hist[size]++;
            }
        }
    }
    return;
}

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    int n = min(h,w);

    vector<string> field(h);
    map<int,int> hist;

    for(int i = 0; i < h; i++)
    {
        cin >> field[i];
    }

    //debug
    //cout << "outside input\n";

    solve(field, hist, h, w);
    for(int i = 1; i <= n; i++)
    {
        int ans = 0;
        if(hist.count(i))
        {
            ans = hist[i];
        }
        cout << ans << (i+1 > n ? "\n" : " ");
    }


    return 0;
}