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

    vector<int> p(5);
    for(auto& t : p) cin >> t;
    int count = 0;

    for(int i = 1; i < 5; i++)
    {
        if(p[i] < p[i-1])
        {
            if(p[i-1] - p[i] == 1) count++;
            else count = -1e5;
        }
    }

    if(count == 1) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}