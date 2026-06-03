#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int k;
    cin >> k;

    /* vector<int> sto(1e5+7);
    string start = "19";
    sto[0] = 19;

    for(int i = 1; i < 1e5+7; i++)
    {
        sto[i] = stoi(start);
        int newnum = start[start.size()-1] - '0' - 1;
        for(int j = start.size() - 2; j >= 0; j--)
        {
            if(newnum == -1)
            {
                newnum = 9;
            }

            start[j] = newnum + '0';
        }
    } */

    vector<int> sto;
    string start;
    
    for(int i = 19; i < 2*1e7; i+=9)
    {
        start = to_string(i);

        int total = 0;
        for(auto p : start) total += p-'0';
        if(total == 10) sto.push_back(i);
    }

    cout << sto[k-1] << '\n';

    return 0;
}