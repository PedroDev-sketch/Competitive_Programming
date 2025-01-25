#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        int n, s, m;
        cin >> n >> s >> m;
        vector<pair<int, int>> task(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> task[i].first >> task[i].second;
        }

        if(task[0].first >= s)
        {
            cout << "YES" << endl;
            continue;
        }

        bool shower = false;
        for(int i = 1; i < n; i++)
        {
            if((task[i].first - task[i - 1].second) >= s) shower =true;
        }

        if((m - task[n-1].second) >= s) shower = true;

        if(shower) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
