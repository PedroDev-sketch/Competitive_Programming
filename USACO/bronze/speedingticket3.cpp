#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> limit(n), bessie(m);
    for(auto& [d, s] : limit) cin >> d >> s;
    for(auto& [d, s] : bessie) cin >> d >> s;

    int i = 0, j = 0, over = 0;
    while(i < n && j < m)
    {
        over = max(over, bessie[j].second - limit[i].second);
        if(limit[i].first < bessie[j].first)
        {
            bessie[j].first -= limit[i].first;
            i++;
        }

        else if(limit[i].first > bessie[j].first)
        {
            limit[i].first -= bessie[j].first;
            j++;
        }

        else
        {
            i++;
            j++;
        }
    }

    cout << over << endl;
    return 0;
}