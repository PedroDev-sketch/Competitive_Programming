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
    string s;
    cin >> s;

    int c1 = 0, c2 = 0, c3 = 0;

    for(auto x: s)
    {
        if(x == '1') c1++;
        else if(x == '2') c2++;
        else if(x == '3') c3++;
    }

    if(c1 ==1 && c2 == 2 && c3 == 3)
        {
            cout << "Yes";
        }
        else cout << "No";
        cout << '\n';

    return 0;
}