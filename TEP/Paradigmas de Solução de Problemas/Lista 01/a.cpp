#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main()
{
    //cin.tie(0)->ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> players, cd;

    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        players.emplace_back(x, y);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        cd.emplace_back(x, y);
    }

    for(int i = 0; i < n; i++)
    {
        int smallest = 1e9+7;
        int ans = 0;
        for(int j = 0; j < m; j++)
        {
            int dist = abs(players[i].first - cd[j].first) + abs(players[i].second - cd[j].second);
            if(smallest > dist)
            {
                smallest = dist;
                ans = j;
            }
        }

        cout << ans+1 << '\n';       
    }

    return 0;
}