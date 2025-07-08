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

    char ans;
    int a, b, c;
    cin >> a >> b >> c;

    if(c  % 2 == 0)
    {
        if(a < 0) a= -a;
        if(b < 0) b = -b;
    }

    if(a > b) ans = '>';
    else if(b > a) ans = '<';
    else ans = '=';

    cout << ans << '\n';

    return 0;
}