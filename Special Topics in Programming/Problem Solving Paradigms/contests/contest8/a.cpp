#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    string s;
    cin >> s;

    for(int i = 3; i >= 1; i--) s[i] = s[i-1];
    s[0] = '0';
    cout << s << '\n';

    return 0;
}