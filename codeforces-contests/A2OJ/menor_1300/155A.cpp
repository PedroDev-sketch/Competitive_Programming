#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, histh = -1, histl = 10010;
    cin >> n;
    vector<int> arr(n);
    set<int> ans;

    cin >> arr[0];
    for(int i = 1; i < n; i++)
    {
        cin >> arr[i];
        for(int j = 1; j <= i; j++)
        {
            if(arr[j] > histh && arr[j] > arr[0])
            {
                histh = arr[j];
                ans.insert(histh);
            }
            else if(arr[j] < histl && arr[j] < arr[0])
            {
                histl = arr[j];
                ans.insert(histl);
            }
        }
    }
/* 
    for(auto x : ans)
    {
        cout << x << " "; 
    }
    cout << endl; */
    cout << ans.size() << '\n';

    return 0;
}