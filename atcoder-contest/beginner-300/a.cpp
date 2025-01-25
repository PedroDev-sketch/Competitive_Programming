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

    int n, a, b, c;
    cin >> n >> a >> b;
    int sum = a+b, ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        if(c == sum) ans = i;
    }
    cout << ans+1 << '\n';

    return 0;
}