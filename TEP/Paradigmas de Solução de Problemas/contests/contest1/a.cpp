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

    int a, b;
    cin >> a >> b;

    double ans = ( (double) a * b) / (double) 100;
    cout << ans << '\n';

    return 0;
}