#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int p1, c1, p2, c2;
    cin >> p1 >> c1 >> p2 >> c2;

    int l1 = p1*c1, l2 = p2*c2;

    if(l1==l2)cout << 0;
    else cout << (l1 > l2 ? "-1" : "1") << '\n';
    return 0;
}