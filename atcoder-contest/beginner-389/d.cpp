#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 
#define int ll

int solve(int r)
{
    int ans = 0;
    int col = r-1;
    
    for(int i = 1; i <= r-1;)
    {
        if((2*col+1)*(2*col+1) + (2*i+1)*(2*i+1) <= 4*r*r)
        {
            ans += col;
            i++;
        }

        else col--;
    }

    ans *= 4;
    ans += (r-1)*4 + 1;

    return ans;
}

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int r;
    cin >> r;

    cout << solve(r) << '\n';

    return 0;
}