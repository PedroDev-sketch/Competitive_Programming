#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ai, bi;
    cin >> n;
    set<int> a, b;

    for(int i = 0; i < n; i++)
    {
        cin >> ai;
        a.insert(ai);
    }

    for(int i = 0; i < n; i++)
    {
        cin >> bi;
        b.insert(bi);
    }

    auto it = next(a.begin(), a.size()-1);
    auto k = next(b.begin(), b.size()-1);
    cout << (*it) + (*k) << endl;

    return 0;
}