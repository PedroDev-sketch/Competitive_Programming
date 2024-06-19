#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> type(n);
    vector<pair<int, int>> range(n);

    for (int i = 0; i < n; i++)
    {
        cin >> type[i] >> range[i].first >> range[i].second;
    }


    pair<int, int> average;
    int flag = 1, x = 0;
    while(flag)
    {
        if(!type[x].compare("none"))
        {
            average = {range[x].first, range[x].second};
            flag = 0;
        }
        x++;
    }


    for (int i = 0; i < n; i++)
    {
        if (!type[i].compare("none"))
        {
            average.first = max(average.first, range[i].first);
            average.second = min(average.second, range[i].second);
        }
    }


    if (!type[0].compare("none"))
    {
        cout << range[0].first << " " << range[0].second << endl;
    }
    else if (!type[0].compare("on"))
    {
        cout << average.first - range[0].second << " " << average.second - range[0].first << endl;
    }
    else
    {
        cout << average.first + range[0].second << " " << average.second + range[0].first << endl;
    }


    if (!type[n - 1].compare("none"))
    {
        cout << range[n - 1].first << " " << range[n - 1].second << endl;
    }
    else if (!type[n - 1].compare("on"))
    {
        cout << average.first + range[n - 1].second << " " << average.second + range[n - 1].first << endl;
    }
    else
    {
        cout << average.first - range[n - 1].second << " " << average.second - range[n - 1].first << endl;
    }

    return 0;
}