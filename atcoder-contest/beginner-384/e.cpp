#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

int solve(vector<vector<int>>& field, int p, int q, int div)
{
    int power = field[p][q];
    int h = field.size();
    int w = field[0].size();

    queue<pair<int,int>> next;
    vector<pair<int,int>> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> visited(h, vector<bool> (w, false));
    
    next.push(make_pair(p, q));

    while(!next.empty())
    {
        int x = next.front().first, y = next.front().second;
        visited[x][y] = true;
        next.pop();

        for(int i = 0; i < 4; i++)
        {
            int newx = x + moves[i].first, newy = y + moves[i].second;
            if(newx >= 0 && newx < h && newy >= 0 && newy < w && !visited[newx][newy])
            {
                //debug
                cout << '\n';
                cout << "got in 1\n";
                cout << (power+1)/div << '\n';
                cout << power/div << '\n';
                cout << field[newx][newy] << '\n';

                if(field[newx][newy] < (power%2 ? (power+1)/div : power/div))
                {
                    //debug
                    cout << "got in 2\n";

                    power += field[newx][newy];
                    next.push(make_pair(newx, newy));
                }
            }
        }
    }


    return power;
}

signed main()
{
    int h, w, x;
    cin >> h >> w >> x;
    vector<vector<int>> field(h, vector<int> (w));

    int p, q;
    cin >> p >> q;
    p--; q--;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> field[i][j];
        }
    }

    int power = solve(field, p, q, x);
    cout << power << '\n';


    return 0;
}