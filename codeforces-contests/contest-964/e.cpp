#include <bits\stdc++.h>
using namespace std;
using ll= long long;
using vll = vector<ll>;

int main()
{
    int t, l, r, count;
    cin >> t;
    while(t--)
    {
        count = 0;
        cin >> l >> r;
        int comp = l;

        vll dist(r-l + 1);
        for(int i = 0; i <= r-l; i++)
        {
            dist[i] = comp++;
        }

        if(floor(dist[0]/3) && floor(dist[1]/3))
        {
            while(dist[0])
            {
                dist[0] = floor(dist[0]/3);
                dist[1] *= 3;
                count++;
            }
        }
        else if(!floor(dist[0]/3) && !floor(dist[1]/3))
        {
            dist[0] *= 3;
            dist[1] = 0;
            count++;
        }
        else if(!floor(dist[0]/3) && floor(dist[1]/3))
        {
            dist[0] = 0;
            dist[1] *= 3;
            count++;
        }
        
        for(int i = 0; i <= r-l; i++)
        {
            while(dist[i])
            {
                dist[i] = floor(dist[i]/3);
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}