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
    int n;
    char c1, c2;
    cin >> n >> c1 >> c2;
    string s;
    cin >> s;

    for(auto& x : s)
    {
        if(x != c1 && x != c2)
        {
            x = c2;
        }
    }

    cout << s << '\n';

    return 0;
}