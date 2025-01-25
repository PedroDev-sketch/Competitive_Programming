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

    int n;
    cin >> n;

    int one = 1, count = 1;
    while(one != n)
    {
        one *= count;
        count++;
    }

    cout << count-1 << '\n';

    return 0;
}