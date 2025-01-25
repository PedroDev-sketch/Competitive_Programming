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

    int a, b, c;
    cin >> a >> b >> c;

    if(a+b == c || a+c == b || (a==b && a==c) || b+c == a)
    cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}