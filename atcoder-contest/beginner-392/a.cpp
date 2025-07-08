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

    int a, b ,c;

    cin >> a >> b >> c;

    bool ans = false;

    if(a * b == c || b * c == a || a * c == b) ans = true;

    cout << (ans ? "Yes" : "No");

    return 0;
}