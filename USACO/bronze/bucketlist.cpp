#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n, s, t, b, ans;
    cin >> n;
    vector<int> schedule(1001);

    for(int i = 0; i < n; i++)
    {
        cin >> s >> t >> b;
        for(int j = s; j <= t; j++)
        {
            schedule[j] += b;
        }
    }

    for(int i = 0; i < schedule.size(); i++)
    {
        ans = max(ans, schedule[i]);
    }

    cout << ans << endl;

    return 0;
}