#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, p;
    cin >> n >> p;

    int np = 1, d = 0;

    while(np*p <= n)
    {
        d++;
        np *= p;
    }
    
    cout << d << '\n';
    return 0;
}