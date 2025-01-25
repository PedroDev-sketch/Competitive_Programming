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
    int count = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '|' && count)
        {
            cout << count << (i+1 < s.length() ? " " : "\n");
            count = 0;
        }
        else if(s[i] == '-') count++;
    }

    return 0;
}