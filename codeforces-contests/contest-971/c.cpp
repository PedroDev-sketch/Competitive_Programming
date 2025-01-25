#include <bits\stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    ll x, y, k, count, cdx, cdy, num;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> k;
        count = 0, cdx = 0, cdy = 0, num = 2;
        while(cdx != x || cdy != y)
        {
            if(num % 2 == 0)
            {
                if(cdx <= x - k)
                {
                    cdx += k;
                    count++;
                } 
                else if(cdx < x)
                {
                    cdx += x - cdx;
                    count++;
                } 
                else if(cdx == x)
                {
                    count++;
                }
            }

            else if(num % 2)
            {
                if(cdy <= y - k)
                {
                    cdy += k;
                    count++;
                }
                else if(cdy < y)
                {
                    cdy += y - cdy;
                    count++;
                } 
                else if(cdy == y)
                {
                    count++;
                }
            }
            num++;
        }
        cout << count << endl;
    }

    return 0;
}