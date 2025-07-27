#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int one = 0;
        int size = s.size();

        for(auto x : s) if(x == '1') one++;

        if(one > k && n >= 2 * k)
        {
            cout << "Bob\n";
            continue;
            
        }

        else
        {
            cout << "Alice\n";
            continue;
        }
    }

    return 0;
}