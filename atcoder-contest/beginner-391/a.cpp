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

    string s, ans;
    cin >> s;

    if(s == "N") ans = "S";
    else if(s == "S") ans = "N";
    else if(s == "E") ans = "W";
    else if(s == "W") ans = "E";
    else if(s == "SE") ans = "NW";
    else if(s == "NW") ans = "SE";
    else if(s == "SW") ans = "NE";
    else if(s == "NE") ans = "SW";

    cout << ans << '\n';


    return 0;
}