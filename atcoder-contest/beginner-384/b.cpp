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
    int n, r;
    cin >> n >> r;
    for(int i = 0; i < n; i++)
    {
        int d, a;
        cin >> d >> a;

        if(d == 1 && r >= 1600 && r <= 2799) r+= a;
        else if(d == 2 && r >= 1200 && r <= 2399) r += a;
    }

    cout << r << '\n';

    return 0;
}