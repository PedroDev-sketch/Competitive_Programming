#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s[0] - '0';
    int m = s[2] - '0';

    cout << n *m << '\n';

    return 0;
}