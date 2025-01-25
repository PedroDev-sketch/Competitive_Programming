#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

vector<string> move(vector<string>& av, int r, int s, int h, int w)
{
    vector<string> moved = av;
    for(int i = 0; i < r; i++)
    {
        auto it = moved.begin();
        string save = moved[0];
        moved.erase(it);
        moved.push_back(save);
    }

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < h; j++)
        {
            auto it = moved[j].begin();
            char save = *it;
            moved[j].erase(it);
            moved[j].push_back(save);
        }
    }
    return moved;
}

auto solve(vector<string>& av, vector<string>& bv, int h, int w)
{
    for(int i = 0; i <= h; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(move(av, i, j, h, w) == bv) return true;
        }
    }
    return false;
}

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    vector<string> av(h), bv(h);

    for(int i = 0; i < h; i++)
    {
        cin >> av[i];
    }

    for(int i = 0; i < h; i++)
    {
        cin >> bv[i];
    }

    if(solve(av, bv, h, w)) cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}