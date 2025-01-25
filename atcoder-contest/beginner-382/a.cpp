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

    int n, d, empty = 0;
    cin >> n >> d;
    vector<char> in(n);

    for(auto& x : in)
    {
        cin >> x;
        if(x == '.') empty++;
    }

    cout << empty + d << '\n';

    return 0;
}