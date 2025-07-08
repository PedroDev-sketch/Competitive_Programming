#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> xs;

    for(int i = 0; i < n; i++)
    {
        int grade = 0;
        for(int j = 0; j < 3; j++)
        {
            int num;
            cin >> num;
            grade += num;
        }
        xs.push_back(grade);
    }

    vector<int> ys = xs;
    sort(all(ys), greater<>());

    for(int i = 0; i < n; i++)
    {
        if(xs[i] + 300 >= ys[k-1]) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}