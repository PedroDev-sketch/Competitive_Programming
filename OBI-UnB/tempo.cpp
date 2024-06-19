#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0, flag;
    cin >> n;
    int num[n] = {0};
    char type[n];
    map<int, pair<int, string>> time;

    for(int i = 0; i < n; i++)
    {
        cin >> type[i] >> num[i];
        time[num[i]] = {0, ""};
    }

    for(int i = 0; i < n; i++)
    {
        if(type[i] == 'R')
        {
            flag = num[i];
        }
        for(auto it = time.begin(); it != time.end(); ++it)
        {

        }
    }

    return 0;
}