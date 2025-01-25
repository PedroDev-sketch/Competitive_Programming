#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
#define x first 
#define y second 

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    map<int, int> vis;
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++)
    {
        if(vis.count(arr[i]))
        {
            ans[i] = vis[arr[i]];
        }
        vis[arr[i]] = i+1;
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << (i < n-1 ? " " : "\n");
    }

    return 0;
}