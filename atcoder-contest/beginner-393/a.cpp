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

    string s1, s2;
    int ans = 0;

    cin >> s1 >> s2;

    if(s1 == "sick" && s2 == "sick") ans = 1;
    else if(s1 == "fine" && s2 == "sick") ans = 3;
    else if(s1 == "sick" && s2 == "fine") ans = 2;
    else ans = 4;

    cout << ans << '\n';

    return 0;
}