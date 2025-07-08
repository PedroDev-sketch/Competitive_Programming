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

    int n, m;
    cin >> n >> m;

    vector<string> s(n), t(m);

    for(auto& p : s) cin >> p;
    for(auto& p : t) cin >> p;

    for(int a = 0; a <= n - m; a++)
    {
        for(int b = 0; b <= n - m; b++)
        {
            bool ok = true;
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(s[a + i][b + j] != t[i][j])
                    {
                        ok = false;
                    }
                }
            }

            if (ok) 
            {
                cout << a + 1 << " " << b + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}