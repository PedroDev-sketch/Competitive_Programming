#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    vector<pair<int,int>> cd;
    bool ans = true;

    vector<vector<char>> field (h, vector<char> (w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> field[i][j];
            if(field[i][j] == '#')
            {
                cd.emplace_back(i, j);
            }
        }
    }

    sort(cd.begin(), cd.end());

    int a = 1e9, b = 0, c = 1e9, d = 0;
    for(int i = 0; i < cd.size(); i++)
    {
        a = min(a, cd[i].x);
        b = max(b, cd[i].x);

        c = min(c, cd[i].y);
        d = max(d, cd[i].y);
    }

    //vector<vector<char>> newf(b-a+1, vector<char>(d-c+1));
    vector<pair<int,int>> bad;

    for(int i = a; i <= b; i++)
    {
        for(int j = c; j <= d; j++)
        {
            //newf[i-a][j-c] = field[i][j];
            if(field[i][j] == '.')
            {
                ans = false;
            }
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}