#include <bits/stdc++.h>
using namespace std;
#define int ll

using ll = long long;

signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    ll minimal = 1e9, order = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];

        int former = minimal;
        minimal = min(minimal, arr[i]);
        if(minimal != former) order = i+1;
    }

    auto checking1 = find(arr.begin(), arr.end(), minimal);
    auto checking2 = find(checking1+1, arr.end(), minimal);

    if(checking2 != arr.end()) cout << "Still Rozdil" << '\n';
    else cout << order << '\n';

    

    return 0;
}