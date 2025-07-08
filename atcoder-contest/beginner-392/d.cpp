#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using ld = long double;

#define x first 
#define y second 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;

    ld chance = 0;
    vector<map<int, ld>> faces(n);

    int sides;
    for(int i = 0; i < n; i++)
    {
        cin >> sides;

        ld div = 1 / (ld)sides;

        int num;
        for(int j = 0; j < sides; j++)
        {
            cin >> num;
            faces[i][num]+=div;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            ld current = 0;

            auto it = faces[i].begin(), jt = faces[j].begin();
            while(it != faces[i].end() && jt != faces[j].end())
            {
                if(it -> x == jt -> x)
                {
                    current += (it -> y) * (jt -> y);
                    it++;
                    jt++;
                    continue;
                }

                if(it -> x < jt -> x)
                {
                    it++;
                }

                else jt++;
            }

            chance = max(chance, current);
        }
    }

    cout << setprecision(15) << chance << '\n';

    return 0;
}