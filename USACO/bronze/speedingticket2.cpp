#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> limits(101);

    int ans = 0, pos = 1;
    for(int i = 0; i < n; i++)
    {
        int seg, limit;
        cin >> seg >> limit;
        for(int j = 0; j < seg; j++)
        {
            limits[pos++] = limit;
        }
    }

    pos = 1;

    for(int i = 0; i < m; i++)
    {
        int seg, speed;
        cin >> seg >> speed;
        for(int j = 0; j < seg; j++)
        {
            if(speed > limits[pos])
            {
                ans = max(ans, speed - limits[pos]);
            }
            pos++;
        }
    }

    cout << ans << endl;
    return 0;
}