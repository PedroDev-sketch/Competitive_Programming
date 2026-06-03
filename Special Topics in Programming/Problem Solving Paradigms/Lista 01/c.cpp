#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

signed main() 
{
    string s;
    cin >> s;

    int n = s.size();
    int total = 0;

    for(int mask = 0; mask < (1 << (n-1)); mask++)
    {
        int num = s[0] - '0';
        int sum = 0;

        for(int i = 1; i < n; i++)
        {
            if(mask & (1 << (i-1)))
            {
                sum += num;
                num = s[i] - '0';
            }
            else num = num*10 + (s[i] - '0');
        }
        sum += num;
        total += sum;
    }

    cout << total << '\n';

    return 0;
}