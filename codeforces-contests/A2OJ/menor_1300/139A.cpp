#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> week(7);
    for(int i = 0; i < 7; i++)
    {
        cin >> week[i];
    }

    while(n>0)
    {
        for(int i = 0; i < 7; i++)
        {
            n -= week[i];
            if(n <= 0)
            {
                cout << (i+1) << '\n';
                return 0;
            }
        }
    }

    return 0;
}