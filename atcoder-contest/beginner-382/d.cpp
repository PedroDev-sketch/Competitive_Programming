#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> keep;
    for(int i = 1; i <= n; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        for(int j = i+10; j <= m; j+= 10)
        {
            temp.push_back(j);
        }

        keep.push_back(temp);
    }

    set<vector<int>> addtokeep;

    for(int i = 0; i < keep.size(); i++)
    {
        vector<int> buff = keep[i];

        int save = buff[keep[0].size()-1]+1;
        while(save <= m)
        {
            buff = keep[i];

            for(int j = keep[0].size()-1; j > 0; j--)
            {
                while(buff[j] < save - (10 * (keep[0].size() - 1 - j)))
                {
                    buff[j]++;
                    addtokeep.insert(buff);
                }
            }
            save++;
        }
    }

    for(auto& x : addtokeep)
    {
        keep.push_back(x);
    }
    sort(keep.begin(), keep.end());

    cout << keep.size() << '\n';
    for(int i = 0; i < keep.size(); i++)
    {
        for(int j = 0; j < keep[0].size(); j++)
        {
            cout << keep[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}