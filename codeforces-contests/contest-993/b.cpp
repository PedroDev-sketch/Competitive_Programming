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

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        for(auto& x : s)
        {
            if(x == 'q') x = 'p';
            else if (x == 'p') x = 'q';
        }

        reverse(s.begin(),s.end());
        cout << s << '\n';
    }

    return 0;
}