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

    int n;
    cin >> n;

    string s;
    cin >> s;

    bool first = true;
    int begin, end;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1' && first)
        {
            begin == i;
            first = false;
        }

        else if(s[i] == '1')
        {
            end = i;
        }
    }

    int mid = (begin + end) / 2;
    int count = 0, numof1 = 0;

    for(int i = begin; i <= end; i++)
    {
        if(s[i] == '1')
        {
            if(i != begin && i != end)
            {
                numof1++;
                count-= numof1;
            }

            if(i < mid)
            {
                count += mid - i;
            }

            if(i >= mid)
            {
                count += i - mid;
            }
        }
    }

    cout << count << '\n';
    

    return 0;
}