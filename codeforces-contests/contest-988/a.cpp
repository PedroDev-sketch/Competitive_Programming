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
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        int n, count = 0;
        cin >> n;
        set<int> s;

        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            if(!s.count(a))
            {
                s.insert(a);
            }
            else
            {
                count++;
                s.erase(a);
            }
        }
        cout << count << '\n';
    }

    return 0;
}