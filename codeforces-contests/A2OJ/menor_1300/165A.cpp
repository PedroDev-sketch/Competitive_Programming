#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

vector<pair<int,int>> cd;

bool isSuperCentral(int a, int b)
{
    int n = cd.size(), con1 = 0, con2 = 0, con3 = 0, con4 = 0;
    for(int i = 0; i < n; i++)
    {
        if(cd[i].x == a && cd[i].y > b) con1++;
        else if(cd[i].x > a && cd[i].y == b) con2++;
        else if(cd[i].x < a && cd[i].y == b) con3++;
        else if(cd[i].x == a && cd[i].y < b) con4++;
    }
    if(con1 && con2 && con3 && con4) return true;
    return false;
}

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, count=0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cd.push_back(make_pair(a, b));
    }

    for(int i = 0; i < n; i++)
    {
        bool check = isSuperCentral(cd[i].first, cd[i].second);
        if(check) count++;
    }

    cout << count << '\n';

    return 0;
}