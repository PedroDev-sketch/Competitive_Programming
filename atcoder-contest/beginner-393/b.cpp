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

    string s;
    cin >> s;

    int count = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A')
        {
            for(int j = i+1; j < s.size(); j++)
            {
                if(s[j] == 'B')
                {
                    for(int k = j+1; k < s.size(); k++)
                    {
                        if(s[k] == 'C' && j - i == k - j)
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << '\n';

    return 0;
}