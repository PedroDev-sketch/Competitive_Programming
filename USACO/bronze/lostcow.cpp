#include <bits\stdc++.h>
using namespace std;

int main()
{
    int x, y, counter = 0, num = 1, dist = 0, origin;
    cin >> x >> y;
    int start = x;

    while(x != y)
    {
        origin = x;

        if(counter == 0 || counter % 2 == 0)
        {
            x = start + num;
        }

        else 
        {
            x = start - num;
        }

        dist += abs(x - origin);
        num *= 2;
        counter++;

        if(x > y)
        {
            dist -= x - y;
            break;
        }
    }

    cout << dist << endl;

    return 0;
}