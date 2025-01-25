#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll

signed main()
{
    int n, m, last_house = 1, time = 0;
    cin >> n >> m;
    vector<int> list(m);

    for(int i = 0; i < m; i++)
    {
        cin >> list[i];
    }

    for(int i = 0; i < m; i++)
    {
        if(list[i] < last_house)
        {
            time += (n - last_house) + list[i];
        }
        else
        {
            time += abs(list[i] - last_house);
        }
        last_house = list[i];
    }

    cout << time << '\n';
    return 0;
}