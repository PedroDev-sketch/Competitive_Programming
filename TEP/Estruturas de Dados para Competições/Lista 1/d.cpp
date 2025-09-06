#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int e, d;
    cin >> e >> d;

    if(e > d) cout << e + d;
    else cout << (d-e)*2;
    cout << '\n';
    return 0;
}