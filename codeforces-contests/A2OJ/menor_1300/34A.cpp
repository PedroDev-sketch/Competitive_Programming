#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count;
    cin >> n;
    vector<int> arr(n);
    pair<int,int> ans;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    count = abs(arr.back() - arr[0]);
    ans.first = 1;
    ans.second = arr.size();

    int former;
    for(int i = 1; i < n; i++)
    {
        former = count;
        count = min(count, abs(arr[i] - arr[i-1]));
        if(count != former)
        {
            ans.first = i+1;
            ans.second = i;
        }
    }

    cout << ans.first << " " << ans.second << '\n';

    return 0;
}