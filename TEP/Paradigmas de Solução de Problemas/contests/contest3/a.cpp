#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int s, t, x;
    cin >> s >> t >> x;

    if(x >= s && x <= t-1) cout << "Yes";
    else if(t < s && (!(x < s && x >= t))) cout << "Yes";
    else cout << "No";
    cout << '\n';
}