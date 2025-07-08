#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    int n, count = 0;
    cin >> n;

    map<int,int> hist;

    int num;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        hist[num]++;
    }

    count = hist.size();

    cout << (count % 2 ? count : count - 1) << '\n';

    return 0;
}
