#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int total = 0;

    int last = 0;
    while(n--)
    {
        int x;
        cin >> x;

        if(last)
        {
            if((x-last)*a < b) total += (x-last)*a;
            else total += b;
        }

        last = x;
    }

    cout << total << '\n';
}