#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    int seg[n][2], drove[m][2];

    for(int i = 0; i < n; i++)
    {
        cin >> seg[i][0] >> seg[i][1];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> drove[i][0] >> drove[i][1];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(drove[j][1] > seg[i][1])
            {
                int x = 0, k = 0, distdrove = 0, distseg = 0;
                while(x < i || k < j)
                {
                    if(x < i) distseg += seg[x][0];
                    if(k < j) distdrove += drove[k][0];
                    x++, k++;
                }
                if(distdrove - distseg <= 0) ans = drove[j][1] - seg[i][1];
            }
        }
    }

    cout << ans << endl;

    return 0;
}