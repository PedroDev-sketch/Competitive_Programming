#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define x first 
#define y second 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    vector<int> t(n), l(n);

    for(int i = 0; i < n; i++)
    {
        cin >> t[i] >> l[i];
    }

    int catchup = 1;
    while(catchup <= d)
    {
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            ans = max(t[i]*(l[i]+catchup), ans);
        }
        catchup++;

        cout << ans << '\n';
    }

    return 0;
}