#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, m, k = 200010;
    vector<int> ans(k, -1);

    cin >> n >> m;
    int a, b;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        while(k > a)
        {
            k--;
            ans[k] = i+1;
        }
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b;
        cout << ans[b] << '\n';
    }

    return 0;
}